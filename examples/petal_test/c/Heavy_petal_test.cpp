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

#include "Heavy_petal_test.hpp"

#define Context(_c) reinterpret_cast<Heavy_petal_test *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_petal_test_new(double sampleRate) {
    return new Heavy_petal_test(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_petal_test_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_petal_test(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_petal_test::Heavy_petal_test(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_kJRW9ADR, 0.0f, sampleRate);
  numBytes += sPhasor_init(&sPhasor_T1iF8cLj, sampleRate);
  numBytes += sPhasor_init(&sPhasor_iQsxF8Yj, sampleRate);
  numBytes += cVar_init_f(&cVar_3zcUMp9P, 0.0f);
  numBytes += sVarf_init(&sVarf_uBBhccwU, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3Ri9pBz1, 0.0f);
  numBytes += cVar_init_f(&cVar_FcPSuKmn, 0.0f);
  numBytes += sVarf_init(&sVarf_1b6i0uCP, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YmpsuvxX, 0.0f);
  numBytes += cVar_init_f(&cVar_VdlhBaIS, 0.0f);
  numBytes += cBinop_init(&cBinop_5lXXtMQz, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_yQcsguUo, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_tCHctrwg, 0.0f);
  numBytes += cVar_init_f(&cVar_gh6oPXPO, 20.0f);
  numBytes += cBinop_init(&cBinop_cbGtkcsc, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_D59FngxH, 0, 1);
  numBytes += cSlice_init(&cSlice_TV4KM8oi, 1, 1);
  numBytes += cVar_init_f(&cVar_ZY3vKZnm, 0.0f);
  numBytes += cBinop_init(&cBinop_FmIdbrVx, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_3MHAsY98, 0.0f);
  numBytes += cVar_init_f(&cVar_umWS32to, 20.0f);
  numBytes += cBinop_init(&cBinop_TcjulL37, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_OLuoQWeE, 0.0f);
  numBytes += cBinop_init(&cBinop_BeVLwfnb, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_m05D3rOs, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_vyBIapfG, 0.0f);
  numBytes += cBinop_init(&cBinop_wWuXYRDR, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_8emhy72t, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_Nqvp3C5J, 1, -1);
  numBytes += cSlice_init(&cSlice_vcAqeYiz, 1, -1);
  numBytes += cBinop_init(&cBinop_6v6QBrNW, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_6EXmGtDK, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_CEBcSc3o, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_20M3nxPk, 0.0f);
  numBytes += cVar_init_f(&cVar_WrDukJUd, 0.0f);
  numBytes += cBinop_init(&cBinop_a9A0A485, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_LykvX4Uc, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_5OYVuhdA, 0.0f);
  numBytes += cVar_init_f(&cVar_MyWzF8im, 20.0f);
  numBytes += cVar_init_f(&cVar_2umSHxTs, 0.0f);
  numBytes += cSlice_init(&cSlice_XjjNKra6, 1, -1);
  numBytes += cSlice_init(&cSlice_LbCSuzN7, 1, -1);
  numBytes += cVar_init_f(&cVar_aDl1kW6a, 0.0f);
  numBytes += cBinop_init(&cBinop_wJY3CRah, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_Nv3T7nbY, 0.0f); // __add
  numBytes += cSlice_init(&cSlice_H2Fd7pHh, 1, 1);
  numBytes += cSlice_init(&cSlice_710HHYYX, 0, 1);
  numBytes += cBinop_init(&cBinop_kNfCvu4F, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_afz25G9G, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_IufVJXCc, 0.0f);
  numBytes += cVar_init_f(&cVar_sXv57mA9, 20.0f);
  numBytes += sVarf_init(&sVarf_211XSfvy, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Ergnj9u7, 0.0f);
  numBytes += sVarf_init(&sVarf_8IZ8sKWo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rnjq9VIF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_c9Q7q45r, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_2ODTAxu3, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_osPQurYz, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_petal_test::~Heavy_petal_test() {
  // nothing to free
}

HvTable *Heavy_petal_test::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_petal_test::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x7AAC371F: { // EncSwitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TMsKH8Ww_sendMessage);
      break;
    }
    case 0x39ADE514: { // Encoder
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3XBwr8xm_sendMessage);
      break;
    }
    case 0x62DD3F82: { // Knob1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RZNhau8s_sendMessage);
      break;
    }
    case 0x6BE4E001: { // Knob2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1vX2h3Dw_sendMessage);
      break;
    }
    case 0xACE00F67: { // Switch1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5Q8t6MBu_sendMessage);
      break;
    }
    case 0x874EC1F2: { // Switch2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dd1ym3M5_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UrMAhNIJ_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_petal_test::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "Switch2";
        info->hash = 0x874EC1F2;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 1: {
        info->name = "Switch1";
        info->hash = 0xACE00F67;
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


void Heavy_petal_test::cVar_3zcUMp9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2ODTAxu3, HV_BINOP_ADD, 1, m, &cBinop_2ODTAxu3_sendMessage);
}

void Heavy_petal_test::cBinop_C6LaSMdc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ergnj9u7, 1, m, &cVar_Ergnj9u7_sendMessage);
}

