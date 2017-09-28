/*
 * Datalogger.h
 *
 *  Created on: Jan 23, 2017
 *      Author: Developer
 */

#ifndef DATALOGGER_H_
#define DATALOGGER_H_
#include<iostream>
#include<fstream>
#include<memory>
#include "Map.h"
#include "Drive.h"
#include "Gear.h"
#include "Hopper.h"
#include "Shooter.h"
class Datalogger {
private:
	bool initiate=false;
	double right, left,intake,hopper,gear,shoot,currentTime,timeRead;
	std::ifstream ShooterRead_, HopperRead_,
	GearRead_,RightDriveRead_,LeftDriveRead_,TimeRead_;
	std::ofstream ShooterWrite_,HopperWrite_,GearWrite_,
	RightDriveWrite_,LeftDriveWrite_,TimeWrite_;
	std::string time_="/media/sda1/time.txt";
	std::string shooter_="/media/sda1/shooter.txt";
	std::string hopper_="/media/sda1/hopper.txt";
	std::string gear_="/media/sda1/gear.txt";
	std::string rightdrive_="/media/sda1/rightdrive.txt";
	std::string leftdrive_="/media/sda1/leftdrive.txt";



public:
	Datalogger();
	void Init();
	void Close();
	void Logging();
	void Playback();
	double FileInput(std::ifstream &file);
	void PlaybackInit();

};

#endif /* DATALOGGER_H_ */
