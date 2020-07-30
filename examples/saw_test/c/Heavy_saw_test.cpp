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
  numBytes += sPhasor_k_init(&sPhasor_h1WYETLz, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_KcIdCbV7, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_U8EOwrDU, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_Ew253r4b, 0.0f, sampleRate);
  numBytes += cVar_init_f(&cVar_6yE73Vd2, 0.0f);
  numBytes += cVar_init_f(&cVar_RkmX7i0n, 0.0f);
  numBytes += cBinop_init(&cBinop_CFMrsTZF, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_7H5ZsgNu, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_itdReb3z, 0.0f);
  numBytes += cVar_init_f(&cVar_FfUhbYIH, 0.0f);
  numBytes += cVar_init_f(&cVar_GkSyP7Ar, 0.0f);
  numBytes += cVar_init_f(&cVar_ri8mNMjT, 0.0f);
  numBytes += cVar_init_f(&cVar_JOJzbDUI, 0.0f);
  numBytes += cVar_init_f(&cVar_sHsVYP1C, 0.0f);
  numBytes += cVar_init_f(&cVar_qnWfCgdk, 0.0f);
  numBytes += cBinop_init(&cBinop_sbwp3YrD, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_K1bSD6o4, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_GqKgjWSc, 0.0f);
  numBytes += cVar_init_f(&cVar_vqPqd4D7, 0.0f);
  numBytes += cVar_init_f(&cVar_dpuwuY82, 0.0f);
  numBytes += cVar_init_f(&cVar_Ujv2caHY, 0.0f);
  numBytes += cVar_init_f(&cVar_FmztyTsT, 0.0f);
  numBytes += cVar_init_f(&cVar_2LkXNtfq, 0.0f);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aKu0lwvR_sendMessage);
      break;
    }
    case 0x4A38F401: { // ChannelB
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uOKDUCaF_sendMessage);
      break;
    }
    case 0x50D8682A: { // ChannelC
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2KSdNZtD_sendMessage);
      break;
    }
    case 0xC09FC6FC: { // ChannelD
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Uuvj8O2m_sendMessage);
      break;
    }
    case 0xBAD7D492: { // ChannelE
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HMWHKYgR_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4vTTtc5b_sendMessage);
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


void Heavy_saw_test::cBinop_EH9ZDhNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 10.0f, 0, m, &cBinop_nkvYkVBF_sendMessage);
}

void Heavy_saw_test::cBinop_zs4hMrca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6yE73Vd2, 0, m, &cVar_6yE73Vd2_sendMessage);
}

void Heavy_saw_test::cVar_6yE73Vd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GKm9nTnW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cD8ri6My_sendMessage);
}

void Heavy_saw_test::cCast_GKm9nTnW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sbwp3YrD, HV_BINOP_ADD, 1, m, &cBinop_sbwp3YrD_sendMessage);
}

void Heavy_saw_test::cCast_0vXyhss5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7H5ZsgNu, HV_BINOP_ADD, 1, m, &cBinop_7H5ZsgNu_sendMessage);
}

void Heavy_saw_test::cVar_RkmX7i0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_586lZvk7_sendMessage);
}

void Heavy_saw_test::cReceive_2KSdNZtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_KmTGopGv_sendMessage);
}

void Heavy_saw_test::cBinop_CFMrsTZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2LkXNtfq, 0, m, &cVar_2LkXNtfq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7H5ZsgNu, HV_BINOP_ADD, 0, m, &cBinop_7H5ZsgNu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_K1bSD6o4, HV_BINOP_ADD, 0, m, &cBinop_K1bSD6o4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sbwp3YrD, HV_BINOP_ADD, 0, m, &cBinop_sbwp3YrD_sendMessage);
}

void Heavy_saw_test::cBinop_nkvYkVBF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JOJzbDUI, 0, m, &cVar_JOJzbDUI_sendMessage);
}

void Heavy_saw_test::cBinop_7H5ZsgNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_h1WYETLz, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GqKgjWSc, 0, m, &cVar_GqKgjWSc_sendMessage);
}

void Heavy_saw_test::cBinop_N2rurflL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Vso6Z7Ph_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KpIUKV46_sendMessage);
}

void Heavy_saw_test::cVar_itdReb3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0RWBMp7L_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_envHjUCW_sendMessage);
}

void Heavy_saw_test::cVar_FfUhbYIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cCast_KpIUKV46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CFMrsTZF, HV_BINOP_ADD, 0, m, &cBinop_CFMrsTZF_sendMessage);
}

