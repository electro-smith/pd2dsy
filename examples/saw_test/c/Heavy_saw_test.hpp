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
  static void cBinop_EH9ZDhNJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zs4hMrca_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6yE73Vd2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GKm9nTnW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0vXyhss5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RkmX7i0n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2KSdNZtD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CFMrsTZF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nkvYkVBF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7H5ZsgNu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N2rurflL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_itdReb3z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FfUhbYIH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KpIUKV46_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_4vTTtc5b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Uuvj8O2m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GkSyP7Ar_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ri8mNMjT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_586lZvk7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JOJzbDUI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pmeLX6Tj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sHsVYP1C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qyD2TYfn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qnWfCgdk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_uOKDUCaF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Vso6Z7Ph_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sbwp3YrD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_K1bSD6o4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KboKQNDS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GqKgjWSc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vqPqd4D7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_J2JalUZM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cD8ri6My_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ufjtbWNJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0RWBMp7L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dpuwuY82_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KmTGopGv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Ujv2caHY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pFfvUCCa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FmztyTsT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2LkXNtfq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_HMWHKYgR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_aKu0lwvR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6QPS1icc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_envHjUCW_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_h1WYETLz;
  SignalPhasor sPhasor_KcIdCbV7;
  SignalPhasor sPhasor_U8EOwrDU;
  SignalPhasor sPhasor_Ew253r4b;
  ControlBinop cBinop_EH9ZDhNJ;
  ControlBinop cBinop_zs4hMrca;
  ControlVar cVar_6yE73Vd2;
  ControlVar cVar_RkmX7i0n;
  ControlBinop cBinop_CFMrsTZF;
  ControlBinop cBinop_nkvYkVBF;
  ControlBinop cBinop_7H5ZsgNu;
  ControlBinop cBinop_N2rurflL;
  ControlVar cVar_itdReb3z;
  ControlVar cVar_FfUhbYIH;
  ControlVar cVar_GkSyP7Ar;
  ControlVar cVar_ri8mNMjT;
  ControlBinop cBinop_586lZvk7;
  ControlVar cVar_JOJzbDUI;
  ControlVar cVar_sHsVYP1C;
  ControlBinop cBinop_qyD2TYfn;
  ControlVar cVar_qnWfCgdk;
  ControlBinop cBinop_sbwp3YrD;
  ControlBinop cBinop_K1bSD6o4;
  ControlVar cVar_GqKgjWSc;
  ControlVar cVar_vqPqd4D7;
  ControlBinop cBinop_J2JalUZM;
  ControlBinop cBinop_ufjtbWNJ;
  ControlVar cVar_dpuwuY82;
  ControlBinop cBinop_KmTGopGv;
  ControlVar cVar_Ujv2caHY;
  ControlBinop cBinop_pFfvUCCa;
  ControlVar cVar_FmztyTsT;
  ControlVar cVar_2LkXNtfq;
  ControlBinop cBinop_6QPS1icc;
};

#endif // _HEAVY_CONTEXT_SAW_TEST_HPP_
