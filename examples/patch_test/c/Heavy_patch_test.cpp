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

#include "Heavy_patch_test.hpp"

#define Context(_c) reinterpret_cast<Heavy_patch_test *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_patch_test_new(double sampleRate) {
    return new Heavy_patch_test(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_patch_test_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_patch_test(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_patch_test::Heavy_patch_test(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_xoiimDbr, 0.0f, sampleRate);
  numBytes += sVarf_init(&sVarf_GKTzrqfo, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_zF2Ofm8L, 0.0f);
  numBytes += cVar_init_f(&cVar_ebhKMDgj, 0.0f);
  numBytes += sVarf_init(&sVarf_YfdbCytH, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_UKOA24X9, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_ck7WKDGs, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_uL6vjWSG, 0.0f); // __sub
  numBytes += cSlice_init(&cSlice_YrppOtby, 1, -1);
  numBytes += cSlice_init(&cSlice_hdk98Rhy, 1, -1);
  numBytes += cBinop_init(&cBinop_1dDQhlRu, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_wWY8m5p3, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_2znDHSAo, 0.0f);
  numBytes += cSlice_init(&cSlice_R4V0daKD, 0, 1);
  numBytes += cSlice_init(&cSlice_k0q18juU, 1, 1);
  numBytes += cBinop_init(&cBinop_a7gonzzA, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_qfEzvVbj, 0.0f);
  numBytes += cVar_init_f(&cVar_pPJ1welq, 0.0f);
  numBytes += cBinop_init(&cBinop_YaLfaBTw, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_nP5KoDn8, 0.0f);
  numBytes += cVar_init_f(&cVar_Hn6ruzZA, 0.0f);
  numBytes += cVar_init_f(&cVar_dRIIaaZt, 20.0f);
  numBytes += cBinop_init(&cBinop_WchswnAm, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_oMwjoJYW, 20.0f);
  numBytes += cDelay_init(this, &cDelay_Ghwg65BB, 0.0f);
  numBytes += cBinop_init(&cBinop_DrOsL6VD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Q5vjDO1h, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_NVvc9LaW, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_ckAwqnWy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wpLznvF1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iu6gfocd, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_2qPNI4Pb, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_VulNNN2K, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_o3wu7zyw, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_GXpJ9Owy, 20.0f);
  numBytes += cSlice_init(&cSlice_oF5uSrwq, 1, -1);
  numBytes += cSlice_init(&cSlice_moPAOQac, 1, -1);
  numBytes += cSlice_init(&cSlice_NlAirE3s, 0, 1);
  numBytes += cSlice_init(&cSlice_8CjmNZ3L, 1, 1);
  numBytes += cVar_init_f(&cVar_FUdegSuV, 0.0f);
  numBytes += cVar_init_f(&cVar_iBhFrnba, 0.0f);
  numBytes += cBinop_init(&cBinop_kJWX31wm, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ylJZBVgk, 0.0f);
  numBytes += cVar_init_f(&cVar_zNxyRWZ4, 0.0f);
  numBytes += cBinop_init(&cBinop_fDRksKkL, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_9CASj0Aq, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_ZyIWhXqL, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_DGOcfmNz, 0.0f);
  numBytes += cBinop_init(&cBinop_dCczlg2X, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_v8t4TSQu, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_XvPGPjhJ, 20.0f);
  numBytes += cDelay_init(this, &cDelay_fYrmED9Y, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_patch_test::~Heavy_patch_test() {
  // nothing to free
}

HvTable *Heavy_patch_test::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_patch_test::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCFD93C2D: { // Ctrl1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yeNjXpM6_sendMessage);
      break;
    }
    case 0xA6D27094: { // Ctrl2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qDH7j9pY_sendMessage);
      break;
    }
    case 0xB00C3479: { // Ctrl3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0N0EuXnQ_sendMessage);
      break;
    }
    case 0x4BA4C205: { // Ctrl4
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jcWkQwBe_sendMessage);
      break;
    }
    case 0x7AAC371F: { // EncSwitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0Jw1B9dH_sendMessage);
      break;
    }
    case 0x39ADE514: { // Encoder
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2bTVchZy_sendMessage);
      break;
    }
    case 0x378CB51F: { // Gate1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7aKNdaU5_sendMessage);
      break;
    }
    case 0x8924DDEB: { // Gate2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hw9YTas8_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2LChM3YV_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_patch_test::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "Gate2";
        info->hash = 0x8924DDEB;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 1: {
        info->name = "Gate1";
        info->hash = 0x378CB51F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 2: {
        info->name = "Encoder";
        info->hash = 0x39ADE514;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 3: {
        info->name = "Ctrl1";
        info->hash = 0xCFD93C2D;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 4: {
        info->name = "Ctrl4";
        info->hash = 0x4BA4C205;
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
      case 6: {
        info->name = "Ctrl2";
        info->hash = 0xA6D27094;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 7: {
        info->name = "Ctrl3";
        info->hash = 0xB00C3479;
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
  return 8;
}



/*
 * Send Function Implementations
 */


void Heavy_patch_test::cCast_uho3V9CP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ScsxONUB_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cMsg_RxKpqRve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_BgUEEqBw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cBinop_hQ3ZhqHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GKTzrqfo, m);
}

void Heavy_patch_test::cReceive_yeNjXpM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.8f, 0, m, &cBinop_hQ3ZhqHB_sendMessage);
}

void Heavy_patch_test::cReceive_7aKNdaU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L9B3GgSw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_79J5jXFl_sendMessage);
}

void Heavy_patch_test::cVar_zF2Ofm8L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UKOA24X9, HV_BINOP_ADD, 1, m, &cBinop_UKOA24X9_sendMessage);
}

