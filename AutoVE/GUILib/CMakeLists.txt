project(GUILib)

set(UTILS_LIBRARY UtilsLib)
set(SOURCE_FILES MainFrame.cpp MainFrame.h pch.h MainWindow.h MainWindow.cpp VideoPanel.cpp VideoPanel.h ChatPanel.cpp ChatPanel.h VideoTimeline.cpp VideoTimeline.h)
set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc media html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC ${wxWidgets_LIBRARIES} PRIVATE ${UTILS_LIBRARY})

# Include directories for UtilsLib
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/${UTILS_LIBRARY})