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
  numBytes += sPhasor_k_init(&sPhasor_nLXU5XFi, 0.0f, sampleRate);
  numBytes += sPhasor_init(&sPhasor_rLXgTH26, sampleRate);
  numBytes += sPhasor_init(&sPhasor_xNMRHnhl, sampleRate);
  numBytes += cVar_init_f(&cVar_5yNgV8NB, 20.0f);
  numBytes += cBinop_init(&cBinop_g9KDEwJf, 20.0f); // __div
  numBytes += cSlice_init(&cSlice_khqS5bXq, 1, -1);
  numBytes += cSlice_init(&cSlice_Ag8BKf22, 1, -1);
  numBytes += cVar_init_f(&cVar_GbAY1sZu, 0.0f);
  numBytes += cBinop_init(&cBinop_19fHVpsx, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_XxCHylgi, 0.0f);
  numBytes += cSlice_init(&cSlice_i3ArZg8M, 1, 1);
  numBytes += cSlice_init(&cSlice_7z3lhuKh, 0, 1);
  numBytes += cBinop_init(&cBinop_zUr4GT2C, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_C5nAY5nZ, 20.0f);
  numBytes += cBinop_init(&cBinop_3JpdT1PO, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_DoUnrMnT, 0.0f);
  numBytes += cBinop_init(&cBinop_MJJ00ohR, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_XSEmxvUd, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_UiasHWVv, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Z0DPHHKX, 0.0f);
  numBytes += cBinop_init(&cBinop_kJp4cLpb, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eY3dZx2R, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_P8Nu5KFN, 0.0f);
  numBytes += cVar_init_f(&cVar_17Luo5P9, 0.0f);
  numBytes += sVarf_init(&sVarf_UAziP5on, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_PAxRvnKu, 0.0f);
  numBytes += sVarf_init(&sVarf_OE3OdJhK, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5icauPP8, 0.0f);
  numBytes += cVar_init_f(&cVar_Uj7EnUDq, 0.0f);
  numBytes += sVarf_init(&sVarf_fzxoCaOJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_svao7tpQ, 0.0f);
  numBytes += cVar_init_f(&cVar_6J3rpIMo, 0.0f);
  numBytes += cBinop_init(&cBinop_kz5KLFuv, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_2veCJGmW, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Ow5SEq4d, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_RVNUOEwd, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_qHoyY5ic, 0.0f);
  numBytes += cVar_init_f(&cVar_UOMJDx3w, 0.0f);
  numBytes += cBinop_init(&cBinop_HcB1qOAF, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_z2kdqjxL, 0.0f);
  numBytes += cBinop_init(&cBinop_VAfnjbDh, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_HgJwzIv4, 20.0f);
  numBytes += cBinop_init(&cBinop_9nsLI3Ig, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_UlLvTBbI, 0.0f);
  numBytes += cSlice_init(&cSlice_78T6Eljz, 1, -1);
  numBytes += cSlice_init(&cSlice_N9TrFY1X, 1, -1);
  numBytes += cVar_init_f(&cVar_GEyJKek6, 0.0f);
  numBytes += cSlice_init(&cSlice_bREMQ2tn, 0, 1);
  numBytes += cSlice_init(&cSlice_E5WjCXP6, 1, 1);
  numBytes += cVar_init_f(&cVar_A5ZvHy5x, 20.0f);
  numBytes += cVar_init_f(&cVar_DKOtRUPi, 0.0f);
  numBytes += cBinop_init(&cBinop_KwY8wtoe, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_9j47F4ip, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_DFU6A1gR, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_WdzmedFO, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Q8g2M6lS, 0.0f);
  numBytes += sVarf_init(&sVarf_7RHPfUSZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YaHDUIlp, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_22Zi2Oqz_sendMessage);
      break;
    }
    case 0x3FE62CA: { // Button2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sqop7LQi_sendMessage);
      break;
    }
    case 0x7AAC371F: { // EncSwitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FlSZF9Ub_sendMessage);
      break;
    }
    case 0x39ADE514: { // Encoder
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WP4bvGXU_sendMessage);
      break;
    }
    case 0x62DD3F82: { // Knob1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_a38l7S3N_sendMessage);
      break;
    }
    case 0x6BE4E001: { // Knob2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_afsoYAoD_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7xwpp2un_sendMessage);
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


void Heavy_pod_test::cCast_axY5nnxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KsfIqGR9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zUr4GT2C, HV_BINOP_ADD, 0, m, &cBinop_zUr4GT2C_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Z0DPHHKX, 1, m, &cVar_Z0DPHHKX_sendMessage);
}

