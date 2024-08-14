project(GUILib)

set(SOURCE_FILES MainFrame.cpp MainFrame.h pch.h MainWindow.h MainWindow.cpp VideoPanel.cpp VideoPanel.h ChatPanel.cpp ChatPanel.h)
set(wxBUILD_PRECOMP OFF)
set(UTILS_LIBRARY UtilsLib)
find_package(wxWidgets COMPONENTS core base xrc media html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})