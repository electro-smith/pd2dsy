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

#include "Heavy_pod_test.hpp"

#define Context(_c) reinterpret_cast<Heavy_pod_test *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_pod_test_new(double sampleRate) {
    return new Heavy_pod_test(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_pod_test_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_pod_test(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_pod_test::Heavy_pod_test(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_Gr6ZYW4t, 0.0f, sampleRate);
  numBytes += sPhasor_init(&sPhasor_fQsmdrWC, sampleRate);
  numBytes += sPhasor_init(&sPhasor_SfGBYeSZ, sampleRate);
  numBytes += sVarf_init(&sVarf_ZqIOnViw, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_g5uIdh5q, 0.0f);
  numBytes += sVarf_init(&sVarf_QPtwKSPh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_D5awyUJN, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_sTwG1uSM, 0.0f);
  numBytes += cSlice_init(&cSlice_va0OES1P, 1, 1);
  numBytes += cSlice_init(&cSlice_pMR5ZFyY, 0, 1);
  numBytes += cVar_init_f(&cVar_rlJ8R5WK, 20.0f);
  numBytes += cVar_init_f(&cVar_YP5gcZ5z, 0.0f);
  numBytes += cBinop_init(&cBinop_T8WB3mwq, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_brflxUZx, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_xYVh4zE4, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_3QANWZzU, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_yMPRZjV6, 0.0f);
  numBytes += cSlice_init(&cSlice_WBh0Fnjn, 1, -1);
  numBytes += cSlice_init(&cSlice_WPhOL2VH, 1, -1);
  numBytes += cBinop_init(&cBinop_WrC33QJC, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_UqVNezBb, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_TSVCYxud, 0.0f);
  numBytes += cBinop_init(&cBinop_btRpFgSI, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_ZOvzunf4, 0.0f);
  numBytes += cVar_init_f(&cVar_MMS5h5MP, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Xo61ue9L, 0.0f);
  numBytes += cVar_init_f(&cVar_0xfLzPuU, 20.0f);
  numBytes += cBinop_init(&cBinop_8ot6EGeD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_85FRrGDr, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_fFL2jsWC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_w1TiJG01, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_HGLPbIbx, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_H8MTpFLu, 0.0f);
  numBytes += cVar_init_f(&cVar_VwG8X0s8, 0.0f);
  numBytes += cBinop_init(&cBinop_uyxKNNg3, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_m07SQ4EM, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_HqOV9Nig, 20.0f);
  numBytes += cBinop_init(&cBinop_3tA9EflQ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_WNdeunlT, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0wWweOVy, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_yCMOQV6O, 0.0f);
  numBytes += cBinop_init(&cBinop_exmXmCeN, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_8PSuGcQG, 1, 1);
  numBytes += cSlice_init(&cSlice_32oLhR5N, 0, 1);
  numBytes += cVar_init_f(&cVar_ony2VgxB, 0.0f);
  numBytes += cSlice_init(&cSlice_Nxhj00OU, 1, -1);
  numBytes += cSlice_init(&cSlice_6iCxFvqL, 1, -1);
  numBytes += cBinop_init(&cBinop_1nF1Ba5k, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_kKCbuLTj, 0.0f);
  numBytes += cVar_init_f(&cVar_hRvFWVbn, 0.0f);
  numBytes += cVar_init_f(&cVar_6OWqBh7Y, 20.0f);
  numBytes += cDelay_init(this, &cDelay_LQZEZutE, 0.0f);
  numBytes += cBinop_init(&cBinop_r70t6sC8, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_K5yPiAkC, 0.0f);
  numBytes += cBinop_init(&cBinop_FgkTMWT3, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_s4aLbCTY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_K6dxxTR0, 0.0f);
  numBytes += cVar_init_f(&cVar_XruCvhiu, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_pod_test::~Heavy_pod_test() {
  // nothing to free
}

HvTable *Heavy_pod_test::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_pod_test::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xB4D78F23: { // Button1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rxL2Vz9t_sendMessage);
      break;
    }
    case 0x3FE62CA: { // Button2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_78b87hrf_sendMessage);
      break;
    }
    case 0x7AAC371F: { // EncSwitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Xi8elKNI_sendMessage);
      break;
    }
    case 0x39ADE514: { // Encoder
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2mJACYJ1_sendMessage);
      break;
    }
    case 0x62DD3F82: { // Knob1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rg3JoWPd_sendMessage);
      break;
    }
    case 0x6BE4E001: { // Knob2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iWCtfb8b_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MgvaJih7_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_pod_test::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "Encoder";
        info->hash = 0x39ADE514;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 1: {
        info->name = "Button2";
        info->hash = 0x3FE62CA;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 2: {
        info->name = "Button1";
        info->hash = 0xB4D78F23;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 3: {
        info->name = "Knob1";
        info->hash = 0x62DD3F82;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 4: {
        info->name = "Knob2";
        info->hash = 0x6BE4E001;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 5: {
        info->name = "EncSwitch";
        info->hash = 0x7AAC371F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 6;
}



/*
 * Send Function Implementations
 */


void Heavy_pod_test::cMsg_vqhuLWeM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Gr6ZYW4t, 0, m);
}

void Heavy_pod_test::cCast_skQKHM05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U4WX4zII_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JniK7oeu_sendMessage);
}

void Heavy_pod_test::cVar_g5uIdh5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_9Yi8LR1A_sendMessage);
}

void Heavy_pod_test::cMsg_gaTQOTQu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_XruCvhiu, 0, m, &cVar_XruCvhiu_sendMessage);
}

