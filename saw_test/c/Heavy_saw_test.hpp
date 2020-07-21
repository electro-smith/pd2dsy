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
  static void cMsg_Xt48ACyy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_WASomJRm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xE8YHJV4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Zqii6GdJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vfibZ0lb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_iv4cB8oX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xkgAl96Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zojD5agM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6XtpRCX3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nxDufe1W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TLjDQLCO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RONxVVYV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PMHTGs3Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N9XPVLx1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JEHP4WXh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Xq27aZJT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_poaDyIax_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZabBSl5U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Qoict3ry_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7APDKe2O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_wPqb6wu4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cSd6EWa7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qsfig2wE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Rfl8aaHg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_P0U1aetl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EA5XM2vg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wMMqeXpJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_IThL8BY0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HoqTXjIs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_boGIB95W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DANadOao_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_v2nlynX7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UONIHmga_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6LFyaEU0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ecmCyrtP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3cmN4SAG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_TA76yrUH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_K2wN6rBk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_6rKGKhgP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3aybLxeI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_feI6gS0c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mjAkdJtT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wVFqrF7x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TN154M1l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JFkuWlD8_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_7pydQdp7;
  SignalPhasor sPhasor_ItojUvBZ;
  SignalPhasor sPhasor_wuuT1eFU;
  SignalPhasor sPhasor_uZtl4lDy;
  ControlBinop cBinop_xE8YHJV4;
  ControlBinop cBinop_Zqii6GdJ;
  ControlVar cVar_vfibZ0lb;
  ControlVar cVar_iv4cB8oX;
  ControlVar cVar_xkgAl96Z;
  ControlBinop cBinop_6XtpRCX3;
  ControlVar cVar_PMHTGs3Y;
  ControlBinop cBinop_N9XPVLx1;
  ControlBinop cBinop_JEHP4WXh;
  ControlVar cVar_Qoict3ry;
  ControlBinop cBinop_7APDKe2O;
  ControlBinop cBinop_cSd6EWa7;
  ControlVar cVar_qsfig2wE;
  ControlBinop cBinop_Rfl8aaHg;
  ControlVar cVar_P0U1aetl;
  ControlBinop cBinop_EA5XM2vg;
  ControlVar cVar_wMMqeXpJ;
  ControlVar cVar_IThL8BY0;
  ControlBinop cBinop_HoqTXjIs;
  ControlBinop cBinop_boGIB95W;
  ControlVar cVar_v2nlynX7;
  ControlBinop cBinop_UONIHmga;
  ControlBinop cBinop_6LFyaEU0;
  ControlVar cVar_ecmCyrtP;
  ControlBinop cBinop_3cmN4SAG;
  ControlVar cVar_3aybLxeI;
  ControlVar cVar_feI6gS0c;
  ControlVar cVar_mjAkdJtT;
  ControlVar cVar_wVFqrF7x;
  ControlBinop cBinop_TN154M1l;
};

#endif // _HEAVY_CONTEXT_SAW_TEST_HPP_
