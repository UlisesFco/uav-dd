/* -*- c++ -*- */
/*
 * Copyright 2020 Ulises Alejandre.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_JAMMER_JAMMER_SG_F_IMPL_H
#define INCLUDED_JAMMER_JAMMER_SG_F_IMPL_H

#include <jammer/jammer_sg_f.h>
#include <gnuradio/fxpt_nco.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace jammer {

    class jammer_sg_f_impl : public jammer_sg_f
    {
    //Private attributes of the class
     private:
       double d_sample_freq;
       double d_frequency;
       double d_ampl;
       gr::fxpt_nco d_nco;

    //public atributes of the class
     public:
      jammer_sg_f_impl(double sample_freq,
                       double freq,
                       double ampl,
                       float phase = 0);
      ~jammer_sg_f_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);

      //Function declaration
      double sampling_freq() const { return d_sample_freq; }
      double frequency() const { return d_frequency; }
      double amplitude() const { return d_ampl; }
      float phase() const { return d_nco.get_phase(); }

      void set_sampling_freq(double sample_freq);
      void set_frequency_msg(pmt::pmt_t msg);
      void set_frequency(double frequency);
      void set_amplitude(double ampl);
      void set_phase(float phase);

    };

  } // namespace jammer
} // namespace gr

#endif /* INCLUDED_JAMMER_JAMMER_SG_F_IMPL_H */
