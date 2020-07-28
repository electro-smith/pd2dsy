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
  numBytes += sPhasor_k_init(&sPhasor_w2IxTRMi, 0.0f, sampleRate);
  numBytes += sVarf_init(&sVarf_gmkGciTn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KuurJuLz, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_IvluaUxQ, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_QzQbrImy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9obsaijU, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_Qvo1Utuk, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_VAPaOfdv, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_DncrkuJc, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Pt9TNQeH, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_MI97R7on, 0.0f);
  numBytes += cVar_init_f(&cVar_7Qj81LrL, 0.0f);
  numBytes += cBinop_init(&cBinop_4IyL0Qpa, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_H404yBxl, 0.0f);
  numBytes += cVar_init_f(&cVar_uAtkPCgr, 20.0f);
  numBytes += cSlice_init(&cSlice_t6tVxfWL, 1, -1);
  numBytes += cSlice_init(&cSlice_ASvqQNWq, 1, -1);
  numBytes += cVar_init_f(&cVar_ImEhCRG5, 0.0f);
  numBytes += cSlice_init(&cSlice_zto46NGN, 1, 1);
  numBytes += cSlice_init(&cSlice_QQKWVMow, 0, 1);
  numBytes += cBinop_init(&cBinop_ktMFNFbk, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_nkBQham4, 20.0f);
  numBytes += cDelay_init(this, &cDelay_tFgTAO32, 0.0f);
  numBytes += cVar_init_f(&cVar_GOFtVCJ5, 0.0f);
  numBytes += cBinop_init(&cBinop_bNqSBW4r, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_DbADAkQj, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_eTbl8M4J, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ltMxBcyw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nwYGEdhT, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_NN7STKmz, 0.0f);
  numBytes += cVar_init_f(&cVar_L6aR9oEa, 0.0f);
  numBytes += cVar_init_f(&cVar_BOyBNdm6, 0.0f);
  numBytes += cVar_init_f(&cVar_IPCMtSMY, 20.0f);
  numBytes += cBinop_init(&cBinop_W76TBtSZ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_mfSmdAaM, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_phhPOqaX, 0.0f); // __sub
  numBytes += cSlice_init(&cSlice_xYLoOeDl, 1, 1);
  numBytes += cSlice_init(&cSlice_5elNEYpt, 0, 1);
  numBytes += cDelay_init(this, &cDelay_TDUVunop, 0.0f);
  numBytes += cVar_init_f(&cVar_cptYcvku, 20.0f);
  numBytes += cBinop_init(&cBinop_Ui3yeRHh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_JyL4fGKw, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_RHCrK3wO, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_LMmWUo2p, 0.0f);
  numBytes += cBinop_init(&cBinop_4nzdhST2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_TyuqAB1v, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_g5mr6KHV, 0.0f);
  numBytes += cBinop_init(&cBinop_n9rueLJH, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_wdRMdsEE, 0.0f);
  numBytes += cVar_init_f(&cVar_AtzGKrm9, 0.0f);
  numBytes += cSlice_init(&cSlice_vVFgewMQ, 1, -1);
  numBytes += cSlice_init(&cSlice_mwwTtF5p, 1, -1);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qW36TTGw_sendMessage);
      break;
    }
    case 0xA6D27094: { // Ctrl2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_b4eJzqhW_sendMessage);
      break;
    }
    case 0xB00C3479: { // Ctrl3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OXfsS0IO_sendMessage);
      break;
    }
    case 0x4BA4C205: { // Ctrl4
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_M82t9twm_sendMessage);
      break;
    }
    case 0x7AAC371F: { // EncSwitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ecO6Thbx_sendMessage);
      break;
    }
    case 0x39ADE514: { // Encoder
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8PZUmR6d_sendMessage);
      break;
    }
    case 0x378CB51F: { // Gate1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ao5QcudY_sendMessage);
      break;
    }
    case 0x8924DDEB: { // Gate2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EtkH80S3_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oRLZRRvN_sendMessage);
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


void Heavy_patch_test::cReceive_ecO6Thbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rfov34yy_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cReceive_qW36TTGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.8f, 0, m, &cBinop_yTjBc8RE_sendMessage);
}

void Heavy_patch_test::cReceive_ao5QcudY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8kBR6vGI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XlznFXMM_sendMessage);
}

