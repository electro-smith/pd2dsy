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
  numBytes += sPhasor_k_init(&sPhasor_SaBRc9ja, 0.0f, sampleRate);
  numBytes += sPhasor_init(&sPhasor_lmVQ54jn, sampleRate);
  numBytes += sPhasor_init(&sPhasor_KHoQ6k0Q, sampleRate);
  numBytes += sVarf_init(&sVarf_5heyqZqj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_6l8XipRe, 0.0f);
  numBytes += cVar_init_f(&cVar_hJpOXJ12, 0.0f);
  numBytes += cBinop_init(&cBinop_QRukWd1V, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_HUufdNNV, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_uSFOcaEY, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_dCaEfd40, 0.0f); // __add
  numBytes += cSlice_init(&cSlice_G0zewBA8, 1, -1);
  numBytes += cSlice_init(&cSlice_B5RYy1IZ, 1, -1);
  numBytes += cVar_init_f(&cVar_XFEuuGTq, 0.0f);
  numBytes += cVar_init_f(&cVar_xgkGQtcg, 20.0f);
  numBytes += cDelay_init(this, &cDelay_u4MbUghp, 0.0f);
  numBytes += cBinop_init(&cBinop_8xwUrCZk, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Wng8V6du, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ChxMxmqa, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Qgt12p7V, 20.0f);
  numBytes += cVar_init_f(&cVar_1SUiqwIi, 0.0f);
  numBytes += cVar_init_f(&cVar_MeoQXGPa, 0.0f);
  numBytes += cBinop_init(&cBinop_0JTKBPjT, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_jMqccK68, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_lqBl6P2i, 0, 1);
  numBytes += cSlice_init(&cSlice_KKbVROYR, 1, 1);
  numBytes += cVar_init_f(&cVar_oGzUpnHJ, 0.0f);
  numBytes += sVarf_init(&sVarf_Tn18nXmH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Z4cLfTT2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rKXvYFCo, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_gvlBfC3W, 0.0f);
  numBytes += cVar_init_f(&cVar_TJKysIVT, 0.0f);
  numBytes += sVarf_init(&sVarf_gnMgAX3B, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_d2hGZ3ld, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_HUkqsRUq, 0.0f);
  numBytes += cVar_init_f(&cVar_KquTuN9f, 20.0f);
  numBytes += cSlice_init(&cSlice_dx4Ig6Ty, 0, 1);
  numBytes += cSlice_init(&cSlice_MI1Bok0L, 1, 1);
  numBytes += cBinop_init(&cBinop_ozNHe3kE, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_YZWRxO9E, 20.0f);
  numBytes += cVar_init_f(&cVar_8YkWIO6I, 0.0f);
  numBytes += cBinop_init(&cBinop_l52C92Rd, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_VxZIj2sj, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_xC3oEbeq, 0.0f);
  numBytes += cBinop_init(&cBinop_hPff1HM5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9XSUtYT7, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_SyRV1LU7, 0.0f);
  numBytes += cBinop_init(&cBinop_DHloVatR, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_XUYILxQI, 0.0f);
  numBytes += cVar_init_f(&cVar_MtvKu94Z, 0.0f);
  numBytes += cSlice_init(&cSlice_wpv2HKcu, 1, -1);
  numBytes += cSlice_init(&cSlice_JVJaKDEO, 1, -1);
  numBytes += cBinop_init(&cBinop_jnmdKTTw, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_lHYbWcLb, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ylVyorh4, 0.0f);
  numBytes += cVar_init_f(&cVar_E3vMFx52, 0.0f);
  numBytes += sVarf_init(&sVarf_CrgDHAF3, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vbFLFdKb_sendMessage);
      break;
    }
    case 0x3FE62CA: { // Button2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YbFGyGur_sendMessage);
      break;
    }
    case 0x7AAC371F: { // EncSwitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rM1PWQ1b_sendMessage);
      break;
    }
    case 0x62DD3F82: { // Knob1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EcyOPryY_sendMessage);
      break;
    }
    case 0x6BE4E001: { // Knob2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1PKslP64_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9kGuzwfg_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_pod_test::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "Knob1";
        info->hash = 0x62DD3F82;
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
        info->name = "Knob2";
        info->hash = 0x6BE4E001;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 4: {
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
  return 5;
}



/*
 * Send Function Implementations
 */


void Heavy_pod_test::cCast_yamzEJ2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uSFOcaEY, HV_BINOP_DIVIDE, 0, m, &cBinop_uSFOcaEY_sendMessage);
}

