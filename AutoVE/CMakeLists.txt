cmake_minimum_required(VERSION 3.20)
project(AutoVE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define library names
set(UTILS_LIBRARY UtilsLib)
set(GUI_LIBRARY GUILib)

# Request the required wxWidgets libs
set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc media html REQUIRED)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

# Add subdirectories for libraries
add_subdirectory(${UTILS_LIBRARY})
add_subdirectory(${GUI_LIBRARY})

# Include directories
include_directories(${GUI_LIBRARY} ${UTILS_LIBRARY})

# Define source files
set(SOURCE_FILES main.cpp pch.h AutoVEApp.h AutoVEApp.cpp)

# Add executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCE_FILES})

# Link libraries
target_link_libraries(${PROJECT_NAME}
        PUBLIC
        ${wxWidgets_LIBRARIES}
        PRIVATE
        ${GUI_LIBRARY}
        ${UTILS_LIBRARY}
        )

# Precompiled headers
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)
