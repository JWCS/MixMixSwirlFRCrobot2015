#include "AnalogRangeFinder.h"
#include "AnalogInput.h"
#include "RobotMap.h"

void AnalogRangeFinder::InitAnalogRangeFinder(void)
{
	inchesPerVolt = RobotMap::analogRangefinder_DEFAULT_INCHES_PER_VOLT;
}
/*
AnalogRangeFinder::AnalogRangeFinder(uint32_t channel)
{
	m_analogChannel = new AnalogInput(channel);
	m_allocatedChannel = true;
	InitAnalogRangeFinder();
}

AnalogRangeFinder::AnalogRangeFinder(AnalogInput *channel)
{
	if (channel != NULL)
	{
		m_analogChannel = channel;
		InitAnalogRangeFinder();
		m_allocatedChannel = false;
	}
}

AnalogRangeFinder::AnalogRangeFinder(AnalogInput &channel)
{
	m_analogChannel = &channel;
	m_allocatedChannel = false;
	InitAnalogRangeFinder();
}*/

AnalogRangeFinder::~AnalogRangeFinder()
{
	if (m_allocatedChannel)
	{
		delete m_analogChannel;
	}
}

float AnalogRangeFinder::GetRangeInches()
{
	return m_analogChannel->GetVoltage() * inchesPerVolt;
}

float AnalogRangeFinder::GetVoltage()
{
	return m_analogChannel->GetVoltage();
}

void AnalogRangeFinder::SetSensitivity(float inches_per_volt)
{
	inchesPerVolt = inches_per_volt;
}


// PIDSource interface
double AnalogRangeFinder::PIDGet()
{
	return GetRangeInches();
}
