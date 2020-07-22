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
  numBytes += sPhasor_k_init(&sPhasor_47j9PTdn, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_IChTPP6p, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_jfzYQQZH, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_cNhd2S3d, 0.0f, sampleRate);
  numBytes += cBinop_init(&cBinop_4D4jrsA1, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_YvNTnEAL, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_8Y77cuwY, 0.0f);
  numBytes += cVar_init_f(&cVar_ZkzFvp6q, 0.0f);
  numBytes += cVar_init_f(&cVar_G6mUt74J, 0.0f);
  numBytes += cVar_init_f(&cVar_278zstdC, 0.0f);
  numBytes += cVar_init_f(&cVar_SW8hY3Ej, 0.0f);
  numBytes += cVar_init_f(&cVar_a8jy5g6u, 0.0f);
  numBytes += cBinop_init(&cBinop_fO7cSD6R, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_PDBritj1, 0.0f);
  numBytes += cVar_init_f(&cVar_K1gn6rHV, 0.0f);
  numBytes += cBinop_init(&cBinop_R0YRd6RI, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_F3ESh9Ct, 0.0f);
  numBytes += cVar_init_f(&cVar_hiGLqQbS, 0.0f);
  numBytes += cVar_init_f(&cVar_eAMZFCJS, 0.0f);
  numBytes += cVar_init_f(&cVar_DMsK7TkR, 0.0f);
  numBytes += cVar_init_f(&cVar_by50kWOM, 0.0f);
  numBytes += cVar_init_f(&cVar_REMRJkd3, 0.0f);
  numBytes += cVar_init_f(&cVar_s5JAxyg5, 0.0f);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2FmjJiWI_sendMessage);
      break;
    }
    case 0x4A38F401: { // ChannelB
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TWGvagTB_sendMessage);
      break;
    }
    case 0x50D8682A: { // ChannelC
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_n7un8OJb_sendMessage);
      break;
    }
    case 0xC09FC6FC: { // ChannelD
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_o1siqQfp_sendMessage);
      break;
    }
    case 0xBAD7D492: { // ChannelE
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3EroFvIO_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_luUCOXxj_sendMessage);
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


void Heavy_saw_test::cCast_RpM5Qsyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4D4jrsA1, HV_BINOP_ADD, 0, m, &cBinop_4D4jrsA1_sendMessage);
}

void Heavy_saw_test::cBinop_4D4jrsA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_jfzYQQZH, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hiGLqQbS, 0, m, &cVar_hiGLqQbS_sendMessage);
}

void Heavy_saw_test::cBinop_YvNTnEAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_cNhd2S3d, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZkzFvp6q, 0, m, &cVar_ZkzFvp6q_sendMessage);
}

void Heavy_saw_test::cBinop_RPtTJuqq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.0f, 0, m, &cBinop_CXbzvy6A_sendMessage);
}

void Heavy_saw_test::cVar_8Y77cuwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_47j9PTdn, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_a8jy5g6u, 0, m, &cVar_a8jy5g6u_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fO7cSD6R, HV_BINOP_ADD, 0, m, &cBinop_fO7cSD6R_sendMessage);
}

void Heavy_saw_test::cBinop_KFoEQqMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 10.0f, 0, m, &cBinop_ghJBZRPU_sendMessage);
}

void Heavy_saw_test::cBinop_BeVkoRAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SW8hY3Ej, 0, m, &cVar_SW8hY3Ej_sendMessage);
}

void Heavy_saw_test::cCast_qwjzH0iZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0YRd6RI, HV_BINOP_ADD, 0, m, &cBinop_R0YRd6RI_sendMessage);
}

void Heavy_saw_test::cMsg_vohlwG6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_REMRJkd3, 0, m, &cVar_REMRJkd3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eAMZFCJS, 0, m, &cVar_eAMZFCJS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SW8hY3Ej, 0, m, &cVar_SW8hY3Ej_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_F3ESh9Ct, 0, m, &cVar_F3ESh9Ct_sendMessage);
}

void Heavy_saw_test::cCast_iHdnWZQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fO7cSD6R, HV_BINOP_ADD, 1, m, &cBinop_fO7cSD6R_sendMessage);
}

void Heavy_saw_test::cReceive_luUCOXxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vohlwG6o_sendMessage(_c, 0, m);
}

void Heavy_saw_test::cVar_ZkzFvp6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cBinop_NT78l8Yp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eAMZFCJS, 0, m, &cVar_eAMZFCJS_sendMessage);
}