void Heavy_patch_test::cMsg_SVfA0ZfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_Oh9rv1K3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cReceive_hw9YTas8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HNjvad30_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uho3V9CP_sendMessage);
}

void Heavy_patch_test::cMsg_uNGYfAQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 440.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_zF2Ofm8L, 0, m, &cVar_zF2Ofm8L_sendMessage);
}

void Heavy_patch_test::cMsg_CV12aDig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_yLeTPvYy_sendMessage);
}

void Heavy_patch_test::cMsg_5ZHCrKcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Oh9rv1K3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cBinop_TDuOXsxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YfdbCytH, m);
}

void Heavy_patch_test::cMsg_rfbDkTuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_yLeTPvYy_sendMessage);
}

void Heavy_patch_test::cVar_ebhKMDgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_patch_test::cBinop_MMWIugDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ckAwqnWy, m);
}

void Heavy_patch_test::cCast_HNjvad30_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RxKpqRve_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cBinop_UKOA24X9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zF2Ofm8L, 0, m, &cVar_zF2Ofm8L_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ebhKMDgj, 0, m, &cVar_ebhKMDgj_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_xoiimDbr, 0, m);
}

void Heavy_patch_test::cCast_L9B3GgSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5ZHCrKcU_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cReceive_qDH7j9pY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.8f, 0, m, &cBinop_MMWIugDF_sendMessage);
}

void Heavy_patch_test::cBinop_yLeTPvYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UKOA24X9, HV_BINOP_ADD, 0, m, &cBinop_UKOA24X9_sendMessage);
}

void Heavy_patch_test::cBinop_wxLiIvhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DrOsL6VD, HV_BINOP_SUBTRACT, 1, m, &cBinop_DrOsL6VD_sendMessage);
}

void Heavy_patch_test::cBinop_7sgO656y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qfEzvVbj, 1, m, &cVar_qfEzvVbj_sendMessage);
}

void Heavy_patch_test::cCast_ZLs7GaTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pPJ1welq, 1, m, &cVar_pPJ1welq_sendMessage);
}

void Heavy_patch_test::cBinop_uL6vjWSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a7gonzzA, HV_BINOP_DIVIDE, 0, m, &cBinop_a7gonzzA_sendMessage);
}

