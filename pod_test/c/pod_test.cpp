#define SAMPLE_RATE 48000.f

#include "daisy_boards.h"

#include "Heavy_pod_test.hpp"

#include <string>;

using namespace daisy;

DSY_BOARD hardware;

int num_params;

Heavy_pod_test hv(SAMPLE_RATE);

void audiocallback(float *in, float *out, size_t size)
{
    hardware.DebounceControls();
    hardware.UpdateAnalogControls();
    for (int i = 0; i < num_params; i++)
    {
	HvParameterInfo info;
	hv.getParameterInfo(i, &info);

	std::string str = "Knob1";
	std::string comp(info.name);
	if (str == comp){
	    hv.sendFloatToReceiver(info.hash, hardware.knob1.Process() * 2000);
	}

	str = "Knob2";
	if (str == comp){
	    hv.sendFloatToReceiver(info.hash, hardware.knob2.Process() * 2000);
	}

	str = "Button1";
	if (str == comp && hardware.button1.RisingEdge()){
	    hv.sendBangToReceiver(info.hash);
	}

	str = "Button2";
	if (str == comp && hardware.button2.RisingEdge()){
	    hv.sendBangToReceiver(info.hash);
	}
    }
    
    hv.processInlineInterleaved(in, out, size/2);	
    // GENERATE AUDIOCALLBACK
}

int main(void)
{
    
    num_params = hv.getParameterInfo(0,NULL);
    
    hardware.Init();

    hardware.StartAdc();
    
    hardware.StartAudio(audiocallback);
    // GENERATE POSTINIT
    for(;;)
    {
        // GENERATE INFINITELOOP
    }
}
