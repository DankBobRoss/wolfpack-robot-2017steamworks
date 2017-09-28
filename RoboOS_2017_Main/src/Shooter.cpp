/*
 * Shooter.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: Developer
 */

#include <Shooter.h>
#include "WPIlib.h"


Shooter::Shooter(std::shared_ptr<CANTalon>shoot1,
std::shared_ptr<CANTalon>shoot2):
Shooter1_(shoot1),Shooter2_(shoot2){

}
void Shooter::Set(State newstate){
	double shooterspeed;
	current_=newstate;
	switch(newstate){
	case DISABLE:
		Shooter1_->SetControlMode(CANTalon::kPercentVbus);
		Shooter2_->SetControlMode(CANTalon::kPercentVbus);
		Shooter1_->Set(0);
		Shooter2_->Set(0);
		SmartDashboard::PutString("shootermode","DISABLE");
		break;
	case SHOOT:
		Shooter1_->SetControlMode(CANTalon::kSpeed);
		Shooter2_->SetControlMode(CANTalon::kFollower);
		Shooter2_->Set(Shooter1_->GetDeviceID());
		Shooter1_->SelectProfileSlot(0);
		Shooter1_->SetSensorDirection(true);
//		SmartDashboard::PutNumber("shooter", Shooter1_->GetSpeed());
		shooterspeed=SmartDashboard::GetNumber("shooter",160);

		Shooter1_->Set(shooterspeed);
		SmartDashboard::PutNumber("encoder",Shooter1_->GetSpeed());
		SmartDashboard::PutNumber("position",Shooter1_->GetPosition());
		SmartDashboard::PutString("shootermode","SHOOT");
		break;

	case TEST:
		Shooter1_->SetControlMode(CANTalon::kPercentVbus);
		double speed=SmartDashboard::GetNumber("shooter",.5);
		Shooter1_->Set(speed);
		SmartDashboard::PutNumber("encoder",Shooter1_->GetSpeed());

//		SmartDashboard::GetNumber("shooter",.4);
//		double speeds=SmartDashboard::GetNumber("shooter".5);
//		Shooter1_->Set(speeds);
	break;

	}

}
bool Shooter::Ready(){//need to tune to see what is reasonable
	average[i]=Shooter1_->GetClosedLoopError();
	double sum=average[0]+average[1]+average[2]+average[3]+average[4]+average[5]+average[6]+average[7]+average[8]+average[9]
	+average[11]+average[12]+average[13]+average[14]+average[15]+average[16]+average[17]+average[18]+average[19]+average[10]																													  ;
	double mean=sum/20;
	i++;
	if(i==9){
		i=0;
	}
	SmartDashboard::PutNumber("mean",mean);
	if(abs(mean)<20){
		SmartDashboard::PutString("up","true");
		return true;

	}
	if(abs(mean)>=20){
		SmartDashboard::PutString("up","false");
		return false;
	}


}
double Shooter::GetState(){
	return static_cast<double>(current_);
}