void Heavy_patch_test::cCast_LOnDOQbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_myRfbiRk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1dDQhlRu, HV_BINOP_ADD, 0, m, &cBinop_1dDQhlRu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nP5KoDn8, 1, m, &cVar_nP5KoDn8_sendMessage);
}

void Heavy_patch_test::cSlice_YrppOtby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TWUDNNZZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LOnDOQbm_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TWUDNNZZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LOnDOQbm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSlice_hdk98Rhy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KRf5mrr5_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_KRf5mrr5_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSwitchcase_Oh9rv1K3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hdk98Rhy, 0, m, &cSlice_hdk98Rhy_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YrppOtby, 0, m, &cSlice_YrppOtby_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FvnByvc5_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_k0q18juU, 0, m, &cSlice_k0q18juU_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_R4V0daKD, 0, m, &cSlice_R4V0daKD_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HquEZzAr_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O0xD68gp_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cBinop_1dDQhlRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hn6ruzZA, 0, m, &cVar_Hn6ruzZA_sendMessage);
}

void Heavy_patch_test::cCast_HquEZzAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b2aQ1O78_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cBinop_wWY8m5p3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7sgO656y_sendMessage);
}

void Heavy_patch_test::cCast_TWUDNNZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KRf5mrr5_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cCast_gcLMImQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uL6vjWSG, HV_BINOP_SUBTRACT, 0, m, &cBinop_uL6vjWSG_sendMessage);
}

void Heavy_patch_test::cVar_2znDHSAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iF6mlFaR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jv7i2pti_sendMessage);
}

void Heavy_patch_test::cSlice_R4V0daKD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZLs7GaTK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gcLMImQY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSlice_k0q18juU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iF6mlFaR_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jv7i2pti_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cBinop_a7gonzzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1dDQhlRu, HV_BINOP_ADD, 1, m, &cBinop_1dDQhlRu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NVvc9LaW, HV_BINOP_ADD, 1, m, &cBinop_NVvc9LaW_sendMessage);
}

void Heavy_patch_test::cVar_qfEzvVbj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DrOsL6VD, HV_BINOP_SUBTRACT, 0, m, &cBinop_DrOsL6VD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_6eNqAjU1_sendMessage);
}

void Heavy_patch_test::cVar_pPJ1welq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nP5KoDn8, 0, m, &cVar_nP5KoDn8_sendMessage);
}

void Heavy_patch_test::cCast_dVVTxeQt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b8HhBfXR_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cSwitchcase_3cSNyEM6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dVVTxeQt_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_YaLfaBTw, HV_BINOP_MULTIPLY, 0, m, &cBinop_YaLfaBTw_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_Q5vjDO1h, HV_BINOP_DIVIDE, 1, m, &cBinop_Q5vjDO1h_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_oMwjoJYW, 0, m, &cVar_oMwjoJYW_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cCast_FvnByvc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2znDHSAo, 0, m, &cVar_2znDHSAo_sendMessage);
}

void Heavy_patch_test::cCast_jv7i2pti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q5vjDO1h, HV_BINOP_DIVIDE, 0, m, &cBinop_Q5vjDO1h_sendMessage);
}

void Heavy_patch_test::cSystem_xK8a9Fpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YaLfaBTw, HV_BINOP_MULTIPLY, 1, m, &cBinop_YaLfaBTw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wWY8m5p3, HV_BINOP_MULTIPLY, 1, m, &cBinop_wWY8m5p3_sendMessage);
}

void Heavy_patch_test::cMsg_a3SPMAeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xK8a9Fpp_sendMessage);
}

void Heavy_patch_test::cBinop_YaLfaBTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wxLiIvhM_sendMessage);
}

void Heavy_patch_test::cCast_JdQMz4ha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pPJ1welq, 0, m, &cVar_pPJ1welq_sendMessage);
}

