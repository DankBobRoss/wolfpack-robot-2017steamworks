/*
 * Hopper.h
 *
 *  Created on: Jan 15, 2017
 *      Author: Developer
 */

#ifndef SRC_HOPPER_H_
#define SRC_HOPPER_H_
#include"WPIlib.h"
#include"CANTalon.h"
#include<memory>

class Hopper {
 private:
	double speed_,intake_,speed;

	std::shared_ptr<CANTalon>Hopper_{new CANTalon(15)};//bad boy bad boy whatcha gonna do
public:
	enum State{

		OFF=0,
		ON,
		INTAKE,
		TEST,
		REVERSE,
		AUTO
	};

	Hopper(double speed, double intake);
	void SetSpeed(double speed);
	void Set(State state);
	double GetState();
	void Set();
	double GetAmp();
private:
	State current_=OFF;






};

#endif /* SRC_HOPPER_H_ */
