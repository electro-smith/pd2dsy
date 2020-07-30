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

#ifndef _HEAVY_CONTEXT_PATCH_TEST_HPP_
#define _HEAVY_CONTEXT_PATCH_TEST_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvMath.h"
#include "HvControlCast.h"

class Heavy_patch_test : public HeavyContext {

 public:
  Heavy_patch_test(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_patch_test();

  const char *getName() override { return "patch_test"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 4; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        CTRL1 = 0xCFD93C2D, // Ctrl1
        CTRL2 = 0xA6D27094, // Ctrl2
        CTRL3 = 0xB00C3479, // Ctrl3
        CTRL4 = 0x4BA4C205, // Ctrl4
        ENCSWITCH = 0x7AAC371F, // EncSwitch
        ENCODER = 0x39ADE514, // Encoder
        GATE1 = 0x378CB51F, // Gate1
        GATE2 = 0x8924DDEB, // Gate2
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cCast_uho3V9CP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RxKpqRve_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hQ3ZhqHB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_yeNjXpM6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7aKNdaU5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zF2Ofm8L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SVfA0ZfX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_hw9YTas8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uNGYfAQN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CV12aDig_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5ZHCrKcU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TDuOXsxK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rfbDkTuk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ebhKMDgj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MMWIugDF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HNjvad30_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UKOA24X9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_L9B3GgSw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qDH7j9pY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yLeTPvYy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wxLiIvhM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7sgO656y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZLs7GaTK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uL6vjWSG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LOnDOQbm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YrppOtby_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_hdk98Rhy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Oh9rv1K3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_1dDQhlRu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HquEZzAr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wWY8m5p3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TWUDNNZZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gcLMImQY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2znDHSAo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_R4V0daKD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_k0q18juU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_a7gonzzA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qfEzvVbj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pPJ1welq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dVVTxeQt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3cSNyEM6_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_FvnByvc5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jv7i2pti_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_xK8a9Fpp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_a3SPMAeq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YaLfaBTw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JdQMz4ha_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nP5KoDn8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Hn6ruzZA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_myRfbiRk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6eNqAjU1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dRIIaaZt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WchswnAm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NV3B3j3n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_b9nuU7Ty_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ZiTUIw9E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mNwF5T2P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kbdtYmcm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_oMwjoJYW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NSpmEPW4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_6OooFPaz_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_Ghwg65BB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DrOsL6VD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9lI79ZvJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GvHcfRMG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Q5vjDO1h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_25Ri4RuD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1kkqWApm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3YDeZyAU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_iBXiEhQR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KRf5mrr5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_b8HhBfXR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iF6mlFaR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_O0xD68gp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_b2aQ1O78_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NVvc9LaW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uW3sbrIv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2bTVchZy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2LChM3YV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ScsxONUB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_0Jw1B9dH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2qPNI4Pb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_W7oVa5Jk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_r9AlfKt9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_v3milKyQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VulNNN2K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o3wu7zyw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GXpJ9Owy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_oF5uSrwq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_moPAOQac_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BgUEEqBw_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_NlAirE3s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_8CjmNZ3L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SIVbqIFq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_u8BWzeoM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_4mq11bVc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rch6BOyR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FUdegSuV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_iBhFrnba_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_brf8h13d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0aQiw6TK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QzaEOZZ4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PBcUhWX5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5Er5YGyG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kJWX31wm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ylJZBVgk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zNxyRWZ4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fDRksKkL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_REchKEXZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iuveSGbL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9CASj0Aq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_f2ujezbA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZyIWhXqL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GZodvKBH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pk9HvJJS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0oInjZGx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ua5RYh76_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_bSgHBjba_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_YNRwP0ue_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_uVBz4075_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DGOcfmNz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rXYo372Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qZTzltFg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dCczlg2X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Zelzm9FS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_P6MpYACM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Z5OpLfTs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_v8t4TSQu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XvPGPjhJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_9WqJHhqU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_HaDLTkXs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_zV4HuF9Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZlwOYr4F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sz2A1oUG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_fYrmED9Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vuzWUh3Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_URFxzp7z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_79J5jXFl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_jcWkQwBe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_0N0EuXnQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_xoiimDbr;
  ControlBinop cBinop_hQ3ZhqHB;
  SignalVarf sVarf_GKTzrqfo;
  ControlVar cVar_zF2Ofm8L;
  ControlBinop cBinop_TDuOXsxK;
  ControlVar cVar_ebhKMDgj;
  SignalVarf sVarf_YfdbCytH;
  ControlBinop cBinop_MMWIugDF;
  ControlBinop cBinop_UKOA24X9;
  SignalVarf sVarf_ck7WKDGs;
  ControlBinop cBinop_yLeTPvYy;
  ControlBinop cBinop_wxLiIvhM;
  ControlBinop cBinop_7sgO656y;
  ControlBinop cBinop_uL6vjWSG;
  ControlSlice cSlice_YrppOtby;
  ControlSlice cSlice_hdk98Rhy;
  ControlBinop cBinop_1dDQhlRu;
  ControlBinop cBinop_wWY8m5p3;
  ControlVar cVar_2znDHSAo;
  ControlSlice cSlice_R4V0daKD;
  ControlSlice cSlice_k0q18juU;
  ControlBinop cBinop_a7gonzzA;
  ControlVar cVar_qfEzvVbj;
  ControlVar cVar_pPJ1welq;
  ControlBinop cBinop_YaLfaBTw;
  ControlVar cVar_nP5KoDn8;
  ControlVar cVar_Hn6ruzZA;
  ControlBinop cBinop_6eNqAjU1;
  ControlVar cVar_dRIIaaZt;
  ControlBinop cBinop_WchswnAm;
  ControlBinop cBinop_NV3B3j3n;
  ControlBinop cBinop_mNwF5T2P;
  ControlVar cVar_oMwjoJYW;
  ControlDelay cDelay_Ghwg65BB;
  ControlBinop cBinop_DrOsL6VD;
  ControlBinop cBinop_Q5vjDO1h;
  ControlBinop cBinop_NVvc9LaW;
  SignalVarf sVarf_ckAwqnWy;
  SignalVarf sVarf_wpLznvF1;
  ControlBinop cBinop_uW3sbrIv;
  SignalVarf sVarf_iu6gfocd;
  ControlBinop cBinop_2qPNI4Pb;
  ControlBinop cBinop_VulNNN2K;
  ControlBinop cBinop_o3wu7zyw;
  ControlVar cVar_GXpJ9Owy;
  ControlSlice cSlice_oF5uSrwq;
  ControlSlice cSlice_moPAOQac;
  ControlSlice cSlice_NlAirE3s;
  ControlSlice cSlice_8CjmNZ3L;
  ControlVar cVar_FUdegSuV;
  ControlVar cVar_iBhFrnba;
  ControlBinop cBinop_QzaEOZZ4;
  ControlBinop cBinop_kJWX31wm;
  ControlVar cVar_ylJZBVgk;
  ControlVar cVar_zNxyRWZ4;
  ControlBinop cBinop_fDRksKkL;
  ControlBinop cBinop_REchKEXZ;
  ControlBinop cBinop_9CASj0Aq;
  ControlBinop cBinop_f2ujezbA;
  ControlBinop cBinop_ZyIWhXqL;
  ControlVar cVar_DGOcfmNz;
  ControlBinop cBinop_dCczlg2X;
  ControlBinop cBinop_v8t4TSQu;
  ControlVar cVar_XvPGPjhJ;
  ControlBinop cBinop_ZlwOYr4F;
  ControlBinop cBinop_sz2A1oUG;
  ControlDelay cDelay_fYrmED9Y;
};

#endif // _HEAVY_CONTEXT_PATCH_TEST_HPP_