void Heavy_petal_test::cBinop_8cw7PpNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_211XSfvy, m);
}

void Heavy_petal_test::cCast_SJNs2t0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QRoDa4gS_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cMsg_UwtgU6gI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_j9Majx8X_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cBinop_XpmSvl6I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2ODTAxu3, HV_BINOP_ADD, 0, m, &cBinop_2ODTAxu3_sendMessage);
}

void Heavy_petal_test::cMsg_DkqOmxsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_6KnmrekP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cReceive_UrMAhNIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5tehPfLb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sXv57mA9, 0, m, &cVar_sXv57mA9_sendMessage);
  cMsg_TurFRjFn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_umWS32to, 0, m, &cVar_umWS32to_sendMessage);
  cMsg_yqb689BU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_20M3nxPk, 0, m, &cVar_20M3nxPk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MyWzF8im, 0, m, &cVar_MyWzF8im_sendMessage);
  cMsg_Vis0Y4Rd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZY3vKZnm, 0, m, &cVar_ZY3vKZnm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gh6oPXPO, 0, m, &cVar_gh6oPXPO_sendMessage);
  cMsg_LohfnGAu_sendMessage(_c, 0, m);
  cMsg_xmQQ0YfY_sendMessage(_c, 0, m);
  cMsg_1BYYjXJJ_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cMsg_1BYYjXJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_3zcUMp9P, 0, m, &cVar_3zcUMp9P_sendMessage);
}

void Heavy_petal_test::cMsg_LohfnGAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_kJRW9ADR, 0, m);
}

void Heavy_petal_test::cCast_EN6m3tUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UwtgU6gI_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cVar_3Ri9pBz1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_8cw7PpNP_sendMessage);
}

void Heavy_petal_test::cCast_BqiBxBsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XW13jcd0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SJNs2t0f_sendMessage);
}

void Heavy_petal_test::cMsg_QRoDa4gS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_6KnmrekP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cVar_FcPSuKmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_petal_test::cCast_0a7wHr8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o6KlbRZ2_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cBinop_qEZSrpu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1b6i0uCP, m);
}

void Heavy_petal_test::cReceive_3XBwr8xm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_XpmSvl6I_sendMessage);
}

void Heavy_petal_test::cVar_YmpsuvxX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_qEZSrpu9_sendMessage);
}

void Heavy_petal_test::cMsg_pM33KNfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_XpmSvl6I_sendMessage);
}

void Heavy_petal_test::cCast_k2e24tnF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o9SumZOD_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cVar_VdlhBaIS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BeVLwfnb, HV_BINOP_ADD, 0, m, &cBinop_BeVLwfnb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQcsguUo, HV_BINOP_ADD, 0, m, &cBinop_yQcsguUo_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uBBhccwU, m);
}

void Heavy_petal_test::cBinop_NtOxhiOp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tCHctrwg, 1, m, &cVar_tCHctrwg_sendMessage);
}

