/*
 * intake.h
 *
 *  Created on: Jan 30, 2017
 *      Author: 99756814
 */


#ifndef INTAKE_H_
#define INTAKE_H_
#include "WPILib.h"
#include "CANTalon.h"


class Intake {
public:
 Intake();

	enum State{
		OFF,
		ON,
		BACK,
		GEARON,
		GEAROFF,
		GEARSCORE,
		STARTINGCONFIG,
		DISABLED

	};

private:
	std::shared_ptr<CANTalon>
		Geary{new CANTalon (9)};//changed to 9
	std::shared_ptr<CANTalon>
		Left{new CANTalon (8)};
	std::shared_ptr<DoubleSolenoid>Position{new DoubleSolenoid(1,0,1)};
	std::shared_ptr<Solenoid>Slide{new Solenoid(1,2)};// not sure what the hell this is for :(
//	std::shared_ptr<DoubleSolenoid>Position{new DoubleSolenoid(1,0,1)};
//		std::shared_ptr<Solenoid>Slide{new Solenoid(1,2)};//previous that worked
	//#pointlesssolenoid #doingtoomuch
	bool init=false;
	std::shared_ptr<Timer>IntakeTimer{new Timer()};
	//added new stuff
	std::shared_ptr<Solenoid>Shux{new Solenoid(2,0)};



public:
	void Set(State current);
	void Reset();


};


#endif /* INTAKE_H_ */
