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
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvMath.h"
#include "HvControlCast.h"

class Heavy_petal_test : public HeavyContext {

 public:
  Heavy_petal_test(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_petal_test();

  const char *getName() override { return "petal_test"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        ENCSWITCH = 0x7AAC371F, // EncSwitch
        ENCODER = 0x39ADE514, // Encoder
        KNOB1 = 0x62DD3F82, // Knob1
        KNOB2 = 0x6BE4E001, // Knob2
        SWITCH1 = 0xACE00F67, // Switch1
        SWITCH2 = 0x874EC1F2, // Switch2
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cVar_3zcUMp9P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_C6LaSMdc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8cw7PpNP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SJNs2t0f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UwtgU6gI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XpmSvl6I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DkqOmxsC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_UrMAhNIJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1BYYjXJJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LohfnGAu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EN6m3tUR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3Ri9pBz1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BqiBxBsY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QRoDa4gS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FcPSuKmn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0a7wHr8Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qEZSrpu9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_3XBwr8xm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YmpsuvxX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pM33KNfD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_k2e24tnF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VdlhBaIS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NtOxhiOp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6ZlKHlUH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FBGT8sdT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5lXXtMQz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yQcsguUo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VwsgLj21_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sBKsRWRZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_bA7YFKuK_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Q7aojFyj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FKUqkyw6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BtNMO6Ho_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0JKoU8JH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tCHctrwg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gh6oPXPO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cbGtkcsc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_D59FngxH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_TV4KM8oi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Vis0Y4Rd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_3zwOx0ln_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bBuG7erI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UanUq7gK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SL1wh8z3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_b5BWKsaC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_OUz1cXKP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_XzVSrD7t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZY3vKZnm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_o4w03pVt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Q4Ki9W2L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_byox4jc3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_FmIdbrVx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Qh30QpSh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_3MHAsY98_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LUuovmw1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_tZ3oEof9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TurFRjFn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bFUY5oyT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_umWS32to_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TcjulL37_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gTq6bgqZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OLuoQWeE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TVC7JnbH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RLTq7Puz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BeVLwfnb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_o9SumZOD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_inVqVguw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m05D3rOs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0YLUcuTe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vyBIapfG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CSHwZjrz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wWuXYRDR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8emhy72t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Nqvp3C5J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_vcAqeYiz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_6KnmrekP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_W9bPi5Pp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4oD3aeKl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6v6QBrNW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6EXmGtDK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CEBcSc3o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SSMGoKZq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hxgaGDXM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_20M3nxPk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lan5jRom_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DlgsExcB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_15dW2K9P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PLzz8thG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4GPfZ1Xe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9cA2scH7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eOJe2Jc0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jxVSx5K6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WrDukJUd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_a9A0A485_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2YHVq5XG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LykvX4Uc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5OYVuhdA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2LiNGfGQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MyWzF8im_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_kCszs9Rr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yqb689BU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2umSHxTs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RuUQXIhj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_R7Gy1FVW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BRu5uNRx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Xclg7bMa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_XjjNKra6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_j9Majx8X_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_LbCSuzN7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Gyg1zZAl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aDl1kW6a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9EA1mq8r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wJY3CRah_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Yj0i5EHW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3RdwwIc5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Nv3T7nbY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_H2Fd7pHh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_710HHYYX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Wa8RQPNs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BFvKq43R_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_7N3LSOIs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kNfCvu4F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_diR8sBVv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IdYmbulu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_afz25G9G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_CvBDQJUq_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_IufVJXCc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZcrUOTdl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5tehPfLb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_JlPbm1KJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8T6l5grT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sXv57mA9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XW13jcd0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Ergnj9u7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tuZbk1zs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_o6KlbRZ2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oJuj7dxz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_5Q8t6MBu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_TMsKH8Ww_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BORh0s4E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2ODTAxu3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_RZNhau8s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xmQQ0YfY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_osPQurYz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_dd1ym3M5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_atoaIX3x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_1vX2h3Dw_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_kJRW9ADR;
  SignalPhasor sPhasor_T1iF8cLj;
  SignalPhasor sPhasor_iQsxF8Yj;
  ControlVar cVar_3zcUMp9P;
  SignalVarf sVarf_uBBhccwU;
  ControlBinop cBinop_8cw7PpNP;
  ControlBinop cBinop_XpmSvl6I;
  ControlVar cVar_3Ri9pBz1;
  ControlVar cVar_FcPSuKmn;
  ControlBinop cBinop_qEZSrpu9;
  SignalVarf sVarf_1b6i0uCP;
  ControlVar cVar_YmpsuvxX;
  ControlVar cVar_VdlhBaIS;
  ControlBinop cBinop_NtOxhiOp;
  ControlBinop cBinop_5lXXtMQz;
  ControlBinop cBinop_yQcsguUo;
  ControlBinop cBinop_VwsgLj21;
  ControlVar cVar_tCHctrwg;
  ControlVar cVar_gh6oPXPO;
  ControlBinop cBinop_cbGtkcsc;
  ControlSlice cSlice_D59FngxH;
  ControlSlice cSlice_TV4KM8oi;
  ControlVar cVar_ZY3vKZnm;
  ControlBinop cBinop_FmIdbrVx;
  ControlDelay cDelay_3MHAsY98;
  ControlBinop cBinop_LUuovmw1;
  ControlBinop cBinop_bFUY5oyT;
  ControlVar cVar_umWS32to;
  ControlBinop cBinop_TcjulL37;
  ControlBinop cBinop_gTq6bgqZ;
  ControlVar cVar_OLuoQWeE;
  ControlBinop cBinop_BeVLwfnb;
  ControlBinop cBinop_m05D3rOs;
  ControlVar cVar_vyBIapfG;
  ControlBinop cBinop_wWuXYRDR;
  ControlBinop cBinop_8emhy72t;
  ControlSlice cSlice_Nqvp3C5J;
  ControlSlice cSlice_vcAqeYiz;
  ControlBinop cBinop_6v6QBrNW;
  ControlBinop cBinop_6EXmGtDK;
  ControlBinop cBinop_CEBcSc3o;
  ControlVar cVar_20M3nxPk;
  ControlBinop cBinop_9cA2scH7;
  ControlBinop cBinop_eOJe2Jc0;
  ControlVar cVar_WrDukJUd;
  ControlBinop cBinop_a9A0A485;
  ControlBinop cBinop_LykvX4Uc;
  ControlVar cVar_5OYVuhdA;
  ControlVar cVar_MyWzF8im;
  ControlVar cVar_2umSHxTs;
  ControlSlice cSlice_XjjNKra6;
  ControlSlice cSlice_LbCSuzN7;
  ControlVar cVar_aDl1kW6a;
  ControlBinop cBinop_wJY3CRah;
  ControlBinop cBinop_Nv3T7nbY;
  ControlSlice cSlice_H2Fd7pHh;
  ControlSlice cSlice_710HHYYX;
  ControlBinop cBinop_7N3LSOIs;
  ControlBinop cBinop_kNfCvu4F;
  ControlBinop cBinop_IdYmbulu;
  ControlBinop cBinop_afz25G9G;
  ControlDelay cDelay_IufVJXCc;
  ControlBinop cBinop_8T6l5grT;
  ControlVar cVar_sXv57mA9;
  SignalVarf sVarf_211XSfvy;
  ControlVar cVar_Ergnj9u7;
  SignalVarf sVarf_8IZ8sKWo;
  SignalVarf sVarf_rnjq9VIF;
  SignalVarf sVarf_c9Q7q45r;
  ControlBinop cBinop_2ODTAxu3;
  ControlVar cVar_osPQurYz;
  ControlBinop cBinop_atoaIX3x;
};

#endif // _HEAVY_CONTEXT_PETAL_TEST_HPP_