void Heavy_patch_test::cReceive_EtkH80S3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xihbtbEf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AazeDKr1_sendMessage);
}

void Heavy_patch_test::cBinop_IvluaUxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L6aR9oEa, 0, m, &cVar_L6aR9oEa_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NN7STKmz, 0, m, &cVar_NN7STKmz_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_w2IxTRMi, 0, m);
}

void Heavy_patch_test::cCast_XlznFXMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v4Hp9zfA_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cBinop_yTjBc8RE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gmkGciTn, m);
}

void Heavy_patch_test::cBinop_JzdoKOpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9obsaijU, m);
}

void Heavy_patch_test::cCast_xihbtbEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JPqYR2I2_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cCast_pNEK2Mp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AqZcBxyI_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cBinop_Qvo1Utuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bNqSBW4r, HV_BINOP_ADD, 1, m, &cBinop_bNqSBW4r_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pt9TNQeH, HV_BINOP_ADD, 1, m, &cBinop_Pt9TNQeH_sendMessage);
}

void Heavy_patch_test::cMsg_kY97KDo5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_GOFtVCJ5, 1, m, &cVar_GOFtVCJ5_sendMessage);
}

void Heavy_patch_test::cCast_riwILOxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VAPaOfdv, HV_BINOP_DIVIDE, 0, m, &cBinop_VAPaOfdv_sendMessage);
}

void Heavy_patch_test::cBinop_VAPaOfdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qvo1Utuk, HV_BINOP_DIVIDE, 1, m, &cBinop_Qvo1Utuk_sendMessage);
}

void Heavy_patch_test::cBinop_DncrkuJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MI97R7on, 1, m, &cVar_MI97R7on_sendMessage);
}

void Heavy_patch_test::cMsg_bk1Cfh5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_MK1OEsvd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cBinop_Pt9TNQeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ImEhCRG5, 1, m, &cVar_ImEhCRG5_sendMessage);
}

void Heavy_patch_test::cCast_QHB6f4DO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g6OPadHT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bNqSBW4r, HV_BINOP_ADD, 0, m, &cBinop_bNqSBW4r_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ImEhCRG5, 1, m, &cVar_ImEhCRG5_sendMessage);
}

void Heavy_patch_test::cCast_aTHd4T6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UHvLIxsk_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cSwitchcase_pqsX9VJQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aTHd4T6B_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_eTbl8M4J, HV_BINOP_MULTIPLY, 0, m, &cBinop_eTbl8M4J_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_VAPaOfdv, HV_BINOP_DIVIDE, 1, m, &cBinop_VAPaOfdv_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_nkBQham4, 0, m, &cVar_nkBQham4_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cCast_EGWJ7SdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kY97KDo5_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cVar_MI97R7on_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DncrkuJc, HV_BINOP_SUBTRACT, 0, m, &cBinop_DncrkuJc_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_n2HUICoV_sendMessage);
}

void Heavy_patch_test::cMsg_MIM4oOCl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_MK1OEsvd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cCast_12e0NHBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DbADAkQj, HV_BINOP_MULTIPLY, 0, m, &cBinop_DbADAkQj_sendMessage);
}

void Heavy_patch_test::cCast_koJl0CJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4IyL0Qpa, HV_BINOP_SUBTRACT, 0, m, &cBinop_4IyL0Qpa_sendMessage);
}

void Heavy_patch_test::cBinop_yG1JPnRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DncrkuJc, HV_BINOP_SUBTRACT, 1, m, &cBinop_DncrkuJc_sendMessage);
}

void Heavy_patch_test::cVar_7Qj81LrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4IyL0Qpa, HV_BINOP_SUBTRACT, 1, m, &cBinop_4IyL0Qpa_sendMessage);
}

void Heavy_patch_test::cBinop_4IyL0Qpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qvo1Utuk, HV_BINOP_DIVIDE, 0, m, &cBinop_Qvo1Utuk_sendMessage);
}

void Heavy_patch_test::cMsg_UHvLIxsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_eTbl8M4J, HV_BINOP_MULTIPLY, 0, m, &cBinop_eTbl8M4J_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VAPaOfdv, HV_BINOP_DIVIDE, 1, m, &cBinop_VAPaOfdv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nkBQham4, 0, m, &cVar_nkBQham4_sendMessage);
}

