/* intake.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: 99756814
 */

#include "Intake.h"

 Intake::Intake(){

}

void Intake::Reset(){
	init=false;
}
 //need some sort of rumble feedback not sure about the sensor that will be used (likely sharp)
void Intake::Set(State current){
	Left->SetControlMode(CANTalon::kPercentVbus);
	//Right->SetControlMode(CANTalon::kFollower);
	//Right->Set(Left->GetDeviceID());
	switch(current){
	case ON:

		Geary->Set(0);

		Shux->Set(false);
		if(init==true){

		Left->Set(1);
		Position->Set(frc::DoubleSolenoid::kReverse);//change to up for gear
		Slide->Set(true);
		frc::SmartDashboard::PutString("IntakeMode","ON");
		}
	//Map::Xbox1->SetRumble(XboxController::kRightRumble,.5);

	break;
	case OFF://stows gear
		Left->Set(0);
		Geary->Set(0);
		Shux->Set(false);
		if(init==false){
				IntakeTimer->Reset();
				IntakeTimer->Start();
				init=true;



			}
			if(IntakeTimer->Get()<4){
				Slide->Set(true);
			}
			if(IntakeTimer->Get()>=4){
				Position->Set(frc::DoubleSolenoid::kReverse);
				Slide->Set(true);

			}

//		Left->Set(0);
//		Position->Set(frc::DoubleSolenoid::kReverse);
		frc::SmartDashboard::PutString("IntakeMode","OFF");

	break;
	case BACK:
		Geary->Set(0);
		Left->Set(-1);
		Position->Set(frc::DoubleSolenoid::kReverse);
		Slide->Set(true);
		Shux->Set(false);
		frc::SmartDashboard::PutString("IntakeMode","BACK");
	break;
	case GEARON:
		Left->Set(0);
		Position->Set(frc::DoubleSolenoid::kForward);
		Geary->Set(1);
		Slide->Set(true);
		Shux->Set(false);
		frc::SmartDashboard::PutString("IntakeMode","GEARON");
	break;
	case GEAROFF:
		Left->Set(0);
		Position->Set(frc::DoubleSolenoid::kForward);
		Geary->Set(0);
		Slide->Set(true);
		Shux->Set(false);
		frc::SmartDashboard::PutString("IntakeMode","GEAROFF");


	break;
	case GEARSCORE:
		Left->Set(-1);
		Position->Set(frc::DoubleSolenoid::kForward);
		Geary->Set(-1);
		Slide->Set(true);
		Shux->Set(false);
		frc::SmartDashboard::PutString("IntakeMode","GEARSCORE");

	break;
	case STARTINGCONFIG:
		Position->Set(frc::DoubleSolenoid::kForward);
		Slide->Set(false);
		Shux->Set(false);
		Geary->Set(0);

		frc::SmartDashboard::PutString("IntakeMode","STARTINGCONFIG");


	break;
	case DISABLED:
		Slide->Set(false);
		Shux->Set(true);

	break;
	}
}