void Heavy_pod_test::cVar_5yNgV8NB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_w8WiUMQs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_g9KDEwJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eY3dZx2R, HV_BINOP_DIVIDE, 1, m, &cBinop_eY3dZx2R_sendMessage);
}

void Heavy_pod_test::cSystem_XdmHrHrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UiasHWVv, HV_BINOP_MULTIPLY, 1, m, &cBinop_UiasHWVv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_19fHVpsx, HV_BINOP_MULTIPLY, 1, m, &cBinop_19fHVpsx_sendMessage);
}

void Heavy_pod_test::cMsg_I6bYagyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XdmHrHrK_sendMessage);
}

void Heavy_pod_test::cBinop_iZw51DjJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mIt9R5Ej_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_F18x8DpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JzFJDZMh_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_JzFJDZMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Uhrc0phW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cSlice_khqS5bXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_JzFJDZMh_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_JzFJDZMh_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSwitchcase_I1ZWwnFZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_khqS5bXq, 0, m, &cSlice_khqS5bXq_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ag8BKf22, 0, m, &cSlice_Ag8BKf22_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_csQ8uGc8_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_i3ArZg8M, 0, m, &cSlice_i3ArZg8M_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_7z3lhuKh, 0, m, &cSlice_7z3lhuKh_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Lh49pN46_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HJLP0kyj_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cSlice_Ag8BKf22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F18x8DpP_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_axY5nnxY_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F18x8DpP_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_axY5nnxY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cVar_GbAY1sZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kJp4cLpb, HV_BINOP_SUBTRACT, 0, m, &cBinop_kJp4cLpb_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_iZw51DjJ_sendMessage);
}

void Heavy_pod_test::cBinop_19fHVpsx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kk8CKPKT_sendMessage);
}

void Heavy_pod_test::cVar_XxCHylgi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RyO90rU5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rV8HjgTB_sendMessage);
}

void Heavy_pod_test::cSlice_i3ArZg8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RyO90rU5_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rV8HjgTB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_7z3lhuKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wEmUgxIP_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GmgoUBym_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cBinop_zUr4GT2C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_P8Nu5KFN, 0, m, &cVar_P8Nu5KFN_sendMessage);
}

void Heavy_pod_test::cCast_GiL5qOwa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IC9cfA04_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_KsfIqGR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IC9cfA04_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_tlaxLQYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7SKSyHti_sendMessage);
}

void Heavy_pod_test::cSystem_7SKSyHti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_d2Sdv6hJ_sendMessage);
}

void Heavy_pod_test::cBinop_d2Sdv6hJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3JpdT1PO, HV_BINOP_MULTIPLY, 1, m, &cBinop_3JpdT1PO_sendMessage);
}

void Heavy_pod_test::cMsg_tic36vmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DoUnrMnT, 0, m, &cDelay_DoUnrMnT_sendMessage);
}

void Heavy_pod_test::cVar_C5nAY5nZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3JpdT1PO, HV_BINOP_MULTIPLY, 0, m, &cBinop_3JpdT1PO_sendMessage);
}

void Heavy_pod_test::cBinop_3JpdT1PO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_PC0e3uru_sendMessage);
}

