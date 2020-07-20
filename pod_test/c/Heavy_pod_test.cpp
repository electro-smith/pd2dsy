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
  numBytes += sPhasor_k_init(&sPhasor_wgt08Q8R, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_IEuOBkHg, 0.0f, sampleRate);
  numBytes += cBinop_init(&cBinop_uvrI0lxA, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_fqn2f6pJ, 20.0f);
  numBytes += cDelay_init(this, &cDelay_r3wfc2gC, 0.0f);
  numBytes += cBinop_init(&cBinop_SsGTD4qt, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_rbt3q7QT, 0.0f);
  numBytes += cBinop_init(&cBinop_Q0rAc6or, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_XeFObm9u, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_clhoXZIm, 0.0f);
  numBytes += cVar_init_f(&cVar_BOTxqYeJ, 20.0f);
  numBytes += cBinop_init(&cBinop_TKr9RQrX, 0.0f); // __add
  numBytes += cSlice_init(&cSlice_1V8c3WWR, 1, -1);
  numBytes += cSlice_init(&cSlice_wxTK81n9, 1, -1);
  numBytes += cBinop_init(&cBinop_DXAGwnaU, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_LfftyXBV, 0.0f);
  numBytes += cBinop_init(&cBinop_y5wZtZMV, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_O22SfyAR, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_d1IInGFK, 0.0f);
  numBytes += cVar_init_f(&cVar_2BBatLhu, 0.0f);
  numBytes += cSlice_init(&cSlice_feWDzIvw, 1, 1);
  numBytes += cSlice_init(&cSlice_2Ih2kQdt, 0, 1);
  numBytes += cBinop_init(&cBinop_uUBSgpcG, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_sbD18Una, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ea3mFglU, 20.0f);
  numBytes += cDelay_init(this, &cDelay_EbkMuX0a, 0.0f);
  numBytes += cBinop_init(&cBinop_3wH3Os3y, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ortzPWrz, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_pEfFjgy8, 0.0f);
  numBytes += cBinop_init(&cBinop_oKgst4sr, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_mex45UFr, 0.0f);
  numBytes += cBinop_init(&cBinop_Ygup5zRr, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_v6HwXBEt, 0.0f);
  numBytes += cBinop_init(&cBinop_5aGP1yO6, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_DdZu1MJb, 20.0f);
  numBytes += cBinop_init(&cBinop_qwcmHfvm, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_HYwPCAby, 1, 1);
  numBytes += cSlice_init(&cSlice_XJydnaDP, 0, 1);
  numBytes += cBinop_init(&cBinop_F9hJzoQy, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_MmG5CZju, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_t79Lzk1t, 0.0f);
  numBytes += cBinop_init(&cBinop_F0VLvBOu, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_UHnFLeyp, 1, -1);
  numBytes += cSlice_init(&cSlice_0zb1aY7t, 1, -1);
  numBytes += cVar_init_f(&cVar_SHDNELmg, 0.0f);
  numBytes += sVarf_init(&sVarf_OpOzS14g, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Vd5dBasc_sendMessage);
      break;
    }
    case 0x3FE62CA: { // Button2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CYV6Bh9u_sendMessage);
      break;
    }
    case 0x62DD3F82: { // Knob1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2Sfibbne_sendMessage);
      break;
    }
    case 0x6BE4E001: { // Knob2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xwi6MaNj_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KD9hl7DB_sendMessage);
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
        info->maxVal = 2000.0f;
        info->defaultVal = 440.0f;
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
        info->maxVal = 2000.0f;
        info->defaultVal = 440.0f;
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
  return 4;
}



/*
 * Send Function Implementations
 */


void Heavy_pod_test::cCast_69zLgQYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V2nUFEm9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZqGBoKlw_sendMessage);
}

void Heavy_pod_test::cCast_PGwTbUVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rbt3q7QT, 0, m, &cVar_rbt3q7QT_sendMessage);
}

void Heavy_pod_test::cSwitchcase_qCrc7y9r_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PGwTbUVW_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_69zLgQYd_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cCast_Krnc6BV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9QeEBtLb_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_zRsGdIQe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Krnc6BV5_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SsGTD4qt, HV_BINOP_MULTIPLY, 0, m, &cBinop_SsGTD4qt_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_XeFObm9u, HV_BINOP_DIVIDE, 1, m, &cBinop_XeFObm9u_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_fqn2f6pJ, 0, m, &cVar_fqn2f6pJ_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cMsg_9QeEBtLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SsGTD4qt, HV_BINOP_MULTIPLY, 0, m, &cBinop_SsGTD4qt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XeFObm9u, HV_BINOP_DIVIDE, 1, m, &cBinop_XeFObm9u_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fqn2f6pJ, 0, m, &cVar_fqn2f6pJ_sendMessage);
}