void Heavy_pod_test::cCast_U6owIQVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vvejQ2DC_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_SsH63pYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XFEuuGTq, 0, m, &cVar_XFEuuGTq_sendMessage);
}

void Heavy_pod_test::cVar_6l8XipRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wng8V6du, HV_BINOP_SUBTRACT, 1, m, &cBinop_Wng8V6du_sendMessage);
}

void Heavy_pod_test::cVar_hJpOXJ12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HUufdNNV, HV_BINOP_SUBTRACT, 0, m, &cBinop_HUufdNNV_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_aDXBI5bU_sendMessage);
}

void Heavy_pod_test::cMsg_yz3wsKoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_teR6aDBd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_QRukWd1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0JTKBPjT, HV_BINOP_ADD, 1, m, &cBinop_0JTKBPjT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dCaEfd40, HV_BINOP_ADD, 1, m, &cBinop_dCaEfd40_sendMessage);
}

void Heavy_pod_test::cBinop_HUufdNNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hJpOXJ12, 1, m, &cVar_hJpOXJ12_sendMessage);
}

void Heavy_pod_test::cBinop_MqEZmJi4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hJpOXJ12, 1, m, &cVar_hJpOXJ12_sendMessage);
}

void Heavy_pod_test::cCast_Ul5xTGNa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eo9KSuBp_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0JTKBPjT, HV_BINOP_ADD, 0, m, &cBinop_0JTKBPjT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MeoQXGPa, 1, m, &cVar_MeoQXGPa_sendMessage);
}

void Heavy_pod_test::cBinop_uSFOcaEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QRukWd1V, HV_BINOP_DIVIDE, 1, m, &cBinop_QRukWd1V_sendMessage);
}

void Heavy_pod_test::cCast_SD20sT0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yz3wsKoZ_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_C0NrZhVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rlalJQyl_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_dCaEfd40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MeoQXGPa, 1, m, &cVar_MeoQXGPa_sendMessage);
}

void Heavy_pod_test::cCast_lXnOeRDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wng8V6du, HV_BINOP_SUBTRACT, 0, m, &cBinop_Wng8V6du_sendMessage);
}

void Heavy_pod_test::cSwitchcase_vSWYxfeK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_B5RYy1IZ, 0, m, &cSlice_B5RYy1IZ_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_G0zewBA8, 0, m, &cSlice_G0zewBA8_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SsH63pYE_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_KKbVROYR, 0, m, &cSlice_KKbVROYR_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lqBl6P2i, 0, m, &cSlice_lqBl6P2i_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U6owIQVi_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SXzfRdIu_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cSlice_G0zewBA8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SD20sT0g_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ul5xTGNa_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SD20sT0g_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ul5xTGNa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_B5RYy1IZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_yz3wsKoZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_yz3wsKoZ_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cBinop_5dwTnBhe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HUufdNNV, HV_BINOP_SUBTRACT, 1, m, &cBinop_HUufdNNV_sendMessage);
}

void Heavy_pod_test::cCast_SXzfRdIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ehch0926_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_vnEj0fmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1SUiqwIi, 0, m, &cVar_1SUiqwIi_sendMessage);
}

void Heavy_pod_test::cCast_2xgrLY2F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ChxMxmqa, HV_BINOP_MULTIPLY, 0, m, &cBinop_ChxMxmqa_sendMessage);
}

void Heavy_pod_test::cVar_XFEuuGTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2xgrLY2F_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yamzEJ2k_sendMessage);
}

void Heavy_pod_test::cCast_eo9KSuBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rlalJQyl_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_oBBha1OT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CmAzEzXp_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_Oa0t82vV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oBBha1OT_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_jMqccK68, HV_BINOP_MULTIPLY, 0, m, &cBinop_jMqccK68_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_uSFOcaEY, HV_BINOP_DIVIDE, 1, m, &cBinop_uSFOcaEY_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_xgkGQtcg, 0, m, &cVar_xgkGQtcg_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cSystem_Pa0yJIkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zuahl5ov_sendMessage);
}

void Heavy_pod_test::cMsg_w5tx2O7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Pa0yJIkw_sendMessage);
}