void Heavy_pod_test::cBinop_PC0e3uru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DoUnrMnT, 2, m, &cDelay_DoUnrMnT_sendMessage);
}

void Heavy_pod_test::cDelay_DoUnrMnT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DoUnrMnT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DoUnrMnT, 0, m, &cDelay_DoUnrMnT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GbAY1sZu, 0, m, &cVar_GbAY1sZu_sendMessage);
}

void Heavy_pod_test::cSwitchcase_Uhrc0phW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_tic36vmT_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_tic36vmT_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3y4VgoBA_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cCast_3y4VgoBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tic36vmT_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DoUnrMnT, 0, m, &cDelay_DoUnrMnT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GbAY1sZu, 0, m, &cVar_GbAY1sZu_sendMessage);
}

void Heavy_pod_test::cBinop_MJJ00ohR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z0DPHHKX, 1, m, &cVar_Z0DPHHKX_sendMessage);
}

void Heavy_pod_test::cBinop_XSEmxvUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eY3dZx2R, HV_BINOP_DIVIDE, 0, m, &cBinop_eY3dZx2R_sendMessage);
}

void Heavy_pod_test::cBinop_UiasHWVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nehLQG5V_sendMessage);
}

void Heavy_pod_test::cCast_rV8HjgTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g9KDEwJf, HV_BINOP_DIVIDE, 0, m, &cBinop_g9KDEwJf_sendMessage);
}

void Heavy_pod_test::cMsg_2stmShKa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UiasHWVv, HV_BINOP_MULTIPLY, 0, m, &cBinop_UiasHWVv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_g9KDEwJf, HV_BINOP_DIVIDE, 1, m, &cBinop_g9KDEwJf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_C5nAY5nZ, 0, m, &cVar_C5nAY5nZ_sendMessage);
}

void Heavy_pod_test::cBinop_kk8CKPKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GbAY1sZu, 1, m, &cVar_GbAY1sZu_sendMessage);
}

void Heavy_pod_test::cCast_wEmUgxIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_17Luo5P9, 1, m, &cVar_17Luo5P9_sendMessage);
}

void Heavy_pod_test::cVar_Z0DPHHKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MJJ00ohR, HV_BINOP_ADD, 0, m, &cBinop_MJJ00ohR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zUr4GT2C, HV_BINOP_ADD, 0, m, &cBinop_zUr4GT2C_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WdzmedFO, m);
}

void Heavy_pod_test::cBinop_kJp4cLpb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GbAY1sZu, 1, m, &cVar_GbAY1sZu_sendMessage);
}

void Heavy_pod_test::cMsg_IC9cfA04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Uhrc0phW_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zUr4GT2C, HV_BINOP_ADD, 1, m, &cBinop_zUr4GT2C_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MJJ00ohR, HV_BINOP_ADD, 1, m, &cBinop_MJJ00ohR_sendMessage);
}

void Heavy_pod_test::cBinop_eY3dZx2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zUr4GT2C, HV_BINOP_ADD, 1, m, &cBinop_zUr4GT2C_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MJJ00ohR, HV_BINOP_ADD, 1, m, &cBinop_MJJ00ohR_sendMessage);
}

void Heavy_pod_test::cCast_DBeqjexU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2stmShKa_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_w8WiUMQs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DBeqjexU_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_UiasHWVv, HV_BINOP_MULTIPLY, 0, m, &cBinop_UiasHWVv_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_g9KDEwJf, HV_BINOP_DIVIDE, 1, m, &cBinop_g9KDEwJf_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_C5nAY5nZ, 0, m, &cVar_C5nAY5nZ_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cVar_P8Nu5KFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XSEmxvUd, HV_BINOP_SUBTRACT, 1, m, &cBinop_XSEmxvUd_sendMessage);
}

void Heavy_pod_test::cMsg_xAK0NN2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Uhrc0phW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_csQ8uGc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XxCHylgi, 0, m, &cVar_XxCHylgi_sendMessage);
}