void Heavy_patch_test::cVar_nP5KoDn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NVvc9LaW, HV_BINOP_ADD, 0, m, &cBinop_NVvc9LaW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1dDQhlRu, HV_BINOP_ADD, 0, m, &cBinop_1dDQhlRu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ck7WKDGs, m);
}

void Heavy_patch_test::cVar_Hn6ruzZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uL6vjWSG, HV_BINOP_SUBTRACT, 1, m, &cBinop_uL6vjWSG_sendMessage);
}

void Heavy_patch_test::cCast_myRfbiRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iBXiEhQR_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cBinop_6eNqAjU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3YDeZyAU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cVar_dRIIaaZt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3cSNyEM6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cBinop_WchswnAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_mNwF5T2P_sendMessage);
}

void Heavy_patch_test::cBinop_NV3B3j3n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WchswnAm, HV_BINOP_MULTIPLY, 1, m, &cBinop_WchswnAm_sendMessage);
}

void Heavy_patch_test::cMsg_b9nuU7Ty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZiTUIw9E_sendMessage);
}

void Heavy_patch_test::cSystem_ZiTUIw9E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NV3B3j3n_sendMessage);
}

void Heavy_patch_test::cBinop_mNwF5T2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ghwg65BB, 2, m, &cDelay_Ghwg65BB_sendMessage);
}

void Heavy_patch_test::cCast_kbdtYmcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NSpmEPW4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ghwg65BB, 0, m, &cDelay_Ghwg65BB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qfEzvVbj, 0, m, &cVar_qfEzvVbj_sendMessage);
}

void Heavy_patch_test::cVar_oMwjoJYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WchswnAm, HV_BINOP_MULTIPLY, 0, m, &cBinop_WchswnAm_sendMessage);
}

void Heavy_patch_test::cMsg_NSpmEPW4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ghwg65BB, 0, m, &cDelay_Ghwg65BB_sendMessage);
}

void Heavy_patch_test::cSwitchcase_6OooFPaz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_NSpmEPW4_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_NSpmEPW4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kbdtYmcm_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cDelay_Ghwg65BB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ghwg65BB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ghwg65BB, 0, m, &cDelay_Ghwg65BB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qfEzvVbj, 0, m, &cVar_qfEzvVbj_sendMessage);
}

void Heavy_patch_test::cBinop_DrOsL6VD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qfEzvVbj, 1, m, &cVar_qfEzvVbj_sendMessage);
}

void Heavy_patch_test::cCast_9lI79ZvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iBXiEhQR_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cMsg_GvHcfRMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_2znDHSAo, 1, m, &cVar_2znDHSAo_sendMessage);
}

void Heavy_patch_test::cBinop_Q5vjDO1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a7gonzzA, HV_BINOP_DIVIDE, 1, m, &cBinop_a7gonzzA_sendMessage);
}

void Heavy_patch_test::cCast_25Ri4RuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9lI79ZvJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JdQMz4ha_sendMessage);
}

void Heavy_patch_test::cCast_1kkqWApm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nP5KoDn8, 0, m, &cVar_nP5KoDn8_sendMessage);
}

void Heavy_patch_test::cSwitchcase_3YDeZyAU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1kkqWApm_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_25Ri4RuD_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_patch_test::cMsg_iBXiEhQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_6OooFPaz_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1dDQhlRu, HV_BINOP_ADD, 1, m, &cBinop_1dDQhlRu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NVvc9LaW, HV_BINOP_ADD, 1, m, &cBinop_NVvc9LaW_sendMessage);
}

void Heavy_patch_test::cMsg_KRf5mrr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_6OooFPaz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cMsg_b8HhBfXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YaLfaBTw, HV_BINOP_MULTIPLY, 0, m, &cBinop_YaLfaBTw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q5vjDO1h, HV_BINOP_DIVIDE, 1, m, &cBinop_Q5vjDO1h_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oMwjoJYW, 0, m, &cVar_oMwjoJYW_sendMessage);
}

