#include <OI.h>
void OI::Enable (){
Map::Gear1->Set();
Map::Drive1->Tele();
Map::Hopper1->Set();

Map::RightFront->SetControlMode(CANTalon::kPercentVbus);
Map::LeftFront->SetControlMode(CANTalon::kPercentVbus);

if(Map::Xbox1->GetTriggerAxis(XboxController::kRightHand) >= .3) {
	Map::Shooter1->Set(Shooter::SHOOT);
	Map::Flashlight1->Set(Relay::kOn);//not the issue
}


if(Map::Xbox1->GetTriggerAxis(XboxController::kRightHand)>.75) {

	Map::Shooter1->Set(Shooter::SHOOT);
	if(Map::Shooter1->Ready()==true){
		Map::Hopper1->Set(Hopper::ON);
		SmartDashboard::PutString("shooty","GO");

	}
	if(Map::Shooter1->Ready()==false){
		Map::Hopper1->Set(Hopper::OFF);
		SmartDashboard::PutString("shooty","Not Ready To Fire");
	}
}


if(Map::Xbox1->GetBumper(Joystick::kRightHand)==true){
Map::Hopper1->Set(Hopper::REVERSE);

}
if(Map::Xbox1->GetTriggerAxis(XboxController::kRightHand)<.3&&Map::Xbox1->GetBumper(Joystick::kRightHand)==false) {
Map::Hopper1->Set(Hopper::OFF);
Map::Shooter1->Set(Shooter::DISABLE);
Map::Flashlight1->Set(Relay::kOff);
}

if(Map::Xbox1->GetTriggerAxis(XboxController::kLeftHand)>.6){
	Map::Drive1->Set(Drive::HIGHGEAR);

}
if(Map::Xbox1->GetBumper(XboxController::kLeftHand)==true&&
		Map::Xbox1->GetTriggerAxis(XboxController::kLeftHand)<=.6){
	Map::Drive1->Set(Drive::LOWGEAR);

}

//if(Map::Xbox2->GetXButton()==true){
//	Map::Gear1->Set(Gear::AUTO);
//}	prob needs to be commented out but wasn't during testing
if(Map::Xbox2->GetYButton()==true){
	Map::Gear1->Set(Gear::HOLD);	//
}
if(Map::Xbox2->GetBButton()==true){
	Map::Gear1->Set(Gear::INTAKE);
}
//if(Map::Xbox2->GetAButton()==true){
//	Map::Gear1->Set(Gear::SCORE);
//}
//if(Map::Xbox2->GetXButton()==true){
//	Map::Gear1->Set(Gear::BALLINTAKE);
//}
//if(Map::Xbox2->GetXButton()==false&&Map::Xbox2->GetBButton()==false&&
//		Map::Xbox2->GetYButton()==false&&Map::Xbox2->GetAButton()==false){
//	Map::Gear1->Set(Gear::HOLD);
//}
//if(Map::Xbox1->GetPOV() == 180){
//	In->Slide->Set(false);
//}
if(Map::Xbox2->GetTriggerAxis(XboxController::kRightHand)> .3&&
		Map::Xbox2->GetTriggerAxis(XboxController::kRightHand)< .5&&Map::Xbox1->GetAButton()==false){
	Map::Intake1->Set(Intake::GEAROFF);

}
if(Map::Xbox2->GetTriggerAxis(XboxController::kRightHand)>= .5){
	Map::Intake1->Set(Intake::GEARON);
}
//if(Map::Xbox2->GetBumper(XboxController::kLeftHand)==true){
//	Map::Intake1->Set(Intake::GEARSCORE);
//}
if(Map::Xbox2->GetBumper(XboxController::kLeftHand)==true){
	Map::Intake1->Set(Intake::GEARSCORE);
}
if(Map::Xbox2->GetTriggerAxis(XboxController::kLeftHand)> .5){
	Map::Intake1->Set(Intake::ON);
}
if(Map::Xbox2->GetTriggerAxis(XboxController::kRightHand)<=.3&&
		Map::Xbox2->GetTriggerAxis(XboxController::kLeftHand)<=.5&&
		Map::Xbox2->GetBumper(XboxController::kLeftHand)==false){
	Map::Intake1->Set(Intake::OFF);
}
if(Map::Xbox2->GetBumper(XboxController::kRightHand)==true){
	Map::Climb1->Set(Climb::CLIMBUP,Map::Xbox2->GetY(XboxController::kLeftHand));
}
if((Map::Xbox2->GetBumper(XboxController::kLeftHand)==false)&&
		(Map::Xbox2->GetBumper(XboxController::kRightHand)==false)){
	Map::Climb1->Set(Climb::STOP,0);
}
if(Map::Xbox1->GetAButton()==true){
	Map::Intake1->Set(Intake::DISABLED);
}
//if(Map::Xbox1->GetBButton() == true){
//	Map::Intake1->Set(Intake::TEST);
//}



}

