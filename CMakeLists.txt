# [ cmake build system --config ]


cmake_minimum_required(VERSION 3.20...3.29)
project(calibration C CXX)


# find package command. Generally, we have (simple signature)

#  [[ find_package(<PackageName> [<version>] [QUIET] \
#       [MODULE] [REQUIRED] [COMPONENTS <components>...])  ]]

# where [.] are optional arguments. We do not expect further
# configuration to be required. In particular, [MODULE]
# defines whether cmake searches external configuration [1].

# If !no_mod, then it uses some (older style)

#                    Find<PackageName>.cmake 

# 'Find Module' file (hence 'module mode'). Else if no_mod, 
# config mode is enabled and cmake looks instead for 

#           <PackageName>-config[-version].cmake  
#        or <lowercasePackageName>-config[-version].cmake
#        or <PackageName>Config[-version].cmake

# files. Note that if no_mod is enabled and no external config
# file is found, we are presented with a fatal error. A reason 
# why we might desire no_mod despite this, is because module 
# mode might lead to less apparent errors due to Find Modules 
# becoming out-of-date [1]. We strongly recommend installing
# library dependencies using a package manager. 

# if you intend to build dependencies from source, and there
# is definitely a case for it, link and include directories
# should be modified to reflect their absolute paths.

find_package(Eigen3 3.3.4 REQUIRED NO_MODULE)
if (Eigen3_FOUND)
    message(STATUS "found eigen --version: " 
        "${Eigen3_VERSION} @ ${Eigen3_DIR}")
endif (Eigen3_FOUND)


find_package(LAPACKE QUIET)
if (LAPACKE_FOUND) 
    message(STATUS "found lapacke ${LAPACKE_LIBRARIES}")
elseif (LAPACKE_FOUND)
    message(STATUS "lapacke libraries disabled\n")
endif (LAPACKE_FOUND)


find_package(BLAS QUIET)
if (BLAS_FOUND)
    message(STATUS "found blas @ ${BLAS_LIBRARIES}")
endif (BLAS_FOUND)


find_package(OpenMP QUIET)
if (OpenMP_FOUND)
    message(STATUS "found openmp ${OpenMP_CXX_LIB_NAMES}")
endif (OpenMP_FOUND)


find_package(CUDAToolkit QUIET) 
if (CUDAToolkit_FOUND)
    message(STATUS "found cuda toolkit --version: "
        "${CUDAToolkit_VERSION} @ ${CUDAToolkit_TARGET_DIR}")
    
    message("    ... enabling cuda language")
    enable_language(CUDA)
endif (CUDAToolkit_FOUND)


find_package(GTest 1.14.0 REQUIRED QUIET)
if (GTest_FOUND)
    message(STATUS "found gtest --version: "
        "${GTest_VERSION} @ ${GTest_ROOT}")
endif(GTest_FOUND)


find_package(Matplot++ QUIET)
if (Matplot++_FOUND)
    message(STATUS "found matplot++ --version: "
        "${Matplot++_VERSION} @ ${Matplot++_DIR}")
endif(Matplot++_FOUND)

find_package(Boost 1.70 REQUIRED NO_MODULE)
if (Boost_FOUND)
    message(STATUS "found boost --version: "
        "${Boost_VERSION} @ ${Boost_DIR}")
endif(Boost_FOUND)


# cmake aware of local scripts path.
list(APPEND CMAKE_MODULE_PATH "${calibration_SOURCE_DIR}/cmake")
include(CMakePackageConfigHelpers)      # -- ignore.
include(GNUInstallDirs)                 # -- ignore.
include(functions)                      # local scripts.

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${calibration_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${calibration_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${calibration_SOURCE_DIR}/lib)







# references & documentation:

#   [1]. CMake Org. cmake-commands <find_package> documentation.
#           https://cmake.org/cmake/help/latest/command/find_package.html.

#   [2]. CMake Org. cmake-modules <FindGTest> documentation.
#           https://cmake.org/cmake/help/latest/module/FindGTest.html.

#   [3]. CMake Org. cmake-modules <FindCUDAToolkit> documentation.
#           https://cmake.org/cmake/help/latest/module/FindCUDAToolkit.html.

#   [4]. CMake Org. cmake-modules <FindBLAS> documentation.
#           https://cmake.org/cmake/help/latest/module/FindBLAS.html#findblas.

#   [5]. CMake Org. cmake-modules <FindOpenMP> documentation.
#           https://cmake.org/cmake/help/latest/module/FindOpenMP.html

#   [6]. CMake Org. cmake-modules <FindBoost> documentation.
#           https://cmake.org/cmake/help/latest/module/FindBoost.html
