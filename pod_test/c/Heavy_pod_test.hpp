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
        KNOB1 = 0x62DD3F82, // Knob1
        KNOB2 = 0x6BE4E001, // Knob2
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cMsg_LUy0FBSK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_sibBgQCK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_krhuWRYl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nUMZAJOf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wUPuQfJB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4xy4sxNd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_thw3ptvf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WDBbAEjQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ReRHycMV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7HunDZjK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HsrV1Wlq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_fQHDBnUb_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_JsbMSXEf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hHo7vRH9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_yNqJxjQN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X0dUmaUx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Y6RJB16d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jJpxIQby_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ygBuN3jN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_hyt26SvK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KFu6Ynxa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NI4g1x0W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XgLKxRzc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RHp5bCVQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gUxQ2PE0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UXTI5Osq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JWXzRph7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BgDmbhTe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ElCRizg0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Sy45LGzn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GJuh0mUK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TVQrgVym_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WiqJ1ERm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_X9MgXM6e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jxlJl4bn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6sIABKgd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ImMADj16_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BjNgwo00_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_pYWordMa_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_rErqrMRn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ezdXe0hN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6nfCZZcY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7nPWSOf7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_8wdGarS0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_wPCnCY1q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_OgAQuYEM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_LpVGKGKO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_zKL97LIp_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_ai4fKLrf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3xj9tfDN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mRRcv7eF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xSR5AsFN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6btXQ1yW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1MFkVCKF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TDgRAhee_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bk99QC81_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_oGIfS2HF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LBHOWwgN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qBADOtuF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_JuuCUVkv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iVspiE9l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xCMcW5Kd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fZsvqTNU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0HgD9csM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Iw06JKVC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_B3iR4fq6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_yUBUEV9d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_kDSFS8yG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2ePW7xrQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YAH1GeAC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_in20j42w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DDQQnVp6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_enCBf0dm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yMI12Kl0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_EB7rRnV4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JrKUDDpx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lSVOWCh3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Vy6Lt8Kt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kEjlQihs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_prAVjwaj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VfvrhqE0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EzPtAE8r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VqetHPss_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Dvx0Srz9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_4QGkrcoJ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_42vpwUsN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Sp5uMUow_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QEZ4IvJC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pNjj660u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZMk4N5Mo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_g3ZeDgiZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wL8EC3uu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_miBnKw3z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pzBAyumX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5SiBM89a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1KIOu314_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BziJtgZ3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_w3O83Qh6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EtcPJwxH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LKjTNWnP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DMQERr58_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ZBmFFyaC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_b4LuKrT7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_WNLyOTjM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Zv35GRq3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XJxqpnJU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1aakfp5j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_138FipWX_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_vrT8CEBb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FPgYG0Sj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7tbPlqNn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_aOrf2ooU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_wKSTuUpA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_x5ChvLoN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gkkjbd8H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yTGFrF4l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TWsHbRSj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XmS1TtxW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GbZdxjBV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Sad2v9z6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_KsBqLfHx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0rWL1X3Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_oehld6aj_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_lZL3MU6u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BcYucJZs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zGVyf740_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_toOqOYyA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OFbZasJk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zja1hDiT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_s1UfJbaT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xDC8reNR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rx7GUYQJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KPIEkksC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_4BM8DAGM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_IaEoKvTC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uGBN4vIO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_F7H3O8aw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_exuoo7uN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rfVQ36cq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_u9EOmEIA_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_hJWdm9Ol;
  SignalPhasor sPhasor_DopNmaFi;
  SignalPhasor sPhasor_zlXMtElD;
  SignalVarf sVarf_LdOvhZOY;
  ControlVar cVar_krhuWRYl;
  ControlBinop cBinop_thw3ptvf;
  ControlDelay cDelay_JsbMSXEf;
  ControlVar cVar_yNqJxjQN;
  ControlBinop cBinop_X0dUmaUx;
  ControlBinop cBinop_Y6RJB16d;
  ControlBinop cBinop_KFu6Ynxa;
  ControlBinop cBinop_XgLKxRzc;
  ControlBinop cBinop_gUxQ2PE0;
  ControlVar cVar_UXTI5Osq;
  ControlBinop cBinop_JWXzRph7;
  ControlBinop cBinop_BgDmbhTe;
  ControlBinop cBinop_GJuh0mUK;
  ControlVar cVar_rErqrMRn;
  ControlSlice cSlice_ezdXe0hN;
  ControlSlice cSlice_6nfCZZcY;
  ControlBinop cBinop_7nPWSOf7;
  ControlSlice cSlice_8wdGarS0;
  ControlSlice cSlice_wPCnCY1q;
  ControlBinop cBinop_ai4fKLrf;
  ControlVar cVar_mRRcv7eF;
  ControlVar cVar_xSR5AsFN;
  ControlBinop cBinop_6btXQ1yW;
  ControlVar cVar_TDgRAhee;
  ControlBinop cBinop_bk99QC81;
  ControlVar cVar_oGIfS2HF;
  ControlBinop cBinop_LBHOWwgN;
  SignalVarf sVarf_L8wMyat0;
  ControlVar cVar_yUBUEV9d;
  ControlBinop cBinop_2ePW7xrQ;
  SignalVarf sVarf_EbJF4KQz;
  SignalVarf sVarf_PwhWE0TY;
  ControlVar cVar_YAH1GeAC;
  ControlVar cVar_in20j42w;
  ControlBinop cBinop_DDQQnVp6;
  ControlVar cVar_enCBf0dm;
  ControlVar cVar_lSVOWCh3;
  ControlVar cVar_Vy6Lt8Kt;
  ControlBinop cBinop_kEjlQihs;
  ControlVar cVar_prAVjwaj;
  ControlVar cVar_VqetHPss;
  ControlBinop cBinop_42vpwUsN;
  ControlBinop cBinop_QEZ4IvJC;
  ControlBinop cBinop_g3ZeDgiZ;
  ControlBinop cBinop_wL8EC3uu;
  ControlBinop cBinop_pzBAyumX;
  ControlBinop cBinop_5SiBM89a;
  ControlVar cVar_1KIOu314;
  ControlDelay cDelay_WNLyOTjM;
  ControlBinop cBinop_XJxqpnJU;
  ControlVar cVar_1aakfp5j;
  ControlBinop cBinop_vrT8CEBb;
  ControlBinop cBinop_FPgYG0Sj;
  ControlSlice cSlice_wKSTuUpA;
  ControlSlice cSlice_x5ChvLoN;
  ControlBinop cBinop_yTGFrF4l;
  ControlBinop cBinop_XmS1TtxW;
  ControlSlice cSlice_KsBqLfHx;
  ControlSlice cSlice_0rWL1X3Y;
  ControlBinop cBinop_lZL3MU6u;
  ControlVar cVar_toOqOYyA;
  ControlBinop cBinop_OFbZasJk;
  ControlVar cVar_s1UfJbaT;
  SignalVarf sVarf_d8h4T5Gx;
  ControlBinop cBinop_uGBN4vIO;
};

#endif // _HEAVY_CONTEXT_POD_TEST_HPP_