void Heavy_pod_test::cSwitchcase_teR6aDBd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_1salrjnF_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_1salrjnF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pa0yv6Fe_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cVar_xgkGQtcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8xwUrCZk, HV_BINOP_MULTIPLY, 0, m, &cBinop_8xwUrCZk_sendMessage);
}

void Heavy_pod_test::cDelay_u4MbUghp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_u4MbUghp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u4MbUghp, 0, m, &cDelay_u4MbUghp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hJpOXJ12, 0, m, &cVar_hJpOXJ12_sendMessage);
}

void Heavy_pod_test::cBinop_XsvkDdvD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_u4MbUghp, 2, m, &cDelay_u4MbUghp_sendMessage);
}

void Heavy_pod_test::cCast_pa0yv6Fe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1salrjnF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u4MbUghp, 0, m, &cDelay_u4MbUghp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hJpOXJ12, 0, m, &cVar_hJpOXJ12_sendMessage);
}

void Heavy_pod_test::cBinop_8xwUrCZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_XsvkDdvD_sendMessage);
}

void Heavy_pod_test::cBinop_zuahl5ov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8xwUrCZk, HV_BINOP_MULTIPLY, 1, m, &cBinop_8xwUrCZk_sendMessage);
}

void Heavy_pod_test::cMsg_1salrjnF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_u4MbUghp, 0, m, &cDelay_u4MbUghp_sendMessage);
}

void Heavy_pod_test::cBinop_Wng8V6du_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QRukWd1V, HV_BINOP_DIVIDE, 0, m, &cBinop_QRukWd1V_sendMessage);
}

void Heavy_pod_test::cBinop_ChxMxmqa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MqEZmJi4_sendMessage);
}

void Heavy_pod_test::cMsg_rlalJQyl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_teR6aDBd_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0JTKBPjT, HV_BINOP_ADD, 1, m, &cBinop_0JTKBPjT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dCaEfd40, HV_BINOP_ADD, 1, m, &cBinop_dCaEfd40_sendMessage);
}

void Heavy_pod_test::cMsg_vvejQ2DC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_teR6aDBd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_aDXBI5bU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JSWl4eoi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cVar_Qgt12p7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Oa0t82vV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_dZZxW4df_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1SUiqwIi, 1, m, &cVar_1SUiqwIi_sendMessage);
}

void Heavy_pod_test::cMsg_Ehch0926_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_XFEuuGTq, 1, m, &cVar_XFEuuGTq_sendMessage);
}

void Heavy_pod_test::cVar_1SUiqwIi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MeoQXGPa, 0, m, &cVar_MeoQXGPa_sendMessage);
}

void Heavy_pod_test::cVar_MeoQXGPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dCaEfd40, HV_BINOP_ADD, 0, m, &cBinop_dCaEfd40_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0JTKBPjT, HV_BINOP_ADD, 0, m, &cBinop_0JTKBPjT_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rKXvYFCo, m);
}

void Heavy_pod_test::cMsg_CmAzEzXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jMqccK68, HV_BINOP_MULTIPLY, 0, m, &cBinop_jMqccK68_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uSFOcaEY, HV_BINOP_DIVIDE, 1, m, &cBinop_uSFOcaEY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xgkGQtcg, 0, m, &cVar_xgkGQtcg_sendMessage);
}

void Heavy_pod_test::cCast_mpmXsuHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_C0NrZhVP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vnEj0fmw_sendMessage);
}

void Heavy_pod_test::cCast_CzftTujb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MeoQXGPa, 0, m, &cVar_MeoQXGPa_sendMessage);
}

void Heavy_pod_test::cSwitchcase_JSWl4eoi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CzftTujb_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mpmXsuHV_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cBinop_0JTKBPjT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6l8XipRe, 0, m, &cVar_6l8XipRe_sendMessage);
}

void Heavy_pod_test::cBinop_jMqccK68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5dwTnBhe_sendMessage);
}

void Heavy_pod_test::cSlice_lqBl6P2i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dZZxW4df_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lXnOeRDv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_KKbVROYR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2xgrLY2F_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yamzEJ2k_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSystem_0W7QMyTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jMqccK68, HV_BINOP_MULTIPLY, 1, m, &cBinop_jMqccK68_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ChxMxmqa, HV_BINOP_MULTIPLY, 1, m, &cBinop_ChxMxmqa_sendMessage);
}