void Heavy_pod_test::cMsg_Ja8sphKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_rfqC9MU2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_cL0dYOCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_clhoXZIm, 1, m, &cVar_clhoXZIm_sendMessage);
}

void Heavy_pod_test::cCast_9LwUUnRG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dYkgI3kY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q0rAc6or, HV_BINOP_ADD, 0, m, &cBinop_Q0rAc6or_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rbt3q7QT, 1, m, &cVar_rbt3q7QT_sendMessage);
}

void Heavy_pod_test::cBinop_uvrI0lxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_oWrSgwBy_sendMessage);
}

void Heavy_pod_test::cSwitchcase_rfqC9MU2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_iS4jEquu_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_iS4jEquu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CHxbV0ad_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cBinop_gRmjQQRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uvrI0lxA, HV_BINOP_MULTIPLY, 1, m, &cBinop_uvrI0lxA_sendMessage);
}

void Heavy_pod_test::cCast_CHxbV0ad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iS4jEquu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_r3wfc2gC, 0, m, &cDelay_r3wfc2gC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LfftyXBV, 0, m, &cVar_LfftyXBV_sendMessage);
}

void Heavy_pod_test::cVar_fqn2f6pJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uvrI0lxA, HV_BINOP_MULTIPLY, 0, m, &cBinop_uvrI0lxA_sendMessage);
}

void Heavy_pod_test::cBinop_oWrSgwBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_r3wfc2gC, 2, m, &cDelay_r3wfc2gC_sendMessage);
}

void Heavy_pod_test::cSystem_QzBjXMUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gRmjQQRJ_sendMessage);
}

void Heavy_pod_test::cMsg_sPTgyJhp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QzBjXMUw_sendMessage);
}

void Heavy_pod_test::cDelay_r3wfc2gC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_r3wfc2gC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_r3wfc2gC, 0, m, &cDelay_r3wfc2gC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LfftyXBV, 0, m, &cVar_LfftyXBV_sendMessage);
}

void Heavy_pod_test::cMsg_iS4jEquu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_r3wfc2gC, 0, m, &cDelay_r3wfc2gC_sendMessage);
}

void Heavy_pod_test::cBinop_SsGTD4qt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MPQclVn9_sendMessage);
}

void Heavy_pod_test::cMsg_JogE89OP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_rfqC9MU2_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q0rAc6or, HV_BINOP_ADD, 1, m, &cBinop_Q0rAc6or_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TKr9RQrX, HV_BINOP_ADD, 1, m, &cBinop_TKr9RQrX_sendMessage);
}

void Heavy_pod_test::cCast_2KM0EIrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DXAGwnaU, HV_BINOP_SUBTRACT, 0, m, &cBinop_DXAGwnaU_sendMessage);
}

void Heavy_pod_test::cVar_rbt3q7QT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TKr9RQrX, HV_BINOP_ADD, 0, m, &cBinop_TKr9RQrX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q0rAc6or, HV_BINOP_ADD, 0, m, &cBinop_Q0rAc6or_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_sbD18Una, m);
}

void Heavy_pod_test::cBinop_Q0rAc6or_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d1IInGFK, 0, m, &cVar_d1IInGFK_sendMessage);
}

void Heavy_pod_test::cCast_KWDAvyHW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2BBatLhu, 0, m, &cVar_2BBatLhu_sendMessage);
}

void Heavy_pod_test::cBinop_XeFObm9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O22SfyAR, HV_BINOP_DIVIDE, 1, m, &cBinop_O22SfyAR_sendMessage);
}

void Heavy_pod_test::cVar_clhoXZIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rbt3q7QT, 0, m, &cVar_rbt3q7QT_sendMessage);
}

void Heavy_pod_test::cVar_BOTxqYeJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zRsGdIQe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_AnKaOq7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7Y3TV6ld_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_MPQclVn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uUBSgpcG, HV_BINOP_SUBTRACT, 1, m, &cBinop_uUBSgpcG_sendMessage);
}

void Heavy_pod_test::cCast_RPbhABd6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ja8sphKQ_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_dukRUxgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XeFObm9u, HV_BINOP_DIVIDE, 0, m, &cBinop_XeFObm9u_sendMessage);
}

void Heavy_pod_test::cCast_dYkgI3kY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JogE89OP_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_TKr9RQrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rbt3q7QT, 1, m, &cVar_rbt3q7QT_sendMessage);
}

