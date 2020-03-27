#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/ulisesfco/tesis/uav-dd/gr-transmitter/python
export PATH=/home/ulisesfco/tesis/uav-dd/gr-transmitter/build/python:$PATH
export LD_LIBRARY_PATH=/home/ulisesfco/tesis/uav-dd/gr-transmitter/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/ulisesfco/tesis/uav-dd/gr-transmitter/build/swig:$PYTHONPATH
/usr/bin/python2 /home/ulisesfco/tesis/uav-dd/gr-transmitter/python/qa_jammer_imp_f.py 