void Heavy_saw_test::cVar_G6mUt74J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cCast_hceupIyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fO7cSD6R, HV_BINOP_ADD, 0, m, &cBinop_fO7cSD6R_sendMessage);
}

void Heavy_saw_test::cReceive_o1siqQfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_yW3KoNQp_sendMessage);
}

void Heavy_saw_test::cCast_WpHZyJQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4D4jrsA1, HV_BINOP_ADD, 1, m, &cBinop_4D4jrsA1_sendMessage);
}

void Heavy_saw_test::cVar_278zstdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_KFoEQqMq_sendMessage);
}

void Heavy_saw_test::cReceive_2FmjJiWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_KFoEQqMq_sendMessage);
}

void Heavy_saw_test::cVar_SW8hY3Ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EeqZ7ldR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JNehnxNL_sendMessage);
}

void Heavy_saw_test::cVar_a8jy5g6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cReceive_TWGvagTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_acrrPSbH_sendMessage);
}

void Heavy_saw_test::cBinop_ghJBZRPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F3ESh9Ct, 0, m, &cVar_F3ESh9Ct_sendMessage);
}

void Heavy_saw_test::cBinop_fO7cSD6R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DMsK7TkR, 0, m, &cVar_DMsK7TkR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0YRd6RI, HV_BINOP_ADD, 0, m, &cBinop_R0YRd6RI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4D4jrsA1, HV_BINOP_ADD, 0, m, &cBinop_4D4jrsA1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YvNTnEAL, HV_BINOP_ADD, 0, m, &cBinop_YvNTnEAL_sendMessage);
}

void Heavy_saw_test::cBinop_acrrPSbH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_6FDjzcSd_sendMessage);
}

void Heavy_saw_test::cBinop_M2uQmzR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_NT78l8Yp_sendMessage);
}

void Heavy_saw_test::cVar_PDBritj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_acrrPSbH_sendMessage);
}

void Heavy_saw_test::cBinop_yW3KoNQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_BeVkoRAz_sendMessage);
}

void Heavy_saw_test::cVar_K1gn6rHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_M2uQmzR3_sendMessage);
}

void Heavy_saw_test::cCast_EeqZ7ldR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YvNTnEAL, HV_BINOP_ADD, 1, m, &cBinop_YvNTnEAL_sendMessage);
}

void Heavy_saw_test::cBinop_R0YRd6RI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_IChTPP6p, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_G6mUt74J, 0, m, &cVar_G6mUt74J_sendMessage);
}

void Heavy_saw_test::cVar_F3ESh9Ct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.0f, 0, m, &cBinop_xnuuZH90_sendMessage);
}

void Heavy_saw_test::cReceive_3EroFvIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_RPtTJuqq_sendMessage);
}

void Heavy_saw_test::cVar_hiGLqQbS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cVar_eAMZFCJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WpHZyJQq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RpM5Qsyf_sendMessage);
}

void Heavy_saw_test::cBinop_CXbzvy6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8Y77cuwY, 0, m, &cVar_8Y77cuwY_sendMessage);
}

void Heavy_saw_test::cCast_DPBJf7H4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0YRd6RI, HV_BINOP_ADD, 1, m, &cBinop_R0YRd6RI_sendMessage);
}

void Heavy_saw_test::cBinop_xnuuZH90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iHdnWZQl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hceupIyy_sendMessage);
}

void Heavy_saw_test::cBinop_6FDjzcSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_REMRJkd3, 0, m, &cVar_REMRJkd3_sendMessage);
}

void Heavy_saw_test::cVar_DMsK7TkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cReceive_n7un8OJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_M2uQmzR3_sendMessage);
}

void Heavy_saw_test::cVar_by50kWOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_RPtTJuqq_sendMessage);
}

void Heavy_saw_test::cVar_REMRJkd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DPBJf7H4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qwjzH0iZ_sendMessage);
}

void Heavy_saw_test::cCast_JNehnxNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YvNTnEAL, HV_BINOP_ADD, 0, m, &cBinop_YvNTnEAL_sendMessage);
}

void Heavy_saw_test::cVar_s5JAxyg5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_yW3KoNQp_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_47j9PTdn, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf0), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_IChTPP6p, VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf1), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_jfzYQQZH, VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf2), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_cNhd2S3d, VOf(Bf3));
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
