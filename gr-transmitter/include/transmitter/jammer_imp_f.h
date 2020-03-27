/* -*- c++ -*- */
/*
 * Copyright 2020 <+YOU OR YOUR COMPANY+>.
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


#ifndef INCLUDED_TRANSMITTER_JAMMER_IMP_F_H
#define INCLUDED_TRANSMITTER_JAMMER_IMP_F_H

#include <transmitter/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace transmitter {

    /*!
     * \brief Cosine pulse jammer with float output
     * \ingroup transmitter
     *
     */
    class TRANSMITTER_API jammer_imp_f : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<jammer_imp_f> sptr;

      /*!
       * \brief Build a pulse jammer source block
       * \param sampling_freq Sampling rate of signal.
       * \param freq Frequency of waveform (relative to sampling_freq).
       * \param ampl Signal amplitude.
       * \param phase Initial phase of the signal
       */
      static sptr make(double sample_freq,
                       double freq,
                       double ampl,
                       float phase = 0);

      /*!
      * Sets the sampling frequency of the signal.
      * \param sampling_freq sampling frequency
      */
      virtual double sampling_freq() const = 0;

      /*!
      * Sets the frequency of the cosine signal.
      * \param frequency frequency of the signal
      */
      virtual double frequency() const = 0;
      /*!
      * Sets the amplitude of the signal.
      * \param frequency frequency of the signal
      */
      virtual double amplitude() const = 0;
      /*!
      * Sets the phase of the signal.
      * \param frequency frequency of the signal
      */
      virtual float phase() const = 0;


      virtual void set_sampling_freq(double sample_freq) = 0;
      virtual void set_frequency(double frequency) = 0;
      virtual void set_amplitude(double ampl) = 0;
      virtual void set_phase(float phase) = 0;
    };

  } // namespace transmitter
} // namespace gr

#endif /* INCLUDED_TRANSMITTER_JAMMER_IMP_F_H */
