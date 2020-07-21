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
  numBytes += sPhasor_k_init(&sPhasor_hJWdm9Ol, 0.0f, sampleRate);
  numBytes += sPhasor_init(&sPhasor_DopNmaFi, sampleRate);
  numBytes += sPhasor_init(&sPhasor_zlXMtElD, sampleRate);
  numBytes += sVarf_init(&sVarf_LdOvhZOY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_krhuWRYl, 0.0f);
  numBytes += cBinop_init(&cBinop_thw3ptvf, 0.0f); // __add
  numBytes += cDelay_init(this, &cDelay_JsbMSXEf, 0.0f);
  numBytes += cVar_init_f(&cVar_yNqJxjQN, 20.0f);
  numBytes += cBinop_init(&cBinop_Y6RJB16d, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_XgLKxRzc, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_gUxQ2PE0, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_UXTI5Osq, 0.0f);
  numBytes += cBinop_init(&cBinop_JWXzRph7, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_rErqrMRn, 0.0f);
  numBytes += cSlice_init(&cSlice_ezdXe0hN, 1, 1);
  numBytes += cSlice_init(&cSlice_6nfCZZcY, 0, 1);
  numBytes += cBinop_init(&cBinop_7nPWSOf7, 0.0f); // __sub
  numBytes += cSlice_init(&cSlice_8wdGarS0, 1, -1);
  numBytes += cSlice_init(&cSlice_wPCnCY1q, 1, -1);
  numBytes += cBinop_init(&cBinop_ai4fKLrf, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_mRRcv7eF, 0.0f);
  numBytes += cVar_init_f(&cVar_xSR5AsFN, 20.0f);
  numBytes += cBinop_init(&cBinop_6btXQ1yW, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_TDgRAhee, 0.0f);
  numBytes += cVar_init_f(&cVar_oGIfS2HF, 0.0f);
  numBytes += cBinop_init(&cBinop_LBHOWwgN, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_L8wMyat0, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_yUBUEV9d, 0.0f);
  numBytes += sVarf_init(&sVarf_EbJF4KQz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PwhWE0TY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YAH1GeAC, 0.0f);
  numBytes += cVar_init_f(&cVar_in20j42w, 0.0f);
  numBytes += cVar_init_f(&cVar_enCBf0dm, 0.0f);
  numBytes += cVar_init_f(&cVar_lSVOWCh3, 0.0f);
  numBytes += cVar_init_f(&cVar_Vy6Lt8Kt, 0.0f);
  numBytes += cBinop_init(&cBinop_kEjlQihs, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_prAVjwaj, 0.0f);
  numBytes += cVar_init_f(&cVar_VqetHPss, 0.0f);
  numBytes += cBinop_init(&cBinop_QEZ4IvJC, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_g3ZeDgiZ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_wL8EC3uu, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_pzBAyumX, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_5SiBM89a, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_1KIOu314, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WNLyOTjM, 0.0f);
  numBytes += cVar_init_f(&cVar_1aakfp5j, 20.0f);
  numBytes += cBinop_init(&cBinop_vrT8CEBb, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_wKSTuUpA, 0, 1);
  numBytes += cSlice_init(&cSlice_x5ChvLoN, 1, 1);
  numBytes += cBinop_init(&cBinop_yTGFrF4l, 0.0f); // __sub
  numBytes += cSlice_init(&cSlice_KsBqLfHx, 1, -1);
  numBytes += cSlice_init(&cSlice_0rWL1X3Y, 1, -1);
  numBytes += cBinop_init(&cBinop_lZL3MU6u, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_toOqOYyA, 0.0f);
  numBytes += cVar_init_f(&cVar_s1UfJbaT, 20.0f);
  numBytes += sVarf_init(&sVarf_d8h4T5Gx, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xCMcW5Kd_sendMessage);
      break;
    }
    case 0x3FE62CA: { // Button2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4BM8DAGM_sendMessage);
      break;
    }
    case 0x7AAC371F: { // EncSwitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kDSFS8yG_sendMessage);
      break;
    }
    case 0x62DD3F82: { // Knob1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IaEoKvTC_sendMessage);
      break;
    }
    case 0x6BE4E001: { // Knob2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EB7rRnV4_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sibBgQCK_sendMessage);
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


void Heavy_pod_test::cMsg_LUy0FBSK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_hJWdm9Ol, 0, m);
}

