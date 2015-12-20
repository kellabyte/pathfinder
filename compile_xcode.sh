#!/bin/bash

rm -rf build
mkdir -p build
cd build
cmake -DCMAKE_OSX_ARCHITECTURES=x86_64 -G Xcode ..
xcodebuild -project pathfinder.xcodeproj/
