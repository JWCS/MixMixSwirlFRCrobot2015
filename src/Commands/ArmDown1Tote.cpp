// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ArmDown1Tote.h"

ArmDown1Tote::ArmDown1Tote() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED
	Requires(Robot::arm);

    // END AUTOGENERATED
}

// Called just before this Command runs the first time
void ArmDown1Tote::Initialize() {
	count=Robot::arm->armEnc->Get();
}

// Called repeatedly when this Command is scheduled to run
void ArmDown1Tote::Execute() {
	Robot::arm->ArmBaseMove(RobotMap::directionN);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmDown1Tote::IsFinished() {
	if(count-Robot::arm->armEnc->Get()>=RobotMap::armCountsTo_d1
			||Robot::arm->toteH_MinDIO)
	{return true;}	else	{return false;}
}

// Called once after isFinished returns true
void ArmDown1Tote::End() {
	Robot::arm->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmDown1Tote::Interrupted() {
	ArmDown1Tote::End();
}
