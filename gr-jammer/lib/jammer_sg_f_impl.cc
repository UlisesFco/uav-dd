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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "jammer_sg_f_impl.h"
#include <gnuradio/math.h>

#include <algorithm>
#include <stdexcept>

#define GR_M_PI 3.14159265358979323846    // pi value definition


namespace gr {
  namespace jammer {

    jammer_sg_f::sptr
    jammer_sg_f::make(double sample_freq, double freq, double ampl, float phase)
    {
      return gnuradio::get_initial_sptr
        (new jammer_sg_f_impl(sample_freq, freq, ampl, phase));
    }

    /*
     * The private constructor
     */
    jammer_sg_f_impl::jammer_sg_f_impl(double sample_freq, double freq, double ampl, float phase)
      : gr::sync_block("jammer_sg_f",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, 1, sizeof(float))),
              d_sample_freq(sample_freq),
              d_frequency(freq),
              d_ampl(ampl)
    {
      this->set_frequency(freq);
      this->set_phase(phase);
      this->message_port_register_in(pmt::mp("freq"));
      this->set_msg_handler(pmt::mp("freq"),
                            boost::bind(&jammer_sg_f_impl::set_frequency_msg, this, _1));
    }

    /*
     * Our virtual destructor.
     */
    jammer_sg_f_impl::~jammer_sg_f_impl()
    {
    }

    void jammer_sg_f_impl::set_frequency_msg(pmt::pmt_t msg)
    {
      // Accepts either a number that is assumed to be the new
      // frequency or a key:value pair message where the key must be
      // "freq" and the value is the new frequency.

      if (pmt::is_number(msg)) {
          set_frequency(pmt::to_double(msg));
      } else if (pmt::is_pair(msg)) {
          pmt::pmt_t key = pmt::car(msg)  ;
          pmt::pmt_t val = pmt::cdr(msg);
          if (pmt::eq(key, pmt::intern("freq"))) {
              if (pmt::is_number(val)) {
                  set_frequency(pmt::to_double(val));
              }
          } else {
              GR_LOG_WARN(this->d_logger,
                          boost::format("Set Frequency Message must have "
                                        "the key = 'freq'; got '%1%'.") %
                              pmt::write_string(key));
          }
      } else {
          GR_LOG_WARN(this->d_logger,
                      "Set Frequency Message must be either a number or a "
                      "key:value pair where the key is 'freq'.");
       }
    }

    int
    jammer_sg_f_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      float *out = (float *) output_items[0];
      gr::thread::scoped_lock l(this->d_setlock);
      d_nco.cos(out, noutput_items, d_ampl);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

    void jammer_sg_f_impl::set_sampling_freq(double sampling_freq)
    {
        d_sample_freq = sampling_freq;
        d_nco.set_freq(2 * GR_M_PI * this->d_frequency / this->d_sample_freq);
    }

    void jammer_sg_f_impl::set_frequency(double frequency)
    {
        d_frequency = frequency;
        d_nco.set_freq(2 * GR_M_PI * this->d_frequency / this->d_sample_freq);
    }

    void jammer_sg_f_impl::set_amplitude(double ampl)
    {
      d_ampl = ampl;
    }

    void jammer_sg_f_impl::set_phase(float phase)
    {
      gr::thread::scoped_lock l(this->d_setlock);
      d_nco.set_phase(phase);
    }

  } /* namespace jammer */
} /* namespace gr */
