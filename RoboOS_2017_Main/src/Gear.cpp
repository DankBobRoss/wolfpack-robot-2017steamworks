/*
 * Gear.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: Developer
 */

#include <Gear.h>

Gear::Gear() {
	// TODO Auto-generated constructor stub

}
//adding intake gear state
void Gear::Set(State state){
	current_=state;
	switch(state){
	case INTAKE:
		Bally1->Set(false);
		Bally2->Set(true);//previous

		 frc::SmartDashboard::PutString("GearMode","INTAKE");
		 //needs to fire a solenoid for gear intake

		Flappy->Set(frc::DoubleSolenoid::kForward);
	break;
	case HOLD:
		Bally1->Set(false);
		Bally2->Set(true);

		GearSolenoid->Set(frc::DoubleSolenoid::kForward);
		Flappy->Set(frc::DoubleSolenoid::kReverse);
		frc::SmartDashboard::PutString("GearMode","HOLD");
	break;
	case SCORE:
		Bally1->Set(false);
		Bally2->Set(true);//the one that needs to be changed to


		GearSolenoid->Set(frc::DoubleSolenoid::kReverse);
		frc::SmartDashboard::PutString("GearMode","SCORE");
		Flappy->Set(frc::DoubleSolenoid::kReverse);
	break;
	case AUTO:

		if(Sharp->GetVoltage()>.5){
			//range needs to be tested to ensure accuracy
			GearSolenoid->Set(frc::DoubleSolenoid::kReverse);
		}
		else{
			GearSolenoid->Set(frc::DoubleSolenoid::kForward);
		}
		Flappy->Set(frc::DoubleSolenoid::kReverse);
		frc::SmartDashboard::PutString("GearMode","AUTO");
	break;
	case BALLINTAKE:
		Bally1->Set(true);
		Bally2->Set(false);//previous

		Flappy->Set(frc::DoubleSolenoid::kForward);
		GearSolenoid->Set(frc::DoubleSolenoid::kForward);
	break;


	default:

	break;



	}



}
void Gear::Set(){
	Set(current_);


}
double Gear::GetSharp(){
	return Sharp->GetVoltage();
}
double Gear::GetState(){
	return static_cast<double>(current_);

}