void Heavy_pod_test::cCast_Rf4qpySW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_17Luo5P9, 0, m, &cVar_17Luo5P9_sendMessage);
}

void Heavy_pod_test::cMsg_v9dGXD4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_XxCHylgi, 1, m, &cVar_XxCHylgi_sendMessage);
}

void Heavy_pod_test::cCast_HJLP0kyj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v9dGXD4o_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_RyO90rU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_19fHVpsx, HV_BINOP_MULTIPLY, 0, m, &cBinop_19fHVpsx_sendMessage);
}

void Heavy_pod_test::cCast_qyhxQk4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GiL5qOwa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rf4qpySW_sendMessage);
}

void Heavy_pod_test::cCast_PqoU3wkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z0DPHHKX, 0, m, &cVar_Z0DPHHKX_sendMessage);
}

void Heavy_pod_test::cSwitchcase_mIt9R5Ej_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PqoU3wkD_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qyhxQk4K_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cCast_GmgoUBym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XSEmxvUd, HV_BINOP_SUBTRACT, 0, m, &cBinop_XSEmxvUd_sendMessage);
}

void Heavy_pod_test::cVar_17Luo5P9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z0DPHHKX, 0, m, &cVar_Z0DPHHKX_sendMessage);
}

void Heavy_pod_test::cCast_Lh49pN46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xAK0NN2g_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_nehLQG5V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kJp4cLpb, HV_BINOP_SUBTRACT, 1, m, &cBinop_kJp4cLpb_sendMessage);
}

void Heavy_pod_test::cMsg_gJT8pGeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_Z5DTeixf_sendMessage);
}

void Heavy_pod_test::cMsg_7LWCJe7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_svao7tpQ, 0, m, &cVar_svao7tpQ_sendMessage);
}

void Heavy_pod_test::cBinop_Ci0cnbMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 2.0f, 0, m, &cBinop_AD3cZGGh_sendMessage);
}

void Heavy_pod_test::cBinop_AD3cZGGh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Uj7EnUDq, 1, m, &cVar_Uj7EnUDq_sendMessage);
}

void Heavy_pod_test::cVar_PAxRvnKu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pod_test::cReceive_7xwpp2un_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tlaxLQYV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_C5nAY5nZ, 0, m, &cVar_C5nAY5nZ_sendMessage);
  cMsg_7Ag2EWan_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HgJwzIv4, 0, m, &cVar_HgJwzIv4_sendMessage);
  cMsg_I6bYagyv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_P8Nu5KFN, 0, m, &cVar_P8Nu5KFN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5yNgV8NB, 0, m, &cVar_5yNgV8NB_sendMessage);
  cMsg_FUrQEpRO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GEyJKek6, 0, m, &cVar_GEyJKek6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_A5ZvHy5x, 0, m, &cVar_A5ZvHy5x_sendMessage);
  cMsg_2fkFRJTY_sendMessage(_c, 0, m);
  cMsg_ObDD4JDF_sendMessage(_c, 0, m);
  cMsg_7LWCJe7p_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_U4yFhdrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_I1ZWwnFZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cMsg_8424ObSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_Gv0Gw6R1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_nqF4Dk7v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iZB92oUI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eoLxI2VX_sendMessage);
}

void Heavy_pod_test::cCast_ida01k5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8424ObSJ_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_Q7KiMWSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Uj7EnUDq, 0, m, &cVar_Uj7EnUDq_sendMessage);
}

void Heavy_pod_test::cVar_5icauPP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pod_test::cReceive_sqop7LQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zGOJnLs7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ida01k5R_sendMessage);
}

void Heavy_pod_test::cReceive_a38l7S3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_Suglh6jo_sendMessage);
}

void Heavy_pod_test::cVar_Uj7EnUDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Ci0cnbMH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PAxRvnKu, 0, m, &cVar_PAxRvnKu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OE3OdJhK, m);
}

