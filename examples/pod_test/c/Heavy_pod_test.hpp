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

#ifndef _HEAVY_CONTEXT_POD_TEST_HPP_
#define _HEAVY_CONTEXT_POD_TEST_HPP_

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

class Heavy_pod_test : public HeavyContext {

 public:
  Heavy_pod_test(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_pod_test();

  const char *getName() override { return "pod_test"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        BUTTON1 = 0xB4D78F23, // Button1
        BUTTON2 = 0x3FE62CA, // Button2
        ENCSWITCH = 0x7AAC371F, // EncSwitch
        ENCODER = 0x39ADE514, // Encoder
        KNOB1 = 0x62DD3F82, // Knob1
        KNOB2 = 0x6BE4E001, // Knob2
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cMsg_I6uCvYyv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QOH6SZrX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7Pt012Ej_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tM4U8LeP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JIQnpzcf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JkzowGNZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_F4cbR7XO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vb4nFUEY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VColkwpl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UIaemIve_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sQgLHNMw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gZy5LVqj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_DJjKIdIH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_T8fk0TLZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_F1Jqlucp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hvJiH4X3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_otsTdnkK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_iWHIbAfh_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_Ivt7YxUT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cj7tIXzh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_11Ss6wgO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4GSm4TwD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UJg5QB6J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_O8LkqKpE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kdDqOMJs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fZBwObfP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_c8w7TCPc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oMmKZM2Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_hS66HgLU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ImXa6IAB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CtarF4kx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_E2KyHijx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UY10uftc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TnVDuIEf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_hvDm2U2n_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_0fspoYl7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QD4SagUH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yGVXuYgI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_j3ERctA2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QPZiPLHE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fuZPYYf5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0ZVvUtBs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yIaGNSeJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1FoONory_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DcSol7tq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Q9MmKgog_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nagHa2jU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_L8Ey55RT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dNGI4LkC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_65qSzppH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_zefvb2RY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BONB2k4R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aRiqpcZJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ygdTN1yz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_a3kPI9Ec_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_0CoKXmii_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dOrHROZY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0BlJCFJb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NqoMlBiE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uD51uQQ9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FKz82hma_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3JkPZFNP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_N0aZKno5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ig4tndb5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_3NJ3KwLG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tLlhqjqv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1vz6RtCG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qSBs09bZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NaXOJabF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Q1rtwqPw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OgwL9CKL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_C0Wf33Z2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_emQzHRDI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_L0eX3Pbr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bozI8STt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sNwcAzVa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_P8ou1P7x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YNAQjn1v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6dlerQ5a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fT8Jyo8A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ivCX9UTa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FfgJSgyU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kyxwxPBi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6XdR6i9Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ctgMPm08_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CVpTKW0h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_lySJWDdX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_cecB7InQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_it2VggLD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hkD5vNs6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TUO6pajd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SDiA0vUV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KgdjuH90_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_RaeASMAk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_un9VnXpe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LZB0Iegy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mSWAphR1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R8RSECM5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UGHMuSSh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_bq6FpnPC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_5QA9bKls_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Y1Zo8ySr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7H6oHGWw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WlEoeWLh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_88HdXiLE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i21j2CsJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3GZCpHAJ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_D2utCPpk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_7LkybTvC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_srNmHn66_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LESkMzGR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jQk659tD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6LN21lIE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tZuAfoRV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZbPvdcnt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9vrQM6zn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Rz51TSGo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_J6nW3pHm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_tnds6xv2_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Y1Wv1m36_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_N1bSU1gx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ynP4bm4d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o5rSQoOX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fz2NJJTG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r9oPGWBH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kf4gLFdd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vezaZErs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_axD9ceCb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fmuAwaDS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cH8RfBuP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IPjqHwyG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wNLRohPn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Ew7jMUOR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eVg8Q7Hm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_XOV7D5AH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_WIrjvcSM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jSgHfZgc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NgAkv28m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_U6mzhDVq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QjOCfNL6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yBpGm6wF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_erCEyoyp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_VVq4mTl9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_i9Zsp3Ov_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qyLjctDU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_TCbNTL8m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tNCKgn5m_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_az3ZC2ou;
  SignalPhasor sPhasor_M8I1v7RF;
  SignalPhasor sPhasor_w1yso8ek;
  ControlVar cVar_QOH6SZrX;
  ControlBinop cBinop_7Pt012Ej;
  SignalVarf sVarf_76SxjIU2;
  SignalVarf sVarf_utAO2pys;
  ControlVar cVar_VColkwpl;
  ControlBinop cBinop_gZy5LVqj;
  ControlVar cVar_T8fk0TLZ;
  ControlSlice cSlice_otsTdnkK;
  ControlSlice cSlice_Ivt7YxUT;
  ControlBinop cBinop_O8LkqKpE;
  ControlBinop cBinop_kdDqOMJs;
  ControlBinop cBinop_c8w7TCPc;
  ControlVar cVar_CtarF4kx;
  ControlVar cVar_0fspoYl7;
  ControlBinop cBinop_QPZiPLHE;
  ControlBinop cBinop_fuZPYYf5;
  ControlBinop cBinop_0ZVvUtBs;
  ControlBinop cBinop_1FoONory;
  ControlBinop cBinop_DcSol7tq;
  ControlVar cVar_Q9MmKgog;
  ControlVar cVar_nagHa2jU;
  ControlVar cVar_L8Ey55RT;
  ControlVar cVar_65qSzppH;
  ControlSlice cSlice_zefvb2RY;
  ControlSlice cSlice_BONB2k4R;
  ControlBinop cBinop_aRiqpcZJ;
  ControlDelay cDelay_0CoKXmii;
  ControlBinop cBinop_dOrHROZY;
  ControlVar cVar_NqoMlBiE;
  ControlBinop cBinop_uD51uQQ9;
  ControlBinop cBinop_FKz82hma;
  ControlBinop cBinop_1vz6RtCG;
  ControlBinop cBinop_qSBs09bZ;
  ControlVar cVar_OgwL9CKL;
  ControlVar cVar_L0eX3Pbr;
  ControlBinop cBinop_bozI8STt;
  SignalVarf sVarf_lbbuLk67;
  ControlBinop cBinop_P8ou1P7x;
  ControlVar cVar_fT8Jyo8A;
  ControlBinop cBinop_CVpTKW0h;
  ControlBinop cBinop_it2VggLD;
  ControlBinop cBinop_SDiA0vUV;
  ControlBinop cBinop_KgdjuH90;
  ControlVar cVar_LZB0Iegy;
  ControlBinop cBinop_R8RSECM5;
  ControlDelay cDelay_5QA9bKls;
  ControlBinop cBinop_WlEoeWLh;
  ControlBinop cBinop_i21j2CsJ;
  ControlSlice cSlice_D2utCPpk;
  ControlSlice cSlice_7LkybTvC;
  ControlVar cVar_srNmHn66;
  ControlVar cVar_LESkMzGR;
  ControlVar cVar_jQk659tD;
  ControlBinop cBinop_6LN21lIE;
  ControlBinop cBinop_tZuAfoRV;
  ControlVar cVar_ZbPvdcnt;
  ControlBinop cBinop_9vrQM6zn;
  ControlBinop cBinop_o5rSQoOX;
  ControlBinop cBinop_r9oPGWBH;
  ControlBinop cBinop_kf4gLFdd;
  ControlBinop cBinop_IPjqHwyG;
  ControlVar cVar_Ew7jMUOR;
  ControlBinop cBinop_jSgHfZgc;
  ControlVar cVar_NgAkv28m;
  ControlSlice cSlice_U6mzhDVq;
  ControlSlice cSlice_QjOCfNL6;
  SignalVarf sVarf_aEe30O2T;
  SignalVarf sVarf_Mx6qCCAn;
  SignalVarf sVarf_cVQzJtij;
};

#endif // _HEAVY_CONTEXT_POD_TEST_HPP_
