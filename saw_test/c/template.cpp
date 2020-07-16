#define SAMPLE_RATE 48000.f

//#include "daisy_boards.h"
#include "../../libdaisy/src/daisy_seed.h"

// GENERATE INCLUDES START
#include "Heavy_saw_test.hpp"
// GENERATE INCLUDES END

using namespace daisy;

//DSY_BOARD hardware;
DaisySeed seed;

Heavy_saw_test hv(SAMPLE_RATE);
int num_params;


// GENERATE GLOBALS START
// GENERATE GLOBALS END

void audiocallback(float *in, float *out, size_t size)
{
   
    for (int i = 0; i < num_params; i++)
    {
	HvParameterInfo info;
	hv.getParameterInfo(i, &info);
	hv.sendFloatToReceiver(info.hash, .2f);
    }
    hv.processInlineInterleaved(in, out, size/2);	
    // GENERATE AUDIOCALLBACK START
    // GENERATE AUDIOCALLBACK END
}

int main(void)
{
    // GENERATE PREINIT START
    // GENERATE PREINIT END
    //if (Board == seed)
    num_params = hv.getParameterInfo(0, NULL);
    
    seed.Configure();
    seed.Init();

    //if (Board != seed)
    //StartAdc()
    seed.StartAudio(audiocallback);
    // GENERATE POSTINIT START
    // GENERATE POSTINIT END    
    
    for(;;)
    {
        // GENERATE INFINITELOOP START
        // GENERATE INFINITELOOP END
    }
}