void Heavy_saw_test::cReceive_4vTTtc5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pmeLX6Tj_sendMessage(_c, 0, m);
}

void Heavy_saw_test::cReceive_Uuvj8O2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_586lZvk7_sendMessage);
}

void Heavy_saw_test::cVar_GkSyP7Ar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_EH9ZDhNJ_sendMessage);
}

void Heavy_saw_test::cVar_ri8mNMjT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_KmTGopGv_sendMessage);
}

void Heavy_saw_test::cBinop_586lZvk7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_zs4hMrca_sendMessage);
}

void Heavy_saw_test::cVar_JOJzbDUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.0f, 0, m, &cBinop_N2rurflL_sendMessage);
}

void Heavy_saw_test::cMsg_pmeLX6Tj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_FmztyTsT, 0, m, &cVar_FmztyTsT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_itdReb3z, 0, m, &cVar_itdReb3z_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6yE73Vd2, 0, m, &cVar_6yE73Vd2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JOJzbDUI, 0, m, &cVar_JOJzbDUI_sendMessage);
}

void Heavy_saw_test::cVar_sHsVYP1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cBinop_qyD2TYfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.0f, 0, m, &cBinop_J2JalUZM_sendMessage);
}

void Heavy_saw_test::cVar_qnWfCgdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cReceive_uOKDUCaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_ufjtbWNJ_sendMessage);
}

void Heavy_saw_test::cCast_Vso6Z7Ph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CFMrsTZF, HV_BINOP_ADD, 1, m, &cBinop_CFMrsTZF_sendMessage);
}

void Heavy_saw_test::cBinop_sbwp3YrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_KcIdCbV7, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qnWfCgdk, 0, m, &cVar_qnWfCgdk_sendMessage);
}

void Heavy_saw_test::cBinop_K1bSD6o4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Ew253r4b, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FfUhbYIH, 0, m, &cVar_FfUhbYIH_sendMessage);
}

void Heavy_saw_test::cCast_KboKQNDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7H5ZsgNu, HV_BINOP_ADD, 0, m, &cBinop_7H5ZsgNu_sendMessage);
}

void Heavy_saw_test::cVar_GqKgjWSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cVar_vqPqd4D7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_qyD2TYfn_sendMessage);
}

void Heavy_saw_test::cBinop_J2JalUZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dpuwuY82, 0, m, &cVar_dpuwuY82_sendMessage);
}

void Heavy_saw_test::cCast_cD8ri6My_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sbwp3YrD, HV_BINOP_ADD, 0, m, &cBinop_sbwp3YrD_sendMessage);
}

void Heavy_saw_test::cBinop_ufjtbWNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_pFfvUCCa_sendMessage);
}

void Heavy_saw_test::cCast_0RWBMp7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K1bSD6o4, HV_BINOP_ADD, 1, m, &cBinop_K1bSD6o4_sendMessage);
}

void Heavy_saw_test::cVar_dpuwuY82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_U8EOwrDU, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sHsVYP1C, 0, m, &cVar_sHsVYP1C_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CFMrsTZF, HV_BINOP_ADD, 0, m, &cBinop_CFMrsTZF_sendMessage);
}

void Heavy_saw_test::cBinop_KmTGopGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_6QPS1icc_sendMessage);
}

void Heavy_saw_test::cVar_Ujv2caHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_ufjtbWNJ_sendMessage);
}

void Heavy_saw_test::cBinop_pFfvUCCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FmztyTsT, 0, m, &cVar_FmztyTsT_sendMessage);
}

void Heavy_saw_test::cVar_FmztyTsT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0vXyhss5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KboKQNDS_sendMessage);
}

void Heavy_saw_test::cVar_2LkXNtfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_saw_test::cReceive_HMWHKYgR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_qyD2TYfn_sendMessage);
}

void Heavy_saw_test::cReceive_aKu0lwvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_EH9ZDhNJ_sendMessage);
}

void Heavy_saw_test::cBinop_6QPS1icc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_itdReb3z, 0, m, &cVar_itdReb3z_sendMessage);
}

void Heavy_saw_test::cCast_envHjUCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K1bSD6o4, HV_BINOP_ADD, 0, m, &cBinop_K1bSD6o4_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_h1WYETLz, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf0), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_KcIdCbV7, VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf1), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_U8EOwrDU, VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf2), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_Ew253r4b, VOf(Bf3));
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
