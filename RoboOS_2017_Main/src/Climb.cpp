/*
 * Climb.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: Long Le
 */

#include <Climb.h>
#include "WPIlib.h"

Climb::Climb(){}
void Climb::Set(State currentState,double speed){
	double climbspeed;

	current_=currentState;
	switch (current_){
	case CLIMBUP:
	climb1_->SetControlMode(CANTalon::kPercentVbus);
	climb2_->SetControlMode(CANTalon::kPercentVbus);

	climb1_->Set(speed);
	climb2_->Set(speed);
	break;
	case CLIMBDOWN:
	climb1_->SetControlMode(CANTalon::kPercentVbus);
	climb2_->SetControlMode(CANTalon::kPercentVbus);
	climb1_->Set(-speed);
	climb2_->Set(-speed);
	break;
	case STOP:
	climb1_->SetControlMode(CANTalon::kPercentVbus);
	climb2_->SetControlMode(CANTalon::kPercentVbus);
	climb1_->Set(0);
	climb2_->Set(0);
	break;

	}
}

double Climb::GetState(){
	return static_cast<double>(current_);
}