void Heavy_pod_test::cReceive_sibBgQCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7tbPlqNn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1aakfp5j, 0, m, &cVar_1aakfp5j_sendMessage);
  cMsg_ygBuN3jN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yNqJxjQN, 0, m, &cVar_yNqJxjQN_sendMessage);
  cMsg_BziJtgZ3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VqetHPss, 0, m, &cVar_VqetHPss_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_s1UfJbaT, 0, m, &cVar_s1UfJbaT_sendMessage);
  cMsg_qBADOtuF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mRRcv7eF, 0, m, &cVar_mRRcv7eF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xSR5AsFN, 0, m, &cVar_xSR5AsFN_sendMessage);
  cMsg_LUy0FBSK_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cVar_krhuWRYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_enCBf0dm, 0, m, &cVar_enCBf0dm_sendMessage);
}

void Heavy_pod_test::cMsg_nUMZAJOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_oehld6aj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cMsg_wUPuQfJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_fQHDBnUb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_4xy4sxNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UXTI5Osq, 1, m, &cVar_UXTI5Osq_sendMessage);
}

void Heavy_pod_test::cBinop_thw3ptvf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mRRcv7eF, 0, m, &cVar_mRRcv7eF_sendMessage);
}

void Heavy_pod_test::cCast_WDBbAEjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HsrV1Wlq_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_ReRHycMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TVQrgVym_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_7HunDZjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3xj9tfDN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_thw3ptvf, HV_BINOP_ADD, 0, m, &cBinop_thw3ptvf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TDgRAhee, 1, m, &cVar_TDgRAhee_sendMessage);
}

void Heavy_pod_test::cMsg_HsrV1Wlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_fQHDBnUb_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_thw3ptvf, HV_BINOP_ADD, 1, m, &cBinop_thw3ptvf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LBHOWwgN, HV_BINOP_ADD, 1, m, &cBinop_LBHOWwgN_sendMessage);
}

void Heavy_pod_test::cSwitchcase_fQHDBnUb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_hHo7vRH9_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_hHo7vRH9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jJpxIQby_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cDelay_JsbMSXEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JsbMSXEf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JsbMSXEf, 0, m, &cDelay_JsbMSXEf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rErqrMRn, 0, m, &cVar_rErqrMRn_sendMessage);
}

void Heavy_pod_test::cMsg_hHo7vRH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JsbMSXEf, 0, m, &cDelay_JsbMSXEf_sendMessage);
}

void Heavy_pod_test::cVar_yNqJxjQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y6RJB16d, HV_BINOP_MULTIPLY, 0, m, &cBinop_Y6RJB16d_sendMessage);
}

void Heavy_pod_test::cBinop_X0dUmaUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JsbMSXEf, 2, m, &cDelay_JsbMSXEf_sendMessage);
}

void Heavy_pod_test::cBinop_Y6RJB16d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_X0dUmaUx_sendMessage);
}

void Heavy_pod_test::cCast_jJpxIQby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hHo7vRH9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JsbMSXEf, 0, m, &cDelay_JsbMSXEf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rErqrMRn, 0, m, &cVar_rErqrMRn_sendMessage);
}

void Heavy_pod_test::cMsg_ygBuN3jN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hyt26SvK_sendMessage);
}

void Heavy_pod_test::cSystem_hyt26SvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KFu6Ynxa_sendMessage);
}

void Heavy_pod_test::cBinop_KFu6Ynxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y6RJB16d, HV_BINOP_MULTIPLY, 1, m, &cBinop_Y6RJB16d_sendMessage);
}

void Heavy_pod_test::cCast_NI4g1x0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wUPuQfJB_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_XgLKxRzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_thw3ptvf, HV_BINOP_ADD, 1, m, &cBinop_thw3ptvf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LBHOWwgN, HV_BINOP_ADD, 1, m, &cBinop_LBHOWwgN_sendMessage);
}

void Heavy_pod_test::cMsg_RHp5bCVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6btXQ1yW, HV_BINOP_MULTIPLY, 0, m, &cBinop_6btXQ1yW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gUxQ2PE0, HV_BINOP_DIVIDE, 1, m, &cBinop_gUxQ2PE0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yNqJxjQN, 0, m, &cVar_yNqJxjQN_sendMessage);
}

void Heavy_pod_test::cBinop_gUxQ2PE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XgLKxRzc, HV_BINOP_DIVIDE, 1, m, &cBinop_XgLKxRzc_sendMessage);
}

