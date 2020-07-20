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
        KNOB1 = 0x62DD3F82, // Knob1
        KNOB2 = 0x6BE4E001, // Knob2
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cCast_69zLgQYd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PGwTbUVW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qCrc7y9r_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Krnc6BV5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_zRsGdIQe_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_9QeEBtLb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ja8sphKQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cL0dYOCZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9LwUUnRG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uvrI0lxA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_rfqC9MU2_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_gRmjQQRJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CHxbV0ad_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fqn2f6pJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oWrSgwBy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_QzBjXMUw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sPTgyJhp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_r3wfc2gC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iS4jEquu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SsGTD4qt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JogE89OP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2KM0EIrZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rbt3q7QT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Q0rAc6or_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KWDAvyHW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XeFObm9u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_clhoXZIm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BOTxqYeJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AnKaOq7J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MPQclVn9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RPbhABd6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dukRUxgD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dYkgI3kY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TKr9RQrX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_77eKXL7F_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_1V8c3WWR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_wxTK81n9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7Y3TV6ld_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YA06KR03_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DXAGwnaU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LfftyXBV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9X6AlxKQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JBPyw0kH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_y5wZtZMV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zUUrS36D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NyFDUXwp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_5LPYaplW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_O22SfyAR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZqGBoKlw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_d1IInGFK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2BBatLhu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_V2nUFEm9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_feWDzIvw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_2Ih2kQdt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_E0KKKbp7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uUBSgpcG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XMYJsE03_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xwi6MaNj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2HnjTtQj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NQBIZ5qC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gdwHmtxS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_V1w1u22o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_I4IDkZOj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_aCKu1geI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_ea3mFglU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_EbkMuX0a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3wH3Os3y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Re1RprFf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YfD0ABJt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9htATmVz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ortzPWrz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eyuK3YWR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZsYgeZzL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_4s6xI9AU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_iIUTxvn3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GYUA6ARG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_sLzwUWnP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_pEfFjgy8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pryPvIKI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_x3t0QW5Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sGkShztG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wdX2hOft_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oKgst4sr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Dd9Hzsau_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mex45UFr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pOu4iCXx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kvy2yJnj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cuhlQbF7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ygup5zRr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_v6HwXBEt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5aGP1yO6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_i15QE2yO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DdZu1MJb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qwcmHfvm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_HYwPCAby_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_XJydnaDP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_F9hJzoQy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VvimoYjz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zh2754ge_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fIGFi3FQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vMzVSagT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RaZgeiHm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MmG5CZju_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_t79Lzk1t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wolOLB05_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_mq7OD5zo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_We8ErdQ8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oflAogm6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pIfwyFJI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jP5Pn2yG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_F0VLvBOu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_UHnFLeyp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0zb1aY7t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_lPXt7Tzy_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_SHDNELmg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xEqLBU6I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KkCYS8XU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_CYV6Bh9u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7vW5Tj1I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sfyzSm7e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_KD9hl7DB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_V0Nvasea_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Vd5dBasc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Gm3yCS0f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2Sfibbne_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_wgt08Q8R;
  SignalPhasor sPhasor_IEuOBkHg;
  ControlBinop cBinop_uvrI0lxA;
  ControlBinop cBinop_gRmjQQRJ;
  ControlVar cVar_fqn2f6pJ;
  ControlBinop cBinop_oWrSgwBy;
  ControlDelay cDelay_r3wfc2gC;
  ControlBinop cBinop_SsGTD4qt;
  ControlVar cVar_rbt3q7QT;
  ControlBinop cBinop_Q0rAc6or;
  ControlBinop cBinop_XeFObm9u;
  ControlVar cVar_clhoXZIm;
  ControlVar cVar_BOTxqYeJ;
  ControlBinop cBinop_MPQclVn9;
  ControlBinop cBinop_TKr9RQrX;
  ControlSlice cSlice_1V8c3WWR;
  ControlSlice cSlice_wxTK81n9;
  ControlBinop cBinop_DXAGwnaU;
  ControlVar cVar_LfftyXBV;
  ControlBinop cBinop_9X6AlxKQ;
  ControlBinop cBinop_y5wZtZMV;
  ControlBinop cBinop_zUUrS36D;
  ControlBinop cBinop_O22SfyAR;
  ControlVar cVar_d1IInGFK;
  ControlVar cVar_2BBatLhu;
  ControlSlice cSlice_feWDzIvw;
  ControlSlice cSlice_2Ih2kQdt;
  ControlBinop cBinop_uUBSgpcG;
  SignalVarf sVarf_sbD18Una;
  ControlBinop cBinop_NQBIZ5qC;
  ControlBinop cBinop_gdwHmtxS;
  ControlVar cVar_ea3mFglU;
  ControlDelay cDelay_EbkMuX0a;
  ControlBinop cBinop_3wH3Os3y;
  ControlBinop cBinop_9htATmVz;
  ControlBinop cBinop_ortzPWrz;
  ControlBinop cBinop_iIUTxvn3;
  ControlVar cVar_pEfFjgy8;
  ControlBinop cBinop_pryPvIKI;
  ControlBinop cBinop_oKgst4sr;
  ControlVar cVar_mex45UFr;
  ControlBinop cBinop_Ygup5zRr;
  ControlVar cVar_v6HwXBEt;
  ControlBinop cBinop_5aGP1yO6;
  ControlVar cVar_DdZu1MJb;
  ControlBinop cBinop_qwcmHfvm;
  ControlSlice cSlice_HYwPCAby;
  ControlSlice cSlice_XJydnaDP;
  ControlBinop cBinop_F9hJzoQy;
  ControlBinop cBinop_MmG5CZju;
  ControlVar cVar_t79Lzk1t;
  ControlBinop cBinop_F0VLvBOu;
  ControlSlice cSlice_UHnFLeyp;
  ControlSlice cSlice_0zb1aY7t;
  ControlVar cVar_SHDNELmg;
  SignalVarf sVarf_OpOzS14g;
};

#endif // _HEAVY_CONTEXT_POD_TEST_HPP_
