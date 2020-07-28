#define SAMPLE_RATE 48000.f

#include "daisy_boards.h"

#include "Heavy_patch_test.hpp"

using namespace daisy;

DSY_BOARD* hardware;

int num_params;

Heavy_patch_test hv(SAMPLE_RATE);

void ProcessControls();

void audiocallback(float **in, float **out, size_t size)
{
    hv.process(in, out, size);

    ProcessControls();
}

int main(void)
{
    hardware = &boardsHardware;
    
    num_params = hv.getParameterInfo(0,NULL);

    hardware->Init();

    hardware->StartAdc();
    
    hardware->StartAudio(audiocallback);
    // GENERATE POSTINIT
    for(;;)
    {
        hardware->DisplayControls(false);
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
	
	// GENERATE CONTROLS
	
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