void Heavy_petal_test::cMsg_6ZlKHlUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_byox4jc3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cCast_FBGT8sdT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k2e24tnF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQcsguUo, HV_BINOP_ADD, 0, m, &cBinop_yQcsguUo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VdlhBaIS, 1, m, &cVar_VdlhBaIS_sendMessage);
}

void Heavy_petal_test::cBinop_5lXXtMQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cbGtkcsc, HV_BINOP_DIVIDE, 1, m, &cBinop_cbGtkcsc_sendMessage);
}

void Heavy_petal_test::cBinop_yQcsguUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZY3vKZnm, 0, m, &cVar_ZY3vKZnm_sendMessage);
}

void Heavy_petal_test::cBinop_VwsgLj21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wWuXYRDR, HV_BINOP_SUBTRACT, 1, m, &cBinop_wWuXYRDR_sendMessage);
}

void Heavy_petal_test::cCast_sBKsRWRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bBuG7erI_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cSwitchcase_bA7YFKuK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sBKsRWRZ_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_8emhy72t, HV_BINOP_MULTIPLY, 0, m, &cBinop_8emhy72t_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_5lXXtMQz, HV_BINOP_DIVIDE, 1, m, &cBinop_5lXXtMQz_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_umWS32to, 0, m, &cVar_umWS32to_sendMessage);
      break;
    }
  }
}

void Heavy_petal_test::cCast_Q7aojFyj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5lXXtMQz, HV_BINOP_DIVIDE, 0, m, &cBinop_5lXXtMQz_sendMessage);
}

void Heavy_petal_test::cCast_FKUqkyw6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OLuoQWeE, 1, m, &cVar_OLuoQWeE_sendMessage);
}

void Heavy_petal_test::cCast_BtNMO6Ho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XzVSrD7t_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cCast_0JKoU8JH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vyBIapfG, 0, m, &cVar_vyBIapfG_sendMessage);
}

void Heavy_petal_test::cVar_tCHctrwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wWuXYRDR, HV_BINOP_SUBTRACT, 0, m, &cBinop_wWuXYRDR_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_gTq6bgqZ_sendMessage);
}

void Heavy_petal_test::cVar_gh6oPXPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bA7YFKuK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cBinop_cbGtkcsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQcsguUo, HV_BINOP_ADD, 1, m, &cBinop_yQcsguUo_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BeVLwfnb, HV_BINOP_ADD, 1, m, &cBinop_BeVLwfnb_sendMessage);
}

void Heavy_petal_test::cSlice_D59FngxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FKUqkyw6_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0YLUcuTe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_petal_test::cSlice_TV4KM8oi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CSHwZjrz_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q7aojFyj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_petal_test::cMsg_Vis0Y4Rd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3zwOx0ln_sendMessage);
}

void Heavy_petal_test::cSystem_3zwOx0ln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8emhy72t, HV_BINOP_MULTIPLY, 1, m, &cBinop_8emhy72t_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TcjulL37, HV_BINOP_MULTIPLY, 1, m, &cBinop_TcjulL37_sendMessage);
}

void Heavy_petal_test::cMsg_bBuG7erI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8emhy72t, HV_BINOP_MULTIPLY, 0, m, &cBinop_8emhy72t_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5lXXtMQz, HV_BINOP_DIVIDE, 1, m, &cBinop_5lXXtMQz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_umWS32to, 0, m, &cVar_umWS32to_sendMessage);
}

void Heavy_petal_test::cCast_UanUq7gK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o4w03pVt_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cCast_SL1wh8z3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TVC7JnbH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RLTq7Puz_sendMessage);
}

void Heavy_petal_test::cCast_b5BWKsaC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VdlhBaIS, 0, m, &cVar_VdlhBaIS_sendMessage);
}

void Heavy_petal_test::cSwitchcase_OUz1cXKP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b5BWKsaC_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SL1wh8z3_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_petal_test::cMsg_XzVSrD7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_vyBIapfG, 1, m, &cVar_vyBIapfG_sendMessage);
}

void Heavy_petal_test::cVar_ZY3vKZnm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m05D3rOs, HV_BINOP_SUBTRACT, 1, m, &cBinop_m05D3rOs_sendMessage);
}