void Heavy_pod_test::cVar_UXTI5Osq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TDgRAhee, 0, m, &cVar_TDgRAhee_sendMessage);
}

void Heavy_pod_test::cBinop_JWXzRph7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XgLKxRzc, HV_BINOP_DIVIDE, 0, m, &cBinop_XgLKxRzc_sendMessage);
}

void Heavy_pod_test::cBinop_BgDmbhTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rErqrMRn, 1, m, &cVar_rErqrMRn_sendMessage);
}

void Heavy_pod_test::cCast_ElCRizg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gUxQ2PE0, HV_BINOP_DIVIDE, 0, m, &cBinop_gUxQ2PE0_sendMessage);
}

void Heavy_pod_test::cCast_Sy45LGzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ai4fKLrf, HV_BINOP_MULTIPLY, 0, m, &cBinop_ai4fKLrf_sendMessage);
}

void Heavy_pod_test::cBinop_GJuh0mUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pYWordMa_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cMsg_TVQrgVym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_fQHDBnUb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_WiqJ1ERm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oGIfS2HF, 0, m, &cVar_oGIfS2HF_sendMessage);
}

void Heavy_pod_test::cCast_X9MgXM6e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6sIABKgd_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_jxlJl4bn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UXTI5Osq, 0, m, &cVar_UXTI5Osq_sendMessage);
}

void Heavy_pod_test::cMsg_6sIABKgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_oGIfS2HF, 1, m, &cVar_oGIfS2HF_sendMessage);
}

void Heavy_pod_test::cCast_ImMADj16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WDBbAEjQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jxlJl4bn_sendMessage);
}

void Heavy_pod_test::cCast_BjNgwo00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TDgRAhee, 0, m, &cVar_TDgRAhee_sendMessage);
}

void Heavy_pod_test::cSwitchcase_pYWordMa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BjNgwo00_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ImMADj16_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cVar_rErqrMRn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7nPWSOf7, HV_BINOP_SUBTRACT, 0, m, &cBinop_7nPWSOf7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_GJuh0mUK_sendMessage);
}

void Heavy_pod_test::cSlice_ezdXe0hN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Sy45LGzn_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ElCRizg0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_6nfCZZcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4xy4sxNd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1MFkVCKF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cBinop_7nPWSOf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rErqrMRn, 1, m, &cVar_rErqrMRn_sendMessage);
}

void Heavy_pod_test::cSlice_8wdGarS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NI4g1x0W_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7HunDZjK_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NI4g1x0W_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7HunDZjK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_wPCnCY1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_wUPuQfJB_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_wUPuQfJB_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSwitchcase_OgAQuYEM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_wPCnCY1q, 0, m, &cSlice_wPCnCY1q_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8wdGarS0, 0, m, &cSlice_8wdGarS0_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WiqJ1ERm_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ezdXe0hN, 0, m, &cSlice_ezdXe0hN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_6nfCZZcY, 0, m, &cSlice_6nfCZZcY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ReRHycMV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X9MgXM6e_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cCast_LpVGKGKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RHp5bCVQ_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_zKL97LIp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LpVGKGKO_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6btXQ1yW, HV_BINOP_MULTIPLY, 0, m, &cBinop_6btXQ1yW_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_gUxQ2PE0, HV_BINOP_DIVIDE, 1, m, &cBinop_gUxQ2PE0_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_yNqJxjQN, 0, m, &cVar_yNqJxjQN_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cBinop_ai4fKLrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BgDmbhTe_sendMessage);
}

void Heavy_pod_test::cCast_3xj9tfDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HsrV1Wlq_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cVar_mRRcv7eF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JWXzRph7, HV_BINOP_SUBTRACT, 1, m, &cBinop_JWXzRph7_sendMessage);
}

void Heavy_pod_test::cVar_xSR5AsFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zKL97LIp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_6btXQ1yW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bk99QC81_sendMessage);
}

void Heavy_pod_test::cCast_1MFkVCKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JWXzRph7, HV_BINOP_SUBTRACT, 0, m, &cBinop_JWXzRph7_sendMessage);
}

void Heavy_pod_test::cVar_TDgRAhee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LBHOWwgN, HV_BINOP_ADD, 0, m, &cBinop_LBHOWwgN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_thw3ptvf, HV_BINOP_ADD, 0, m, &cBinop_thw3ptvf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LdOvhZOY, m);
}

