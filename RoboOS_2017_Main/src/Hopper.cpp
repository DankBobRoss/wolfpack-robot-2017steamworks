/*
 * Hopper.cpp
 *
 *  Created on: Jan 15, 2017
 *      Author: Developer
 */

#include <Hopper.h>
#include"WPIlib.h"
#include "CANTalon.h"
Hopper::Hopper(double speed,double intake):speed_(speed),intake_(intake)  {

}

void Hopper::SetSpeed(double speed){
	Hopper_->SetControlMode(CANTalon::kSpeed);
	Hopper_->SelectProfileSlot(0);
	Hopper_->Set(speed);
}
void Hopper::Set(State state){


	current_=state;
	switch(state){
		case ON:
			//SetSpeed(speed_);
			//Hopper_->SetControlMode(CANTalon::kPercentVbus);
			speed=SmartDashboard::GetNumber("hopper", .4);
			SmartDashboard::PutNumber("hoppercurrentspeed",0);
			 Hopper_->Set(speed);

			SmartDashboard::PutString("HopperMode","ON");
		break;
		case INTAKE:
			SetSpeed(intake_);
			SmartDashboard::PutString("HopperMode","INTAKE");
		break;
		case OFF:
			//SetSpeed(0);
			//speed=SmartDashboard::GetNumber("hopper", .4);
			Hopper_->Set(0);
			SmartDashboard::PutString("HopperMode","OFF");
		break;
		case TEST:

			Hopper_->SetControlMode(CANTalon::kPercentVbus);
			speed=SmartDashboard::GetNumber("hopper", .4);
			Hopper_->Set(speed);
			SmartDashboard::PutString("HopperMode","TEST");
			if(Hopper_->GetSpeed()==0){
				Hopper_->Set(-speed);//attempt to unjam hopper
				//need to test to see if it works
				//these lines were just added

			}
		case REVERSE:
			speed=SmartDashboard::GetNumber("hopper", .4);
			Hopper_->Set(-speed);


		break;
		case AUTO:

			Hopper_->Set(.4);

			SmartDashboard::PutString("HopperMode","AUTO");

		break;

	}




}
void Hopper::Set(){
	Set(current_);
}
double Hopper::GetAmp(){
	Hopper_->GetOutputCurrent();

}
