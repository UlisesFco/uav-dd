#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/ulisesfco/tesis/gr-jammer/lib
export PATH=/home/ulisesfco/tesis/gr-jammer/build/lib:$PATH
export LD_LIBRARY_PATH=/home/ulisesfco/tesis/gr-jammer/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-jammer 