void Heavy_pod_test::cCast_JniK7oeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sjJ9gRE4_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_UF44XRmb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_Xd9EJk0N_sendMessage);
}

void Heavy_pod_test::cVar_sTwG1uSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pod_test::cReceive_2mJACYJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_Xd9EJk0N_sendMessage);
}

void Heavy_pod_test::cCast_nTU7lceK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dexYfRg8_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_D5Src07m_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nTU7lceK_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_T8WB3mwq, HV_BINOP_MULTIPLY, 0, m, &cBinop_T8WB3mwq_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_btRpFgSI, HV_BINOP_DIVIDE, 1, m, &cBinop_btRpFgSI_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_0xfLzPuU, 0, m, &cVar_0xfLzPuU_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cCast_Wt0Ev5N9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YP5gcZ5z, 1, m, &cVar_YP5gcZ5z_sendMessage);
}

void Heavy_pod_test::cCast_CWL61kQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GhzYUbMQ_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSystem_2EdV7FvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T8WB3mwq, HV_BINOP_MULTIPLY, 1, m, &cBinop_T8WB3mwq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_85FRrGDr, HV_BINOP_MULTIPLY, 1, m, &cBinop_85FRrGDr_sendMessage);
}

void Heavy_pod_test::cMsg_VFnQ82NR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2EdV7FvT_sendMessage);
}

void Heavy_pod_test::cCast_uLoOOS1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YP5gcZ5z, 0, m, &cVar_YP5gcZ5z_sendMessage);
}

void Heavy_pod_test::cSlice_va0OES1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_K2tdlERv_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_o4h9LZQv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_pMR5ZFyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Wt0Ev5N9_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Rxdo0Rvn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cVar_rlJ8R5WK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_D5Src07m_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cMsg_GhzYUbMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_p452rArI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_jrKiXdpd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gIMdeLWV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xYVh4zE4, HV_BINOP_ADD, 0, m, &cBinop_xYVh4zE4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yMPRZjV6, 1, m, &cVar_yMPRZjV6_sendMessage);
}

void Heavy_pod_test::cMsg_Ig9Gn2xe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_p452rArI_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xYVh4zE4, HV_BINOP_ADD, 1, m, &cBinop_xYVh4zE4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UqVNezBb, HV_BINOP_ADD, 1, m, &cBinop_UqVNezBb_sendMessage);
}

