cmake_minimum_required(VERSION 3.20)
project(UtilsLib)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES Actions.cpp Actions.h AutoVEAPI.cpp AutoVEAPI.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
## Specify the paths to FFmpeg
#set(FFMPEG_INCLUDE_DIR /path/to/ffmpeg/include)
#set(FFMPEG_LIBRARY_DIR /path/to/ffmpeg/lib)
#
## Find FFmpeg libraries
#find_library(AVCODEC_LIBRARY NAMES avcodec PATHS ${FFMPEG_LIBRARY_DIR})
#find_library(AVFORMAT_LIBRARY NAMES avformat PATHS ${FFMPEG_LIBRARY_DIR})
#find_library(AVUTIL_LIBRARY NAMES avutil PATHS ${FFMPEG_LIBRARY_DIR})
#find_library(SWSCALE_LIBRARY NAMES swscale PATHS ${FFMPEG_LIBRARY_DIR})
#
## Check if the libraries are found
#if(NOT AVCODEC_LIBRARY OR NOT AVFORMAT_LIBRARY OR NOT AVUTIL_LIBRARY OR NOT SWSCALE_LIBRARY)
#    message(FATAL_ERROR "Could not find one or more FFmpeg libraries")
#endif()
#
## Include directories
#include_directories(${FFMPEG_INCLUDE_DIR})

## Link the FFmpeg libraries
#target_link_libraries(${PROJECT_NAME}
#        ${AVCODEC_LIBRARY}
#        ${AVFORMAT_LIBRARY}
#        ${AVUTIL_LIBRARY}
#        ${SWSCALE_LIBRARY}
#        )