void Heavy_patch_test::cVar_H404yBxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ImEhCRG5, 0, m, &cVar_ImEhCRG5_sendMessage);
}

void Heavy_patch_test::cVar_uAtkPCgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pqsX9VJQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cSlice_t6tVxfWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_MIM4oOCl_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_MIM4oOCl_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSlice_ASvqQNWq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g5WtZ7O9_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QHB6f4DO_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g5WtZ7O9_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QHB6f4DO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSwitchcase_eQsXyCSH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_t6tVxfWL, 0, m, &cSlice_t6tVxfWL_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ASvqQNWq, 0, m, &cSlice_ASvqQNWq_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XbIrC0PK_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_zto46NGN, 0, m, &cSlice_zto46NGN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QQKWVMow, 0, m, &cSlice_QQKWVMow_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R1xuFzO6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EGWJ7SdB_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cCast_ApxgtkMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H404yBxl, 0, m, &cVar_H404yBxl_sendMessage);
}

void Heavy_patch_test::cVar_ImEhCRG5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pt9TNQeH, HV_BINOP_ADD, 0, m, &cBinop_Pt9TNQeH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bNqSBW4r, HV_BINOP_ADD, 0, m, &cBinop_bNqSBW4r_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nwYGEdhT, m);
}

void Heavy_patch_test::cSlice_zto46NGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_12e0NHBV_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_riwILOxI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSlice_QQKWVMow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FW9LkdmC_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_koJl0CJP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cCast_R1xuFzO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bk1Cfh5y_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cCast_pih5f5gR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DsOIpXp0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tFgTAO32, 0, m, &cDelay_tFgTAO32_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MI97R7on, 0, m, &cVar_MI97R7on_sendMessage);
}

void Heavy_patch_test::cBinop_ktMFNFbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_e3olvLCz_sendMessage);
}

void Heavy_patch_test::cMsg_DsOIpXp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tFgTAO32, 0, m, &cDelay_tFgTAO32_sendMessage);
}

void Heavy_patch_test::cBinop_OKOh6i3B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ktMFNFbk, HV_BINOP_MULTIPLY, 1, m, &cBinop_ktMFNFbk_sendMessage);
}

void Heavy_patch_test::cVar_nkBQham4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ktMFNFbk, HV_BINOP_MULTIPLY, 0, m, &cBinop_ktMFNFbk_sendMessage);
}

void Heavy_patch_test::cMsg_JM4eyQQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Mr9JRdyz_sendMessage);
}

void Heavy_patch_test::cSystem_Mr9JRdyz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OKOh6i3B_sendMessage);
}

void Heavy_patch_test::cSwitchcase_MK1OEsvd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_DsOIpXp0_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_DsOIpXp0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pih5f5gR_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cBinop_e3olvLCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tFgTAO32, 2, m, &cDelay_tFgTAO32_sendMessage);
}

void Heavy_patch_test::cDelay_tFgTAO32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tFgTAO32, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tFgTAO32, 0, m, &cDelay_tFgTAO32_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MI97R7on, 0, m, &cVar_MI97R7on_sendMessage);
}

void Heavy_patch_test::cCast_FW9LkdmC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H404yBxl, 1, m, &cVar_H404yBxl_sendMessage);
}

void Heavy_patch_test::cVar_GOFtVCJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_12e0NHBV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_riwILOxI_sendMessage);
}

void Heavy_patch_test::cCast_g6OPadHT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AqZcBxyI_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cBinop_n2HUICoV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Hz6sMWzO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cMsg_PADxVlRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_v9YDu9ys_sendMessage);
}

void Heavy_patch_test::cSystem_v9YDu9ys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eTbl8M4J, HV_BINOP_MULTIPLY, 1, m, &cBinop_eTbl8M4J_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DbADAkQj, HV_BINOP_MULTIPLY, 1, m, &cBinop_DbADAkQj_sendMessage);
}

void Heavy_patch_test::cCast_g5WtZ7O9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MIM4oOCl_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cBinop_Rsr616IT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MI97R7on, 1, m, &cVar_MI97R7on_sendMessage);
}

void Heavy_patch_test::cBinop_bNqSBW4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7Qj81LrL, 0, m, &cVar_7Qj81LrL_sendMessage);
}