void Heavy_pod_test::cSwitchcase_77eKXL7F_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1V8c3WWR, 0, m, &cSlice_1V8c3WWR_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_wxTK81n9, 0, m, &cSlice_wxTK81n9_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KWDAvyHW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_feWDzIvw, 0, m, &cSlice_feWDzIvw_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_2Ih2kQdt, 0, m, &cSlice_2Ih2kQdt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RPbhABd6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JBPyw0kH_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cSlice_1V8c3WWR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_7Y3TV6ld_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_7Y3TV6ld_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_wxTK81n9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AnKaOq7J_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9LwUUnRG_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AnKaOq7J_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9LwUUnRG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cMsg_7Y3TV6ld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_rfqC9MU2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cMsg_YA06KR03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_2BBatLhu, 1, m, &cVar_2BBatLhu_sendMessage);
}

void Heavy_pod_test::cBinop_DXAGwnaU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O22SfyAR, HV_BINOP_DIVIDE, 0, m, &cBinop_O22SfyAR_sendMessage);
}

void Heavy_pod_test::cVar_LfftyXBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uUBSgpcG, HV_BINOP_SUBTRACT, 0, m, &cBinop_uUBSgpcG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_9X6AlxKQ_sendMessage);
}

void Heavy_pod_test::cBinop_9X6AlxKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qCrc7y9r_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_JBPyw0kH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YA06KR03_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_y5wZtZMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zUUrS36D_sendMessage);
}

void Heavy_pod_test::cBinop_zUUrS36D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LfftyXBV, 1, m, &cVar_LfftyXBV_sendMessage);
}

void Heavy_pod_test::cMsg_NyFDUXwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5LPYaplW_sendMessage);
}

void Heavy_pod_test::cSystem_5LPYaplW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SsGTD4qt, HV_BINOP_MULTIPLY, 1, m, &cBinop_SsGTD4qt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_y5wZtZMV, HV_BINOP_MULTIPLY, 1, m, &cBinop_y5wZtZMV_sendMessage);
}

void Heavy_pod_test::cBinop_O22SfyAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q0rAc6or, HV_BINOP_ADD, 1, m, &cBinop_Q0rAc6or_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TKr9RQrX, HV_BINOP_ADD, 1, m, &cBinop_TKr9RQrX_sendMessage);
}

void Heavy_pod_test::cCast_ZqGBoKlw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_clhoXZIm, 0, m, &cVar_clhoXZIm_sendMessage);
}

void Heavy_pod_test::cVar_d1IInGFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DXAGwnaU, HV_BINOP_SUBTRACT, 1, m, &cBinop_DXAGwnaU_sendMessage);
}

void Heavy_pod_test::cVar_2BBatLhu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_E0KKKbp7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dukRUxgD_sendMessage);
}

void Heavy_pod_test::cCast_V2nUFEm9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JogE89OP_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSlice_feWDzIvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_E0KKKbp7_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dukRUxgD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_2Ih2kQdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cL0dYOCZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2KM0EIrZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cCast_E0KKKbp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y5wZtZMV, HV_BINOP_MULTIPLY, 0, m, &cBinop_y5wZtZMV_sendMessage);
}

void Heavy_pod_test::cBinop_uUBSgpcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LfftyXBV, 1, m, &cVar_LfftyXBV_sendMessage);
}

void Heavy_pod_test::cMsg_XMYJsE03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_lPXt7Tzy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cReceive_xwi6MaNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_wgt08Q8R, 0, m);
}

void Heavy_pod_test::cMsg_2HnjTtQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_77eKXL7F_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_NQBIZ5qC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3wH3Os3y, HV_BINOP_MULTIPLY, 1, m, &cBinop_3wH3Os3y_sendMessage);
}

void Heavy_pod_test::cBinop_gdwHmtxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EbkMuX0a, 2, m, &cDelay_EbkMuX0a_sendMessage);
}

void Heavy_pod_test::cMsg_V1w1u22o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_EbkMuX0a, 0, m, &cDelay_EbkMuX0a_sendMessage);
}

void Heavy_pod_test::cCast_I4IDkZOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V1w1u22o_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EbkMuX0a, 0, m, &cDelay_EbkMuX0a_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SHDNELmg, 0, m, &cVar_SHDNELmg_sendMessage);
}

void Heavy_pod_test::cSwitchcase_aCKu1geI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_V1w1u22o_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_V1w1u22o_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I4IDkZOj_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cVar_ea3mFglU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3wH3Os3y, HV_BINOP_MULTIPLY, 0, m, &cBinop_3wH3Os3y_sendMessage);
}