void Heavy_pod_test::cMsg_iHQfDG0b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0W7QMyTr_sendMessage);
}

void Heavy_pod_test::cVar_oGzUpnHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_Sr0DY3gw_sendMessage);
}

void Heavy_pod_test::cMsg_TE0C22Gh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_SaBRc9ja, 0, m);
}

void Heavy_pod_test::cMsg_5f3BfHeI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_vSWYxfeK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_HT9AhEjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gvlBfC3W, 1, m, &cVar_gvlBfC3W_sendMessage);
}

void Heavy_pod_test::cCast_ejP3iFJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WUlvjWnX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PTI93DOX_sendMessage);
}

void Heavy_pod_test::cMsg_PrQHyjlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_vSWYxfeK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_Sr0DY3gw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CrgDHAF3, m);
}

void Heavy_pod_test::cReceive_vbFLFdKb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WUlvjWnX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PTI93DOX_sendMessage);
}

void Heavy_pod_test::cReceive_EcyOPryY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_Sr0DY3gw_sendMessage);
}

void Heavy_pod_test::cCast_WUlvjWnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dW5Yp4fG_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cReceive_YbFGyGur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tCXSkeWo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4kReowmx_sendMessage);
}

void Heavy_pod_test::cCast_tCXSkeWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5f3BfHeI_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_09wjUMpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tCXSkeWo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4kReowmx_sendMessage);
}

void Heavy_pod_test::cVar_gvlBfC3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Xf91weWe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_E3vMFx52, 0, m, &cVar_E3vMFx52_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_5heyqZqj, m);
}

void Heavy_pod_test::cVar_TJKysIVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_u6TQ0UBY_sendMessage);
}

void Heavy_pod_test::cBinop_Xf91weWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 2.0f, 0, m, &cBinop_HT9AhEjD_sendMessage);
}

void Heavy_pod_test::cCast_WS8Svw43_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gvlBfC3W, 0, m, &cVar_gvlBfC3W_sendMessage);
}

void Heavy_pod_test::cReceive_rM1PWQ1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gvlBfC3W, 0, m, &cVar_gvlBfC3W_sendMessage);
}

void Heavy_pod_test::cMsg_dW5Yp4fG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_48zVgGoN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_PTI93DOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qNXYfu50_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_qNXYfu50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_48zVgGoN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cMsg_bramYGKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_cMuT1fw6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_h68MsSo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x8c3obFT_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_FMywHr3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_onFFMfOk_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_y0r8augW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yhFhslNr_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_w0QwuYgU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y0r8augW_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_DHloVatR, HV_BINOP_MULTIPLY, 0, m, &cBinop_DHloVatR_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_l52C92Rd, HV_BINOP_DIVIDE, 1, m, &cBinop_l52C92Rd_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_KquTuN9f, 0, m, &cVar_KquTuN9f_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cCast_7K7xYdIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x8c3obFT_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_d2hGZ3ld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_eMSRJk4j_sendMessage);
}

void Heavy_pod_test::cSystem_hZ75LPtV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fMum2nIP_sendMessage);
}

void Heavy_pod_test::cMsg_O8eoFoRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hZ75LPtV_sendMessage);
}

void Heavy_pod_test::cDelay_HUkqsRUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HUkqsRUq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HUkqsRUq, 0, m, &cDelay_HUkqsRUq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XUYILxQI, 0, m, &cVar_XUYILxQI_sendMessage);
}

void Heavy_pod_test::cMsg_O5MXVaLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HUkqsRUq, 0, m, &cDelay_HUkqsRUq_sendMessage);
}

void Heavy_pod_test::cVar_KquTuN9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_d2hGZ3ld, HV_BINOP_MULTIPLY, 0, m, &cBinop_d2hGZ3ld_sendMessage);
}

void Heavy_pod_test::cBinop_fMum2nIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_d2hGZ3ld, HV_BINOP_MULTIPLY, 1, m, &cBinop_d2hGZ3ld_sendMessage);
}

void Heavy_pod_test::cSwitchcase_cMuT1fw6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_O5MXVaLh_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_O5MXVaLh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3V0I5Uri_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cBinop_eMSRJk4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HUkqsRUq, 2, m, &cDelay_HUkqsRUq_sendMessage);
}

