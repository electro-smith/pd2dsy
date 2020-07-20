#define SAMPLE_RATE 48000.f

#include "daisy_boards.h"

#include "Heavy_saw_test.hpp"

using namespace daisy;

DSY_BOARD hardware;

int num_params;

Heavy_saw_test hv(SAMPLE_RATE);

void audiocallback(float *in, float *out, size_t size)
{
    for (int i = 0; i < num_params; i++)
    {
	HvParameterInfo info;
	hv.getParameterInfo(i, &info);
	hv.sendFloatToReceiver(info.hash, 0.2f);
    }
    
    hv.processInlineInterleaved(in, out, size/2);	
    // GENERATE AUDIOCALLBACK
}

int main(void)
{
    hardware.Configure();
    num_params = hv.getParameterInfo(0,NULL);
    
    hardware.Init();

    
    
    hardware.StartAudio(audiocallback);
    // GENERATE POSTINIT
    for(;;)
    {
        // GENERATE INFINITELOOP
    }
}