void Heavy_pod_test::cDelay_EbkMuX0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EbkMuX0a, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EbkMuX0a, 0, m, &cDelay_EbkMuX0a_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SHDNELmg, 0, m, &cVar_SHDNELmg_sendMessage);
}

void Heavy_pod_test::cBinop_3wH3Os3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_gdwHmtxS_sendMessage);
}

void Heavy_pod_test::cSystem_Re1RprFf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NQBIZ5qC_sendMessage);
}

void Heavy_pod_test::cMsg_YfD0ABJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Re1RprFf_sendMessage);
}

void Heavy_pod_test::cBinop_9htATmVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SHDNELmg, 1, m, &cVar_SHDNELmg_sendMessage);
}

void Heavy_pod_test::cBinop_ortzPWrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t79Lzk1t, 1, m, &cVar_t79Lzk1t_sendMessage);
}

void Heavy_pod_test::cCast_eyuK3YWR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pOu4iCXx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RaZgeiHm_sendMessage);
}

void Heavy_pod_test::cCast_ZsYgeZzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t79Lzk1t, 0, m, &cVar_t79Lzk1t_sendMessage);
}

void Heavy_pod_test::cSwitchcase_4s6xI9AU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZsYgeZzL_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eyuK3YWR_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cBinop_iIUTxvn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5aGP1yO6, HV_BINOP_SUBTRACT, 1, m, &cBinop_5aGP1yO6_sendMessage);
}

void Heavy_pod_test::cCast_GYUA6ARG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wdX2hOft_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_sLzwUWnP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GYUA6ARG_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MmG5CZju, HV_BINOP_MULTIPLY, 0, m, &cBinop_MmG5CZju_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_F9hJzoQy, HV_BINOP_DIVIDE, 1, m, &cBinop_F9hJzoQy_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_ea3mFglU, 0, m, &cVar_ea3mFglU_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cVar_pEfFjgy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ygup5zRr, HV_BINOP_SUBTRACT, 1, m, &cBinop_Ygup5zRr_sendMessage);
}

void Heavy_pod_test::cBinop_pryPvIKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4s6xI9AU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_x3t0QW5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F9hJzoQy, HV_BINOP_DIVIDE, 0, m, &cBinop_F9hJzoQy_sendMessage);
}

void Heavy_pod_test::cCast_sGkShztG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VvimoYjz_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_wdX2hOft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MmG5CZju, HV_BINOP_MULTIPLY, 0, m, &cBinop_MmG5CZju_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_F9hJzoQy, HV_BINOP_DIVIDE, 1, m, &cBinop_F9hJzoQy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ea3mFglU, 0, m, &cVar_ea3mFglU_sendMessage);
}

void Heavy_pod_test::cBinop_oKgst4sr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pEfFjgy8, 0, m, &cVar_pEfFjgy8_sendMessage);
}

void Heavy_pod_test::cMsg_Dd9Hzsau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_aCKu1geI_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oKgst4sr, HV_BINOP_ADD, 1, m, &cBinop_oKgst4sr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ortzPWrz, HV_BINOP_ADD, 1, m, &cBinop_ortzPWrz_sendMessage);
}

void Heavy_pod_test::cVar_mex45UFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vMzVSagT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_x3t0QW5Z_sendMessage);
}

void Heavy_pod_test::cCast_pOu4iCXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dd9Hzsau_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_kvy2yJnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oflAogm6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oKgst4sr, HV_BINOP_ADD, 0, m, &cBinop_oKgst4sr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_t79Lzk1t, 1, m, &cVar_t79Lzk1t_sendMessage);
}

void Heavy_pod_test::cCast_cuhlQbF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jP5Pn2yG_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_Ygup5zRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F0VLvBOu, HV_BINOP_DIVIDE, 0, m, &cBinop_F0VLvBOu_sendMessage);
}

void Heavy_pod_test::cVar_v6HwXBEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t79Lzk1t, 0, m, &cVar_t79Lzk1t_sendMessage);
}

void Heavy_pod_test::cBinop_5aGP1yO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SHDNELmg, 1, m, &cVar_SHDNELmg_sendMessage);
}

void Heavy_pod_test::cCast_i15QE2yO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_v6HwXBEt, 1, m, &cVar_v6HwXBEt_sendMessage);
}

void Heavy_pod_test::cVar_DdZu1MJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sLzwUWnP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_qwcmHfvm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9htATmVz_sendMessage);
}

void Heavy_pod_test::cSlice_HYwPCAby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vMzVSagT_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_x3t0QW5Z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_XJydnaDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_i15QE2yO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wolOLB05_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cBinop_F9hJzoQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F0VLvBOu, HV_BINOP_DIVIDE, 1, m, &cBinop_F0VLvBOu_sendMessage);
}

