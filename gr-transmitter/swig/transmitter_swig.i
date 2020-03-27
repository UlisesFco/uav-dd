/* -*- c++ -*- */

#define TRANSMITTER_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "transmitter_swig_doc.i"

%{
#include "transmitter/jammer_imp_f.h"
%}


%include "transmitter/jammer_imp_f.h"
GR_SWIG_BLOCK_MAGIC2(transmitter, jammer_imp_f);
