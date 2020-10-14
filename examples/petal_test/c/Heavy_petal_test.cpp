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
  numBytes += sLine_init(&sLine_htWIdGll);
  numBytes += sTabhead_init(&sTabhead_beYfjtA7, &hTable_7cvQjdPW);
  numBytes += sTabread_init(&sTabread_Vv35pd4X, &hTable_7cvQjdPW, false);
  numBytes += sTabread_init(&sTabread_wvptcjyp, &hTable_7cvQjdPW, false);
  numBytes += sTabwrite_init(&sTabwrite_wmgd5jvg, &hTable_7cvQjdPW);
  numBytes += sVarf_init(&sVarf_ZpCuQgwC, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_1x0Bl66S, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_wIdXD2A5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sSEI5SE2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Nxr8gYAi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3wR8pllz, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_sGwopm9u, "del-1001-delay");
  numBytes += sVarf_init(&sVarf_dIF5CQlZ, 0.0f, 0.0f, false);
  numBytes += hTable_init(&hTable_7cvQjdPW, 256);
  numBytes += cDelay_init(this, &cDelay_p1Y1F9Az, 0.0f);
  numBytes += cDelay_init(this, &cDelay_gUhuo2Qm, 0.0f);
  numBytes += sVarf_init(&sVarf_yLiwD5Qw, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_petal_test::~Heavy_petal_test() {
  cPack_free(&cPack_1x0Bl66S);
  hTable_free(&hTable_7cvQjdPW);
}

HvTable *Heavy_petal_test::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x549A9784: return &hTable_7cvQjdPW; // del-1001-delay
    default: return nullptr;
  }
}

void Heavy_petal_test::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x4D9F260A: { // Knob3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uCxOuGEe_sendMessage);
      break;
    }
    case 0xDB6872A1: { // Knob4
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1P0jWXcK_sendMessage);
      break;
    }
    case 0x5C0E4419: { // Knob5
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mzsYMcu4_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_J6GOm3mh_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_petal_test::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "Knob3";
        info->hash = 0x4D9F260A;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 1: {
        info->name = "Knob5";
        info->hash = 0x5C0E4419;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 2: {
        info->name = "Knob4";
        info->hash = 0xDB6872A1;
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
  return 3;
}



/*
 * Send Function Implementations
 */


void Heavy_petal_test::cCast_Y6EeZwE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1x0Bl66S, 1, m, &cPack_1x0Bl66S_sendMessage);
}

void Heavy_petal_test::cBinop_rhSMPOv3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wIdXD2A5, m);
}

void Heavy_petal_test::cReceive_mzsYMcu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yLiwD5Qw, m);
}

void Heavy_petal_test::cBinop_IVnXQHa8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_rhSMPOv3_sendMessage);
}

void Heavy_petal_test::cReceive_J6GOm3mh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5uPSViCx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sGwopm9u, 0, m, &cVar_sGwopm9u_sendMessage);
  cMsg_wi1nT0o2_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cReceive_1P0jWXcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 999.0f, 0, m, &cBinop_4saOlz15_sendMessage);
}

void Heavy_petal_test::cReceive_uCxOuGEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IVnXQHa8_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dIF5CQlZ, m);
}

void Heavy_petal_test::cPack_1x0Bl66S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_htWIdGll, 0, m, NULL);
}

void Heavy_petal_test::cBinop_4saOlz15_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y6EeZwE7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cQMixQ9p_sendMessage);
}

void Heavy_petal_test::cSystem_v7OQflfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bdFqpAgN_sendMessage);
}

void Heavy_petal_test::cMsg_wi1nT0o2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_v7OQflfv_sendMessage);
}

void Heavy_petal_test::cMsg_ewb1jCuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GynmzqDS_sendMessage);
}

void Heavy_petal_test::cBinop_bdFqpAgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3wR8pllz, m);
}

void Heavy_petal_test::cSystem_GynmzqDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_WgvfVDpm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Nxr8gYAi, m);
}

void Heavy_petal_test::cBinop_WgvfVDpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sSEI5SE2, m);
}

void Heavy_petal_test::cVar_sGwopm9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ewb1jCuo_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cCast_cQMixQ9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1x0Bl66S, 0, m, &cPack_1x0Bl66S_sendMessage);
}

