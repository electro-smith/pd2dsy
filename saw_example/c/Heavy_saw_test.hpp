/**
 * Copyright (c) 2020 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_SAW_TEST_HPP_
#define _HEAVY_CONTEXT_SAW_TEST_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"
#include "HvControlCast.h"

class Heavy_saw_test : public HeavyContext {

 public:
  Heavy_saw_test(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_saw_test();

  const char *getName() override { return "saw_test"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        CHANNELA = 0x7BCBAF78, // ChannelA
        CHANNELB = 0x4A38F401, // ChannelB
        CHANNELC = 0x50D8682A, // ChannelC
        CHANNELD = 0xC09FC6FC, // ChannelD
        CHANNELE = 0xBAD7D492, // ChannelE
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cBinop_5zTHL2D6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_F7fxJ0iq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zWYYKpON_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ycZyv3E7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FD6t5B1N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_TwKWkurM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kjRCzRTY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qKs4tfrn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1bIBqJyq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rt0o5x3l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gCDSGplt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0JqBhlBS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rEyWJIKW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sBhbo45C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tvMr0lXr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OHQfjsH6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R1KSZFGB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4o5ECeDk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PlioLfJB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vt7TDp7W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wQK6Duvj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bh5vTtFy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9Oml17LX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xnYgRzbF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0t4Vj0fU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_nNU6qng2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Svxb6wJn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_QMbkzw94_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_YmnhTTOa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_R6fvDPF5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rQb47qp3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_DS4X3zX1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_V6wyYb7a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QRBDHx2W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_t7jv092g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qQmCZGxS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_le1BfLj7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3hAAlPrP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eRhWmcS4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2Fr5OYsC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_x6gQhH88_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_srjTawl5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_efwLfj9G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hCjNtkPM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_t6Qw1OoG_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_XbFWnjal;
  SignalPhasor sPhasor_wKOUDAof;
  SignalPhasor sPhasor_8Cht3vET;
  SignalPhasor sPhasor_HbhefDY5;
  ControlBinop cBinop_5zTHL2D6;
  ControlVar cVar_F7fxJ0iq;
  ControlBinop cBinop_ycZyv3E7;
  ControlVar cVar_FD6t5B1N;
  ControlVar cVar_kjRCzRTY;
  ControlBinop cBinop_1bIBqJyq;
  ControlBinop cBinop_rt0o5x3l;
  ControlBinop cBinop_gCDSGplt;
  ControlVar cVar_0JqBhlBS;
  ControlBinop cBinop_rEyWJIKW;
  ControlBinop cBinop_tvMr0lXr;
  ControlVar cVar_OHQfjsH6;
  ControlBinop cBinop_R1KSZFGB;
  ControlVar cVar_4o5ECeDk;
  ControlBinop cBinop_PlioLfJB;
  ControlVar cVar_vt7TDp7W;
  ControlVar cVar_wQK6Duvj;
  ControlBinop cBinop_9Oml17LX;
  ControlVar cVar_0t4Vj0fU;
  ControlBinop cBinop_Svxb6wJn;
  ControlBinop cBinop_rQb47qp3;
  ControlVar cVar_QRBDHx2W;
  ControlBinop cBinop_qQmCZGxS;
  ControlBinop cBinop_le1BfLj7;
  ControlVar cVar_3hAAlPrP;
  ControlVar cVar_eRhWmcS4;
  ControlBinop cBinop_2Fr5OYsC;
  ControlVar cVar_efwLfj9G;
  ControlVar cVar_hCjNtkPM;
  ControlVar cVar_t6Qw1OoG;
};

#endif // _HEAVY_CONTEXT_SAW_TEST_HPP_
