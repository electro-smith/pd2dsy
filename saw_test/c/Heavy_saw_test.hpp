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
  static void cVar_xxWu1sFh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cqYsthS0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0jgbHrqr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_LILiAvWD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gyRIDrHN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_whfBe1tC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UPRx2FrA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ukftJVM0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZiH1cKdF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YF145JmQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9O7tHrRF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_cVlpFzZv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Ep2zfhkX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Pqve8EgC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8klHn8I0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r3NGYuHW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9oedrnvZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JFuTuZHv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_I7YCjCFQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_wW6GX1LZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QCiUwFak_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xhWa3okD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ijCbGNqg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6xdLlMYo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cvwX8F8T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_txrhHBFI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PsvZHxW9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GPYMYrHp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3jLIGZz3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WgP29A4a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_r3GWGrhn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_J6zxJ42A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LFt6m5ax_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lucsumAt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_We35ebGk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kWo9DG6g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2pwhPC37_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OlWKwnj4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xAyjLTGq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qtNgnmGD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BrCj6xFM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wH4MyiAO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6xLs5Guk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_L0peQVXZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AiElEK1d_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_kkRpaPXh;
  SignalPhasor sPhasor_vrROgBEU;
  SignalPhasor sPhasor_44zI63nZ;
  SignalPhasor sPhasor_lbcHEsxT;
  ControlVar cVar_xxWu1sFh;
  ControlBinop cBinop_cqYsthS0;
  ControlBinop cBinop_0jgbHrqr;
  ControlBinop cBinop_gyRIDrHN;
  ControlBinop cBinop_UPRx2FrA;
  ControlBinop cBinop_ukftJVM0;
  ControlVar cVar_ZiH1cKdF;
  ControlVar cVar_YF145JmQ;
  ControlVar cVar_9O7tHrRF;
  ControlVar cVar_Pqve8EgC;
  ControlBinop cBinop_r3NGYuHW;
  ControlBinop cBinop_9oedrnvZ;
  ControlVar cVar_JFuTuZHv;
  ControlBinop cBinop_xhWa3okD;
  ControlVar cVar_6xdLlMYo;
  ControlVar cVar_cvwX8F8T;
  ControlBinop cBinop_PsvZHxW9;
  ControlBinop cBinop_GPYMYrHp;
  ControlVar cVar_3jLIGZz3;
  ControlVar cVar_WgP29A4a;
  ControlVar cVar_r3GWGrhn;
  ControlVar cVar_LFt6m5ax;
  ControlBinop cBinop_lucsumAt;
  ControlVar cVar_kWo9DG6g;
  ControlVar cVar_xAyjLTGq;
  ControlVar cVar_qtNgnmGD;
  ControlBinop cBinop_wH4MyiAO;
  ControlBinop cBinop_6xLs5Guk;
  ControlBinop cBinop_L0peQVXZ;
  ControlBinop cBinop_AiElEK1d;
};

#endif // _HEAVY_CONTEXT_SAW_TEST_HPP_
