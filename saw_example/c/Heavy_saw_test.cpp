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

#include "Heavy_saw_test.hpp"

#define Context(_c) reinterpret_cast<Heavy_saw_test *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_saw_test_new(double sampleRate) {
    return new Heavy_saw_test(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_saw_test_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_saw_test(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_saw_test::Heavy_saw_test(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_XbFWnjal, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_wKOUDAof, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_8Cht3vET, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_HbhefDY5, 0.0f, sampleRate);
  numBytes += cVar_init_f(&cVar_F7fxJ0iq, 0.0f);
  numBytes += cVar_init_f(&cVar_FD6t5B1N, 0.0f);
  numBytes += cVar_init_f(&cVar_kjRCzRTY, 0.0f);
  numBytes += cBinop_init(&cBinop_rt0o5x3l, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_0JqBhlBS, 0.0f);
  numBytes += cBinop_init(&cBinop_rEyWJIKW, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_OHQfjsH6, 0.0f);
  numBytes += cVar_init_f(&cVar_4o5ECeDk, 0.0f);
  numBytes += cVar_init_f(&cVar_vt7TDp7W, 0.0f);
  numBytes += cVar_init_f(&cVar_wQK6Duvj, 0.0f);
  numBytes += cBinop_init(&cBinop_9Oml17LX, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_0t4Vj0fU, 0.0f);
  numBytes += cVar_init_f(&cVar_QRBDHx2W, 0.0f);
  numBytes += cBinop_init(&cBinop_le1BfLj7, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_3hAAlPrP, 0.0f);
  numBytes += cVar_init_f(&cVar_eRhWmcS4, 0.0f);
  numBytes += cVar_init_f(&cVar_efwLfj9G, 0.0f);
  numBytes += cVar_init_f(&cVar_hCjNtkPM, 0.0f);
  numBytes += cVar_init_f(&cVar_t6Qw1OoG, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_saw_test::~Heavy_saw_test() {
  // nothing to free
}

HvTable *Heavy_saw_test::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_saw_test::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x7BCBAF78: { // ChannelA
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_srjTawl5_sendMessage);
      break;
    }
    case 0x4A38F401: { // ChannelB
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_R6fvDPF5_sendMessage);
      break;
    }
    case 0x50D8682A: { // ChannelC
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TwKWkurM_sendMessage);
      break;
    }
    case 0xC09FC6FC: { // ChannelD
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nNU6qng2_sendMessage);
      break;
    }
    case 0xBAD7D492: { // ChannelE
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QMbkzw94_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DS4X3zX1_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_saw_test::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "ChannelC";
        info->hash = 0x50D8682A;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 1: {
        info->name = "ChannelB";
        info->hash = 0x4A38F401;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 2: {
        info->name = "ChannelA";
        info->hash = 0x7BCBAF78;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 3: {
        info->name = "ChannelE";
        info->hash = 0xBAD7D492;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 4: {
        info->name = "ChannelD";
        info->hash = 0xC09FC6FC;
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


void Heavy_saw_test::cBinop_5zTHL2D6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sBhbo45C_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_t7jv092g_sendMessage);
}

void Heavy_saw_test::cVar_F7fxJ0iq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YmnhTTOa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_x6gQhH88_sendMessage);
}

void Heavy_saw_test::cMsg_zWYYKpON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_F7fxJ0iq, 0, m, &cVar_F7fxJ0iq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3hAAlPrP, 0, m, &cVar_3hAAlPrP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OHQfjsH6, 0, m, &cVar_OHQfjsH6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0JqBhlBS, 0, m, &cVar_0JqBhlBS_sendMessage);
}

void Heavy_saw_test::cBinop_ycZyv3E7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0JqBhlBS, 0, m, &cVar_0JqBhlBS_sendMessage);
}

void Heavy_saw_test::cVar_FD6t5B1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cReceive_TwKWkurM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_Svxb6wJn_sendMessage);
}

void Heavy_saw_test::cVar_kjRCzRTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_wKOUDAof, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_efwLfj9G, 0, m, &cVar_efwLfj9G_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9Oml17LX, HV_BINOP_ADD, 0, m, &cBinop_9Oml17LX_sendMessage);
}

void Heavy_saw_test::cCast_qKs4tfrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_le1BfLj7, HV_BINOP_ADD, 1, m, &cBinop_le1BfLj7_sendMessage);
}

void Heavy_saw_test::cBinop_1bIBqJyq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OHQfjsH6, 0, m, &cVar_OHQfjsH6_sendMessage);
}

void Heavy_saw_test::cBinop_rt0o5x3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_8Cht3vET, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0t4Vj0fU, 0, m, &cVar_0t4Vj0fU_sendMessage);
}

void Heavy_saw_test::cBinop_gCDSGplt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_1bIBqJyq_sendMessage);
}

void Heavy_saw_test::cVar_0JqBhlBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.0f, 0, m, &cBinop_5zTHL2D6_sendMessage);
}

