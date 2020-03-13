#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/ulisesfco/tesis/gr-jammer/python
export PATH=/home/ulisesfco/tesis/gr-jammer/build/python:$PATH
export LD_LIBRARY_PATH=/home/ulisesfco/tesis/gr-jammer/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/ulisesfco/tesis/gr-jammer/build/swig:$PYTHONPATH
/usr/bin/python2 /home/ulisesfco/tesis/gr-jammer/python/qa_jammer_sg_f.py 