void Heavy_pod_test::cBinop_bk99QC81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7nPWSOf7, HV_BINOP_SUBTRACT, 1, m, &cBinop_7nPWSOf7_sendMessage);
}

void Heavy_pod_test::cVar_oGIfS2HF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Sy45LGzn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ElCRizg0_sendMessage);
}

void Heavy_pod_test::cBinop_LBHOWwgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TDgRAhee, 1, m, &cVar_TDgRAhee_sendMessage);
}

void Heavy_pod_test::cMsg_qBADOtuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JuuCUVkv_sendMessage);
}

void Heavy_pod_test::cSystem_JuuCUVkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6btXQ1yW, HV_BINOP_MULTIPLY, 1, m, &cBinop_6btXQ1yW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ai4fKLrf, HV_BINOP_MULTIPLY, 1, m, &cBinop_ai4fKLrf_sendMessage);
}

void Heavy_pod_test::cMsg_iVspiE9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  cSwitchcase_OgAQuYEM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cReceive_xCMcW5Kd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Iw06JKVC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0HgD9csM_sendMessage);
}

void Heavy_pod_test::cBinop_fZsvqTNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yUBUEV9d, 1, m, &cVar_yUBUEV9d_sendMessage);
}

void Heavy_pod_test::cCast_0HgD9csM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nUMZAJOf_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_Iw06JKVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u9EOmEIA_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_B3iR4fq6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iVspiE9l_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cVar_yUBUEV9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_uGBN4vIO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lSVOWCh3, 0, m, &cVar_lSVOWCh3_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_PwhWE0TY, m);
}

void Heavy_pod_test::cReceive_kDSFS8yG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yUBUEV9d, 0, m, &cVar_yUBUEV9d_sendMessage);
}

void Heavy_pod_test::cBinop_2ePW7xrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EbJF4KQz, m);
}

void Heavy_pod_test::cVar_YAH1GeAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_2ePW7xrQ_sendMessage);
}

void Heavy_pod_test::cVar_in20j42w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_DDQQnVp6_sendMessage);
}

void Heavy_pod_test::cBinop_DDQQnVp6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_L8wMyat0, m);
}

void Heavy_pod_test::cVar_enCBf0dm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pod_test::cCast_yMI12Kl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Iw06JKVC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0HgD9csM_sendMessage);
}

void Heavy_pod_test::cReceive_EB7rRnV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_2ePW7xrQ_sendMessage);
}

void Heavy_pod_test::cMsg_JrKUDDpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_OgAQuYEM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cVar_lSVOWCh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pod_test::cVar_Vy6Lt8Kt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1KIOu314, 0, m, &cVar_1KIOu314_sendMessage);
}

void Heavy_pod_test::cBinop_kEjlQihs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_42vpwUsN_sendMessage);
}

void Heavy_pod_test::cVar_prAVjwaj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZMk4N5Mo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rx7GUYQJ_sendMessage);
}

void Heavy_pod_test::cCast_VfvrhqE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GbZdxjBV_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_EzPtAE8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kEjlQihs, HV_BINOP_MULTIPLY, 0, m, &cBinop_kEjlQihs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lZL3MU6u, HV_BINOP_DIVIDE, 1, m, &cBinop_lZL3MU6u_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1aakfp5j, 0, m, &cVar_1aakfp5j_sendMessage);
}

void Heavy_pod_test::cVar_VqetHPss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yTGFrF4l, HV_BINOP_SUBTRACT, 1, m, &cBinop_yTGFrF4l_sendMessage);
}

void Heavy_pod_test::cCast_Dvx0Srz9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EzPtAE8r_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cSwitchcase_4QGkrcoJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dvx0Srz9_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kEjlQihs, HV_BINOP_MULTIPLY, 0, m, &cBinop_kEjlQihs_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_lZL3MU6u, HV_BINOP_DIVIDE, 1, m, &cBinop_lZL3MU6u_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_1aakfp5j, 0, m, &cVar_1aakfp5j_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cBinop_42vpwUsN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wL8EC3uu, HV_BINOP_SUBTRACT, 1, m, &cBinop_wL8EC3uu_sendMessage);
}

void Heavy_pod_test::cCast_Sp5uMUow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GbZdxjBV_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cBinop_QEZ4IvJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1KIOu314, 1, m, &cVar_1KIOu314_sendMessage);
}

