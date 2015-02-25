// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ARM_H
#define ARM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Jude Sauve 2015
 */
class Arm: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	// BEGIN AUTOGENERATED
	SpeedController* lift;
	Encoder* armEnc;
	DigitalInput* toteH_MinDIO;
	DigitalInput* canAnd4ToteH_MaxDIO;

    // END AUTOGENERATED
	Arm();
	void InitDefaultCommand();
	void Stop();
	void ArmBaseMove(int direction);
	void ResetEnc();
	int ArmRoundH();
	float RoughHight();
	float ArmClawPlateAngle();
};

#endif