void Heavy_patch_test::cCast_iF6mlFaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wWY8m5p3, HV_BINOP_MULTIPLY, 0, m, &cBinop_wWY8m5p3_sendMessage);
}

void Heavy_patch_test::cCast_O0xD68gp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GvHcfRMG_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cMsg_b2aQ1O78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_6OooFPaz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cBinop_NVvc9LaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nP5KoDn8, 1, m, &cVar_nP5KoDn8_sendMessage);
}

void Heavy_patch_test::cBinop_uW3sbrIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wpLznvF1, m);
}

void Heavy_patch_test::cReceive_2bTVchZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_yLeTPvYy_sendMessage);
}

void Heavy_patch_test::cReceive_2LChM3YV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HaDLTkXs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XvPGPjhJ, 0, m, &cVar_XvPGPjhJ_sendMessage);
  cMsg_b9nuU7Ty_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oMwjoJYW, 0, m, &cVar_oMwjoJYW_sendMessage);
  cMsg_u8BWzeoM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ylJZBVgk, 0, m, &cVar_ylJZBVgk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GXpJ9Owy, 0, m, &cVar_GXpJ9Owy_sendMessage);
  cMsg_a3SPMAeq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Hn6ruzZA, 0, m, &cVar_Hn6ruzZA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dRIIaaZt, 0, m, &cVar_dRIIaaZt_sendMessage);
  cMsg_uNGYfAQN_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cMsg_ScsxONUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_BgUEEqBw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cReceive_0Jw1B9dH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uNGYfAQN_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cBinop_2qPNI4Pb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DGOcfmNz, 1, m, &cVar_DGOcfmNz_sendMessage);
}

void Heavy_patch_test::cCast_W7oVa5Jk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uVBz4075_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cMsg_r9AlfKt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_9WqJHhqU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cCast_v3milKyQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FUdegSuV, 1, m, &cVar_FUdegSuV_sendMessage);
}

void Heavy_patch_test::cBinop_VulNNN2K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dCczlg2X, HV_BINOP_DIVIDE, 0, m, &cBinop_dCczlg2X_sendMessage);
}

void Heavy_patch_test::cBinop_o3wu7zyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zNxyRWZ4, 1, m, &cVar_zNxyRWZ4_sendMessage);
}

void Heavy_patch_test::cVar_GXpJ9Owy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_YNRwP0ue_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cSlice_oF5uSrwq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W7oVa5Jk_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Zelzm9FS_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W7oVa5Jk_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Zelzm9FS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSlice_moPAOQac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_uVBz4075_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_uVBz4075_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSwitchcase_BgUEEqBw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_moPAOQac, 0, m, &cSlice_moPAOQac_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oF5uSrwq, 0, m, &cSlice_oF5uSrwq_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PBcUhWX5_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_8CjmNZ3L, 0, m, &cSlice_8CjmNZ3L_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_NlAirE3s, 0, m, &cSlice_NlAirE3s_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_URFxzp7z_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rXYo372Y_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cSlice_NlAirE3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_v3milKyQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0aQiw6TK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSlice_8CjmNZ3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GZodvKBH_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_brf8h13d_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cCast_SIVbqIFq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FUdegSuV, 0, m, &cVar_FUdegSuV_sendMessage);
}

void Heavy_patch_test::cMsg_u8BWzeoM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4mq11bVc_sendMessage);
}

void Heavy_patch_test::cSystem_4mq11bVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZyIWhXqL, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZyIWhXqL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kJWX31wm, HV_BINOP_MULTIPLY, 1, m, &cBinop_kJWX31wm_sendMessage);
}

void Heavy_patch_test::cCast_rch6BOyR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iuveSGbL_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cVar_FUdegSuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zNxyRWZ4, 0, m, &cVar_zNxyRWZ4_sendMessage);
}

void Heavy_patch_test::cVar_iBhFrnba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GZodvKBH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_brf8h13d_sendMessage);
}