void Heavy_pod_test::cVar_YP5gcZ5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yMPRZjV6, 0, m, &cVar_yMPRZjV6_sendMessage);
}

void Heavy_pod_test::cBinop_T8WB3mwq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vg2mWKki_sendMessage);
}

void Heavy_pod_test::cBinop_brflxUZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZOvzunf4, 1, m, &cVar_ZOvzunf4_sendMessage);
}

void Heavy_pod_test::cBinop_xYVh4zE4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MMS5h5MP, 0, m, &cVar_MMS5h5MP_sendMessage);
}

void Heavy_pod_test::cBinop_3QANWZzU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xYVh4zE4, HV_BINOP_ADD, 1, m, &cBinop_xYVh4zE4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UqVNezBb, HV_BINOP_ADD, 1, m, &cBinop_UqVNezBb_sendMessage);
}

void Heavy_pod_test::cCast_K2tdlERv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_85FRrGDr, HV_BINOP_MULTIPLY, 0, m, &cBinop_85FRrGDr_sendMessage);
}

void Heavy_pod_test::cCast_xFWEYPlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TSVCYxud, 0, m, &cVar_TSVCYxud_sendMessage);
}

void Heavy_pod_test::cMsg_HKuKWU0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_p452rArI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_WRBFzhKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TGEJGkja_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cVar_yMPRZjV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UqVNezBb, HV_BINOP_ADD, 0, m, &cBinop_UqVNezBb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xYVh4zE4, HV_BINOP_ADD, 0, m, &cBinop_xYVh4zE4_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_D5awyUJN, m);
}

void Heavy_pod_test::cSlice_WBh0Fnjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_56v6NlEr_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jrKiXdpd_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_56v6NlEr_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jrKiXdpd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_WPhOL2VH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_HKuKWU0W_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_HKuKWU0W_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSwitchcase_Z525OfWg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WPhOL2VH, 0, m, &cSlice_WPhOL2VH_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WBh0Fnjn, 0, m, &cSlice_WBh0Fnjn_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xFWEYPlB_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_va0OES1P, 0, m, &cSlice_va0OES1P_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_pMR5ZFyY, 0, m, &cSlice_pMR5ZFyY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CWL61kQe_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6PFw9JwV_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cCast_gIMdeLWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ig9Gn2xe_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_dexYfRg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_T8WB3mwq, HV_BINOP_MULTIPLY, 0, m, &cBinop_T8WB3mwq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_btRpFgSI, HV_BINOP_DIVIDE, 1, m, &cBinop_btRpFgSI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0xfLzPuU, 0, m, &cVar_0xfLzPuU_sendMessage);
}

void Heavy_pod_test::cCast_56v6NlEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HKuKWU0W_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_3HvXekhb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ig9Gn2xe_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_6PFw9JwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YWC33Qeo_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_o4h9LZQv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_btRpFgSI, HV_BINOP_DIVIDE, 0, m, &cBinop_btRpFgSI_sendMessage);
}

void Heavy_pod_test::cBinop_WrC33QJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3QANWZzU, HV_BINOP_DIVIDE, 0, m, &cBinop_3QANWZzU_sendMessage);
}

void Heavy_pod_test::cBinop_UqVNezBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yMPRZjV6, 1, m, &cVar_yMPRZjV6_sendMessage);
}

void Heavy_pod_test::cCast_Rxdo0Rvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WrC33QJC, HV_BINOP_SUBTRACT, 0, m, &cBinop_WrC33QJC_sendMessage);
}

void Heavy_pod_test::cVar_TSVCYxud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_K2tdlERv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_o4h9LZQv_sendMessage);
}

void Heavy_pod_test::cMsg_YWC33Qeo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_TSVCYxud, 1, m, &cVar_TSVCYxud_sendMessage);
}

void Heavy_pod_test::cBinop_vg2mWKki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_brflxUZx, HV_BINOP_SUBTRACT, 1, m, &cBinop_brflxUZx_sendMessage);
}