void Heavy_pod_test::cBinop_Z5DTeixf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kz5KLFuv, HV_BINOP_ADD, 0, m, &cBinop_kz5KLFuv_sendMessage);
}

void Heavy_pod_test::cReceive_afsoYAoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_8NuIPDSh_sendMessage);
}

void Heavy_pod_test::cMsg_75JAYIfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Gv0Gw6R1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cReceive_FlSZF9Ub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Uj7EnUDq, 0, m, &cVar_Uj7EnUDq_sendMessage);
}

void Heavy_pod_test::cVar_svao7tpQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kz5KLFuv, HV_BINOP_ADD, 1, m, &cBinop_kz5KLFuv_sendMessage);
}

void Heavy_pod_test::cMsg_BYCwxw0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_I1ZWwnFZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cVar_6J3rpIMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_8NuIPDSh_sendMessage);
}

void Heavy_pod_test::cBinop_8NuIPDSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UAziP5on, m);
}

void Heavy_pod_test::cReceive_22Zi2Oqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iZB92oUI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eoLxI2VX_sendMessage);
}

void Heavy_pod_test::cBinop_kz5KLFuv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5icauPP8, 0, m, &cVar_5icauPP8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_svao7tpQ, 0, m, &cVar_svao7tpQ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YaHDUIlp, m);
}

void Heavy_pod_test::cMsg_DWL4Mw8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_Z5DTeixf_sendMessage);
}

void Heavy_pod_test::cCast_iZB92oUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U4yFhdrQ_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_2fkFRJTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_nLXU5XFi, 0, m);
}

void Heavy_pod_test::cCast_lC1OyRrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zGOJnLs7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ida01k5R_sendMessage);
}

void Heavy_pod_test::cBinop_2veCJGmW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UlLvTBbI, 1, m, &cVar_UlLvTBbI_sendMessage);
}

void Heavy_pod_test::cCast_lxzXtzlK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9nsLI3Ig, HV_BINOP_MULTIPLY, 0, m, &cBinop_9nsLI3Ig_sendMessage);
}

void Heavy_pod_test::cCast_nnhVH9P3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xlcgbR3y_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_seCS54g8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iNHGHwM5_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_Ow5SEq4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UOMJDx3w, 1, m, &cVar_UOMJDx3w_sendMessage);
}

void Heavy_pod_test::cMsg_xlcgbR3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_DKOtRUPi, 1, m, &cVar_DKOtRUPi_sendMessage);
}

void Heavy_pod_test::cBinop_ydbeuK8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1BNSPRsf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cMsg_pD3bb1xb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_cYLz54cv_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KwY8wtoe, HV_BINOP_ADD, 1, m, &cBinop_KwY8wtoe_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2veCJGmW, HV_BINOP_ADD, 1, m, &cBinop_2veCJGmW_sendMessage);
}

void Heavy_pod_test::cSystem_wlxVhNNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HcB1qOAF, HV_BINOP_MULTIPLY, 1, m, &cBinop_HcB1qOAF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9nsLI3Ig, HV_BINOP_MULTIPLY, 1, m, &cBinop_9nsLI3Ig_sendMessage);
}

void Heavy_pod_test::cMsg_FUrQEpRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wlxVhNNs_sendMessage);
}

void Heavy_pod_test::cCast_y7chm5tH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pD3bb1xb_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_xvWbMJNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9j47F4ip, HV_BINOP_DIVIDE, 0, m, &cBinop_9j47F4ip_sendMessage);
}

void Heavy_pod_test::cBinop_JZNmXcxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UOMJDx3w, 1, m, &cVar_UOMJDx3w_sendMessage);
}

void Heavy_pod_test::cBinop_RVNUOEwd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DFU6A1gR, HV_BINOP_DIVIDE, 0, m, &cBinop_DFU6A1gR_sendMessage);
}

void Heavy_pod_test::cBinop_xehACsip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ow5SEq4d, HV_BINOP_SUBTRACT, 1, m, &cBinop_Ow5SEq4d_sendMessage);
}