void Heavy_patch_test::cMsg_AqZcBxyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_MK1OEsvd_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bNqSBW4r, HV_BINOP_ADD, 1, m, &cBinop_bNqSBW4r_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pt9TNQeH, HV_BINOP_ADD, 1, m, &cBinop_Pt9TNQeH_sendMessage);
}

void Heavy_patch_test::cCast_ydxjP47j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pNEK2Mp9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ApxgtkMB_sendMessage);
}

void Heavy_patch_test::cCast_RCxnDVTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ImEhCRG5, 0, m, &cVar_ImEhCRG5_sendMessage);
}

void Heavy_patch_test::cSwitchcase_Hz6sMWzO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RCxnDVTP_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ydxjP47j_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_patch_test::cCast_XbIrC0PK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GOFtVCJ5, 0, m, &cVar_GOFtVCJ5_sendMessage);
}

void Heavy_patch_test::cBinop_DbADAkQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Rsr616IT_sendMessage);
}

void Heavy_patch_test::cBinop_eTbl8M4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yG1JPnRH_sendMessage);
}

void Heavy_patch_test::cMsg_Rfov34yy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 440.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_L6aR9oEa, 0, m, &cVar_L6aR9oEa_sendMessage);
}

void Heavy_patch_test::cMsg_JPqYR2I2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_eQsXyCSH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cCast_AazeDKr1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HzSevzIE_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cReceive_OXfsS0IO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.8f, 0, m, &cBinop_JzdoKOpn_sendMessage);
}

void Heavy_patch_test::cBinop_mr5eKsMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ltMxBcyw, m);
}

void Heavy_patch_test::cVar_NN7STKmz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_patch_test::cMsg_7K1yj4xR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_ZUkN3CYJ_sendMessage);
}

void Heavy_patch_test::cVar_L6aR9oEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IvluaUxQ, HV_BINOP_ADD, 1, m, &cBinop_IvluaUxQ_sendMessage);
}

void Heavy_patch_test::cReceive_M82t9twm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.8f, 0, m, &cBinop_KE4FUbDW_sendMessage);
}

void Heavy_patch_test::cReceive_8PZUmR6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_ZUkN3CYJ_sendMessage);
}

void Heavy_patch_test::cMsg_HzSevzIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_eQsXyCSH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cCast_8kBR6vGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IQLkhYqB_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cMsg_IQLkhYqB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_WZLSm9P3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cReceive_oRLZRRvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JM4eyQQT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nkBQham4, 0, m, &cVar_nkBQham4_sendMessage);
  cMsg_ZS6Ri5DL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cptYcvku, 0, m, &cVar_cptYcvku_sendMessage);
  cMsg_PADxVlRt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7Qj81LrL, 0, m, &cVar_7Qj81LrL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uAtkPCgr, 0, m, &cVar_uAtkPCgr_sendMessage);
  cMsg_nz11cKso_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BOyBNdm6, 0, m, &cVar_BOyBNdm6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IPCMtSMY, 0, m, &cVar_IPCMtSMY_sendMessage);
  cMsg_Rfov34yy_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cMsg_v4Hp9zfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_WZLSm9P3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cBinop_ZUkN3CYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IvluaUxQ, HV_BINOP_ADD, 0, m, &cBinop_IvluaUxQ_sendMessage);
}

void Heavy_patch_test::cMsg_ZZ9n7Pwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_ZUkN3CYJ_sendMessage);
}

void Heavy_patch_test::cBinop_KE4FUbDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QzQbrImy, m);
}

void Heavy_patch_test::cReceive_b4eJzqhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.8f, 0, m, &cBinop_mr5eKsMY_sendMessage);
}

void Heavy_patch_test::cMsg_wRWBcIRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_n9rueLJH, HV_BINOP_MULTIPLY, 0, m, &cBinop_n9rueLJH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RHCrK3wO, HV_BINOP_DIVIDE, 1, m, &cBinop_RHCrK3wO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cptYcvku, 0, m, &cVar_cptYcvku_sendMessage);
}

void Heavy_patch_test::cCast_pbXUReD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_a4tOXH6F_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JyL4fGKw, HV_BINOP_ADD, 0, m, &cBinop_JyL4fGKw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LMmWUo2p, 1, m, &cVar_LMmWUo2p_sendMessage);
}

