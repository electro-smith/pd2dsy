#include  "daisy_seed.h"
{display_conditional}
// name: {target_name}
struct Daisy {{
	void Init(bool boost = false) {{
		seed.Configure();
 		seed.Init(boost);
        
		{init}
        
		{switch}
        
		{switch3}
        
		{gatein}
		
		{encoder}
		
		{analogcount}
		
		{init_single}
		
		seed.adc.Init(cfg, ANALOG_COUNT);
		
		{ctrl_init}
		
		{led}
		
		{rgbled}
		
		{gateout}
		
		{dachandle}
		
		{display}
	}}

	void ProcessAllControls() {{
		{process}
	}}

	void PostProcess() {{
		{postprocess}
	}}

	void Display() {{
		{displayprocess}
	}}

	void SetAudioSampleRate(daisy::SaiHandle::Config::SampleRate samplerate) {{
		seed.SetAudioSampleRate(samplerate);
		SetHidUpdateRates();
	}}
	void SetAudioBlockSize(size_t size) {{
		seed.SetAudioBlockSize(size);
		SetHidUpdateRates();
	}}

	void SetHidUpdateRates() {{
		{hidupdaterates}
	}}

	daisy::DaisySeed seed;
	
	{comps}
	
	{dispdec}
	
	int menu_click = 0, menu_hold = 0, menu_rotate = 0;

}};