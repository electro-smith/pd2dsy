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
  numBytes += sPhasor_k_init(&sPhasor_az3ZC2ou, 0.0f, sampleRate);
  numBytes += sPhasor_init(&sPhasor_M8I1v7RF, sampleRate);
  numBytes += sPhasor_init(&sPhasor_w1yso8ek, sampleRate);
  numBytes += cVar_init_f(&cVar_QOH6SZrX, 0.0f);
  numBytes += sVarf_init(&sVarf_76SxjIU2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_utAO2pys, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VColkwpl, 0.0f);
  numBytes += cVar_init_f(&cVar_T8fk0TLZ, 0.0f);
  numBytes += cSlice_init(&cSlice_otsTdnkK, 1, -1);
  numBytes += cSlice_init(&cSlice_Ivt7YxUT, 1, -1);
  numBytes += cBinop_init(&cBinop_O8LkqKpE, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_c8w7TCPc, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_CtarF4kx, 20.0f);
  numBytes += cVar_init_f(&cVar_0fspoYl7, 0.0f);
  numBytes += cBinop_init(&cBinop_fuZPYYf5, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_0ZVvUtBs, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_1FoONory, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DcSol7tq, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_Q9MmKgog, 0.0f);
  numBytes += cVar_init_f(&cVar_nagHa2jU, 0.0f);
  numBytes += cVar_init_f(&cVar_L8Ey55RT, 0.0f);
  numBytes += cVar_init_f(&cVar_65qSzppH, 0.0f);
  numBytes += cSlice_init(&cSlice_zefvb2RY, 1, 1);
  numBytes += cSlice_init(&cSlice_BONB2k4R, 0, 1);
  numBytes += cBinop_init(&cBinop_aRiqpcZJ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_0CoKXmii, 0.0f);
  numBytes += cVar_init_f(&cVar_NqoMlBiE, 20.0f);
  numBytes += cBinop_init(&cBinop_FKz82hma, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_qSBs09bZ, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_OgwL9CKL, 0.0f);
  numBytes += cVar_init_f(&cVar_L0eX3Pbr, 0.0f);
  numBytes += sVarf_init(&sVarf_lbbuLk67, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_P8ou1P7x, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_fT8Jyo8A, 0.0f);
  numBytes += cVar_init_f(&cVar_LZB0Iegy, 20.0f);
  numBytes += cBinop_init(&cBinop_R8RSECM5, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_5QA9bKls, 0.0f);
  numBytes += cBinop_init(&cBinop_WlEoeWLh, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_i21j2CsJ, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_D2utCPpk, 1, -1);
  numBytes += cSlice_init(&cSlice_7LkybTvC, 1, -1);
  numBytes += cVar_init_f(&cVar_srNmHn66, 0.0f);
  numBytes += cVar_init_f(&cVar_LESkMzGR, 0.0f);
  numBytes += cVar_init_f(&cVar_jQk659tD, 0.0f);
  numBytes += cBinop_init(&cBinop_6LN21lIE, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_tZuAfoRV, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ZbPvdcnt, 0.0f);
  numBytes += cBinop_init(&cBinop_9vrQM6zn, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_o5rSQoOX, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_kf4gLFdd, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_IPjqHwyG, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_Ew7jMUOR, 20.0f);
  numBytes += cVar_init_f(&cVar_NgAkv28m, 0.0f);
  numBytes += cSlice_init(&cSlice_U6mzhDVq, 1, 1);
  numBytes += cSlice_init(&cSlice_QjOCfNL6, 0, 1);
  numBytes += sVarf_init(&sVarf_aEe30O2T, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Mx6qCCAn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cVQzJtij, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DJjKIdIH_sendMessage);
      break;
    }
    case 0x3FE62CA: { // Button2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_C0Wf33Z2_sendMessage);
      break;
    }
    case 0x7AAC371F: { // EncSwitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cecB7InQ_sendMessage);
      break;
    }
    case 0x39ADE514: { // Encoder
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ctgMPm08_sendMessage);
      break;
    }
    case 0x62DD3F82: { // Knob1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lySJWDdX_sendMessage);
      break;
    }
    case 0x6BE4E001: { // Knob2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JkzowGNZ_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TCbNTL8m_sendMessage);
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


void Heavy_pod_test::cMsg_I6uCvYyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_bozI8STt_sendMessage);
}

void Heavy_pod_test::cVar_QOH6SZrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_7Pt012Ej_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VColkwpl, 0, m, &cVar_VColkwpl_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_utAO2pys, m);
}