void Heavy_patch_test::cVar_BOyBNdm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4nzdhST2, HV_BINOP_SUBTRACT, 1, m, &cBinop_4nzdhST2_sendMessage);
}

void Heavy_patch_test::cMsg_c0F7oRmY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_uJ0KFkoV_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JyL4fGKw, HV_BINOP_ADD, 1, m, &cBinop_JyL4fGKw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_W76TBtSZ, HV_BINOP_ADD, 1, m, &cBinop_W76TBtSZ_sendMessage);
}

void Heavy_patch_test::cVar_IPCMtSMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lKwtC2jU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cCast_a4tOXH6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c0F7oRmY_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cBinop_W76TBtSZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LMmWUo2p, 1, m, &cVar_LMmWUo2p_sendMessage);
}

void Heavy_patch_test::cMsg_TDj0PYxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_wdRMdsEE, 1, m, &cVar_wdRMdsEE_sendMessage);
}

void Heavy_patch_test::cBinop_mfSmdAaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JyL4fGKw, HV_BINOP_ADD, 1, m, &cBinop_JyL4fGKw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_W76TBtSZ, HV_BINOP_ADD, 1, m, &cBinop_W76TBtSZ_sendMessage);
}

void Heavy_patch_test::cBinop_phhPOqaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g5mr6KHV, 1, m, &cVar_g5mr6KHV_sendMessage);
}

void Heavy_patch_test::cCast_wB435jCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wRWBcIRC_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cSwitchcase_lKwtC2jU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wB435jCr_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_n9rueLJH, HV_BINOP_MULTIPLY, 0, m, &cBinop_n9rueLJH_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_RHCrK3wO, HV_BINOP_DIVIDE, 1, m, &cBinop_RHCrK3wO_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_cptYcvku, 0, m, &cVar_cptYcvku_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cCast_ukwbHGte_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Md6vKbqn_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cCast_ss93tudW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0OkAzMj1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NhgUPk60_sendMessage);
}

void Heavy_patch_test::cCast_ZBjIb8lY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LMmWUo2p, 0, m, &cVar_LMmWUo2p_sendMessage);
}

void Heavy_patch_test::cSwitchcase_R8N53kPP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZBjIb8lY_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ss93tudW_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_patch_test::cCast_RfaRNGBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RHCrK3wO, HV_BINOP_DIVIDE, 0, m, &cBinop_RHCrK3wO_sendMessage);
}

void Heavy_patch_test::cMsg_Eqb7ZWgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_uJ0KFkoV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cCast_uKMckuuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TDj0PYxm_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cSlice_xYLoOeDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_v7VohJMm_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RfaRNGBS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSlice_5elNEYpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_paUVPyIK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_knFQfcaf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cCast_iPzycmet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YdlE1qjl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TDUVunop, 0, m, &cDelay_TDUVunop_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_g5mr6KHV, 0, m, &cVar_g5mr6KHV_sendMessage);
}

void Heavy_patch_test::cBinop_bMgaP3Cz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TDUVunop, 2, m, &cDelay_TDUVunop_sendMessage);
}

void Heavy_patch_test::cMsg_YdlE1qjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TDUVunop, 0, m, &cDelay_TDUVunop_sendMessage);
}

void Heavy_patch_test::cBinop_rcp1lKOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ui3yeRHh, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ui3yeRHh_sendMessage);
}

void Heavy_patch_test::cDelay_TDUVunop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TDUVunop, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TDUVunop, 0, m, &cDelay_TDUVunop_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_g5mr6KHV, 0, m, &cVar_g5mr6KHV_sendMessage);
}

void Heavy_patch_test::cSwitchcase_uJ0KFkoV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_YdlE1qjl_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_YdlE1qjl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iPzycmet_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cVar_cptYcvku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ui3yeRHh, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ui3yeRHh_sendMessage);
}

void Heavy_patch_test::cBinop_Ui3yeRHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_bMgaP3Cz_sendMessage);
}

void Heavy_patch_test::cSystem_K2qDzpJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rcp1lKOM_sendMessage);
}

void Heavy_patch_test::cMsg_ZS6Ri5DL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K2qDzpJw_sendMessage);
}

void Heavy_patch_test::cBinop_JyL4fGKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BOyBNdm6, 0, m, &cVar_BOyBNdm6_sendMessage);
}

