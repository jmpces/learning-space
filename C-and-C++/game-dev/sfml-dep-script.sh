#!/usr/bin/bash

# Install CMake GUI
sudo apt-get install cmake-gui

# SFML Dependencies
sudo apt-get install libpthread-stubs0-dev
sudo apt-get install libgl1-mesa-dev
sudo apt-get install libx11-dev
sudo apt-get install libxrandr-dev
sudo apt-get install libxcb-image0-dev
sudo apt-get install libfreetype6-dev
sudo apt-get install libglew1.5-dev
sudo apt-get install libjpeg-dev
sudo apt-get install libjpeg8-dev
sudo apt-get install libsndfile1-dev
sudo apt-get install libopenal-dev
sudo apt-get install libvorbis-dev
sudo apt-get install libflac-dev
sudo apt install libxcursor-dev

# Joystick
sudo apt-get install libudev-dev

# -----------------------------------
# check if they are already installed
# -----------------------------------

# dpkg --list '*package-name*'

sudo apt-get install libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libxcb-image0-dev libfreetype6-dev libglew1.5-dev libjpeg-dev libjpeg8-dev libsndfile1-dev libopenal-dev libvorbis-dev libflac-dev libxcursor-dev libudev-dev

