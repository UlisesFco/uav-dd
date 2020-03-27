#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/ulisesfco/tesis/uav-dd/gr-transmitter/lib
export PATH=/home/ulisesfco/tesis/uav-dd/gr-transmitter/build/lib:$PATH
export LD_LIBRARY_PATH=/home/ulisesfco/tesis/uav-dd/gr-transmitter/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-transmitter 
