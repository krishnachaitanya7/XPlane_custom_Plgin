#!/usr/bin/bash
executable_name="MotionData_Plugin"
XPlane_Directory="/home/shine/X-Plane 11/"
aircraft_folder="Aircraft/Laminar Research/Cessna 172SP/plugins/MotionData/64/"
plugin_name="lin.xpl"
if [[ -f "$XPlane_Directory$aircraft_folder$plugin_name" ]]; then
    rm "$XPlane_Directory$aircraft_folder$plugin_name"
fi
g++ -o "$executable_name" -DAPL=0 -DIBM=0 -DLIN=1 -DXPLM200=1 -DXPLM210=1 -DXPLM300=1 -DXPLM301=1 -shared -rdynamic -nodefaultlibs -undefined_warning -fPIC MotionData.cpp
cp "$executable_name" "$XPlane_Directory$aircraft_folder$plugin_name"