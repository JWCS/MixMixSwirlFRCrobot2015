// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Drive.h"

Drive::Drive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::mecDrive);
	Drive::SetInterruptible(false);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void Drive::Initialize() {
	Robot::mecDrive->ResetRefAngle();
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	//Code for Joystick manipulation?? Probably
	if(Robot::oi->resetGyro)
		Robot::mecDrive->ResetRefAngle();

	if(Robot::oi->gyroLess->Get()){
	Robot::mecDrive->MecanumDrive(
			Robot::oi->deadbandKill(Robot::oi->getstick()->GetX()*RobotMap::joyAxisXscale, RobotMap::joyXdeadBand),
			Robot::oi->deadbandKill(Robot::oi->getstick()->GetY()*RobotMap::joyAxisYscale, RobotMap::joyYdeadBand),
			Robot::mecDrive->FourB2VRota(Robot::oi->turnL_Slow->Get(), Robot::oi->turnL_Slow->Get(),
					Robot::oi->turnR_Slow->Get(), Robot::oi->turnR_Fast->Get()), true);
	}else{
		Robot::mecDrive->MecanumDrive(
					Robot::oi->deadbandKill(Robot::oi->getstick()->GetX()*RobotMap::joyAxisXscale, RobotMap::joyXdeadBand),
					Robot::oi->deadbandKill(Robot::oi->getstick()->GetY()*RobotMap::joyAxisYscale, RobotMap::joyYdeadBand),
					Robot::mecDrive->FourB2VRota(Robot::oi->turnL_Slow->Get(), Robot::oi->turnL_Slow->Get(),
							Robot::oi->turnR_Slow->Get(), Robot::oi->turnR_Fast->Get()));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false; //Need some sort of check for at end?? such as IsTimedOut();
}

// Called once after isFinished returns true
void Drive::End() {
	Robot::mecDrive->StopDrive();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