void Heavy_patch_test::cCast_brf8h13d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9CASj0Aq, HV_BINOP_DIVIDE, 0, m, &cBinop_9CASj0Aq_sendMessage);
}

void Heavy_patch_test::cCast_0aQiw6TK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VulNNN2K, HV_BINOP_SUBTRACT, 0, m, &cBinop_VulNNN2K_sendMessage);
}

void Heavy_patch_test::cBinop_QzaEOZZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DGOcfmNz, 1, m, &cVar_DGOcfmNz_sendMessage);
}

void Heavy_patch_test::cCast_PBcUhWX5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iBhFrnba, 0, m, &cVar_iBhFrnba_sendMessage);
}

void Heavy_patch_test::cCast_5Er5YGyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iuveSGbL_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cBinop_kJWX31wm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QzaEOZZ4_sendMessage);
}

void Heavy_patch_test::cVar_ylJZBVgk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VulNNN2K, HV_BINOP_SUBTRACT, 1, m, &cBinop_VulNNN2K_sendMessage);
}

void Heavy_patch_test::cVar_zNxyRWZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o3wu7zyw, HV_BINOP_ADD, 0, m, &cBinop_o3wu7zyw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fDRksKkL, HV_BINOP_ADD, 0, m, &cBinop_fDRksKkL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_iu6gfocd, m);
}

void Heavy_patch_test::cBinop_fDRksKkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ylJZBVgk, 0, m, &cVar_ylJZBVgk_sendMessage);
}

void Heavy_patch_test::cBinop_REchKEXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2qPNI4Pb, HV_BINOP_SUBTRACT, 1, m, &cBinop_2qPNI4Pb_sendMessage);
}

void Heavy_patch_test::cMsg_iuveSGbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_9WqJHhqU_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fDRksKkL, HV_BINOP_ADD, 1, m, &cBinop_fDRksKkL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_o3wu7zyw, HV_BINOP_ADD, 1, m, &cBinop_o3wu7zyw_sendMessage);
}

void Heavy_patch_test::cBinop_9CASj0Aq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dCczlg2X, HV_BINOP_DIVIDE, 1, m, &cBinop_dCczlg2X_sendMessage);
}

void Heavy_patch_test::cBinop_f2ujezbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ua5RYh76_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cBinop_ZyIWhXqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_REchKEXZ_sendMessage);
}

void Heavy_patch_test::cCast_GZodvKBH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kJWX31wm, HV_BINOP_MULTIPLY, 0, m, &cBinop_kJWX31wm_sendMessage);
}

void Heavy_patch_test::cCast_pk9HvJJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rch6BOyR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SIVbqIFq_sendMessage);
}

void Heavy_patch_test::cCast_0oInjZGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zNxyRWZ4, 0, m, &cVar_zNxyRWZ4_sendMessage);
}

void Heavy_patch_test::cSwitchcase_ua5RYh76_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0oInjZGx_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pk9HvJJS_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_patch_test::cCast_bSgHBjba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qZTzltFg_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cSwitchcase_YNRwP0ue_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bSgHBjba_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZyIWhXqL, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZyIWhXqL_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_9CASj0Aq, HV_BINOP_DIVIDE, 1, m, &cBinop_9CASj0Aq_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_XvPGPjhJ, 0, m, &cVar_XvPGPjhJ_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cMsg_uVBz4075_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_9WqJHhqU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cVar_DGOcfmNz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2qPNI4Pb, HV_BINOP_SUBTRACT, 0, m, &cBinop_2qPNI4Pb_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_f2ujezbA_sendMessage);
}

void Heavy_patch_test::cCast_rXYo372Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vuzWUh3Q_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cMsg_qZTzltFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZyIWhXqL, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZyIWhXqL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9CASj0Aq, HV_BINOP_DIVIDE, 1, m, &cBinop_9CASj0Aq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XvPGPjhJ, 0, m, &cVar_XvPGPjhJ_sendMessage);
}