void Heavy_pod_test::cMsg_pNjj660u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_138FipWX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_ZMk4N5Mo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g3ZeDgiZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_g3ZeDgiZ_sendMessage);
}

void Heavy_pod_test::cBinop_g3ZeDgiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OFbZasJk_sendMessage);
}

void Heavy_pod_test::cBinop_wL8EC3uu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_toOqOYyA, 1, m, &cVar_toOqOYyA_sendMessage);
}

void Heavy_pod_test::cMsg_miBnKw3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_138FipWX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cBinop_pzBAyumX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5SiBM89a, HV_BINOP_ADD, 1, m, &cBinop_5SiBM89a_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QEZ4IvJC, HV_BINOP_ADD, 1, m, &cBinop_QEZ4IvJC_sendMessage);
}

void Heavy_pod_test::cBinop_5SiBM89a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VqetHPss, 0, m, &cVar_VqetHPss_sendMessage);
}

void Heavy_pod_test::cVar_1KIOu314_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QEZ4IvJC, HV_BINOP_ADD, 0, m, &cBinop_QEZ4IvJC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5SiBM89a, HV_BINOP_ADD, 0, m, &cBinop_5SiBM89a_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_d8h4T5Gx, m);
}

void Heavy_pod_test::cMsg_BziJtgZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_w3O83Qh6_sendMessage);
}

void Heavy_pod_test::cSystem_w3O83Qh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kEjlQihs, HV_BINOP_MULTIPLY, 1, m, &cBinop_kEjlQihs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_g3ZeDgiZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_g3ZeDgiZ_sendMessage);
}

void Heavy_pod_test::cCast_EtcPJwxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gkkjbd8H_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cCast_LKjTNWnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Sp5uMUow_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BcYucJZs_sendMessage);
}

void Heavy_pod_test::cCast_DMQERr58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1KIOu314, 0, m, &cVar_1KIOu314_sendMessage);
}

void Heavy_pod_test::cSwitchcase_ZBmFFyaC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DMQERr58_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LKjTNWnP_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pod_test::cMsg_b4LuKrT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WNLyOTjM, 0, m, &cDelay_WNLyOTjM_sendMessage);
}

void Heavy_pod_test::cDelay_WNLyOTjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WNLyOTjM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WNLyOTjM, 0, m, &cDelay_WNLyOTjM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_toOqOYyA, 0, m, &cVar_toOqOYyA_sendMessage);
}

void Heavy_pod_test::cCast_Zv35GRq3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b4LuKrT7_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WNLyOTjM, 0, m, &cDelay_WNLyOTjM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_toOqOYyA, 0, m, &cVar_toOqOYyA_sendMessage);
}

void Heavy_pod_test::cBinop_XJxqpnJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WNLyOTjM, 2, m, &cDelay_WNLyOTjM_sendMessage);
}

void Heavy_pod_test::cVar_1aakfp5j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vrT8CEBb, HV_BINOP_MULTIPLY, 0, m, &cBinop_vrT8CEBb_sendMessage);
}

void Heavy_pod_test::cSwitchcase_138FipWX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_b4LuKrT7_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_b4LuKrT7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Zv35GRq3_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cBinop_vrT8CEBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_XJxqpnJU_sendMessage);
}

void Heavy_pod_test::cBinop_FPgYG0Sj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vrT8CEBb, HV_BINOP_MULTIPLY, 1, m, &cBinop_vrT8CEBb_sendMessage);
}

void Heavy_pod_test::cMsg_7tbPlqNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aOrf2ooU_sendMessage);
}

void Heavy_pod_test::cSystem_aOrf2ooU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FPgYG0Sj_sendMessage);
}

void Heavy_pod_test::cSlice_wKSTuUpA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xDC8reNR_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TWsHbRSj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_x5ChvLoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZMk4N5Mo_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rx7GUYQJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cMsg_gkkjbd8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_prAVjwaj, 1, m, &cVar_prAVjwaj_sendMessage);
}

void Heavy_pod_test::cBinop_yTGFrF4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pzBAyumX, HV_BINOP_DIVIDE, 0, m, &cBinop_pzBAyumX_sendMessage);
}

void Heavy_pod_test::cCast_TWsHbRSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yTGFrF4l, HV_BINOP_SUBTRACT, 0, m, &cBinop_yTGFrF4l_sendMessage);
}

