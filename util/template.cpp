#define SAMPLE_RATE 48000.f

#include "daisy_boards.h"

// GENERATE INCLUDES

using namespace daisy;

DSY_BOARD hardware;

int num_params;

// GENERATE GLOBALS

void audiocallback(float *in, float *out, size_t size)
{
    for (int i = 0; i < num_params; i++)
    {
	HvParameterInfo info;
	hv.getParameterInfo(i, &info);
	hv.sendFloatToReceiver(info.hash, 0.f);
    }
    
    hv.processInlineInterleaved(in, out, size/2);	
    // GENERATE AUDIOCALLBACK
}

int main(void)
{
    // GENERATE PREINIT
    num_params = hv.getParameterInfo(0,NULL);
    
    hardware.Init();

    // GENERATE ADC
    
    hardware.StartAudio(audiocallback);
    // GENERATE POSTINIT
    for(;;)
    {
        // GENERATE INFINITELOOP
    }
}