void Heavy_pod_test::cCast_WCFzaoew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pD3bb1xb_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cVar_qHoyY5ic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UlLvTBbI, 0, m, &cVar_UlLvTBbI_sendMessage);
}

void Heavy_pod_test::cVar_UOMJDx3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ow5SEq4d, HV_BINOP_SUBTRACT, 0, m, &cBinop_Ow5SEq4d_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_ydbeuK8H_sendMessage);
}

void Heavy_pod_test::cBinop_HcB1qOAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xehACsip_sendMessage);
}

void Heavy_pod_test::cMsg_moYSdUqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_cYLz54cv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cMsg_GDSpZRwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HcB1qOAF, HV_BINOP_MULTIPLY, 0, m, &cBinop_HcB1qOAF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9j47F4ip, HV_BINOP_DIVIDE, 1, m, &cBinop_9j47F4ip_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HgJwzIv4, 0, m, &cVar_HgJwzIv4_sendMessage);
}

void Heavy_pod_test::cDelay_z2kdqjxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z2kdqjxL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z2kdqjxL, 0, m, &cDelay_z2kdqjxL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UOMJDx3w, 0, m, &cVar_UOMJDx3w_sendMessage);
}

void Heavy_pod_test::cBinop_ePsnHqPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z2kdqjxL, 2, m, &cDelay_z2kdqjxL_sendMessage);
}

void Heavy_pod_test::cMsg_7Ag2EWan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_agsXpmta_sendMessage);
}

void Heavy_pod_test::cSystem_agsXpmta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wIePkI8C_sendMessage);
}

void Heavy_pod_test::cBinop_VAfnjbDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ePsnHqPv_sendMessage);
}

void Heavy_pod_test::cBinop_wIePkI8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VAfnjbDh, HV_BINOP_MULTIPLY, 1, m, &cBinop_VAfnjbDh_sendMessage);
}

void Heavy_pod_test::cCast_24DTiiFf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B6fb886A_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z2kdqjxL, 0, m, &cDelay_z2kdqjxL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UOMJDx3w, 0, m, &cVar_UOMJDx3w_sendMessage);
}

void Heavy_pod_test::cSwitchcase_cYLz54cv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_B6fb886A_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_B6fb886A_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_24DTiiFf_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cMsg_B6fb886A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_z2kdqjxL, 0, m, &cDelay_z2kdqjxL_sendMessage);
}

void Heavy_pod_test::cVar_HgJwzIv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VAfnjbDh, HV_BINOP_MULTIPLY, 0, m, &cBinop_VAfnjbDh_sendMessage);
}

void Heavy_pod_test::cBinop_9nsLI3Ig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JZNmXcxb_sendMessage);
}

void Heavy_pod_test::cCast_ffdkAVfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qHoyY5ic, 0, m, &cVar_qHoyY5ic_sendMessage);
}

void Heavy_pod_test::cVar_UlLvTBbI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2veCJGmW, HV_BINOP_ADD, 0, m, &cBinop_2veCJGmW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KwY8wtoe, HV_BINOP_ADD, 0, m, &cBinop_KwY8wtoe_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fzxoCaOJ, m);
}

void Heavy_pod_test::cCast_Nq4NylJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_moYSdUqC_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_KoAj0BBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GDSpZRwP_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_x9qc3fXd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KoAj0BBo_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_HcB1qOAF, HV_BINOP_MULTIPLY, 0, m, &cBinop_HcB1qOAF_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_9j47F4ip, HV_BINOP_DIVIDE, 1, m, &cBinop_9j47F4ip_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_HgJwzIv4, 0, m, &cVar_HgJwzIv4_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cCast_VJVE33vj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RVNUOEwd, HV_BINOP_SUBTRACT, 0, m, &cBinop_RVNUOEwd_sendMessage);
}

