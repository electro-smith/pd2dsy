#define SAMPLE_RATE 48000.f

#include "daisy_boards.h"

#include "c/Heavy_saw_test.hpp"

using namespace daisy;

DSY_BOARD* hardware;

int num_params;

Heavy_saw_test hv(SAMPLE_RATE);

void ProcessControls();

void audiocallback(float **in, float **out, size_t size)
{
    hv.process(in, out, size);
    ProcessControls();
}

int main(void)
{
    hardware = &boardsHardware;
    hardware->Configure();
    num_params = hv.getParameterInfo(0,NULL);

    hardware->Init();

    
    
    hardware->StartAudio(audiocallback);
    // GENERATE POSTINIT
    for(;;)
    {
        // GENERATE INFINITELOOP
    }
}

void ProcessControls()
{
    // GENERATE DEBOUNCE
    
    for (int i = 0; i < num_params; i++)
    {
	HvParameterInfo info;
	hv.getParameterInfo(i, &info);
	
	hv.sendFloatToReceiver(info.hash, 0.f);
	
	std::string name(info.name);

	for (int j = 0; j < DaisyNumParameters; j++){
	    if (DaisyParameters[j].name == name)
	    {
		float sig = DaisyParameters[j].Process();
		
		if (DaisyParameters[j].mode == ENCODER || DaisyParameters[j].mode == KNOB)
		    hv.sendFloatToReceiver(info.hash, sig);
		else if(sig)
		    hv.sendBangToReceiver(info.hash);
	    }
	}	
    }
}