void Heavy_pod_test::cBinop_7Pt012Ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 2.0f, 0, m, &cBinop_vb4nFUEY_sendMessage);
}

void Heavy_pod_test::cCast_tM4U8LeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kyxwxPBi_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_JIQnpzcf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6XdR6i9Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tM4U8LeP_sendMessage);
}

void Heavy_pod_test::cReceive_JkzowGNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_gZy5LVqj_sendMessage);
}

void Heavy_pod_test::cMsg_F4cbR7XO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_3GZCpHAJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_vb4nFUEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QOH6SZrX, 1, m, &cVar_QOH6SZrX_sendMessage);
}

void Heavy_pod_test::cVar_VColkwpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pod_test::cCast_UIaemIve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sQgLHNMw_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_sQgLHNMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_3GZCpHAJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_gZy5LVqj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_76SxjIU2, m);
}

void Heavy_pod_test::cReceive_DJjKIdIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UIaemIve_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FfgJSgyU_sendMessage);
}

void Heavy_pod_test::cVar_T8fk0TLZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P8ou1P7x, HV_BINOP_ADD, 1, m, &cBinop_P8ou1P7x_sendMessage);
}

void Heavy_pod_test::cMsg_F1Jqlucp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_0fspoYl7, 1, m, &cVar_0fspoYl7_sendMessage);
}

void Heavy_pod_test::cCast_hvJiH4X3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q1rtwqPw_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSlice_otsTdnkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_oMmKZM2Q_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_oMmKZM2Q_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSwitchcase_iWHIbAfh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_otsTdnkK, 0, m, &cSlice_otsTdnkK_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ivt7YxUT, 0, m, &cSlice_Ivt7YxUT_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yGVXuYgI_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_zefvb2RY, 0, m, &cSlice_zefvb2RY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_BONB2k4R, 0, m, &cSlice_BONB2k4R_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hvJiH4X3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_11Ss6wgO_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cSlice_Ivt7YxUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cj7tIXzh_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UJg5QB6J_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cj7tIXzh_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UJg5QB6J_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cCast_cj7tIXzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oMmKZM2Q_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_11Ss6wgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F1Jqlucp_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_4GSm4TwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L8Ey55RT, 1, m, &cVar_L8Ey55RT_sendMessage);
}

void Heavy_pod_test::cCast_UJg5QB6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dNGI4LkC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fuZPYYf5, HV_BINOP_ADD, 0, m, &cBinop_fuZPYYf5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nagHa2jU, 1, m, &cVar_nagHa2jU_sendMessage);
}

void Heavy_pod_test::cBinop_O8LkqKpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fuZPYYf5, HV_BINOP_ADD, 1, m, &cBinop_fuZPYYf5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DcSol7tq, HV_BINOP_ADD, 1, m, &cBinop_DcSol7tq_sendMessage);
}

void Heavy_pod_test::cBinop_kdDqOMJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qSBs09bZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_qSBs09bZ_sendMessage);
}

void Heavy_pod_test::cCast_fZBwObfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L8Ey55RT, 0, m, &cVar_L8Ey55RT_sendMessage);
}

void Heavy_pod_test::cBinop_c8w7TCPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O8LkqKpE, HV_BINOP_DIVIDE, 1, m, &cBinop_O8LkqKpE_sendMessage);
}

void Heavy_pod_test::cMsg_oMmKZM2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_3JkPZFNP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cSystem_hS66HgLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1FoONory, HV_BINOP_MULTIPLY, 1, m, &cBinop_1FoONory_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0ZVvUtBs, HV_BINOP_MULTIPLY, 1, m, &cBinop_0ZVvUtBs_sendMessage);
}

void Heavy_pod_test::cMsg_ImXa6IAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hS66HgLU_sendMessage);
}

void Heavy_pod_test::cVar_CtarF4kx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_a3kPI9Ec_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_E2KyHijx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0ZVvUtBs, HV_BINOP_MULTIPLY, 0, m, &cBinop_0ZVvUtBs_sendMessage);
}

void Heavy_pod_test::cCast_UY10uftc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j3ERctA2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fZBwObfP_sendMessage);
}

void Heavy_pod_test::cCast_TnVDuIEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nagHa2jU, 0, m, &cVar_nagHa2jU_sendMessage);
}