void Heavy_pod_test::cBinop_btRpFgSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3QANWZzU, HV_BINOP_DIVIDE, 1, m, &cBinop_3QANWZzU_sendMessage);
}

void Heavy_pod_test::cVar_ZOvzunf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_brflxUZx, HV_BINOP_SUBTRACT, 0, m, &cBinop_brflxUZx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_WRBFzhKO_sendMessage);
}

void Heavy_pod_test::cVar_MMS5h5MP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WrC33QJC, HV_BINOP_SUBTRACT, 1, m, &cBinop_WrC33QJC_sendMessage);
}

void Heavy_pod_test::cMsg_5RBSmIie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PKc6eaCr_sendMessage);
}

void Heavy_pod_test::cSystem_PKc6eaCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_c3XFLwHU_sendMessage);
}

void Heavy_pod_test::cSwitchcase_p452rArI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_onB0nwdp_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_onB0nwdp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aZdVJqnC_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cDelay_Xo61ue9L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Xo61ue9L, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xo61ue9L, 0, m, &cDelay_Xo61ue9L_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZOvzunf4, 0, m, &cVar_ZOvzunf4_sendMessage);
}

void Heavy_pod_test::cVar_0xfLzPuU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8ot6EGeD, HV_BINOP_MULTIPLY, 0, m, &cBinop_8ot6EGeD_sendMessage);
}

void Heavy_pod_test::cCast_aZdVJqnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_onB0nwdp_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xo61ue9L, 0, m, &cDelay_Xo61ue9L_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZOvzunf4, 0, m, &cVar_ZOvzunf4_sendMessage);
}

void Heavy_pod_test::cBinop_8ot6EGeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_t79l9YwU_sendMessage);
}

void Heavy_pod_test::cBinop_t79l9YwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xo61ue9L, 2, m, &cDelay_Xo61ue9L_sendMessage);
}

void Heavy_pod_test::cMsg_onB0nwdp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xo61ue9L, 0, m, &cDelay_Xo61ue9L_sendMessage);
}

void Heavy_pod_test::cBinop_c3XFLwHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8ot6EGeD, HV_BINOP_MULTIPLY, 1, m, &cBinop_8ot6EGeD_sendMessage);
}

void Heavy_pod_test::cCast_0XxL7ReE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3HvXekhb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uLoOOS1A_sendMessage);
}

void Heavy_pod_test::cCast_ivgeaPNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yMPRZjV6, 0, m, &cVar_yMPRZjV6_sendMessage);
}

void Heavy_pod_test::cSwitchcase_TGEJGkja_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ivgeaPNW_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0XxL7ReE_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cBinop_85FRrGDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Dw8P11WH_sendMessage);
}

void Heavy_pod_test::cBinop_Dw8P11WH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZOvzunf4, 1, m, &cVar_ZOvzunf4_sendMessage);
}

void Heavy_pod_test::cReceive_iWCtfb8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_x9sh2yQP_sendMessage);
}

void Heavy_pod_test::cBinop_Xd9EJk0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HGLPbIbx, HV_BINOP_ADD, 0, m, &cBinop_HGLPbIbx_sendMessage);
}

void Heavy_pod_test::cCast_IR7O2Ryc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5lZeFxG8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zo11eAjS_sendMessage);
}

void Heavy_pod_test::cBinop_HGLPbIbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_K6dxxTR0, 0, m, &cVar_K6dxxTR0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_H8MTpFLu, 0, m, &cVar_H8MTpFLu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_s4aLbCTY, m);
}

void Heavy_pod_test::cMsg_A9pVvtFq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Z525OfWg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cMsg_5K8MluVN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_H8MTpFLu, 0, m, &cVar_H8MTpFLu_sendMessage);
}

void Heavy_pod_test::cMsg_UyMpEJJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_FqkVS0yU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cReceive_78b87hrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5lZeFxG8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zo11eAjS_sendMessage);
}

void Heavy_pod_test::cCast_5lZeFxG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UyMpEJJG_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cReceive_Xi8elKNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XruCvhiu, 0, m, &cVar_XruCvhiu_sendMessage);
}

