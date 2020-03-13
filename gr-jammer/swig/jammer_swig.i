/* -*- c++ -*- */

#define JAMMER_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "jammer_swig_doc.i"

%{
#include "jammer/jammer_sg_f.h"
%}


%include "jammer/jammer_sg_f.h"
GR_SWIG_BLOCK_MAGIC2(jammer, jammer_sg_f);
