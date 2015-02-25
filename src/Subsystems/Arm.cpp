// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Arm.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED
#include "../Commands/ArmToToteH.h"
// END AUTOGENERATED

Arm::Arm() : Subsystem("Arm") {
	// BEGIN AUTOGENERATED
	lift = RobotMap::lift;
	armEnc = RobotMap::armEnc;
	toteH_MinDIO = RobotMap::toteH_MinDIO;
	canAnd4ToteH_MaxDIO = RobotMap::canAnd4ToteH_MaxDIO;

    // END AUTOGENERATED
}

void Arm::Stop(){
	lift->Set(0.0);
}

void Arm::ArmBaseMove(int direction){
		lift->Set(RobotMap::armRate*direction);
}

void Arm::ResetEnc(){
	armEnc->Reset();
}

int Arm::ArmRoundH(){
	return Robot::arm->armEnc->Get()/RobotMap::armCountsTo_d1 + (Robot::arm->armEnc->Get()%RobotMap::armCountsTo_d1)*2/RobotMap::armCountsTo_d1;
}

float Arm::RoughHight(){
	return (float)armEnc->Get();
}

float Arm::ArmClawPlateAngle(){
	return Arm::RoughHight()*RobotMap::scaleAngleDev + RobotMap::initAngle;
}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED
	SetDefaultCommand(new ArmToToteH());

    // END AUTOGENERATED
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

