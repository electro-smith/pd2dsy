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
  static void cCast_RpM5Qsyf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4D4jrsA1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YvNTnEAL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RPtTJuqq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8Y77cuwY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KFoEQqMq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BeVkoRAz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qwjzH0iZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vohlwG6o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iHdnWZQl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_luUCOXxj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZkzFvp6q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NT78l8Yp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_G6mUt74J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hceupIyy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_o1siqQfp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WpHZyJQq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_278zstdC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2FmjJiWI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_SW8hY3Ej_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_a8jy5g6u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_TWGvagTB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ghJBZRPU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fO7cSD6R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_acrrPSbH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M2uQmzR3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PDBritj1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yW3KoNQp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_K1gn6rHV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EeqZ7ldR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R0YRd6RI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_F3ESh9Ct_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_3EroFvIO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hiGLqQbS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eAMZFCJS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CXbzvy6A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DPBJf7H4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xnuuZH90_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6FDjzcSd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DMsK7TkR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_n7un8OJb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_by50kWOM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_REMRJkd3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JNehnxNL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_s5JAxyg5_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_47j9PTdn;
  SignalPhasor sPhasor_IChTPP6p;
  SignalPhasor sPhasor_jfzYQQZH;
  SignalPhasor sPhasor_cNhd2S3d;
  ControlBinop cBinop_4D4jrsA1;
  ControlBinop cBinop_YvNTnEAL;
  ControlBinop cBinop_RPtTJuqq;
  ControlVar cVar_8Y77cuwY;
  ControlBinop cBinop_KFoEQqMq;
  ControlBinop cBinop_BeVkoRAz;
  ControlVar cVar_ZkzFvp6q;
  ControlBinop cBinop_NT78l8Yp;
  ControlVar cVar_G6mUt74J;
  ControlVar cVar_278zstdC;
  ControlVar cVar_SW8hY3Ej;
  ControlVar cVar_a8jy5g6u;
  ControlBinop cBinop_ghJBZRPU;
  ControlBinop cBinop_fO7cSD6R;
  ControlBinop cBinop_acrrPSbH;
  ControlBinop cBinop_M2uQmzR3;
  ControlVar cVar_PDBritj1;
  ControlBinop cBinop_yW3KoNQp;
  ControlVar cVar_K1gn6rHV;
  ControlBinop cBinop_R0YRd6RI;
  ControlVar cVar_F3ESh9Ct;
  ControlVar cVar_hiGLqQbS;
  ControlVar cVar_eAMZFCJS;
  ControlBinop cBinop_CXbzvy6A;
  ControlBinop cBinop_xnuuZH90;
  ControlBinop cBinop_6FDjzcSd;
  ControlVar cVar_DMsK7TkR;
  ControlVar cVar_by50kWOM;
  ControlVar cVar_REMRJkd3;
  ControlVar cVar_s5JAxyg5;
};

#endif // _HEAVY_CONTEXT_SAW_TEST_HPP_