void Heavy_saw_test::cBinop_rEyWJIKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_HbhefDY5, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eRhWmcS4, 0, m, &cVar_eRhWmcS4_sendMessage);
}

void Heavy_saw_test::cCast_sBhbo45C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9Oml17LX, HV_BINOP_ADD, 1, m, &cBinop_9Oml17LX_sendMessage);
}

void Heavy_saw_test::cBinop_tvMr0lXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_qQmCZGxS_sendMessage);
}

void Heavy_saw_test::cVar_OHQfjsH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bh5vTtFy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xnYgRzbF_sendMessage);
}

void Heavy_saw_test::cBinop_R1KSZFGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.0f, 0, m, &cBinop_rQb47qp3_sendMessage);
}

void Heavy_saw_test::cVar_4o5ECeDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cBinop_PlioLfJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3hAAlPrP, 0, m, &cVar_3hAAlPrP_sendMessage);
}

void Heavy_saw_test::cVar_vt7TDp7W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_tvMr0lXr_sendMessage);
}

void Heavy_saw_test::cVar_wQK6Duvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_Svxb6wJn_sendMessage);
}

void Heavy_saw_test::cCast_bh5vTtFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rt0o5x3l, HV_BINOP_ADD, 1, m, &cBinop_rt0o5x3l_sendMessage);
}

void Heavy_saw_test::cBinop_9Oml17LX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4o5ECeDk, 0, m, &cVar_4o5ECeDk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rEyWJIKW, HV_BINOP_ADD, 0, m, &cBinop_rEyWJIKW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_le1BfLj7, HV_BINOP_ADD, 0, m, &cBinop_le1BfLj7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rt0o5x3l, HV_BINOP_ADD, 0, m, &cBinop_rt0o5x3l_sendMessage);
}

void Heavy_saw_test::cCast_xnYgRzbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rt0o5x3l, HV_BINOP_ADD, 0, m, &cBinop_rt0o5x3l_sendMessage);
}

void Heavy_saw_test::cVar_0t4Vj0fU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cReceive_nNU6qng2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_gCDSGplt_sendMessage);
}

void Heavy_saw_test::cBinop_Svxb6wJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_PlioLfJB_sendMessage);
}

void Heavy_saw_test::cReceive_QMbkzw94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_R1KSZFGB_sendMessage);
}

void Heavy_saw_test::cCast_YmnhTTOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rEyWJIKW, HV_BINOP_ADD, 1, m, &cBinop_rEyWJIKW_sendMessage);
}

void Heavy_saw_test::cReceive_R6fvDPF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_tvMr0lXr_sendMessage);
}

void Heavy_saw_test::cBinop_rQb47qp3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kjRCzRTY, 0, m, &cVar_kjRCzRTY_sendMessage);
}

void Heavy_saw_test::cReceive_DS4X3zX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zWYYKpON_sendMessage(_c, 0, m);
}

void Heavy_saw_test::cCast_V6wyYb7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_le1BfLj7, HV_BINOP_ADD, 0, m, &cBinop_le1BfLj7_sendMessage);
}

void Heavy_saw_test::cVar_QRBDHx2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_R1KSZFGB_sendMessage);
}

void Heavy_saw_test::cCast_t7jv092g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9Oml17LX, HV_BINOP_ADD, 0, m, &cBinop_9Oml17LX_sendMessage);
}

void Heavy_saw_test::cBinop_qQmCZGxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F7fxJ0iq, 0, m, &cVar_F7fxJ0iq_sendMessage);
}

void Heavy_saw_test::cBinop_le1BfLj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_XbFWnjal, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FD6t5B1N, 0, m, &cVar_FD6t5B1N_sendMessage);
}

void Heavy_saw_test::cVar_3hAAlPrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qKs4tfrn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V6wyYb7a_sendMessage);
}

void Heavy_saw_test::cVar_eRhWmcS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cBinop_2Fr5OYsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 10.0f, 0, m, &cBinop_ycZyv3E7_sendMessage);
}

void Heavy_saw_test::cCast_x6gQhH88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rEyWJIKW, HV_BINOP_ADD, 0, m, &cBinop_rEyWJIKW_sendMessage);
}

void Heavy_saw_test::cReceive_srjTawl5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_2Fr5OYsC_sendMessage);
}

void Heavy_saw_test::cVar_efwLfj9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cVar_hCjNtkPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_gCDSGplt_sendMessage);
}

void Heavy_saw_test::cVar_t6Qw1OoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_2Fr5OYsC_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_saw_test::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3;

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
    __hv_phasor_k_f(&sPhasor_XbFWnjal, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf0), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_wKOUDAof, VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf1), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_8Cht3vET, VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf2), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_HbhefDY5, VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf3), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.75f, 0.75f, 0.75f, 0.75f, 0.75f, 0.75f, 0.75f, 0.75f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_saw_test::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_saw_test::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
