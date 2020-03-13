#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2020 Ulises Alejandre.
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

from gnuradio import gr, gr_unittest
import math
import pmt
from gnuradio import blocks
import jammer_swig as jammer

class qa_jammer_sg_f (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block()

    def tearDown (self):
        self.tb = None

    def test_jammer_sg_f (self):
        tb = self.tb
        sqrt2 = math.sqrt(2)/2
        exp_res = (1, sqrt2, 0, -sqrt2, -1, -sqrt2, 0, sqrt2, 1)
        src = jammer.jammer_sg_f(8,1,1,0) #1 Hz frequency cosine sampled @ 8 Hz
        op = blocks.head(gr.sizeof_float, 9) #Limits to 9 samples of the input
        dst = blocks.vector_sink_f() #sink for the signal
        tb.connect(src, op) #connect source to head
        tb.connect(op,dst) #connect head to sink
        self.tb.run () #run flowgraph
        # check data
        dst_data = dst.data()
        self.assertFloatTuplesAlmostEqual(exp_res, dst_data, 5)


if __name__ == '__main__':
    gr_unittest.run(qa_jammer_sg_f, "qa_jammer_sg_f.xml")
