#define SAMPLE_RATE 48000.f

#include "daisy_boards.h"

#include "Heavy_pod_test.hpp"

using namespace daisy;

DSY_BOARD* hardware;

int num_params;

Heavy_pod_test hv(SAMPLE_RATE);

void ProcessControls();

void audiocallback(float *in, float *out, size_t size)
{
    ProcessControls();
    
    hv.processInlineInterleaved(in, out, size/2);	
    // GENERATE AUDIOCALLBACK
}

int main(void)
{
    
    num_params = hv.getParameterInfo(0,NULL);

    hardware = &boardsHardware;
    hardware->Init();

    hardware->StartAdc();
    
    hardware->StartAudio(audiocallback);
    // GENERATE POSTINIT
    for(;;)
    {
        // GENERATE INFINITELOOP
    }
}

void ProcessControls()
{
    hardware->DebounceControls();
    hardware->UpdateAnalogControls();
    
    for (int i = 0; i < num_params; i++)
    {
	HvParameterInfo info;
	hv.getParameterInfo(i, &info);

	std::string name(info.name);

	for (int j = 0; j < DaisyNumParameters; j++){
	    if (DaisyParameters[j].name == name)
	    {
		float sig = DaisyParameters[j].Process();
		
		if (! DaisyParameters[j].isBang)
		    hv.sendFloatToReceiver(info.hash, sig);
		else if(sig)
		    hv.sendBangToReceiver(info.hash);
	    }
	}	
    }
}