void Heavy_petal_test::cMsg_o4w03pVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_byox4jc3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cMsg_Q4Ki9W2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3MHAsY98, 0, m, &cDelay_3MHAsY98_sendMessage);
}

void Heavy_petal_test::cSwitchcase_byox4jc3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_Q4Ki9W2L_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Q4Ki9W2L_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qh30QpSh_sendMessage);
      break;
    }
  }
}

void Heavy_petal_test::cBinop_FmIdbrVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_LUuovmw1_sendMessage);
}

void Heavy_petal_test::cCast_Qh30QpSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q4Ki9W2L_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3MHAsY98, 0, m, &cDelay_3MHAsY98_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tCHctrwg, 0, m, &cVar_tCHctrwg_sendMessage);
}

void Heavy_petal_test::cDelay_3MHAsY98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3MHAsY98, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3MHAsY98, 0, m, &cDelay_3MHAsY98_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tCHctrwg, 0, m, &cVar_tCHctrwg_sendMessage);
}

void Heavy_petal_test::cBinop_LUuovmw1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3MHAsY98, 2, m, &cDelay_3MHAsY98_sendMessage);
}

void Heavy_petal_test::cSystem_tZ3oEof9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bFUY5oyT_sendMessage);
}

void Heavy_petal_test::cMsg_TurFRjFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tZ3oEof9_sendMessage);
}

void Heavy_petal_test::cBinop_bFUY5oyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FmIdbrVx, HV_BINOP_MULTIPLY, 1, m, &cBinop_FmIdbrVx_sendMessage);
}

void Heavy_petal_test::cVar_umWS32to_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FmIdbrVx, HV_BINOP_MULTIPLY, 0, m, &cBinop_FmIdbrVx_sendMessage);
}

void Heavy_petal_test::cBinop_TcjulL37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NtOxhiOp_sendMessage);
}

void Heavy_petal_test::cBinop_gTq6bgqZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OUz1cXKP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cVar_OLuoQWeE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VdlhBaIS, 0, m, &cVar_VdlhBaIS_sendMessage);
}

void Heavy_petal_test::cCast_TVC7JnbH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o9SumZOD_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cCast_RLTq7Puz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OLuoQWeE, 0, m, &cVar_OLuoQWeE_sendMessage);
}

void Heavy_petal_test::cBinop_BeVLwfnb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VdlhBaIS, 1, m, &cVar_VdlhBaIS_sendMessage);
}

void Heavy_petal_test::cMsg_o9SumZOD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_byox4jc3_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQcsguUo, HV_BINOP_ADD, 1, m, &cBinop_yQcsguUo_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BeVLwfnb, HV_BINOP_ADD, 1, m, &cBinop_BeVLwfnb_sendMessage);
}

void Heavy_petal_test::cCast_inVqVguw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6ZlKHlUH_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cBinop_m05D3rOs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cbGtkcsc, HV_BINOP_DIVIDE, 0, m, &cBinop_cbGtkcsc_sendMessage);
}

void Heavy_petal_test::cCast_0YLUcuTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m05D3rOs, HV_BINOP_SUBTRACT, 0, m, &cBinop_m05D3rOs_sendMessage);
}

void Heavy_petal_test::cVar_vyBIapfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CSHwZjrz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q7aojFyj_sendMessage);
}

void Heavy_petal_test::cCast_CSHwZjrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TcjulL37, HV_BINOP_MULTIPLY, 0, m, &cBinop_TcjulL37_sendMessage);
}

void Heavy_petal_test::cBinop_wWuXYRDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tCHctrwg, 1, m, &cVar_tCHctrwg_sendMessage);
}

void Heavy_petal_test::cBinop_8emhy72t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VwsgLj21_sendMessage);
}