void Heavy_patch_test::cBinop_dCczlg2X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fDRksKkL, HV_BINOP_ADD, 1, m, &cBinop_fDRksKkL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_o3wu7zyw, HV_BINOP_ADD, 1, m, &cBinop_o3wu7zyw_sendMessage);
}

void Heavy_patch_test::cCast_Zelzm9FS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5Er5YGyG_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fDRksKkL, HV_BINOP_ADD, 0, m, &cBinop_fDRksKkL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zNxyRWZ4, 1, m, &cVar_zNxyRWZ4_sendMessage);
}

void Heavy_patch_test::cMsg_P6MpYACM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fYrmED9Y, 0, m, &cDelay_fYrmED9Y_sendMessage);
}

void Heavy_patch_test::cCast_Z5OpLfTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_P6MpYACM_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fYrmED9Y, 0, m, &cDelay_fYrmED9Y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DGOcfmNz, 0, m, &cVar_DGOcfmNz_sendMessage);
}

void Heavy_patch_test::cBinop_v8t4TSQu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_sz2A1oUG_sendMessage);
}

void Heavy_patch_test::cVar_XvPGPjhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v8t4TSQu, HV_BINOP_MULTIPLY, 0, m, &cBinop_v8t4TSQu_sendMessage);
}

void Heavy_patch_test::cSwitchcase_9WqJHhqU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_P6MpYACM_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_P6MpYACM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z5OpLfTs_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cMsg_HaDLTkXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zV4HuF9Z_sendMessage);
}

void Heavy_patch_test::cSystem_zV4HuF9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZlwOYr4F_sendMessage);
}

void Heavy_patch_test::cBinop_ZlwOYr4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v8t4TSQu, HV_BINOP_MULTIPLY, 1, m, &cBinop_v8t4TSQu_sendMessage);
}

void Heavy_patch_test::cBinop_sz2A1oUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fYrmED9Y, 2, m, &cDelay_fYrmED9Y_sendMessage);
}

void Heavy_patch_test::cDelay_fYrmED9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fYrmED9Y, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fYrmED9Y, 0, m, &cDelay_fYrmED9Y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DGOcfmNz, 0, m, &cVar_DGOcfmNz_sendMessage);
}

void Heavy_patch_test::cMsg_vuzWUh3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_iBhFrnba, 1, m, &cVar_iBhFrnba_sendMessage);
}

void Heavy_patch_test::cCast_URFxzp7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r9AlfKt9_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cCast_79J5jXFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SVfA0ZfX_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cReceive_jcWkQwBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.8f, 0, m, &cBinop_uW3sbrIv_sendMessage);
}

void Heavy_patch_test::cReceive_0N0EuXnQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.8f, 0, m, &cBinop_TDuOXsxK_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_patch_test::process(float **inputBuffers, float **outputBuffers, int n) {
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
  hv_bufferf_t O0, O1, O2, O3;

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
    __hv_zero_f(VOf(O2));
    __hv_zero_f(VOf(O3));

    // process all signal functions
    __hv_phasor_k_f(&sPhasor_xoiimDbr, VOf(Bf0));
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
    __hv_varread_f(&sVarf_GKTzrqfo, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_ck7WKDGs, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_YfdbCytH, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O2), VOf(O2));
    __hv_varread_f(&sVarf_wpLznvF1, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O3), VOf(O3));
    __hv_varread_f(&sVarf_ckAwqnWy, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_iu6gfocd, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
    __hv_store_f(outputBuffers[2]+n, VIf(O2));
    __hv_store_f(outputBuffers[3]+n, VIf(O3));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_patch_test::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 4 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(4*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);
  bOut[2] = outputBuffers+(2*n4);
  bOut[3] = outputBuffers+(3*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_patch_test::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 4 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(4*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  
  // interleave the heavy output into the output buffer
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+4*j] = bOut[i*n4+j];
    }
  }

  return n;
}
