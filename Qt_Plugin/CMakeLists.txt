# Cmake Code for XPlane
include_directories("/usr/local/include")
set(CMAKE_CXX_FLAGS "-shared -rdynamic -nodefaultlibs -undefined_warning -fPIC -Wall -Wextra")
add_definitions(-DAPL=0 -DIBM=0 -DLIN=1 -DXPLM200=1 -DXPLM210=1 -DXPLM300=1 -DXPLM301=1)
# End
# CMake for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(project_sources mainwindow.cpp qt_Xplane_test.cpp)
set(project_headers mainwindow.h)
set(project_ui mainwindow.ui)
qt5_wrap_ui(ui_wrap ${project_ui})
qt5_wrap_cpp(moc_sources ${project_headers})
add_executable(qt_xplane_test
        ${project_sources}
        ${ui_wrap}
        ${moc_sources}
        ${project_headers})
target_link_libraries(qt_xplane_test Qt5::Core Qt5::Gui Qt5::Widgets)