void Heavy_petal_test::cSlice_Nqvp3C5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_o4w03pVt_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_o4w03pVt_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_petal_test::cSlice_vcAqeYiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UanUq7gK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FBGT8sdT_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UanUq7gK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FBGT8sdT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_petal_test::cSwitchcase_6KnmrekP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Nqvp3C5J, 0, m, &cSlice_Nqvp3C5J_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vcAqeYiz, 0, m, &cSlice_vcAqeYiz_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0JKoU8JH_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_TV4KM8oi, 0, m, &cSlice_TV4KM8oi_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_D59FngxH, 0, m, &cSlice_D59FngxH_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_inVqVguw_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BtNMO6Ho_sendMessage);
      break;
    }
  }
}

void Heavy_petal_test::cCast_W9bPi5Pp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4GPfZ1Xe_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cCast_4oD3aeKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SSMGoKZq_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cBinop_6v6QBrNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eOJe2Jc0_sendMessage);
}

void Heavy_petal_test::cBinop_6EXmGtDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7N3LSOIs_sendMessage);
}

void Heavy_petal_test::cBinop_CEBcSc3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LykvX4Uc, HV_BINOP_DIVIDE, 0, m, &cBinop_LykvX4Uc_sendMessage);
}

void Heavy_petal_test::cMsg_SSMGoKZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_CvBDQJUq_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_a9A0A485, HV_BINOP_ADD, 1, m, &cBinop_a9A0A485_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nv3T7nbY, HV_BINOP_ADD, 1, m, &cBinop_Nv3T7nbY_sendMessage);
}

void Heavy_petal_test::cCast_hxgaGDXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DlgsExcB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_a9A0A485, HV_BINOP_ADD, 0, m, &cBinop_a9A0A485_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WrDukJUd, 1, m, &cVar_WrDukJUd_sendMessage);
}

void Heavy_petal_test::cVar_20M3nxPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CEBcSc3o, HV_BINOP_SUBTRACT, 1, m, &cBinop_CEBcSc3o_sendMessage);
}

void Heavy_petal_test::cMsg_lan5jRom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_CvBDQJUq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cCast_DlgsExcB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SSMGoKZq_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cCast_15dW2K9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CEBcSc3o, HV_BINOP_SUBTRACT, 0, m, &cBinop_CEBcSc3o_sendMessage);
}

void Heavy_petal_test::cCast_PLzz8thG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lan5jRom_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cMsg_4GPfZ1Xe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_CvBDQJUq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cBinop_9cA2scH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BRu5uNRx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cBinop_eOJe2Jc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kNfCvu4F, HV_BINOP_SUBTRACT, 1, m, &cBinop_kNfCvu4F_sendMessage);
}

void Heavy_petal_test::cCast_jxVSx5K6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5OYVuhdA, 0, m, &cVar_5OYVuhdA_sendMessage);
}

void Heavy_petal_test::cVar_WrDukJUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nv3T7nbY, HV_BINOP_ADD, 0, m, &cBinop_Nv3T7nbY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_a9A0A485, HV_BINOP_ADD, 0, m, &cBinop_a9A0A485_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rnjq9VIF, m);
}

void Heavy_petal_test::cBinop_a9A0A485_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_20M3nxPk, 0, m, &cVar_20M3nxPk_sendMessage);
}

void Heavy_petal_test::cMsg_2YHVq5XG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6v6QBrNW, HV_BINOP_MULTIPLY, 0, m, &cBinop_6v6QBrNW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wJY3CRah, HV_BINOP_DIVIDE, 1, m, &cBinop_wJY3CRah_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sXv57mA9, 0, m, &cVar_sXv57mA9_sendMessage);
}

void Heavy_petal_test::cBinop_LykvX4Uc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a9A0A485, HV_BINOP_ADD, 1, m, &cBinop_a9A0A485_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nv3T7nbY, HV_BINOP_ADD, 1, m, &cBinop_Nv3T7nbY_sendMessage);
}

void Heavy_petal_test::cVar_5OYVuhdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WrDukJUd, 0, m, &cVar_WrDukJUd_sendMessage);
}

void Heavy_petal_test::cCast_2LiNGfGQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2umSHxTs, 0, m, &cVar_2umSHxTs_sendMessage);
}