void Heavy_pod_test::cMsg_Gc0e1gts_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_FqkVS0yU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_9Yi8LR1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_w1TiJG01, m);
}

void Heavy_pod_test::cReceive_rg3JoWPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_9Yi8LR1A_sendMessage);
}

void Heavy_pod_test::cVar_H8MTpFLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HGLPbIbx, HV_BINOP_ADD, 1, m, &cBinop_HGLPbIbx_sendMessage);
}

void Heavy_pod_test::cCast_U4WX4zII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A9pVvtFq_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cVar_VwG8X0s8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_x9sh2yQP_sendMessage);
}

void Heavy_pod_test::cBinop_uyxKNNg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oA9COVXI_sendMessage);
}

void Heavy_pod_test::cBinop_N7DfrbV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ony2VgxB, 1, m, &cVar_ony2VgxB_sendMessage);
}

void Heavy_pod_test::cBinop_m07SQ4EM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_exmXmCeN, HV_BINOP_DIVIDE, 1, m, &cBinop_exmXmCeN_sendMessage);
}

void Heavy_pod_test::cCast_QlJecbHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kKCbuLTj, 0, m, &cVar_kKCbuLTj_sendMessage);
}

void Heavy_pod_test::cCast_f5TEc7tN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MxaL6ctg_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_j6wvQCsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_09Ethe8F_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cVar_HqOV9Nig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uGE0ZKfd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_3tA9EflQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_K5yPiAkC, 0, m, &cVar_K5yPiAkC_sendMessage);
}

void Heavy_pod_test::cCast_E27vuc8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yCMOQV6O, 1, m, &cVar_yCMOQV6O_sendMessage);
}

void Heavy_pod_test::cBinop_WNdeunlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_N7DfrbV7_sendMessage);
}

void Heavy_pod_test::cBinop_0wWweOVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_exmXmCeN, HV_BINOP_DIVIDE, 0, m, &cBinop_exmXmCeN_sendMessage);
}

void Heavy_pod_test::cBinop_QhanG4Ur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5dXlvPjD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cVar_yCMOQV6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hRvFWVbn, 0, m, &cVar_hRvFWVbn_sendMessage);
}

void Heavy_pod_test::cMsg_FzuRZLmt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BnjWY7qt_sendMessage);
}

void Heavy_pod_test::cSystem_BnjWY7qt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uyxKNNg3, HV_BINOP_MULTIPLY, 1, m, &cBinop_uyxKNNg3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WNdeunlT, HV_BINOP_MULTIPLY, 1, m, &cBinop_WNdeunlT_sendMessage);
}

void Heavy_pod_test::cCast_8DRnyySH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_09Ethe8F_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_MxaL6ctg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kKCbuLTj, 1, m, &cVar_kKCbuLTj_sendMessage);
}

void Heavy_pod_test::cBinop_exmXmCeN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3tA9EflQ, HV_BINOP_ADD, 1, m, &cBinop_3tA9EflQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1nF1Ba5k, HV_BINOP_ADD, 1, m, &cBinop_1nF1Ba5k_sendMessage);
}

void Heavy_pod_test::cMsg_fQAlSgHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uyxKNNg3, HV_BINOP_MULTIPLY, 0, m, &cBinop_uyxKNNg3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_m07SQ4EM, HV_BINOP_DIVIDE, 1, m, &cBinop_m07SQ4EM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6OWqBh7Y, 0, m, &cVar_6OWqBh7Y_sendMessage);
}

void Heavy_pod_test::cCast_YBioI0MV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8DRnyySH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3tA9EflQ, HV_BINOP_ADD, 0, m, &cBinop_3tA9EflQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hRvFWVbn, 1, m, &cVar_hRvFWVbn_sendMessage);
}

void Heavy_pod_test::cBinop_oA9COVXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FgkTMWT3, HV_BINOP_SUBTRACT, 1, m, &cBinop_FgkTMWT3_sendMessage);
}

