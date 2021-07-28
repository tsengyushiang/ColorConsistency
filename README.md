# Quick Start

- cmake-gui 3.18.3
    - `your project folder/ColorConsistency/Source`
    - `your project folder/ColorConsistency/Source/build`
    - configure with vs2019
    - download libraies 
        - [opencv3.4](https://drive.google.com/file/d/1UucTEp2o5m3zd7H_vI1Qbz00tHbl7XTp/view?usp=sharing)
        - [VTK-8.2](https://drive.google.com/file/d/1IE-Nehx3HWsSet8xFCttnoRAiGZgRe5q/view?usp=sharing)
    - choose `opencv-3.4/build`
    - generate and OpenProject

-  Open `your project folder/ColorConsistency/Source/build/CoColourPro.sln`
- switch to `Realse/x64` and set `Uniform` as start project

- set libirarise

    - add `C:\git\VTK-8.2.0\build\lib\Release` to lib folder

    - replace `C:\ProgramData\Anaconda3\Library\lib\hdf5.lib...` to
        ```
        C:\Users\tseng\anaconda3\Library\lib\hdf5.lib
        vtkRenderingOpenGL2-8.2.lib
        vtkCommonCore-8.2.lib
        vtksys-8.2.lib
        vtkCommonDataModel-8.2.lib
        vtkCommonMath-8.2.lib
        vtkCommonMisc-8.2.lib
        vtkCommonSystem-8.2.lib
        vtkCommonTransforms-8.2.lib
        vtkCommonExecutionModel-8.2.lib
        vtkRenderingCore-8.2.lib
        vtkCommonColor-8.2.lib
        vtkCommonComputationalGeometry-8.2.lib
        vtkFiltersCore-8.2.lib
        vtkFiltersGeneral-8.2.lib
        vtkFiltersGeometry-8.2.lib
        vtkFiltersSources-8.2.lib
        vtkglew-8.2.lib
        vtkInteractionStyle-8.2.lib
        vtkFiltersExtraction-8.2.lib
        vtkFiltersStatistics-8.2.lib
        vtkImagingFourier-8.2.lib
        vtkImagingCore-8.2.lib
        vtkRenderingLOD-8.2.lib
        vtkFiltersModeling-8.2.lib
        vtkIOPLY-8.2.lib
        vtkIOCore-8.2.lib
        vtkdoubleconversion-8.2.lib
        vtklz4-8.2.lib
        vtklzma-8.2.lib
        vtkzlib-8.2.lib
        vtkFiltersTexture-8.2.lib
        vtkRenderingFreeType-8.2.lib
        vtkfreetype-8.2.lib
        vtkIOExport-8.2.lib
        vtkIOImage-8.2.lib
        vtkDICOMParser-8.2.lib
        vtkmetaio-8.2.lib
        vtkjpeg-8.2.lib
        vtkpng-8.2.lib
        vtktiff-8.2.lib
        vtkIOXML-8.2.lib
        vtkIOXMLParser-8.2.lib
        vtkexpat-8.2.lib
        vtkRenderingContext2D-8.2.lib
        vtkRenderingGL2PSOpenGL2-8.2.lib
        vtkgl2ps-8.2.lib
        vtkIOGeometry-8.2.lib
        vtkIOLegacy-8.2.lib
        ```

- this project is fork version of https://github.com/MenghanXia/ColorConsistency

## Introduction

This project is developed for optimizing the color consistency across images and guarantee the imaging
quality of individual image meanwhile. we parameterize the color remapping curve as transform model, 
and express the constraints of color consistency, contrast and gradient in an uniform energy function. It 
can be formulated as a convex quadratic programming problem which provides the global optimal solution efficiently.

This C++ implemented algorithm is described in:  
"[Color Consistency Correction Based on Remapping Optimization for Image Stitching](http://menghanxia.github.io/papers/2017_Color_Remapping_Optimization_iccvw.pdf)", ICCV Workshop 2017.  
"[A Closed-Form Solution for Multi-View Color Correction with Gradient Preservation](http://menghanxia.github.io/papers/2019_Color_Consistency_Optimization_isprs_journal.pdf)", ISPRS Journal 2019 (Extended version).  
This program is free for personal, non-profit and academic use. If you have any question, please contact: menghanxyz@gmail.com (Menghan Xia)

Here is an example for demonstration below:

<img src="Docs/demo_show.jpg" width="900px"/>

## Usage
### 1. Dependent Libarary [compulsory]:
OpenCV 2.4.9 is recommended.

### 2. Project Configure:
This procedure is developed on *Visual Studio 2010* under *Windows8.1* system environment,
where the source code is organized with CMakeLists. So, before opening it in Visual Studio,
you need to configure the project with the software named *CMake*.

### 3. Running and Test:
There will be a "*Data*" folder in the decompressing files, where three created folders exist:  
- "*Cache*"  : creat a text file that describes the adjacent relationships of each image. [example contained]
- "*Images*" : input your source images that are aligned geometrically. [example contained]
- "*Results*": procedure will output the processed results in this position. [creat it by yourself]

Besides, to use the existing "*Data*" directory successfully, do not forget to UPDATE the path variable 
'*baseDir*' as **the absolute path** of your directory "*Data*" in the source file "*CoColour/Source/Utils/util.h*" [line 16]

So far, you can run the procedure and see the color correction results now. 