void Heavy_petal_test::cVar_MyWzF8im_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BFvKq43R_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cSystem_kCszs9Rr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6v6QBrNW, HV_BINOP_MULTIPLY, 1, m, &cBinop_6v6QBrNW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6EXmGtDK, HV_BINOP_MULTIPLY, 1, m, &cBinop_6EXmGtDK_sendMessage);
}

void Heavy_petal_test::cMsg_yqb689BU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kCszs9Rr_sendMessage);
}

void Heavy_petal_test::cVar_2umSHxTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Xclg7bMa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9EA1mq8r_sendMessage);
}

void Heavy_petal_test::cCast_RuUQXIhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4oD3aeKl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jxVSx5K6_sendMessage);
}

void Heavy_petal_test::cCast_R7Gy1FVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WrDukJUd, 0, m, &cVar_WrDukJUd_sendMessage);
}

void Heavy_petal_test::cSwitchcase_BRu5uNRx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R7Gy1FVW_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RuUQXIhj_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_petal_test::cCast_Xclg7bMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6EXmGtDK, HV_BINOP_MULTIPLY, 0, m, &cBinop_6EXmGtDK_sendMessage);
}

void Heavy_petal_test::cSlice_XjjNKra6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_lan5jRom_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_lan5jRom_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_petal_test::cSwitchcase_j9Majx8X_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XjjNKra6, 0, m, &cSlice_XjjNKra6_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LbCSuzN7, 0, m, &cSlice_LbCSuzN7_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2LiNGfGQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_H2Fd7pHh, 0, m, &cSlice_H2Fd7pHh_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_710HHYYX, 0, m, &cSlice_710HHYYX_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W9bPi5Pp_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Yj0i5EHW_sendMessage);
      break;
    }
  }
}

void Heavy_petal_test::cSlice_LbCSuzN7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PLzz8thG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hxgaGDXM_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PLzz8thG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hxgaGDXM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_petal_test::cMsg_Gyg1zZAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_2umSHxTs, 1, m, &cVar_2umSHxTs_sendMessage);
}

void Heavy_petal_test::cVar_aDl1kW6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kNfCvu4F, HV_BINOP_SUBTRACT, 0, m, &cBinop_kNfCvu4F_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_9cA2scH7_sendMessage);
}

void Heavy_petal_test::cCast_9EA1mq8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wJY3CRah, HV_BINOP_DIVIDE, 0, m, &cBinop_wJY3CRah_sendMessage);
}

void Heavy_petal_test::cBinop_wJY3CRah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LykvX4Uc, HV_BINOP_DIVIDE, 1, m, &cBinop_LykvX4Uc_sendMessage);
}

void Heavy_petal_test::cCast_Yj0i5EHW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Gyg1zZAl_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cCast_3RdwwIc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5OYVuhdA, 1, m, &cVar_5OYVuhdA_sendMessage);
}

void Heavy_petal_test::cBinop_Nv3T7nbY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WrDukJUd, 1, m, &cVar_WrDukJUd_sendMessage);
}

void Heavy_petal_test::cSlice_H2Fd7pHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Xclg7bMa_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9EA1mq8r_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_petal_test::cSlice_710HHYYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3RdwwIc5_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_15dW2K9P_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_petal_test::cCast_Wa8RQPNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2YHVq5XG_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cSwitchcase_BFvKq43R_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wa8RQPNs_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6v6QBrNW, HV_BINOP_MULTIPLY, 0, m, &cBinop_6v6QBrNW_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_wJY3CRah, HV_BINOP_DIVIDE, 1, m, &cBinop_wJY3CRah_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_sXv57mA9, 0, m, &cVar_sXv57mA9_sendMessage);
      break;
    }
  }
}

void Heavy_petal_test::cBinop_7N3LSOIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aDl1kW6a, 1, m, &cVar_aDl1kW6a_sendMessage);
}

void Heavy_petal_test::cBinop_kNfCvu4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aDl1kW6a, 1, m, &cVar_aDl1kW6a_sendMessage);
}

void Heavy_petal_test::cCast_diR8sBVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZcrUOTdl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IufVJXCc, 0, m, &cDelay_IufVJXCc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aDl1kW6a, 0, m, &cVar_aDl1kW6a_sendMessage);
}