void Heavy_petal_test::cMsg_9OK41fUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7cvQjdPW, 0, m, &hTable_7cvQjdPW_sendMessage);
}

void Heavy_petal_test::hTable_7cvQjdPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5kaHPYhR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gUhuo2Qm, 2, m, &cDelay_gUhuo2Qm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L9DNMork_sendMessage);
}

void Heavy_petal_test::cCast_L9DNMork_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gUhuo2Qm, 0, m, &cDelay_gUhuo2Qm_sendMessage);
}

void Heavy_petal_test::cMsg_Uj4eixEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7cvQjdPW, 0, m, &hTable_7cvQjdPW_sendMessage);
}

void Heavy_petal_test::cMsg_5kaHPYhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_p1Y1F9Az, 2, m, &cDelay_p1Y1F9Az_sendMessage);
}

void Heavy_petal_test::cSystem_Q08rTTUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_q9p1bE6w_sendMessage);
}

void Heavy_petal_test::cMsg_5uPSViCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Q08rTTUn_sendMessage);
}

void Heavy_petal_test::cBinop_UalFQZgp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Uj4eixEa_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cBinop_q9p1bE6w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_UalFQZgp_sendMessage);
}

void Heavy_petal_test::cDelay_p1Y1F9Az_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_p1Y1F9Az, m);
  cMsg_9OK41fUy_sendMessage(_c, 0, m);
}

void Heavy_petal_test::cDelay_gUhuo2Qm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gUhuo2Qm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p1Y1F9Az, 0, m, &cDelay_p1Y1F9Az_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gUhuo2Qm, 0, m, &cDelay_gUhuo2Qm_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_wmgd5jvg, 1, m, NULL);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3;
  hv_bufferi_t Bi0, Bi1;

  // input and output vars
  hv_bufferf_t O0, O1;
  hv_bufferf_t I0, I1;

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

    // load input buffers
    __hv_load_f(inputBuffers[0]+n, VOf(I0));
    __hv_load_f(inputBuffers[1]+n, VOf(I1));

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_line_f(&sLine_htWIdGll, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_beYfjtA7, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_3wR8pllz, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_sSEI5SE2, VOf(Bf0));
    __hv_min_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf2));
    __hv_varread_f(&sVarf_Nxr8gYAi, VOf(Bf0));
    __hv_zero_f(VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Vv35pd4X, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_wvptcjyp, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_yLiwD5Qw, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_f(&sVarf_ZpCuQgwC, VIf(Bf2));
    __hv_varread_f(&sVarf_dIF5CQlZ, VOf(Bf2));
    __hv_varread_f(&sVarf_wIdXD2A5, VOf(Bf3));
    __hv_mul_f(VIf(I0), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_ZpCuQgwC, VOf(Bf3));
    __hv_add_f(VIf(I0), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_wmgd5jvg, VIf(Bf3));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_petal_test::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s)
  float **const bIn = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bIn[0] = inputBuffers+(0*n4);
  bIn[1] = inputBuffers+(1*n4);

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_petal_test::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s), uninterleave
  float *const bIn = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));
  #if HV_SIMD_SSE || HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 a = _mm_load_ps(inputBuffers+i);                // LRLR
    __m128 b = _mm_load_ps(inputBuffers+4+i);              // LRLR
    __m128 x = _mm_shuffle_ps(a, b, _MM_SHUFFLE(2,0,2,0)); // LLLL
    __m128 y = _mm_shuffle_ps(a, b, _MM_SHUFFLE(3,1,3,1)); // RRRR
    _mm_store_ps(bIn+j, x);
    _mm_store_ps(bIn+n4+j, y);
  }
  #elif HV_SIMD_NEON
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4x2_t a = vld2q_f32(inputBuffers+i); // load and uninterleave
    vst1q_f32(bIn+j, a.val[0]);
    vst1q_f32(bIn+n4+j, a.val[1]);
  }
  #else // HV_SIMD_NONE
  for (int j = 0; j < n4; ++j) {
    bIn[0*n4+j] = inputBuffers[0+2*j];
    bIn[1*n4+j] = inputBuffers[1+2*j];
  }
  #endif

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