void Heavy_pod_test::cCast_hw96Iqho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yCMOQV6O, 0, m, &cVar_yCMOQV6O_sendMessage);
}

void Heavy_pod_test::cSlice_8PSuGcQG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_i4XglkmO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kusXHA0p_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_32oLhR5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_E27vuc8H_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4KDufybY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cMsg_vwcxfBWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_ziuRJbSo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_i4XglkmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WNdeunlT, HV_BINOP_MULTIPLY, 0, m, &cBinop_WNdeunlT_sendMessage);
}

void Heavy_pod_test::cVar_ony2VgxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FgkTMWT3, HV_BINOP_SUBTRACT, 0, m, &cBinop_FgkTMWT3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_QhanG4Ur_sendMessage);
}

void Heavy_pod_test::cSlice_Nxhj00OU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_vwcxfBWL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_vwcxfBWL_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_6iCxFvqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SdksBj6S_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YBioI0MV_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SdksBj6S_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YBioI0MV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSwitchcase_FqkVS0yU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Nxhj00OU, 0, m, &cSlice_Nxhj00OU_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6iCxFvqL, 0, m, &cSlice_6iCxFvqL_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QlJecbHD_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_8PSuGcQG, 0, m, &cSlice_8PSuGcQG_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_32oLhR5N, 0, m, &cSlice_32oLhR5N_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_frFQoZ0i_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f5TEc7tN_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cMsg_09Ethe8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_ziuRJbSo_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3tA9EflQ, HV_BINOP_ADD, 1, m, &cBinop_3tA9EflQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1nF1Ba5k, HV_BINOP_ADD, 1, m, &cBinop_1nF1Ba5k_sendMessage);
}

void Heavy_pod_test::cMsg_HQcWTSQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_ziuRJbSo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_1nF1Ba5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hRvFWVbn, 1, m, &cVar_hRvFWVbn_sendMessage);
}

void Heavy_pod_test::cVar_kKCbuLTj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_i4XglkmO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kusXHA0p_sendMessage);
}

void Heavy_pod_test::cVar_hRvFWVbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1nF1Ba5k, HV_BINOP_ADD, 0, m, &cBinop_1nF1Ba5k_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3tA9EflQ, HV_BINOP_ADD, 0, m, &cBinop_3tA9EflQ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZqIOnViw, m);
}

void Heavy_pod_test::cBinop_wcCpLEwc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LQZEZutE, 2, m, &cDelay_LQZEZutE_sendMessage);
}

void Heavy_pod_test::cBinop_OT5g8ooV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r70t6sC8, HV_BINOP_MULTIPLY, 1, m, &cBinop_r70t6sC8_sendMessage);
}

void Heavy_pod_test::cSwitchcase_ziuRJbSo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_DDDNMwgq_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_DDDNMwgq_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EdmUDHMS_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cMsg_DDDNMwgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LQZEZutE, 0, m, &cDelay_LQZEZutE_sendMessage);
}

void Heavy_pod_test::cVar_6OWqBh7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r70t6sC8, HV_BINOP_MULTIPLY, 0, m, &cBinop_r70t6sC8_sendMessage);
}

void Heavy_pod_test::cDelay_LQZEZutE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LQZEZutE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LQZEZutE, 0, m, &cDelay_LQZEZutE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ony2VgxB, 0, m, &cVar_ony2VgxB_sendMessage);
}

void Heavy_pod_test::cCast_EdmUDHMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DDDNMwgq_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LQZEZutE, 0, m, &cDelay_LQZEZutE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ony2VgxB, 0, m, &cVar_ony2VgxB_sendMessage);
}

void Heavy_pod_test::cBinop_r70t6sC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_wcCpLEwc_sendMessage);
}

void Heavy_pod_test::cMsg_di74TRcu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Gvgw9tWP_sendMessage);
}

void Heavy_pod_test::cSystem_Gvgw9tWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OT5g8ooV_sendMessage);
}

