/*
 * Map.h
 *
 *  Created on: Jan 24, 2017
 *      Author: Developer
 */

#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include <memory>
#include <string>
#include "WPIlib.h"
#include "CANTalon.h"
#include "Hopper.h"
#include "Shooter.h"
#include "Gear.h"
#include "AHRS.h"
#include "Drive.h"
#include "Intake.h"
#include "Interface.h"
#include "Climb.h"

class Map {
public:
	void Init();
	static std::shared_ptr<Relay>Flashlight1;
	static std::shared_ptr<DoubleSolenoid>Solenoid1;
	static std::shared_ptr<CANTalon>Talon1;
	static std::shared_ptr<CANTalon>Talon2;
	static std::shared_ptr<CANTalon>Talon3;
	static std::shared_ptr<CANTalon>RightFront;
	static std::shared_ptr<CANTalon>RightBack;
	static std::shared_ptr<CANTalon>LeftFront;
	static std::shared_ptr<CANTalon>LeftBack;
	static std::shared_ptr<Hopper>Hopper1;
	static std::shared_ptr<Shooter>Shooter1;
	static std::shared_ptr<Gear>Gear1;
	static std::shared_ptr<Timer>PlaybackTimer;
	static std::shared_ptr<Timer>MotionProfileTimer;
	static std::shared_ptr<XboxController>Xbox1;
	static std::shared_ptr<XboxController>Xbox2;
	static std::shared_ptr<AHRS>NavX;
	static std::shared_ptr<Drive>Drive1;
	static std::shared_ptr<Intake>Intake1;
	static std::shared_ptr<Climb>Climb1;
	//static std::shared_ptr<Interface>Interface1;


};

#endif /* MAP_H_ */
