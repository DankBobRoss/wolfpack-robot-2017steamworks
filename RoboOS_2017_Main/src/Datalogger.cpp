/*
 * Datalogger.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: Developer
 */

#include "Datalogger.h"
Datalogger::Datalogger(){

}

void Datalogger::Init(){
	ShooterWrite_.open(shooter_);
	HopperWrite_.open(hopper_);
	GearWrite_.open(gear_);
	TimeWrite_.open(time_);
	RightDriveWrite_.open(rightdrive_);
	LeftDriveWrite_.open(leftdrive_);
	Map::PlaybackTimer->Start();
	initiate=false;
}
void Datalogger::PlaybackInit(){
	ShooterRead_.open(shooter_);
	HopperRead_.open(hopper_);
	GearRead_.open(gear_);
	TimeRead_.open(time_);
	RightDriveRead_.open(rightdrive_);
	LeftDriveRead_.open(leftdrive_);

}
void Datalogger::Logging(){

ShooterWrite_<<Map::Shooter1->GetState();
SmartDashboard::PutNumber("shotsfired",Map::Shooter1->GetState());
HopperWrite_<<Map::Hopper1->GetState();
GearWrite_<<Map::Gear1->GetState();
TimeWrite_<<Map::PlaybackTimer->Get();;
RightDriveWrite_<<Map::RightFront->Get();
LeftDriveWrite_<<Map::LeftFront->Get();





}
double Datalogger::FileInput(std::ifstream &file){
	float line;
	if(file.eof()==0){
		file>>line;
		return line;
	}
	else{
		return 0;

	}



}
void Datalogger::Close(){
	ShooterWrite_.close();
	HopperWrite_.close();
	GearWrite_.close();
	TimeWrite_.close();
	RightDriveWrite_.close();
	LeftDriveWrite_.close();
	ShooterRead_.close();
	HopperRead_.close();
	GearRead_.close();
	TimeRead_.close();
	RightDriveRead_.close();
	LeftDriveRead_.close();


}
void Datalogger::Playback(){

	if(initiate==false){
		TimeRead_>>timeRead;
		ShooterRead_>>shoot;
		GearRead_>>gear;
		HopperRead_>>hopper;
		RightDriveRead_>>right;
		LeftDriveRead_>>left;
		initiate=true;
		Map::PlaybackTimer->Start();
		Map::PlaybackTimer->Reset();
	}
	currentTime=Map::PlaybackTimer->Get();
	if(currentTime>timeRead){
		timeRead=FileInput(TimeRead_);
		shoot=FileInput(ShooterRead_);
		gear=FileInput(GearRead_);
		hopper=FileInput(HopperRead_);
		right=FileInput(RightDriveRead_);
		left=FileInput(LeftDriveRead_);

	}
	Map::Shooter1->Set(static_cast<Shooter::State>(shoot));
	Map::Gear1->Set(static_cast<Gear::State>(gear));
	Map::Hopper1->Set(static_cast<Hopper::State>(hopper));
	Map::RightFront->SetControlMode(CANTalon::kPercentVbus);
	Map::RightFront->Set(right);
	Map::LeftFront->SetControlMode(CANTalon::kPercentVbus);
	Map::LeftFront->Set(left);


}