void Heavy_pod_test::cCast_3V0I5Uri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O5MXVaLh_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HUkqsRUq, 0, m, &cDelay_HUkqsRUq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XUYILxQI, 0, m, &cVar_XUYILxQI_sendMessage);
}

void Heavy_pod_test::cMsg_onFFMfOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_8YkWIO6I, 1, m, &cVar_8YkWIO6I_sendMessage);
}

void Heavy_pod_test::cSlice_dx4Ig6Ty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oij3Ce2r_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xudxAgwX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_MI1Bok0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fIkJXbGo_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bAwhhShJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cBinop_ozNHe3kE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xC3oEbeq, 0, m, &cVar_xC3oEbeq_sendMessage);
}

void Heavy_pod_test::cMsg_x8c3obFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_cMuT1fw6_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ozNHe3kE, HV_BINOP_ADD, 1, m, &cBinop_ozNHe3kE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jnmdKTTw, HV_BINOP_ADD, 1, m, &cBinop_jnmdKTTw_sendMessage);
}

void Heavy_pod_test::cVar_YZWRxO9E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_w0QwuYgU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_iruQ3qyM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SyRV1LU7, 0, m, &cVar_SyRV1LU7_sendMessage);
}

void Heavy_pod_test::cVar_8YkWIO6I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fIkJXbGo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bAwhhShJ_sendMessage);
}

void Heavy_pod_test::cBinop_l52C92Rd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VxZIj2sj, HV_BINOP_DIVIDE, 1, m, &cBinop_VxZIj2sj_sendMessage);
}

void Heavy_pod_test::cBinop_ePiHACft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_a2C2tHJH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_fIkJXbGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lHYbWcLb, HV_BINOP_MULTIPLY, 0, m, &cBinop_lHYbWcLb_sendMessage);
}

void Heavy_pod_test::cCast_0kYXdthU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7K7xYdIB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iruQ3qyM_sendMessage);
}

void Heavy_pod_test::cCast_xguBgQ40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MtvKu94Z, 0, m, &cVar_MtvKu94Z_sendMessage);
}

void Heavy_pod_test::cSwitchcase_a2C2tHJH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xguBgQ40_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0kYXdthU_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cBinop_VxZIj2sj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ozNHe3kE, HV_BINOP_ADD, 1, m, &cBinop_ozNHe3kE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jnmdKTTw, HV_BINOP_ADD, 1, m, &cBinop_jnmdKTTw_sendMessage);
}

void Heavy_pod_test::cCast_YxLM56G0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8YkWIO6I, 0, m, &cVar_8YkWIO6I_sendMessage);
}

void Heavy_pod_test::cMsg_VcYJPTCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_cMuT1fw6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cVar_xC3oEbeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9XSUtYT7, HV_BINOP_SUBTRACT, 1, m, &cBinop_9XSUtYT7_sendMessage);
}

void Heavy_pod_test::cBinop_AlC0iIS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XUYILxQI, 1, m, &cVar_XUYILxQI_sendMessage);
}

void Heavy_pod_test::cBinop_hPff1HM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XUYILxQI, 1, m, &cVar_XUYILxQI_sendMessage);
}

void Heavy_pod_test::cCast_xudxAgwX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9XSUtYT7, HV_BINOP_SUBTRACT, 0, m, &cBinop_9XSUtYT7_sendMessage);
}

void Heavy_pod_test::cBinop_9XSUtYT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VxZIj2sj, HV_BINOP_DIVIDE, 0, m, &cBinop_VxZIj2sj_sendMessage);
}

void Heavy_pod_test::cVar_SyRV1LU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MtvKu94Z, 0, m, &cVar_MtvKu94Z_sendMessage);
}

void Heavy_pod_test::cBinop_DHloVatR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TNyKuKBY_sendMessage);
}

void Heavy_pod_test::cBinop_TNyKuKBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hPff1HM5, HV_BINOP_SUBTRACT, 1, m, &cBinop_hPff1HM5_sendMessage);
}

void Heavy_pod_test::cCast_liVJH6Q7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bramYGKJ_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_APr0uaNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h68MsSo0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ozNHe3kE, HV_BINOP_ADD, 0, m, &cBinop_ozNHe3kE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MtvKu94Z, 1, m, &cVar_MtvKu94Z_sendMessage);
}

void Heavy_pod_test::cVar_XUYILxQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hPff1HM5, HV_BINOP_SUBTRACT, 0, m, &cBinop_hPff1HM5_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_ePiHACft_sendMessage);
}