void Heavy_pod_test::cSwitchcase_hvDm2U2n_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TnVDuIEf_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UY10uftc_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cVar_0fspoYl7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_E2KyHijx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QD4SagUH_sendMessage);
}

void Heavy_pod_test::cCast_QD4SagUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c8w7TCPc, HV_BINOP_DIVIDE, 0, m, &cBinop_c8w7TCPc_sendMessage);
}

void Heavy_pod_test::cCast_yGVXuYgI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0fspoYl7, 0, m, &cVar_0fspoYl7_sendMessage);
}

void Heavy_pod_test::cCast_j3ERctA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NaXOJabF_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_QPZiPLHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Q9MmKgog, 1, m, &cVar_Q9MmKgog_sendMessage);
}

void Heavy_pod_test::cBinop_fuZPYYf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_65qSzppH, 0, m, &cVar_65qSzppH_sendMessage);
}

void Heavy_pod_test::cBinop_0ZVvUtBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QPZiPLHE_sendMessage);
}

void Heavy_pod_test::cCast_yIaGNSeJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aRiqpcZJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_aRiqpcZJ_sendMessage);
}

void Heavy_pod_test::cBinop_1FoONory_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kdDqOMJs_sendMessage);
}

void Heavy_pod_test::cBinop_DcSol7tq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nagHa2jU, 1, m, &cVar_nagHa2jU_sendMessage);
}

void Heavy_pod_test::cVar_Q9MmKgog_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qSBs09bZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_qSBs09bZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_1vz6RtCG_sendMessage);
}

void Heavy_pod_test::cVar_nagHa2jU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DcSol7tq, HV_BINOP_ADD, 0, m, &cBinop_DcSol7tq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fuZPYYf5, HV_BINOP_ADD, 0, m, &cBinop_fuZPYYf5_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_aEe30O2T, m);
}

void Heavy_pod_test::cVar_L8Ey55RT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nagHa2jU, 0, m, &cVar_nagHa2jU_sendMessage);
}

void Heavy_pod_test::cCast_dNGI4LkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NaXOJabF_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cVar_65qSzppH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aRiqpcZJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_aRiqpcZJ_sendMessage);
}

void Heavy_pod_test::cSlice_zefvb2RY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_E2KyHijx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QD4SagUH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_BONB2k4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4GSm4TwD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yIaGNSeJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cBinop_aRiqpcZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O8LkqKpE, HV_BINOP_DIVIDE, 0, m, &cBinop_O8LkqKpE_sendMessage);
}

void Heavy_pod_test::cCast_ygdTN1yz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tLlhqjqv_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_a3kPI9Ec_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ygdTN1yz_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1FoONory, HV_BINOP_MULTIPLY, 0, m, &cBinop_1FoONory_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_c8w7TCPc, HV_BINOP_DIVIDE, 1, m, &cBinop_c8w7TCPc_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_NqoMlBiE, 0, m, &cVar_NqoMlBiE_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cDelay_0CoKXmii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0CoKXmii, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0CoKXmii, 0, m, &cDelay_0CoKXmii_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Q9MmKgog, 0, m, &cVar_Q9MmKgog_sendMessage);
}

void Heavy_pod_test::cBinop_dOrHROZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0CoKXmii, 2, m, &cDelay_0CoKXmii_sendMessage);
}

void Heavy_pod_test::cMsg_0BlJCFJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0CoKXmii, 0, m, &cDelay_0CoKXmii_sendMessage);
}

void Heavy_pod_test::cVar_NqoMlBiE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FKz82hma, HV_BINOP_MULTIPLY, 0, m, &cBinop_FKz82hma_sendMessage);
}

void Heavy_pod_test::cBinop_uD51uQQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FKz82hma, HV_BINOP_MULTIPLY, 1, m, &cBinop_FKz82hma_sendMessage);
}

void Heavy_pod_test::cBinop_FKz82hma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_dOrHROZY_sendMessage);
}

void Heavy_pod_test::cSwitchcase_3JkPZFNP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_0BlJCFJb_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_0BlJCFJb_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_N0aZKno5_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cCast_N0aZKno5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0BlJCFJb_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0CoKXmii, 0, m, &cDelay_0CoKXmii_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Q9MmKgog, 0, m, &cVar_Q9MmKgog_sendMessage);
}

void Heavy_pod_test::cMsg_ig4tndb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3NJ3KwLG_sendMessage);
}

void Heavy_pod_test::cSystem_3NJ3KwLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uD51uQQ9_sendMessage);
}