void Heavy_pod_test::cBinop_XmS1TtxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZBmFFyaC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cMsg_GbZdxjBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_138FipWX_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5SiBM89a, HV_BINOP_ADD, 1, m, &cBinop_5SiBM89a_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QEZ4IvJC, HV_BINOP_ADD, 1, m, &cBinop_QEZ4IvJC_sendMessage);
}

void Heavy_pod_test::cCast_Sad2v9z6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VfvrhqE0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5SiBM89a, HV_BINOP_ADD, 0, m, &cBinop_5SiBM89a_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1KIOu314, 1, m, &cVar_1KIOu314_sendMessage);
}

void Heavy_pod_test::cSlice_KsBqLfHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_pNjj660u_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_pNjj660u_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSlice_0rWL1X3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zGVyf740_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Sad2v9z6_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zGVyf740_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Sad2v9z6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pod_test::cSwitchcase_oehld6aj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KsBqLfHx, 0, m, &cSlice_KsBqLfHx_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0rWL1X3Y, 0, m, &cSlice_0rWL1X3Y_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zja1hDiT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_x5ChvLoN, 0, m, &cSlice_x5ChvLoN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_wKSTuUpA, 0, m, &cSlice_wKSTuUpA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KPIEkksC_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EtcPJwxH_sendMessage);
      break;
    }
  }
}

void Heavy_pod_test::cBinop_lZL3MU6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pzBAyumX, HV_BINOP_DIVIDE, 1, m, &cBinop_pzBAyumX_sendMessage);
}

void Heavy_pod_test::cCast_BcYucJZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Vy6Lt8Kt, 0, m, &cVar_Vy6Lt8Kt_sendMessage);
}

void Heavy_pod_test::cCast_zGVyf740_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pNjj660u_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cVar_toOqOYyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wL8EC3uu, HV_BINOP_SUBTRACT, 0, m, &cBinop_wL8EC3uu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_XmS1TtxW_sendMessage);
}

void Heavy_pod_test::cBinop_OFbZasJk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_toOqOYyA, 1, m, &cVar_toOqOYyA_sendMessage);
}

void Heavy_pod_test::cCast_zja1hDiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_prAVjwaj, 0, m, &cVar_prAVjwaj_sendMessage);
}

void Heavy_pod_test::cVar_s1UfJbaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4QGkrcoJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pod_test::cCast_xDC8reNR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Vy6Lt8Kt, 1, m, &cVar_Vy6Lt8Kt_sendMessage);
}

void Heavy_pod_test::cCast_rx7GUYQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lZL3MU6u, HV_BINOP_DIVIDE, 0, m, &cBinop_lZL3MU6u_sendMessage);
}

void Heavy_pod_test::cCast_KPIEkksC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_miBnKw3z_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cReceive_4BM8DAGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rfVQ36cq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B3iR4fq6_sendMessage);
}

void Heavy_pod_test::cReceive_IaEoKvTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_DDQQnVp6_sendMessage);
}

void Heavy_pod_test::cBinop_uGBN4vIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 2.0f, 0, m, &cBinop_fZsvqTNU_sendMessage);
}

void Heavy_pod_test::cCast_F7H3O8aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yUBUEV9d, 0, m, &cVar_yUBUEV9d_sendMessage);
}

void Heavy_pod_test::cCast_exuoo7uN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rfVQ36cq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B3iR4fq6_sendMessage);
}

void Heavy_pod_test::cCast_rfVQ36cq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JrKUDDpx_sendMessage(_c, 0, m);
}

void Heavy_pod_test::cMsg_u9EOmEIA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_oehld6aj_onMessage(_c, NULL, 0, m, NULL);
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
    __hv_varread_f(&sVarf_EbJF4KQz, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_hJWdm9Ol, VOf(Bf1));
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
    __hv_varread_f(&sVarf_PwhWE0TY, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_phasor_f(&sPhasor_DopNmaFi, VIf(Bf0), VOf(Bf0));
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
    __hv_varread_f(&sVarf_LdOvhZOY, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O1), VOf(O1));
    __hv_varread_f(&sVarf_L8wMyat0, VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_zlXMtElD, VIf(Bf2), VOf(Bf2));
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
    __hv_varread_f(&sVarf_d8h4T5Gx, VOf(Bf0));
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
