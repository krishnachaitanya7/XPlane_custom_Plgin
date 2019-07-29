#!/usr/bin/bash
executable_name="cmake-build-debug/Qt_Plugin/qt_xplane_test"
XPlane_Directory="/home/shine/X-Plane 11/"
aircraft_folder="Aircraft/Laminar Research/Cessna 172SP/plugins/qt_xplane_test/64/"
plugin_name="lin.xpl"
cd "/home/shine/CLionProjects/XPlane_custom_Plgin"
if [[ -f "$XPlane_Directory$aircraft_folder$plugin_name" ]]; then
    rm "$XPlane_Directory$aircraft_folder$plugin_name"
fi
cp "$executable_name" "$XPlane_Directory$aircraft_folder$plugin_name"