void Heavy_pod_test::cMsg_tLlhqjqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1FoONory, HV_BINOP_MULTIPLY, 0, m, &cBinop_1FoONory_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_c8w7TCPc, HV_BINOP_DIVIDE, 1, m, &cBinop_c8w7TCPc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NqoMlBiE, 0, m, &cVar_NqoMlBiE_sendMessage);
}

void Heavy_pod_test::cBinop_1vz6RtCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_hvDm2U2n_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_qSBs09bZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Q9MmKgog, 1, m, &cVar_Q9MmKgog_sendMessage);
}

void Heavy_pod_test::cMsg_NaXOJabF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_3JkPZFNP_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fuZPYYf5, HV_BINOP_ADD, 1, m, &cBinop_fuZPYYf5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DcSol7tq, HV_BINOP_ADD, 1, m, &cBinop_DcSol7tq_sendMessage);
}

void Heavy_pod_test::cMsg_Q1rtwqPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_3JkPZFNP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cVar_OgwL9CKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_CVpTKW0h_sendMessage);
}

void Heavy_pod_test::cReceive_C0Wf33Z2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6XdR6i9Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tM4U8LeP_sendMessage);
}

void Heavy_pod_test::cMsg_emQzHRDI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_iWHIbAfh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cVar_L0eX3Pbr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pod_test::cBinop_bozI8STt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P8ou1P7x, HV_BINOP_ADD, 0, m, &cBinop_P8ou1P7x_sendMessage);
}

void Heavy_pod_test::cMsg_sNwcAzVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_QOH6SZrX, 0, m, &cVar_QOH6SZrX_sendMessage);
}

void Heavy_pod_test::cBinop_P8ou1P7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L0eX3Pbr, 0, m, &cVar_L0eX3Pbr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_T8fk0TLZ, 0, m, &cVar_T8fk0TLZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Mx6qCCAn, m);
}

void Heavy_pod_test::cMsg_YNAQjn1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_bozI8STt_sendMessage);
}

void Heavy_pod_test::cCast_6dlerQ5a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UIaemIve_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FfgJSgyU_sendMessage);
}

void Heavy_pod_test::cVar_fT8Jyo8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_gZy5LVqj_sendMessage);
}

void Heavy_pod_test::cCast_ivCX9UTa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QOH6SZrX, 0, m, &cVar_QOH6SZrX_sendMessage);
}

void Heavy_pod_test::cCast_FfgJSgyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F4cbR7XO_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_kyxwxPBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_iWHIbAfh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_6XdR6i9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_emQzHRDI_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cReceive_ctgMPm08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_bozI8STt_sendMessage);
}

void Heavy_pod_test::cBinop_CVpTKW0h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cVQzJtij, m);
}

void Heavy_pod_test::cReceive_lySJWDdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_CVpTKW0h_sendMessage);
}

void Heavy_pod_test::cReceive_cecB7InQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QOH6SZrX, 0, m, &cVar_QOH6SZrX_sendMessage);
}

void Heavy_pod_test::cBinop_it2VggLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9vrQM6zn, HV_BINOP_SUBTRACT, 1, m, &cBinop_9vrQM6zn_sendMessage);
}

void Heavy_pod_test::cCast_hkD5vNs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jQk659tD, 1, m, &cVar_jQk659tD_sendMessage);
}

void Heavy_pod_test::cCast_TUO6pajd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o5rSQoOX, HV_BINOP_DIVIDE, 0, m, &cBinop_o5rSQoOX_sendMessage);
}

void Heavy_pod_test::cBinop_SDiA0vUV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5QA9bKls, 2, m, &cDelay_5QA9bKls_sendMessage);
}

void Heavy_pod_test::cBinop_KgdjuH90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R8RSECM5, HV_BINOP_MULTIPLY, 1, m, &cBinop_R8RSECM5_sendMessage);
}

void Heavy_pod_test::cSystem_RaeASMAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KgdjuH90_sendMessage);
}

void Heavy_pod_test::cMsg_un9VnXpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RaeASMAk_sendMessage);
}

void Heavy_pod_test::cVar_LZB0Iegy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R8RSECM5, HV_BINOP_MULTIPLY, 0, m, &cBinop_R8RSECM5_sendMessage);
}

void Heavy_pod_test::cCast_mSWAphR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UGHMuSSh_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5QA9bKls, 0, m, &cDelay_5QA9bKls_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZbPvdcnt, 0, m, &cVar_ZbPvdcnt_sendMessage);
}