void Heavy_petal_test::cBinop_IdYmbulu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_afz25G9G, HV_BINOP_MULTIPLY, 1, m, &cBinop_afz25G9G_sendMessage);
}

void Heavy_petal_test::cBinop_afz25G9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_8T6l5grT_sendMessage);
}

void Heavy_petal_test::cSwitchcase_CvBDQJUq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_ZcrUOTdl_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ZcrUOTdl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_diR8sBVv_sendMessage);
      break;
    }
  }
}

void Heavy_petal_test::cDelay_IufVJXCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IufVJXCc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IufVJXCc, 0, m, &cDelay_IufVJXCc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aDl1kW6a, 0, m, &cVar_aDl1kW6a_sendMessage);
}

void Heavy_petal_test::cMsg_ZcrUOTdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IufVJXCc, 0, m, &cDelay_IufVJXCc_sendMessage);
}

void Heavy_petal_test::cMsg_5tehPfLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JlPbm1KJ_sendMessage);
}

void Heavy_petal_test::cSystem_JlPbm1KJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IdYmbulu_sendMessage);
}

void Heavy_petal_test::cBinop_8T6l5grT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IufVJXCc, 2, m, &cDelay_IufVJXCc_sendMessage);
}

void Heavy_petal_test::cVar_sXv57mA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_afz25G9G, HV_BINOP_MULTIPLY, 0, m, &cBinop_afz25G9G_sendMessage);
}

void Heavy_petal_test::cCast_XW13jcd0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DkqOmxsC_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cVar_Ergnj9u7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_atoaIX3x_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FcPSuKmn, 0, m, &cVar_FcPSuKmn_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_c9Q7q45r, m);
}

void Heavy_petal_test::cMsg_tuZbk1zs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_XpmSvl6I_sendMessage);
}

void Heavy_petal_test::cMsg_o6KlbRZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_j9Majx8X_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_petal_test::cCast_oJuj7dxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ergnj9u7, 0, m, &cVar_Ergnj9u7_sendMessage);
}

void Heavy_petal_test::cReceive_5Q8t6MBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0a7wHr8Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EN6m3tUR_sendMessage);
}

void Heavy_petal_test::cReceive_TMsKH8Ww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ergnj9u7, 0, m, &cVar_Ergnj9u7_sendMessage);
}

void Heavy_petal_test::cCast_BORh0s4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0a7wHr8Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EN6m3tUR_sendMessage);
}

void Heavy_petal_test::cBinop_2ODTAxu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_osPQurYz, 0, m, &cVar_osPQurYz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3zcUMp9P, 0, m, &cVar_3zcUMp9P_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8IZ8sKWo, m);
}

void Heavy_petal_test::cReceive_RZNhau8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_qEZSrpu9_sendMessage);
}

void Heavy_petal_test::cMsg_xmQQ0YfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Ergnj9u7, 0, m, &cVar_Ergnj9u7_sendMessage);
}

void Heavy_petal_test::cVar_osPQurYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_petal_test::cReceive_dd1ym3M5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XW13jcd0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SJNs2t0f_sendMessage);
}

void Heavy_petal_test::cBinop_atoaIX3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 2.0f, 0, m, &cBinop_C6LaSMdc_sendMessage);
}

void Heavy_petal_test::cReceive_1vX2h3Dw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_8cw7PpNP_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_petal_test::process(float **inputBuffers, float **outputBuffers, int n) {
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
    __hv_varread_f(&sVarf_1b6i0uCP, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_kJRW9ADR, VOf(Bf1));
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
    __hv_varread_f(&sVarf_8IZ8sKWo, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_c9Q7q45r, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_phasor_f(&sPhasor_T1iF8cLj, VIf(Bf0), VOf(Bf0));
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
    __hv_varread_f(&sVarf_rnjq9VIF, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_211XSfvy, VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_iQsxF8Yj, VIf(Bf2), VOf(Bf2));
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
    __hv_varread_f(&sVarf_uBBhccwU, VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_petal_test::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_petal_test::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