void Heavy_pod_test::cVar_MtvKu94Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jnmdKTTw, HV_BINOP_ADD, 0, m, &cBinop_jnmdKTTw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ozNHe3kE, HV_BINOP_ADD, 0, m, &cBinop_ozNHe3kE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Tn18nXmH, m);
}

void Heavy_pod_test::cCast_bAwhhShJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l52C92Rd, HV_BINOP_DIVIDE, 0, m, &cBinop_l52C92Rd_sendMessage);
}

void Heavy_pod_test::cCast_oij3Ce2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SyRV1LU7, 1, m, &cVar_SyRV1LU7_sendMessage);
}

void Heavy_pod_test::cMsg_yhFhslNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DHloVatR, HV_BINOP_MULTIPLY, 0, m, &cBinop_DHloVatR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_l52C92Rd, HV_BINOP_DIVIDE, 1, m, &cBinop_l52C92Rd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KquTuN9f, 0, m, &cVar_KquTuN9f_sendMessage);
}

void Heavy_pod_test::cSlice_wpv2HKcu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1Gq4MGlF_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_APr0uaNw_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1Gq4MGlF_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_APr0uaNw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSwitchcase_48zVgGoN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JVJaKDEO, 0, m, &cSlice_JVJaKDEO_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_wpv2HKcu, 0, m, &cSlice_wpv2HKcu_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YxLM56G0_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_MI1Bok0L, 0, m, &cSlice_MI1Bok0L_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dx4Ig6Ty, 0, m, &cSlice_dx4Ig6Ty_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_liVJH6Q7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FMywHr3L_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cSlice_JVJaKDEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_VcYJPTCU_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_VcYJPTCU_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cCast_1Gq4MGlF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VcYJPTCU_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSystem_1HYxyLba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DHloVatR, HV_BINOP_MULTIPLY, 1, m, &cBinop_DHloVatR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lHYbWcLb, HV_BINOP_MULTIPLY, 1, m, &cBinop_lHYbWcLb_sendMessage);
}

void Heavy_pod_test::cMsg_lzTLfpPI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1HYxyLba_sendMessage);
}

void Heavy_pod_test::cBinop_jnmdKTTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MtvKu94Z, 1, m, &cVar_MtvKu94Z_sendMessage);
}

void Heavy_pod_test::cBinop_lHYbWcLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AlC0iIS7_sendMessage);
}

void Heavy_pod_test::cVar_ylVyorh4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Z4cLfTT2, m);
}

void Heavy_pod_test::cBinop_u6TQ0UBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gnMgAX3B, m);
}

void Heavy_pod_test::cReceive_9kGuzwfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O8eoFoRy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KquTuN9f, 0, m, &cVar_KquTuN9f_sendMessage);
  cMsg_w5tx2O7G_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xgkGQtcg, 0, m, &cVar_xgkGQtcg_sendMessage);
  cMsg_lzTLfpPI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xC3oEbeq, 0, m, &cVar_xC3oEbeq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YZWRxO9E, 0, m, &cVar_YZWRxO9E_sendMessage);
  cMsg_iHQfDG0b_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6l8XipRe, 0, m, &cVar_6l8XipRe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Qgt12p7V, 0, m, &cVar_Qgt12p7V_sendMessage);
  cMsg_TE0C22Gh_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cVar_E3vMFx52_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pod_test::cCast_4kReowmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PrQHyjlV_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cReceive_1PKslP64_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_u6TQ0UBY_sendMessage);
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
    __hv_varread_f(&sVarf_Z4cLfTT2, VOf(Bf0));
    __hv_varread_f(&sVarf_CrgDHAF3, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_SaBRc9ja, VOf(Bf1));
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
    __hv_var_k_f(VOf(Bf4), 300.0f, 300.0f, 300.0f, 300.0f, 300.0f, 300.0f, 300.0f, 300.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_5heyqZqj, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_phasor_f(&sPhasor_lmVQ54jn, VIf(Bf0), VOf(Bf0));
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
    __hv_varread_f(&sVarf_Tn18nXmH, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_gnMgAX3B, VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_KHoQ6k0Q, VIf(Bf2), VOf(Bf2));
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
    __hv_varread_f(&sVarf_rKXvYFCo, VOf(Bf0));
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