void Heavy_pod_test::cBinop_R8RSECM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_SDiA0vUV_sendMessage);
}

void Heavy_pod_test::cMsg_UGHMuSSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5QA9bKls, 0, m, &cDelay_5QA9bKls_sendMessage);
}

void Heavy_pod_test::cSwitchcase_bq6FpnPC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_UGHMuSSh_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_UGHMuSSh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mSWAphR1_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cDelay_5QA9bKls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5QA9bKls, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5QA9bKls, 0, m, &cDelay_5QA9bKls_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZbPvdcnt, 0, m, &cVar_ZbPvdcnt_sendMessage);
}

void Heavy_pod_test::cCast_Y1Zo8ySr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NgAkv28m, 0, m, &cVar_NgAkv28m_sendMessage);
}

void Heavy_pod_test::cCast_7H6oHGWw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WlEoeWLh, HV_BINOP_SUBTRACT, 0, m, &cBinop_WlEoeWLh_sendMessage);
}

void Heavy_pod_test::cBinop_WlEoeWLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kf4gLFdd, HV_BINOP_DIVIDE, 0, m, &cBinop_kf4gLFdd_sendMessage);
}

void Heavy_pod_test::cCast_88HdXiLE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vezaZErs_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_i21j2CsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_it2VggLD_sendMessage);
}

void Heavy_pod_test::cSwitchcase_3GZCpHAJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7LkybTvC, 0, m, &cSlice_7LkybTvC_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_D2utCPpk, 0, m, &cSlice_D2utCPpk_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y1Zo8ySr_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_U6mzhDVq, 0, m, &cSlice_U6mzhDVq_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QjOCfNL6, 0, m, &cSlice_QjOCfNL6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_erCEyoyp_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yBpGm6wF_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cSlice_D2utCPpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_88HdXiLE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wNLRohPn_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_88HdXiLE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wNLRohPn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_7LkybTvC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_vezaZErs_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_vezaZErs_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cVar_srNmHn66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WlEoeWLh, HV_BINOP_SUBTRACT, 1, m, &cBinop_WlEoeWLh_sendMessage);
}

void Heavy_pod_test::cVar_LESkMzGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6LN21lIE, HV_BINOP_ADD, 0, m, &cBinop_6LN21lIE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IPjqHwyG, HV_BINOP_ADD, 0, m, &cBinop_IPjqHwyG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lbbuLk67, m);
}

void Heavy_pod_test::cVar_jQk659tD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LESkMzGR, 0, m, &cVar_LESkMzGR_sendMessage);
}

void Heavy_pod_test::cBinop_6LN21lIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LESkMzGR, 1, m, &cVar_LESkMzGR_sendMessage);
}

void Heavy_pod_test::cBinop_tZuAfoRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_r9oPGWBH_sendMessage);
}

void Heavy_pod_test::cVar_ZbPvdcnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9vrQM6zn, HV_BINOP_SUBTRACT, 0, m, &cBinop_9vrQM6zn_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_jSgHfZgc_sendMessage);
}

void Heavy_pod_test::cBinop_9vrQM6zn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZbPvdcnt, 1, m, &cVar_ZbPvdcnt_sendMessage);
}

void Heavy_pod_test::cCast_Rz51TSGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y1Wv1m36_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_axD9ceCb_sendMessage);
}

void Heavy_pod_test::cCast_J6nW3pHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LESkMzGR, 0, m, &cVar_LESkMzGR_sendMessage);
}

void Heavy_pod_test::cSwitchcase_tnds6xv2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J6nW3pHm_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rz51TSGo_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cCast_Y1Wv1m36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fz2NJJTG_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_N1bSU1gx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fz2NJJTG_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_ynP4bm4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_bq6FpnPC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_o5rSQoOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kf4gLFdd, HV_BINOP_DIVIDE, 1, m, &cBinop_kf4gLFdd_sendMessage);
}

void Heavy_pod_test::cMsg_fz2NJJTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_bq6FpnPC_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IPjqHwyG, HV_BINOP_ADD, 1, m, &cBinop_IPjqHwyG_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6LN21lIE, HV_BINOP_ADD, 1, m, &cBinop_6LN21lIE_sendMessage);
}

void Heavy_pod_test::cBinop_r9oPGWBH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZbPvdcnt, 1, m, &cVar_ZbPvdcnt_sendMessage);
}

