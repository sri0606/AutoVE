cmake_minimum_required(VERSION 3.20)
project(AutoVE)
set(GUI_LIBRARY GUILib)

set(CMAKE_CXX_STANDARD 17)

# Request the required wxWidgets libs
# Turn off wxWidgets own precompiled header system, since
# it doesn't seem to work. The CMake version works much better.
set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc media html REQUIRED)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

add_subdirectory(${GUI_LIBRARY})
include_directories(${GUI_LIBRARY})

set(SOURCE_FILES main.cpp pch.h AutoVEApp.h AutoVEApp.cpp)

add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCE_FILES})

# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${GUI_LIBRARY})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)
