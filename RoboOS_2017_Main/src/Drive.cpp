/*

 * Drive.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: AT
 */

#include "Drive.h"

Drive::Drive(std::shared_ptr<CANTalon>RightTalon,std::shared_ptr<CANTalon>LeftTalon):RightFront_(RightTalon), LeftFront_(LeftTalon){


}

void Drive::Set(State current){
	RightFront_->Set(Xbox1->GetY(frc::XboxController::kRightHand));
	LeftFront_->Set(Xbox1->GetY(frc::XboxController::kLeftHand));//negative was removed intentionally//changed so the ptr was fed need to test and ensure it still works
	switch(current){
	case LOWGEAR:
		Shifter1_->Set(frc::DoubleSolenoid::kForward);
		frc::SmartDashboard::PutString("DriveMode","HIGHGEAR");
	break;
	case HIGHGEAR:

		Shifter1_->Set(frc::DoubleSolenoid::kReverse);
		frc::SmartDashboard::PutString("DriveMode","LOWGEAR");
	break;

//	case WHEEL:
//	double turn=.5-Wheel1->GetX	(Joystick::kRightHand);
//	if(turn<0){
//		turn=-turn;
//	}
//	SmartDashboard::PutNumber("turn", turn);
//	if(Wheel1->GetX(Joystick::kRightHand)<=.5){
//		Map::LeftFront->Set(-(Joystick1->GetY(Joystick::kRightHand)-turn));
//		Map::RightFront->Set(Joystick1->GetY(Joystick::kRightHand));
//
//  }
//	if(Wheel1->GetX(Joystick::kRightHand)>.5){
//		Map::LeftFront->Set(-(Joystick1->GetY(Joystick::kRightHand)));
//		Map::RightFront->Set(Joystick1->GetY(Joystick::kRightHand)-turn);
//	}
//
//			SmartDashboard::PutNumber("rightvoltage",Map::RightFront->Get());
//			SmartDashboard::PutNumber("leftvoltage",Map::LeftFront->Get());
//	break;






	}
}
void Drive::Tele(){
	RightFront_->Set(Xbox1->GetY(frc::XboxController::kRightHand));
	LeftFront_->Set(Xbox1->GetY(frc::XboxController::kLeftHand));
}
double Drive::Right(){
	return Xbox1->GetY(frc::XboxController::kRightHand);
}
double Drive::Left(){
	return Xbox1->GetY(frc::XboxController::kLeftHand);

}
void Drive::Do(double power){
	RightFront_->Set(power);
	LeftFront_->Set(power);
}











