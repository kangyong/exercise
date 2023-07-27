cmake_minimum_required (VERSION 2.8) 
project (test C CXX)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
SET(CMAKE_BUILD_TYPE "DEBUG")


# OpneCV
# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
set(OpenCV_DIR /home/kangyong/github/opencv/build)
find_package(OpenCV 4.0 REQUIRED PATHS "/home/kangyong/usr/local/")
# find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")


# 
# tensorRT
if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
    set(CURRENT_SYSTEM "Linux")
    MESSAGE(STATUS "current operation system is ${CMAKE_SYSTEM}")
    message(STATUS "current operation system name is ${CMAKE_SYSTEM}")
    set(TENSORRT_DIR "/home/kangyong/github/TensorRT-7.2.2.3/")
    set(CUDA_TOOLKIT_ROOT_DIR "/usr/local/cuda")
    set(CUDNN_ROOT_DIR "/usr/local/cuda")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "aarch64") # orin
    MESSAGE(STATUS "current operation system is ${CMAKE_SYSTEM}")
    message(STATUS "current operation system name is ${CMAKE_SYSTEM_NAME}")
    message(STATUS "current CMAKE_HOST_SYSTEM_PROCESSOR name is ${CMAKE_HOST_SYSTEM_PROCESSOR}")
    set(CURRENT_SYSTEM "aarch")
    set(TENSORRT_INCLUDE_DIRS /usr/include/aarch64-linux-gnu/)
    set(TENSORRT_LIBRARY_DIRS /usr/lib/aarch64-linux-gnu/)
    find_path(TENSORRT_INCLUDE_DIR NvInfer.h
        HINTS ${TENSORRT_ROOT} PATH_SUFFIXES include/)
    message(STATUS "Found TensorRT headers at ${TENSORRT_INCLUDE_DIR}")
    find_library(TENSORRT_LIBRARY_INFER nvinfer
        HINTS ${TENSORRT_ROOT} ${TENSORRT_BUILD} ${CUDA_TOOLKIT_ROOT_DIR}
        PATH_SUFFIXES lib lib64 lib/x64)
    find_library(TENSORRT_LIBRARY_ONNXPARSER nvonnxparser
        HINTS  ${TENSORRT_ROOT} ${TENSORRT_BUILD} ${CUDA_TOOLKIT_ROOT_DIR}
        PATH_SUFFIXES lib lib64 lib/x64)
    set(TENSORRT_LIBRARY ${TENSORRT_LIBRARY_INFER} ${TENSORRT_LIBRARY_ONNXPARSER})
    message(STATUS "Find TensorRT libs: ${TENSORRT_LIBRARY}")
endif()



# BOOST
FIND_PACKAGE(Boost REQUIRED COMPONENTS system program_options)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
list(APPEND test_LINKER_LIBS
    ${Boost_SYSTEM_LIBRARIES}
    ${Boost_PROGRAM_OPTIONS_LIBRARY})

set(PROJECT_ROOT ".")
file(GLOB src_file ${PROJECT_ROOT}/*.cpp)

add_executable(main boost_program_options.cpp ${src_file})
target_link_libraries(main ${test_LINKER_LIBS})