void Heavy_pod_test::cSlice_78T6Eljz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_seCS54g8_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_58UKcRgE_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_seCS54g8_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_58UKcRgE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSwitchcase_Gv0Gw6R1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_N9TrFY1X, 0, m, &cSlice_N9TrFY1X_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_78T6Eljz, 0, m, &cSlice_78T6Eljz_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gwOeMPE8_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_E5WjCXP6, 0, m, &cSlice_E5WjCXP6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_bREMQ2tn, 0, m, &cSlice_bREMQ2tn_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Nq4NylJY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nnhVH9P3_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cSlice_N9TrFY1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_iNHGHwM5_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_iNHGHwM5_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cVar_GEyJKek6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RVNUOEwd, HV_BINOP_SUBTRACT, 1, m, &cBinop_RVNUOEwd_sendMessage);
}

void Heavy_pod_test::cSlice_bREMQ2tn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_m3SNlfVw_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VJVE33vj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_E5WjCXP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lxzXtzlK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xvWbMJNW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cVar_A5ZvHy5x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_x9qc3fXd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cVar_DKOtRUPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lxzXtzlK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xvWbMJNW_sendMessage);
}

void Heavy_pod_test::cBinop_KwY8wtoe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GEyJKek6, 0, m, &cVar_GEyJKek6_sendMessage);
}

void Heavy_pod_test::cCast_S6py8yid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y7chm5tH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ffdkAVfA_sendMessage);
}

void Heavy_pod_test::cCast_V6FCFgK7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UlLvTBbI, 0, m, &cVar_UlLvTBbI_sendMessage);
}

void Heavy_pod_test::cSwitchcase_1BNSPRsf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V6FCFgK7_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S6py8yid_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cMsg_iNHGHwM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_cYLz54cv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_9j47F4ip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DFU6A1gR, HV_BINOP_DIVIDE, 1, m, &cBinop_DFU6A1gR_sendMessage);
}

void Heavy_pod_test::cCast_m3SNlfVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qHoyY5ic, 1, m, &cVar_qHoyY5ic_sendMessage);
}

void Heavy_pod_test::cCast_58UKcRgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WCFzaoew_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KwY8wtoe, HV_BINOP_ADD, 0, m, &cBinop_KwY8wtoe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UlLvTBbI, 1, m, &cVar_UlLvTBbI_sendMessage);
}

void Heavy_pod_test::cBinop_DFU6A1gR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KwY8wtoe, HV_BINOP_ADD, 1, m, &cBinop_KwY8wtoe_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2veCJGmW, HV_BINOP_ADD, 1, m, &cBinop_2veCJGmW_sendMessage);
}

void Heavy_pod_test::cCast_gwOeMPE8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DKOtRUPi, 0, m, &cVar_DKOtRUPi_sendMessage);
}

void Heavy_pod_test::cVar_Q8g2M6lS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_Suglh6jo_sendMessage);
}

void Heavy_pod_test::cBinop_Suglh6jo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7RHPfUSZ, m);
}

void Heavy_pod_test::cMsg_ObDD4JDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Uj7EnUDq, 0, m, &cVar_Uj7EnUDq_sendMessage);
}

void Heavy_pod_test::cCast_eoLxI2VX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BYCwxw0p_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_zGOJnLs7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_75JAYIfD_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cReceive_WP4bvGXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_Z5DTeixf_sendMessage);
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
    __hv_varread_f(&sVarf_UAziP5on, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_nLXU5XFi, VOf(Bf1));
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
    __hv_varread_f(&sVarf_YaHDUIlp, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_OE3OdJhK, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_phasor_f(&sPhasor_rLXgTH26, VIf(Bf0), VOf(Bf0));
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
    __hv_varread_f(&sVarf_fzxoCaOJ, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O1), VOf(O1));
    __hv_varread_f(&sVarf_7RHPfUSZ, VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_xNMRHnhl, VIf(Bf2), VOf(Bf2));
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
    __hv_varread_f(&sVarf_WdzmedFO, VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));

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
