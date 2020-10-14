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

#ifndef _HEAVY_CONTEXT_PETAL_TEST_HPP_
#define _HEAVY_CONTEXT_PETAL_TEST_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalTabwrite.h"
#include "HvTable.h"
#include "HvSignalLine.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvSignalVar.h"
#include "HvControlDelay.h"
#include "HvMath.h"
#include "HvControlPack.h"
#include "HvSignalTabread.h"
#include "HvControlCast.h"

class Heavy_petal_test : public HeavyContext {

 public:
  Heavy_petal_test(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_petal_test();

  const char *getName() override { return "petal_test"; }
  int getNumInputChannels() override { return 2; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        KNOB3 = 0x4D9F260A, // Knob3
        KNOB4 = 0xDB6872A1, // Knob4
        KNOB5 = 0x5C0E4419, // Knob5
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cCast_Y6EeZwE7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rhSMPOv3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_mzsYMcu4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IVnXQHa8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_J6GOm3mh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_1P0jWXcK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_uCxOuGEe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_1x0Bl66S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4saOlz15_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_v7OQflfv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wi1nT0o2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ewb1jCuo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bdFqpAgN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GynmzqDS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WgvfVDpm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sGwopm9u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cQMixQ9p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9OK41fUy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_7cvQjdPW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_L9DNMork_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Uj4eixEa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5kaHPYhR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Q08rTTUn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5uPSViCx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UalFQZgp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_q9p1bE6w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_p1Y1F9Az_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_gUhuo2Qm_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_htWIdGll;
  SignalTabhead sTabhead_beYfjtA7;
  SignalTabread sTabread_Vv35pd4X;
  SignalTabread sTabread_wvptcjyp;
  SignalTabwrite sTabwrite_wmgd5jvg;
  ControlBinop cBinop_rhSMPOv3;
  ControlBinop cBinop_IVnXQHa8;
  SignalVarf sVarf_ZpCuQgwC;
  ControlPack cPack_1x0Bl66S;
  ControlBinop cBinop_4saOlz15;
  SignalVarf sVarf_wIdXD2A5;
  SignalVarf sVarf_sSEI5SE2;
  SignalVarf sVarf_Nxr8gYAi;
  ControlBinop cBinop_bdFqpAgN;
  SignalVarf sVarf_3wR8pllz;
  ControlBinop cBinop_WgvfVDpm;
  ControlVar cVar_sGwopm9u;
  SignalVarf sVarf_dIF5CQlZ;
  HvTable hTable_7cvQjdPW;
  ControlBinop cBinop_UalFQZgp;
  ControlBinop cBinop_q9p1bE6w;
  ControlDelay cDelay_p1Y1F9Az;
  ControlDelay cDelay_gUhuo2Qm;
  SignalVarf sVarf_yLiwD5Qw;
};

#endif // _HEAVY_CONTEXT_PETAL_TEST_HPP_
