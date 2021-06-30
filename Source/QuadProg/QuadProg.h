/*
 File $Id: QuadProg++.hh 232 2007-06-21 12:29:00Z digasper $ 
 
 The quadprog_solve() function implements the algorithm of Goldfarb and Idnani 
 for the solution of a (convex) Quadratic Programming problem
 by means of an active-set dual method.
	 
The problem is in the form:

min 0.5 * x G x + g0 x
s.t.
    CE^T x + ce0 = 0
    CI^T x + ci0 >= 0
	 
 The matrix and vectors dimensions are as follows:
     G: n * n
		g0: n
				
		CE: n * p
	 ce0: p
				
	  CI: n * m
   ci0: m

     x: n
 
 The function will return the cost of the solution written in the x vector or
 std::numeric_limits::infinity() if the problem is infeasible. In the latter case
 the value of the x vector is not correct.
 
 References: D. Goldfarb, A. Idnani. A numerically stable dual method for solving
             strictly convex quadratic programs. Mathematical Programming 27 (1983) pp. 1-33.

 Notes:
  1. pay attention in setting up the vectors ce0 and ci0. 
	   If the constraints of your problem are specified in the form 
	   A^T x = b and C^T x >= d, then you should set ce0 = -b and ci0 = -d.
  2. The matrices have column dimension equal to MATRIX_DIM, 
     a constant set to 20 in this file (by means of a #define macro). 
     If the matrices are bigger than 20 x 20 the limit could be
		 increased by means of a -DMATRIX_DIM=n on the compiler command line.
  3. The matrix G is modified within the function since it is used to compute
     the G = L^T L cholesky factorization for further computations inside the function. 
     If you need the original matrix G you should make a copy of it and pass the copy
     to the function.
    
 Author: Luca Di Gaspero
  			 DIEGM - University of Udine, Italy
				 luca.digaspero@uniud.it
				 http://www.diegm.uniud.it/digaspero/
 
 The author will be grateful if the researchers using this software will
 acknowledge the contribution of this function in their research papers.
 
 Copyright (c) 2007-2016 Luca Di Gaspero
 
 This software may be modified and distributed under the terms
 of the MIT license.  See the LICENSE file for details.
*/


#ifndef _QUADPROGPP
#define _QUADPROGPP
#include "cv.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Array.h"

using namespace std;

namespace QP
{
	void solveQuadraProgram( cv::Mat_<double> H,  cv::Mat_<double> h,  cv::Mat_<double> A,  cv::Mat_<double> a, 
		 cv::Mat_<double> B,  cv::Mat_<double> b,  cv::Mat_<double> &params);
	void solveQuadraProgram( cv::Mat_<double> H,  cv::Mat_<double> h,  cv::Mat_<double> B,  cv::Mat_<double> b,  cv::Mat_<double> &params);


	double solve_quadprog(QPArray::Matrix<double>& G, QPArray::Vector<double>& g0, 
		const QPArray::Matrix<double>& CE, const QPArray::Vector<double>& ce0,  
		const QPArray::Matrix<double>& CI, const QPArray::Vector<double>& ci0, 
		QPArray::Vector<double>& x);

	// Utility functions for updating some data needed by the solution method 
	void compute_d(QPArray::Vector<double>& d, const QPArray::Matrix<double>& J, const QPArray::Vector<double>& np);
	void update_z(QPArray::Vector<double>& z, const QPArray::Matrix<double>& J, const QPArray::Vector<double>& d, int iq);
	void update_r(const QPArray::Matrix<double>& R, QPArray::Vector<double>& r, const QPArray::Vector<double>& d, int iq);
	bool add_constraint(QPArray::Matrix<double>& R, QPArray::Matrix<double>& J, QPArray::Vector<double>& d, int& iq, double& rnorm);
	void delete_constraint(QPArray::Matrix<double>& R, QPArray::Matrix<double>& J, QPArray::Vector<int>& A, QPArray::Vector<double>& u, int n, int p, int& iq, int l);

	// Utility functions for computing the Cholesky decomposition and solving
	// linear systems
	void cholesky_decomposition(QPArray::Matrix<double>& A);
	void cholesky_solve(const QPArray::Matrix<double>& L, QPArray::Vector<double>& x, const QPArray::Vector<double>& b);
	void forward_elimination(const QPArray::Matrix<double>& L, QPArray::Vector<double>& y, const QPArray::Vector<double>& b);
	void backward_elimination(const QPArray::Matrix<double>& U, QPArray::Vector<double>& x, const QPArray::Vector<double>& y);

	// Utility functions for computing the scalar product and the euclidean 
	// distance between two numbers
	double scalar_product(const QPArray::Vector<double>& x, const QPArray::Vector<double>& y);
	double distance(double a, double b);

	// Utility functions for printing vectors and matrices
	void print_matrix(char* name, const QPArray::Matrix<double>& A, int n = -1, int m = -1);

	template<typename T>
	void print_vector(char* name, const QPArray::Vector<T>& v, int n = -1);
}



#endif // #define _QUADPROGPP