void Heavy_pod_test::cBinop_kf4gLFdd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IPjqHwyG, HV_BINOP_ADD, 1, m, &cBinop_IPjqHwyG_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6LN21lIE, HV_BINOP_ADD, 1, m, &cBinop_6LN21lIE_sendMessage);
}

void Heavy_pod_test::cMsg_vezaZErs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_bq6FpnPC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_axD9ceCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jQk659tD, 0, m, &cVar_jQk659tD_sendMessage);
}

void Heavy_pod_test::cMsg_fmuAwaDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_NgAkv28m, 1, m, &cVar_NgAkv28m_sendMessage);
}

void Heavy_pod_test::cMsg_cH8RfBuP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_i21j2CsJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_i21j2CsJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_o5rSQoOX, HV_BINOP_DIVIDE, 1, m, &cBinop_o5rSQoOX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LZB0Iegy, 0, m, &cVar_LZB0Iegy_sendMessage);
}

void Heavy_pod_test::cBinop_IPjqHwyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_srNmHn66, 0, m, &cVar_srNmHn66_sendMessage);
}

void Heavy_pod_test::cCast_wNLRohPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_N1bSU1gx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IPjqHwyG, HV_BINOP_ADD, 0, m, &cBinop_IPjqHwyG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LESkMzGR, 1, m, &cVar_LESkMzGR_sendMessage);
}

void Heavy_pod_test::cVar_Ew7jMUOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XOV7D5AH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_eVg8Q7Hm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cH8RfBuP_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_XOV7D5AH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eVg8Q7Hm_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_i21j2CsJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_i21j2CsJ_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_o5rSQoOX, HV_BINOP_DIVIDE, 1, m, &cBinop_o5rSQoOX_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_LZB0Iegy, 0, m, &cVar_LZB0Iegy_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cCast_WIrjvcSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tZuAfoRV, HV_BINOP_MULTIPLY, 0, m, &cBinop_tZuAfoRV_sendMessage);
}

void Heavy_pod_test::cBinop_jSgHfZgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_tnds6xv2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cVar_NgAkv28m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WIrjvcSM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TUO6pajd_sendMessage);
}

void Heavy_pod_test::cSlice_U6mzhDVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WIrjvcSM_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TUO6pajd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_QjOCfNL6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hkD5vNs6_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7H6oHGWw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cCast_yBpGm6wF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fmuAwaDS_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_erCEyoyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ynP4bm4d_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSystem_VVq4mTl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i21j2CsJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_i21j2CsJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tZuAfoRV, HV_BINOP_MULTIPLY, 1, m, &cBinop_tZuAfoRV_sendMessage);
}

void Heavy_pod_test::cMsg_i9Zsp3Ov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VVq4mTl9_sendMessage);
}

void Heavy_pod_test::cMsg_qyLjctDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_az3ZC2ou, 0, m);
}

void Heavy_pod_test::cReceive_TCbNTL8m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_un9VnXpe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LZB0Iegy, 0, m, &cVar_LZB0Iegy_sendMessage);
  cMsg_ig4tndb5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NqoMlBiE, 0, m, &cVar_NqoMlBiE_sendMessage);
  cMsg_i9Zsp3Ov_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_srNmHn66, 0, m, &cVar_srNmHn66_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Ew7jMUOR, 0, m, &cVar_Ew7jMUOR_sendMessage);
  cMsg_ImXa6IAB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_65qSzppH, 0, m, &cVar_65qSzppH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CtarF4kx, 0, m, &cVar_CtarF4kx_sendMessage);
  cMsg_qyLjctDU_sendMessage(_c, 0, m);
  cMsg_sNwcAzVa_sendMessage(_c, 0, m);
  cMsg_tNCKgn5m_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_tNCKgn5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_T8fk0TLZ, 0, m, &cVar_T8fk0TLZ_sendMessage);
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
    __hv_varread_f(&sVarf_cVQzJtij, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_az3ZC2ou, VOf(Bf1));
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
    __hv_varread_f(&sVarf_Mx6qCCAn, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_utAO2pys, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_phasor_f(&sPhasor_M8I1v7RF, VIf(Bf0), VOf(Bf0));
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
    __hv_varread_f(&sVarf_lbbuLk67, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_76SxjIU2, VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_w1yso8ek, VIf(Bf2), VOf(Bf2));
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
    __hv_varread_f(&sVarf_aEe30O2T, VOf(Bf0));
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