void Heavy_pod_test::cVar_K5yPiAkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0wWweOVy, HV_BINOP_SUBTRACT, 1, m, &cBinop_0wWweOVy_sendMessage);
}

void Heavy_pod_test::cCast_nWmtLZQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fQAlSgHd_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_uGE0ZKfd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nWmtLZQS_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_uyxKNNg3, HV_BINOP_MULTIPLY, 0, m, &cBinop_uyxKNNg3_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_m07SQ4EM, HV_BINOP_DIVIDE, 1, m, &cBinop_m07SQ4EM_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_6OWqBh7Y, 0, m, &cVar_6OWqBh7Y_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cCast_SdksBj6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vwcxfBWL_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_jhQ3EV84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j6wvQCsU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hw96Iqho_sendMessage);
}

void Heavy_pod_test::cCast_6gNNEvRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hRvFWVbn, 0, m, &cVar_hRvFWVbn_sendMessage);
}

void Heavy_pod_test::cSwitchcase_5dXlvPjD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6gNNEvRe_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jhQ3EV84_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cCast_kusXHA0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m07SQ4EM, HV_BINOP_DIVIDE, 0, m, &cBinop_m07SQ4EM_sendMessage);
}

void Heavy_pod_test::cCast_4KDufybY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0wWweOVy, HV_BINOP_SUBTRACT, 0, m, &cBinop_0wWweOVy_sendMessage);
}

void Heavy_pod_test::cCast_frFQoZ0i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HQcWTSQP_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_FgkTMWT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ony2VgxB, 1, m, &cVar_ony2VgxB_sendMessage);
}

void Heavy_pod_test::cVar_K6dxxTR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pod_test::cVar_XruCvhiu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_VA8bcvML_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sTwG1uSM, 0, m, &cVar_sTwG1uSM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fFL2jsWC, m);
}

void Heavy_pod_test::cBinop_VA8bcvML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 2.0f, 0, m, &cBinop_y7uFnIoF_sendMessage);
}

void Heavy_pod_test::cBinop_y7uFnIoF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XruCvhiu, 1, m, &cVar_XruCvhiu_sendMessage);
}

void Heavy_pod_test::cMsg_DjIuTofO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_Xd9EJk0N_sendMessage);
}

void Heavy_pod_test::cReceive_MgvaJih7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5RBSmIie_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0xfLzPuU, 0, m, &cVar_0xfLzPuU_sendMessage);
  cMsg_di74TRcu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6OWqBh7Y, 0, m, &cVar_6OWqBh7Y_sendMessage);
  cMsg_VFnQ82NR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MMS5h5MP, 0, m, &cVar_MMS5h5MP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rlJ8R5WK, 0, m, &cVar_rlJ8R5WK_sendMessage);
  cMsg_FzuRZLmt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_K5yPiAkC, 0, m, &cVar_K5yPiAkC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HqOV9Nig, 0, m, &cVar_HqOV9Nig_sendMessage);
  cMsg_vqhuLWeM_sendMessage(_c, 0, m);
  cMsg_gaTQOTQu_sendMessage(_c, 0, m);
  cMsg_5K8MluVN_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_yarcIcXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XruCvhiu, 0, m, &cVar_XruCvhiu_sendMessage);
}

void Heavy_pod_test::cMsg_sjJ9gRE4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_Z525OfWg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cReceive_rxL2Vz9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U4WX4zII_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JniK7oeu_sendMessage);
}

void Heavy_pod_test::cCast_zo11eAjS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Gc0e1gts_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_x9sh2yQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QPtwKSPh, m);
}




/*
 * Context Process Implementation
 */

int Heavy_pod_test::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_f(&sVarf_w1TiJG01, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_Gr6ZYW4t, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_s4aLbCTY, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_fFL2jsWC, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_phasor_f(&sPhasor_fQsmdrWC, VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf3), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf0), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_D5awyUJN, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_QPtwKSPh, VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_SfGBYeSZ, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf3), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_ZqIOnViw, VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_pod_test::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_pod_test::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
