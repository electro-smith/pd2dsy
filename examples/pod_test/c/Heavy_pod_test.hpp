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
  static void cMsg_vqhuLWeM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_skQKHM05_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_g5uIdh5q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gaTQOTQu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JniK7oeu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UF44XRmb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sTwG1uSM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2mJACYJ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nTU7lceK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_D5Src07m_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Wt0Ev5N9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CWL61kQe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_2EdV7FvT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VFnQ82NR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uLoOOS1A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_va0OES1P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_pMR5ZFyY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rlJ8R5WK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GhzYUbMQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jrKiXdpd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ig9Gn2xe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YP5gcZ5z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_T8WB3mwq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_brflxUZx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xYVh4zE4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3QANWZzU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_K2tdlERv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xFWEYPlB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HKuKWU0W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WRBFzhKO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_yMPRZjV6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_WBh0Fnjn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_WPhOL2VH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Z525OfWg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_gIMdeLWV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dexYfRg8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_56v6NlEr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3HvXekhb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6PFw9JwV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_o4h9LZQv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WrC33QJC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UqVNezBb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Rxdo0Rvn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TSVCYxud_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YWC33Qeo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vg2mWKki_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_btRpFgSI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZOvzunf4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MMS5h5MP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5RBSmIie_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_PKc6eaCr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_p452rArI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_Xo61ue9L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0xfLzPuU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aZdVJqnC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8ot6EGeD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_t79l9YwU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_onB0nwdp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_c3XFLwHU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0XxL7ReE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ivgeaPNW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_TGEJGkja_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_85FRrGDr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Dw8P11WH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_iWCtfb8b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xd9EJk0N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IR7O2Ryc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HGLPbIbx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_A9pVvtFq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5K8MluVN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UyMpEJJG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_78b87hrf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5lZeFxG8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Xi8elKNI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Gc0e1gts_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9Yi8LR1A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_rg3JoWPd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_H8MTpFLu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_U4WX4zII_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VwG8X0s8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uyxKNNg3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N7DfrbV7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m07SQ4EM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QlJecbHD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_f5TEc7tN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_j6wvQCsU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HqOV9Nig_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3tA9EflQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_E27vuc8H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WNdeunlT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0wWweOVy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QhanG4Ur_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_yCMOQV6O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FzuRZLmt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_BnjWY7qt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8DRnyySH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MxaL6ctg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_exmXmCeN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fQAlSgHd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_YBioI0MV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oA9COVXI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hw96Iqho_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_8PSuGcQG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_32oLhR5N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vwcxfBWL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_i4XglkmO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ony2VgxB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Nxhj00OU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6iCxFvqL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_FqkVS0yU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_09Ethe8F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HQcWTSQP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1nF1Ba5k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kKCbuLTj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hRvFWVbn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wcCpLEwc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OT5g8ooV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ziuRJbSo_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_DDDNMwgq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6OWqBh7Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_LQZEZutE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EdmUDHMS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r70t6sC8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_di74TRcu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Gvgw9tWP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_K5yPiAkC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nWmtLZQS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_uGE0ZKfd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_SdksBj6S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jhQ3EV84_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6gNNEvRe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5dXlvPjD_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_kusXHA0p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4KDufybY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_frFQoZ0i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FgkTMWT3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_K6dxxTR0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XruCvhiu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VA8bcvML_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_y7uFnIoF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DjIuTofO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_MgvaJih7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yarcIcXp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sjJ9gRE4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_rxL2Vz9t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zo11eAjS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_x9sh2yQP_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_Gr6ZYW4t;
  SignalPhasor sPhasor_fQsmdrWC;
  SignalPhasor sPhasor_SfGBYeSZ;
  SignalVarf sVarf_ZqIOnViw;
  ControlVar cVar_g5uIdh5q;
  SignalVarf sVarf_QPtwKSPh;
  SignalVarf sVarf_D5awyUJN;
  ControlVar cVar_sTwG1uSM;
  ControlSlice cSlice_va0OES1P;
  ControlSlice cSlice_pMR5ZFyY;
  ControlVar cVar_rlJ8R5WK;
  ControlVar cVar_YP5gcZ5z;
  ControlBinop cBinop_T8WB3mwq;
  ControlBinop cBinop_brflxUZx;
  ControlBinop cBinop_xYVh4zE4;
  ControlBinop cBinop_3QANWZzU;
  ControlBinop cBinop_WRBFzhKO;
  ControlVar cVar_yMPRZjV6;
  ControlSlice cSlice_WBh0Fnjn;
  ControlSlice cSlice_WPhOL2VH;
  ControlBinop cBinop_WrC33QJC;
  ControlBinop cBinop_UqVNezBb;
  ControlVar cVar_TSVCYxud;
  ControlBinop cBinop_vg2mWKki;
  ControlBinop cBinop_btRpFgSI;
  ControlVar cVar_ZOvzunf4;
  ControlVar cVar_MMS5h5MP;
  ControlDelay cDelay_Xo61ue9L;
  ControlVar cVar_0xfLzPuU;
  ControlBinop cBinop_8ot6EGeD;
  ControlBinop cBinop_t79l9YwU;
  ControlBinop cBinop_c3XFLwHU;
  ControlBinop cBinop_85FRrGDr;
  ControlBinop cBinop_Dw8P11WH;
  SignalVarf sVarf_fFL2jsWC;
  ControlBinop cBinop_Xd9EJk0N;
  SignalVarf sVarf_w1TiJG01;
  ControlBinop cBinop_HGLPbIbx;
  ControlBinop cBinop_9Yi8LR1A;
  ControlVar cVar_H8MTpFLu;
  ControlVar cVar_VwG8X0s8;
  ControlBinop cBinop_uyxKNNg3;
  ControlBinop cBinop_N7DfrbV7;
  ControlBinop cBinop_m07SQ4EM;
  ControlVar cVar_HqOV9Nig;
  ControlBinop cBinop_3tA9EflQ;
  ControlBinop cBinop_WNdeunlT;
  ControlBinop cBinop_0wWweOVy;
  ControlBinop cBinop_QhanG4Ur;
  ControlVar cVar_yCMOQV6O;
  ControlBinop cBinop_exmXmCeN;
  ControlBinop cBinop_oA9COVXI;
  ControlSlice cSlice_8PSuGcQG;
  ControlSlice cSlice_32oLhR5N;
  ControlVar cVar_ony2VgxB;
  ControlSlice cSlice_Nxhj00OU;
  ControlSlice cSlice_6iCxFvqL;
  ControlBinop cBinop_1nF1Ba5k;
  ControlVar cVar_kKCbuLTj;
  ControlVar cVar_hRvFWVbn;
  ControlBinop cBinop_wcCpLEwc;
  ControlBinop cBinop_OT5g8ooV;
  ControlVar cVar_6OWqBh7Y;
  ControlDelay cDelay_LQZEZutE;
  ControlBinop cBinop_r70t6sC8;
  ControlVar cVar_K5yPiAkC;
  ControlBinop cBinop_FgkTMWT3;
  SignalVarf sVarf_s4aLbCTY;
  ControlVar cVar_K6dxxTR0;
  ControlVar cVar_XruCvhiu;
  ControlBinop cBinop_VA8bcvML;
  ControlBinop cBinop_x9sh2yQP;
};

#endif // _HEAVY_CONTEXT_POD_TEST_HPP_
