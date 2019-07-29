# Cmake Code for XPlane
include_directories("/usr/local/include")
set(CMAKE_CXX_FLAGS "-shared -rdynamic -nodefaultlibs -undefined_warning -fPIC -Wall")
add_definitions(-DAPL=0 -DIBM=0 -DLIN=1 -DXPLM200=1 -DXPLM210=1 -DXPLM300=1 -DXPLM301=1)
# End
# CMake for Qt
add_executable(qt_xplane_test qt_Xplane_test.cpp)
target_link_libraries(qt_xplane_test Qt5::Widgets)
