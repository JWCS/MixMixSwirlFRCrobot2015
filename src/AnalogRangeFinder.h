#ifndef ANALOGRANGEFINDER_H
#define ANALOGRANGEFINDER_H

//#include "SensorBase.h"
//#include "PIDSource.h"
#include "AnalogInput.h"

class AnalogInput;


//Designed for the MaxBotix LV-MaxSonar®-EZ1, but should work for any analog output sonar module
class AnalogRangeFinder : public AnalogInput
{
private:
	float inchesPerVolt;
	AnalogInput *m_analogChannel;
	bool m_allocatedChannel;

	void InitAnalogRangeFinder(void);

public:
	explicit AnalogRangeFinder(uint32_t channel);
	explicit AnalogRangeFinder(AnalogInput *channel);
	explicit AnalogRangeFinder(AnalogInput &channel);
	virtual ~AnalogRangeFinder();

	virtual float GetRangeInches();
	float GetVoltage();
	void SetSensitivity(float inches_per_volt);

	// PIDSource interface
	double PIDGet();

};



#endif
