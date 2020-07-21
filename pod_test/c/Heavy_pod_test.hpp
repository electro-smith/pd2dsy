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
        KNOB1 = 0x62DD3F82, // Knob1
        KNOB2 = 0x6BE4E001, // Knob2
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cCast_yamzEJ2k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_U6owIQVi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SsH63pYE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6l8XipRe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hJpOXJ12_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yz3wsKoZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QRukWd1V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HUufdNNV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MqEZmJi4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Ul5xTGNa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uSFOcaEY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SD20sT0g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_C0NrZhVP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dCaEfd40_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lXnOeRDv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_vSWYxfeK_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_G0zewBA8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_B5RYy1IZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5dwTnBhe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SXzfRdIu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vnEj0fmw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2xgrLY2F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XFEuuGTq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eo9KSuBp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oBBha1OT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Oa0t82vV_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSystem_Pa0yJIkw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_w5tx2O7G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_teR6aDBd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_xgkGQtcg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_u4MbUghp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XsvkDdvD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pa0yv6Fe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8xwUrCZk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zuahl5ov_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1salrjnF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Wng8V6du_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ChxMxmqa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rlalJQyl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vvejQ2DC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aDXBI5bU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Qgt12p7V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dZZxW4df_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ehch0926_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1SUiqwIi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MeoQXGPa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CmAzEzXp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mpmXsuHV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CzftTujb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_JSWl4eoi_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_0JTKBPjT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jMqccK68_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lqBl6P2i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_KKbVROYR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_0W7QMyTr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iHQfDG0b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_oGzUpnHJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TE0C22Gh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5f3BfHeI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HT9AhEjD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ejP3iFJp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PrQHyjlV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Sr0DY3gw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_vbFLFdKb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_EcyOPryY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WUlvjWnX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_YbFGyGur_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tCXSkeWo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_09wjUMpD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gvlBfC3W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TJKysIVT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xf91weWe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WS8Svw43_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_rM1PWQ1b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dW5Yp4fG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PTI93DOX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qNXYfu50_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bramYGKJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_h68MsSo0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FMywHr3L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_y0r8augW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_w0QwuYgU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_7K7xYdIB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_d2hGZ3ld_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_hZ75LPtV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_O8eoFoRy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_HUkqsRUq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_O5MXVaLh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KquTuN9f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fMum2nIP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_cMuT1fw6_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_eMSRJk4j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3V0I5Uri_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_onFFMfOk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dx4Ig6Ty_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_MI1Bok0L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ozNHe3kE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_x8c3obFT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YZWRxO9E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iruQ3qyM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8YkWIO6I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l52C92Rd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ePiHACft_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fIkJXbGo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0kYXdthU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xguBgQ40_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_a2C2tHJH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_VxZIj2sj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_YxLM56G0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VcYJPTCU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xC3oEbeq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AlC0iIS7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hPff1HM5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xudxAgwX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9XSUtYT7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_SyRV1LU7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DHloVatR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TNyKuKBY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_liVJH6Q7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_APr0uaNw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XUYILxQI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MtvKu94Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bAwhhShJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oij3Ce2r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yhFhslNr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_wpv2HKcu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_48zVgGoN_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_JVJaKDEO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1Gq4MGlF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_1HYxyLba_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lzTLfpPI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jnmdKTTw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lHYbWcLb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ylVyorh4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_u6TQ0UBY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_9kGuzwfg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_E3vMFx52_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4kReowmx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_1PKslP64_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_SaBRc9ja;
  SignalPhasor sPhasor_lmVQ54jn;
  SignalPhasor sPhasor_KHoQ6k0Q;
  SignalVarf sVarf_5heyqZqj;
  ControlVar cVar_6l8XipRe;
  ControlVar cVar_hJpOXJ12;
  ControlBinop cBinop_QRukWd1V;
  ControlBinop cBinop_HUufdNNV;
  ControlBinop cBinop_MqEZmJi4;
  ControlBinop cBinop_uSFOcaEY;
  ControlBinop cBinop_dCaEfd40;
  ControlSlice cSlice_G0zewBA8;
  ControlSlice cSlice_B5RYy1IZ;
  ControlBinop cBinop_5dwTnBhe;
  ControlVar cVar_XFEuuGTq;
  ControlVar cVar_xgkGQtcg;
  ControlDelay cDelay_u4MbUghp;
  ControlBinop cBinop_XsvkDdvD;
  ControlBinop cBinop_8xwUrCZk;
  ControlBinop cBinop_zuahl5ov;
  ControlBinop cBinop_Wng8V6du;
  ControlBinop cBinop_ChxMxmqa;
  ControlBinop cBinop_aDXBI5bU;
  ControlVar cVar_Qgt12p7V;
  ControlVar cVar_1SUiqwIi;
  ControlVar cVar_MeoQXGPa;
  ControlBinop cBinop_0JTKBPjT;
  ControlBinop cBinop_jMqccK68;
  ControlSlice cSlice_lqBl6P2i;
  ControlSlice cSlice_KKbVROYR;
  ControlVar cVar_oGzUpnHJ;
  SignalVarf sVarf_Tn18nXmH;
  SignalVarf sVarf_Z4cLfTT2;
  ControlBinop cBinop_Sr0DY3gw;
  SignalVarf sVarf_rKXvYFCo;
  ControlVar cVar_gvlBfC3W;
  ControlVar cVar_TJKysIVT;
  ControlBinop cBinop_Xf91weWe;
  SignalVarf sVarf_gnMgAX3B;
  ControlBinop cBinop_d2hGZ3ld;
  ControlDelay cDelay_HUkqsRUq;
  ControlVar cVar_KquTuN9f;
  ControlBinop cBinop_fMum2nIP;
  ControlBinop cBinop_eMSRJk4j;
  ControlSlice cSlice_dx4Ig6Ty;
  ControlSlice cSlice_MI1Bok0L;
  ControlBinop cBinop_ozNHe3kE;
  ControlVar cVar_YZWRxO9E;
  ControlVar cVar_8YkWIO6I;
  ControlBinop cBinop_l52C92Rd;
  ControlBinop cBinop_ePiHACft;
  ControlBinop cBinop_VxZIj2sj;
  ControlVar cVar_xC3oEbeq;
  ControlBinop cBinop_AlC0iIS7;
  ControlBinop cBinop_hPff1HM5;
  ControlBinop cBinop_9XSUtYT7;
  ControlVar cVar_SyRV1LU7;
  ControlBinop cBinop_DHloVatR;
  ControlBinop cBinop_TNyKuKBY;
  ControlVar cVar_XUYILxQI;
  ControlVar cVar_MtvKu94Z;
  ControlSlice cSlice_wpv2HKcu;
  ControlSlice cSlice_JVJaKDEO;
  ControlBinop cBinop_jnmdKTTw;
  ControlBinop cBinop_lHYbWcLb;
  ControlVar cVar_ylVyorh4;
  ControlBinop cBinop_u6TQ0UBY;
  ControlVar cVar_E3vMFx52;
  SignalVarf sVarf_CrgDHAF3;
};

#endif // _HEAVY_CONTEXT_POD_TEST_HPP_
