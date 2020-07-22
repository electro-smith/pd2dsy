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
  static void cReceive_ecO6Thbx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qW36TTGw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ao5QcudY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_EtkH80S3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IvluaUxQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XlznFXMM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yTjBc8RE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JzdoKOpn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xihbtbEf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pNEK2Mp9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Qvo1Utuk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kY97KDo5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_riwILOxI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VAPaOfdv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DncrkuJc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bk1Cfh5y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Pt9TNQeH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QHB6f4DO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aTHd4T6B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_pqsX9VJQ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_EGWJ7SdB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MI97R7on_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MIM4oOCl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_12e0NHBV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_koJl0CJP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yG1JPnRH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7Qj81LrL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4IyL0Qpa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UHvLIxsk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_H404yBxl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_uAtkPCgr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_t6tVxfWL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ASvqQNWq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_eQsXyCSH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_ApxgtkMB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ImEhCRG5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_zto46NGN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QQKWVMow_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_R1xuFzO6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pih5f5gR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ktMFNFbk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DsOIpXp0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OKOh6i3B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nkBQham4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JM4eyQQT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Mr9JRdyz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_MK1OEsvd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_e3olvLCz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_tFgTAO32_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FW9LkdmC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GOFtVCJ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_g6OPadHT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_n2HUICoV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PADxVlRt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_v9YDu9ys_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_g5WtZ7O9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Rsr616IT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bNqSBW4r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AqZcBxyI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ydxjP47j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RCxnDVTP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Hz6sMWzO_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_XbIrC0PK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DbADAkQj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eTbl8M4J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Rfov34yy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JPqYR2I2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AazeDKr1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_OXfsS0IO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mr5eKsMY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NN7STKmz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7K1yj4xR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_L6aR9oEa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_M82t9twm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_8PZUmR6d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HzSevzIE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8kBR6vGI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IQLkhYqB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_oRLZRRvN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_v4Hp9zfA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZUkN3CYJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZZ9n7Pwn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KE4FUbDW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_b4eJzqhW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wRWBcIRC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pbXUReD9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BOyBNdm6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_c0F7oRmY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_IPCMtSMY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_a4tOXH6F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_W76TBtSZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TDj0PYxm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mfSmdAaM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_phhPOqaX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wB435jCr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_lKwtC2jU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_ukwbHGte_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ss93tudW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZBjIb8lY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_R8N53kPP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_RfaRNGBS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Eqb7ZWgy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uKMckuuQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_xYLoOeDl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_5elNEYpt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iPzycmet_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bMgaP3Cz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YdlE1qjl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rcp1lKOM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_TDUVunop_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_uJ0KFkoV_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_cptYcvku_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ui3yeRHh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_K2qDzpJw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZS6Ri5DL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JyL4fGKw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_L3sNHohT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_knFQfcaf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Md6vKbqn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Unv3tfiR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RHCrK3wO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LMmWUo2p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0OkAzMj1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b6zsjdeV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4nzdhST2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MieWf5s0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AkxUfLdD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TyuqAB1v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_v7VohJMm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_paUVPyIK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_qi9tXwAd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nz11cKso_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_g5mr6KHV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_n9rueLJH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wdRMdsEE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_AtzGKrm9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_vVFgewMQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mwwTtF5p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_WZLSm9P3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_NhgUPk60_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_w2IxTRMi;
  SignalVarf sVarf_gmkGciTn;
  SignalVarf sVarf_KuurJuLz;
  ControlBinop cBinop_IvluaUxQ;
  ControlBinop cBinop_yTjBc8RE;
  ControlBinop cBinop_JzdoKOpn;
  SignalVarf sVarf_QzQbrImy;
  SignalVarf sVarf_9obsaijU;
  ControlBinop cBinop_Qvo1Utuk;
  ControlBinop cBinop_VAPaOfdv;
  ControlBinop cBinop_DncrkuJc;
  ControlBinop cBinop_Pt9TNQeH;
  ControlVar cVar_MI97R7on;
  ControlBinop cBinop_yG1JPnRH;
  ControlVar cVar_7Qj81LrL;
  ControlBinop cBinop_4IyL0Qpa;
  ControlVar cVar_H404yBxl;
  ControlVar cVar_uAtkPCgr;
  ControlSlice cSlice_t6tVxfWL;
  ControlSlice cSlice_ASvqQNWq;
  ControlVar cVar_ImEhCRG5;
  ControlSlice cSlice_zto46NGN;
  ControlSlice cSlice_QQKWVMow;
  ControlBinop cBinop_ktMFNFbk;
  ControlBinop cBinop_OKOh6i3B;
  ControlVar cVar_nkBQham4;
  ControlBinop cBinop_e3olvLCz;
  ControlDelay cDelay_tFgTAO32;
  ControlVar cVar_GOFtVCJ5;
  ControlBinop cBinop_n2HUICoV;
  ControlBinop cBinop_Rsr616IT;
  ControlBinop cBinop_bNqSBW4r;
  ControlBinop cBinop_DbADAkQj;
  ControlBinop cBinop_eTbl8M4J;
  SignalVarf sVarf_ltMxBcyw;
  SignalVarf sVarf_nwYGEdhT;
  ControlBinop cBinop_mr5eKsMY;
  ControlVar cVar_NN7STKmz;
  ControlVar cVar_L6aR9oEa;
  ControlBinop cBinop_ZUkN3CYJ;
  ControlBinop cBinop_KE4FUbDW;
  ControlVar cVar_BOyBNdm6;
  ControlVar cVar_IPCMtSMY;
  ControlBinop cBinop_W76TBtSZ;
  ControlBinop cBinop_mfSmdAaM;
  ControlBinop cBinop_phhPOqaX;
  ControlSlice cSlice_xYLoOeDl;
  ControlSlice cSlice_5elNEYpt;
  ControlBinop cBinop_bMgaP3Cz;
  ControlBinop cBinop_rcp1lKOM;
  ControlDelay cDelay_TDUVunop;
  ControlVar cVar_cptYcvku;
  ControlBinop cBinop_Ui3yeRHh;
  ControlBinop cBinop_JyL4fGKw;
  ControlBinop cBinop_Unv3tfiR;
  ControlBinop cBinop_RHCrK3wO;
  ControlVar cVar_LMmWUo2p;
  ControlBinop cBinop_b6zsjdeV;
  ControlBinop cBinop_4nzdhST2;
  ControlBinop cBinop_MieWf5s0;
  ControlBinop cBinop_TyuqAB1v;
  ControlVar cVar_g5mr6KHV;
  ControlBinop cBinop_n9rueLJH;
  ControlVar cVar_wdRMdsEE;
  ControlVar cVar_AtzGKrm9;
  ControlSlice cSlice_vVFgewMQ;
  ControlSlice cSlice_mwwTtF5p;
};

#endif // _HEAVY_CONTEXT_PATCH_TEST_HPP_