void Heavy_pod_test::cMsg_VvimoYjz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_aCKu1geI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_zh2754ge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pIfwyFJI_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_fIGFi3FQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mex45UFr, 0, m, &cVar_mex45UFr_sendMessage);
}

void Heavy_pod_test::cCast_vMzVSagT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qwcmHfvm, HV_BINOP_MULTIPLY, 0, m, &cBinop_qwcmHfvm_sendMessage);
}

void Heavy_pod_test::cCast_RaZgeiHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_v6HwXBEt, 0, m, &cVar_v6HwXBEt_sendMessage);
}

void Heavy_pod_test::cBinop_MmG5CZju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iIUTxvn3_sendMessage);
}

void Heavy_pod_test::cVar_t79Lzk1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ortzPWrz, HV_BINOP_ADD, 0, m, &cBinop_ortzPWrz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oKgst4sr, HV_BINOP_ADD, 0, m, &cBinop_oKgst4sr_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OpOzS14g, m);
}

void Heavy_pod_test::cCast_wolOLB05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ygup5zRr, HV_BINOP_SUBTRACT, 0, m, &cBinop_Ygup5zRr_sendMessage);
}

void Heavy_pod_test::cSystem_mq7OD5zo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MmG5CZju, HV_BINOP_MULTIPLY, 1, m, &cBinop_MmG5CZju_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qwcmHfvm, HV_BINOP_MULTIPLY, 1, m, &cBinop_qwcmHfvm_sendMessage);
}

void Heavy_pod_test::cMsg_We8ErdQ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mq7OD5zo_sendMessage);
}

void Heavy_pod_test::cCast_oflAogm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dd9Hzsau_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_pIfwyFJI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_aCKu1geI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cMsg_jP5Pn2yG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_mex45UFr, 1, m, &cVar_mex45UFr_sendMessage);
}

void Heavy_pod_test::cBinop_F0VLvBOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oKgst4sr, HV_BINOP_ADD, 1, m, &cBinop_oKgst4sr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ortzPWrz, HV_BINOP_ADD, 1, m, &cBinop_ortzPWrz_sendMessage);
}

void Heavy_pod_test::cSlice_UHnFLeyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sGkShztG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kvy2yJnj_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sGkShztG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kvy2yJnj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_0zb1aY7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_VvimoYjz_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_VvimoYjz_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSwitchcase_lPXt7Tzy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0zb1aY7t, 0, m, &cSlice_0zb1aY7t_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UHnFLeyp, 0, m, &cSlice_UHnFLeyp_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fIGFi3FQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_HYwPCAby, 0, m, &cSlice_HYwPCAby_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_XJydnaDP, 0, m, &cSlice_XJydnaDP_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zh2754ge_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cuhlQbF7_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cVar_SHDNELmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5aGP1yO6, HV_BINOP_SUBTRACT, 0, m, &cBinop_5aGP1yO6_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_pryPvIKI_sendMessage);
}

void Heavy_pod_test::cCast_xEqLBU6I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Gm3yCS0f_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_KkCYS8XU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2HnjTtQj_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cReceive_CYV6Bh9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V0Nvasea_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sfyzSm7e_sendMessage);
}

void Heavy_pod_test::cMsg_7vW5Tj1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_lPXt7Tzy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_sfyzSm7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7vW5Tj1I_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cReceive_KD9hl7DB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sPTgyJhp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fqn2f6pJ, 0, m, &cVar_fqn2f6pJ_sendMessage);
  cMsg_YfD0ABJt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ea3mFglU, 0, m, &cVar_ea3mFglU_sendMessage);
  cMsg_NyFDUXwp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_d1IInGFK, 0, m, &cVar_d1IInGFK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BOTxqYeJ, 0, m, &cVar_BOTxqYeJ_sendMessage);
  cMsg_We8ErdQ8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pEfFjgy8, 0, m, &cVar_pEfFjgy8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DdZu1MJb, 0, m, &cVar_DdZu1MJb_sendMessage);
}

void Heavy_pod_test::cCast_V0Nvasea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XMYJsE03_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cReceive_Vd5dBasc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KkCYS8XU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xEqLBU6I_sendMessage);
}

void Heavy_pod_test::cMsg_Gm3yCS0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_77eKXL7F_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cReceive_2Sfibbne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_IEuOBkHg, 0, m);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4;

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
    __hv_phasor_k_f(&sPhasor_wgt08Q8R, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_OpOzS14g, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));
    __hv_phasor_k_f(&sPhasor_IEuOBkHg, VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf2), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_sbD18Una, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O0), VOf(O0));

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