void Heavy_patch_test::cCast_L3sNHohT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Eqb7ZWgy_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cCast_knFQfcaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4nzdhST2, HV_BINOP_SUBTRACT, 0, m, &cBinop_4nzdhST2_sendMessage);
}

void Heavy_patch_test::cMsg_Md6vKbqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_uJ0KFkoV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cBinop_Unv3tfiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_R8N53kPP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_patch_test::cBinop_RHCrK3wO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mfSmdAaM, HV_BINOP_DIVIDE, 1, m, &cBinop_mfSmdAaM_sendMessage);
}

void Heavy_patch_test::cVar_LMmWUo2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W76TBtSZ, HV_BINOP_ADD, 0, m, &cBinop_W76TBtSZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JyL4fGKw, HV_BINOP_ADD, 0, m, &cBinop_JyL4fGKw_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KuurJuLz, m);
}

void Heavy_patch_test::cCast_0OkAzMj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c0F7oRmY_sendMessage(_c, 0, m);
}

void Heavy_patch_test::cBinop_b6zsjdeV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_phhPOqaX, HV_BINOP_SUBTRACT, 1, m, &cBinop_phhPOqaX_sendMessage);
}

void Heavy_patch_test::cBinop_4nzdhST2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mfSmdAaM, HV_BINOP_DIVIDE, 0, m, &cBinop_mfSmdAaM_sendMessage);
}

void Heavy_patch_test::cBinop_MieWf5s0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g5mr6KHV, 1, m, &cVar_g5mr6KHV_sendMessage);
}

void Heavy_patch_test::cCast_AkxUfLdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wdRMdsEE, 0, m, &cVar_wdRMdsEE_sendMessage);
}

void Heavy_patch_test::cBinop_TyuqAB1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MieWf5s0_sendMessage);
}

void Heavy_patch_test::cCast_v7VohJMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TyuqAB1v, HV_BINOP_MULTIPLY, 0, m, &cBinop_TyuqAB1v_sendMessage);
}

void Heavy_patch_test::cCast_paUVPyIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AtzGKrm9, 1, m, &cVar_AtzGKrm9_sendMessage);
}

void Heavy_patch_test::cSystem_qi9tXwAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n9rueLJH, HV_BINOP_MULTIPLY, 1, m, &cBinop_n9rueLJH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TyuqAB1v, HV_BINOP_MULTIPLY, 1, m, &cBinop_TyuqAB1v_sendMessage);
}

void Heavy_patch_test::cMsg_nz11cKso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qi9tXwAd_sendMessage);
}

void Heavy_patch_test::cVar_g5mr6KHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_phhPOqaX, HV_BINOP_SUBTRACT, 0, m, &cBinop_phhPOqaX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_Unv3tfiR_sendMessage);
}

void Heavy_patch_test::cBinop_n9rueLJH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_b6zsjdeV_sendMessage);
}

void Heavy_patch_test::cVar_wdRMdsEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_v7VohJMm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RfaRNGBS_sendMessage);
}

void Heavy_patch_test::cVar_AtzGKrm9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LMmWUo2p, 0, m, &cVar_LMmWUo2p_sendMessage);
}

void Heavy_patch_test::cSlice_vVFgewMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ukwbHGte_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pbXUReD9_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ukwbHGte_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pbXUReD9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSlice_mwwTtF5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Md6vKbqn_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_Md6vKbqn_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_patch_test::cSwitchcase_WZLSm9P3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mwwTtF5p, 0, m, &cSlice_mwwTtF5p_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vVFgewMQ, 0, m, &cSlice_vVFgewMQ_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AkxUfLdD_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_xYLoOeDl, 0, m, &cSlice_xYLoOeDl_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_5elNEYpt, 0, m, &cSlice_5elNEYpt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L3sNHohT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uKMckuuQ_sendMessage);
      break;
    }
  }
}

void Heavy_patch_test::cCast_NhgUPk60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AtzGKrm9, 0, m, &cVar_AtzGKrm9_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_w2IxTRMi, VOf(Bf0));
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
    __hv_varread_f(&sVarf_ltMxBcyw, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_nwYGEdhT, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));
    __hv_varread_f(&sVarf_gmkGciTn, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_KuurJuLz, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_QzQbrImy, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O3), VOf(O3));
    __hv_varread_f(&sVarf_9obsaijU, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O2), VOf(O2));

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
