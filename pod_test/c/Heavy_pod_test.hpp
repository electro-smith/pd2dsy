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
#include "HvControlDelay.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlVar.h"
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
  static void cCast_axY5nnxY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5yNgV8NB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_g9KDEwJf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_XdmHrHrK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_I6bYagyv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iZw51DjJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_F18x8DpP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JzFJDZMh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_khqS5bXq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_I1ZWwnFZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_Ag8BKf22_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GbAY1sZu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_19fHVpsx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XxCHylgi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_i3ArZg8M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_7z3lhuKh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zUr4GT2C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GiL5qOwa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KsfIqGR9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tlaxLQYV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_7SKSyHti_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_d2Sdv6hJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tic36vmT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_C5nAY5nZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3JpdT1PO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PC0e3uru_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_DoUnrMnT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Uhrc0phW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_3y4VgoBA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MJJ00ohR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XSEmxvUd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UiasHWVv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rV8HjgTB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2stmShKa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kk8CKPKT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wEmUgxIP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Z0DPHHKX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kJp4cLpb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IC9cfA04_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eY3dZx2R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DBeqjexU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_w8WiUMQs_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_P8Nu5KFN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xAK0NN2g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_csQ8uGc8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Rf4qpySW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_v9dGXD4o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HJLP0kyj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RyO90rU5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qyhxQk4K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PqoU3wkD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_mIt9R5Ej_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_GmgoUBym_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_17Luo5P9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Lh49pN46_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nehLQG5V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gJT8pGeH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7LWCJe7p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ci0cnbMH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AD3cZGGh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PAxRvnKu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7xwpp2un_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_U4yFhdrQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8424ObSJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nqF4Dk7v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ida01k5R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Q7KiMWSG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5icauPP8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_sqop7LQi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_a38l7S3N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Uj7EnUDq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Z5DTeixf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_afsoYAoD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_75JAYIfD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_FlSZF9Ub_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_svao7tpQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BYCwxw0p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6J3rpIMo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8NuIPDSh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_22Zi2Oqz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kz5KLFuv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DWL4Mw8x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iZB92oUI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2fkFRJTY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lC1OyRrn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2veCJGmW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lxzXtzlK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nnhVH9P3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_seCS54g8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ow5SEq4d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xlcgbR3y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ydbeuK8H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pD3bb1xb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_wlxVhNNs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FUrQEpRO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_y7chm5tH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xvWbMJNW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JZNmXcxb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RVNUOEwd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xehACsip_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WCFzaoew_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qHoyY5ic_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UOMJDx3w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HcB1qOAF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_moYSdUqC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GDSpZRwP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_z2kdqjxL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ePsnHqPv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7Ag2EWan_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_agsXpmta_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VAfnjbDh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wIePkI8C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_24DTiiFf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_cYLz54cv_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_B6fb886A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HgJwzIv4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9nsLI3Ig_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ffdkAVfA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UlLvTBbI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Nq4NylJY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KoAj0BBo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_x9qc3fXd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_VJVE33vj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_78T6Eljz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Gv0Gw6R1_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_N9TrFY1X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GEyJKek6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_bREMQ2tn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_E5WjCXP6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_A5ZvHy5x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DKOtRUPi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KwY8wtoe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_S6py8yid_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_V6FCFgK7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_1BNSPRsf_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_iNHGHwM5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9j47F4ip_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_m3SNlfVw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_58UKcRgE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DFU6A1gR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gwOeMPE8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Q8g2M6lS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Suglh6jo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ObDD4JDF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eoLxI2VX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zGOJnLs7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_WP4bvGXU_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_nLXU5XFi;
  SignalPhasor sPhasor_rLXgTH26;
  SignalPhasor sPhasor_xNMRHnhl;
  ControlVar cVar_5yNgV8NB;
  ControlBinop cBinop_g9KDEwJf;
  ControlBinop cBinop_iZw51DjJ;
  ControlSlice cSlice_khqS5bXq;
  ControlSlice cSlice_Ag8BKf22;
  ControlVar cVar_GbAY1sZu;
  ControlBinop cBinop_19fHVpsx;
  ControlVar cVar_XxCHylgi;
  ControlSlice cSlice_i3ArZg8M;
  ControlSlice cSlice_7z3lhuKh;
  ControlBinop cBinop_zUr4GT2C;
  ControlBinop cBinop_d2Sdv6hJ;
  ControlVar cVar_C5nAY5nZ;
  ControlBinop cBinop_3JpdT1PO;
  ControlBinop cBinop_PC0e3uru;
  ControlDelay cDelay_DoUnrMnT;
  ControlBinop cBinop_MJJ00ohR;
  ControlBinop cBinop_XSEmxvUd;
  ControlBinop cBinop_UiasHWVv;
  ControlBinop cBinop_kk8CKPKT;
  ControlVar cVar_Z0DPHHKX;
  ControlBinop cBinop_kJp4cLpb;
  ControlBinop cBinop_eY3dZx2R;
  ControlVar cVar_P8Nu5KFN;
  ControlVar cVar_17Luo5P9;
  ControlBinop cBinop_nehLQG5V;
  ControlBinop cBinop_Ci0cnbMH;
  SignalVarf sVarf_UAziP5on;
  ControlVar cVar_PAxRvnKu;
  SignalVarf sVarf_OE3OdJhK;
  ControlVar cVar_5icauPP8;
  ControlVar cVar_Uj7EnUDq;
  ControlBinop cBinop_Z5DTeixf;
  SignalVarf sVarf_fzxoCaOJ;
  ControlVar cVar_svao7tpQ;
  ControlVar cVar_6J3rpIMo;
  ControlBinop cBinop_8NuIPDSh;
  ControlBinop cBinop_kz5KLFuv;
  ControlBinop cBinop_2veCJGmW;
  ControlBinop cBinop_Ow5SEq4d;
  ControlBinop cBinop_ydbeuK8H;
  ControlBinop cBinop_JZNmXcxb;
  ControlBinop cBinop_RVNUOEwd;
  ControlBinop cBinop_xehACsip;
  ControlVar cVar_qHoyY5ic;
  ControlVar cVar_UOMJDx3w;
  ControlBinop cBinop_HcB1qOAF;
  ControlDelay cDelay_z2kdqjxL;
  ControlBinop cBinop_ePsnHqPv;
  ControlBinop cBinop_VAfnjbDh;
  ControlBinop cBinop_wIePkI8C;
  ControlVar cVar_HgJwzIv4;
  ControlBinop cBinop_9nsLI3Ig;
  ControlVar cVar_UlLvTBbI;
  ControlSlice cSlice_78T6Eljz;
  ControlSlice cSlice_N9TrFY1X;
  ControlVar cVar_GEyJKek6;
  ControlSlice cSlice_bREMQ2tn;
  ControlSlice cSlice_E5WjCXP6;
  ControlVar cVar_A5ZvHy5x;
  ControlVar cVar_DKOtRUPi;
  ControlBinop cBinop_KwY8wtoe;
  ControlBinop cBinop_9j47F4ip;
  ControlBinop cBinop_DFU6A1gR;
  SignalVarf sVarf_WdzmedFO;
  ControlVar cVar_Q8g2M6lS;
  SignalVarf sVarf_7RHPfUSZ;
  ControlBinop cBinop_Suglh6jo;
  SignalVarf sVarf_YaHDUIlp;
};

#endif // _HEAVY_CONTEXT_POD_TEST_HPP_
