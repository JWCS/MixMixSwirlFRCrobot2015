// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "MecDrive.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/Drive.h"

// BEGIN AUTOGENERATED
MecDrive::MecDrive() : PIDSubsystem("MecDrive", 1/18, 0.0, 0.0) {
	SetAbsoluteTolerance(RobotMap::mecPidTolerance);
	GetPIDController()->SetContinuous(true);
	LiveWindow::GetInstance()->AddActuator("MecDrive", "PIDSubsystem Controller", GetPIDController());
	GetPIDController()->SetInputRange(-180.0, 180.0);
	GetPIDController()->SetOutputRange(-1.0, 1.0);
    // END AUTOGENERATED

	// BEGIN AUTOGENERATED
	gyro = RobotMap::gyro;
	//sonic = RobotMap::sonic;
	driveFL = RobotMap::driveFL;
	driveFR = RobotMap::driveFR;
	driveBL = RobotMap::driveBL;
	driveBR = RobotMap::driveBR;
	baseDrive = RobotMap::baseDrive;
    // END AUTOGENERATED
	refAngle=0.0;
	rotation=0.0;
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
}

double MecDrive::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;	
        return gyro->PIDGet();

}

void MecDrive::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	//->PIDWrite(output);
	//rotation->
	rotation=(float)output;
}

void MecDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Drive());

}

void MecDrive::ResetRefAngle()
{
	gyro->Reset();
	refAngle=gyro->GetAngle();
	PIDSubsystem::SetSetpoint(refAngle);
	PIDSubsystem::Enable();
}

void MecDrive::StopDrive()
{
	baseDrive->StopMotor();
}

float MecDrive::DynamicTarget(float turn)
{
	refAngle+=turn;//if turn is in degrees; Due to not using an axis, but buttons, this is simple expected
	if(refAngle>180.0)
		refAngle-=360.0;
	if(refAngle<-180.0)
		refAngle+=360.0;//This should make the input circular/continuous (possibly redundant); ex. refAngle=190 (out of input range)-> refAngle=-170 (in range)
	return refAngle;
}

void MecDrive::MecanumDrive(float x, float y, float turn)
{
	if(
			std::abs(refAngle-PIDSubsystem::GetSetpoint())	*RobotMap::driveTurnTargetZ	//IS a scale factor of the original pos - target pos
						>std::abs(PIDSubsystem::GetPosition()-PIDSubsystem::GetSetpoint())//greater than the current pos - target pos?
			&&(turn!=0.0)//AND do we STILL want to turn or want to Start turning?
		){
	PIDSubsystem::SetSetpoint(DynamicTarget(turn));//Will not keep calling the DT method and accidentally add gazillians of turn to refAngle
	PIDSubsystem::Enable();
	}

	baseDrive->MecanumDrive_Cartesian(x, y, rotation);
}

void MecDrive::MecanumDrive(float x, float y, float turn, bool gyroLess){
	baseDrive->MecanumDrive_Cartesian(x, y, turn);
}

float MecDrive::FourB2VRota(bool lFast, bool lSlow, bool rSlow, bool rFast, bool gyroLess) {

//The angles assume straight forward is heading 0 degrees
	float out=0.0;
		if(lSlow){
				out= -RobotMap::slowAngleR;
			}else if(rSlow){
						out= RobotMap::slowAngleR;
			}else if(lFast){
						out= -RobotMap::fastAngleR; //SO MANY CONSTANTS ON THIS PAGE. PLS PLS PLS PLS WORK!!!
			}else if(rFast){
						out= RobotMap::fastAngleR;
			}else{
						out= 0.0;
			};
	return out;
	SmartDashboard::PutBoolean("GyroLess Drive", true);
}

float MecDrive::FourB2VRota(bool lFast, bool lSlow, bool rSlow, bool rFast) {
	float out=0.0;
	if(lSlow){
					out= -RobotMap::slowAngle;
				}else if(rSlow){
							out= RobotMap::slowAngle;
				}else if(lFast){
							out= -RobotMap::fastAngle; //SO MANY CONSTANTS ON THIS PAGE. PLS PLS PLS PLS WORK!!!
				}else if(rFast){
							out= RobotMap::fastAngle;
				}else{
							out= 0.0;
				};
	return out;
	SmartDashboard::PutBoolean("GyroLess Drive", false);
}

