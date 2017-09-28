/*
 * Shooter.h
 *
 *  Created on: Jan 13, 2017
 *      Author: Developer
 */

#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_
#include "WPIlib.h"
#include "CANTalon.h"
#include <iostream>
#include <memory>
#include <string>
#include "math.h"
#include<iostream>
#include<fstream>


class Shooter {
private:
	std::shared_ptr<CANTalon>Shooter1_;
	std::shared_ptr<CANTalon>Shooter2_;//if each shooter uses two motors
	std::shared_ptr<CANTalon>Mag1_;//feeds balls from hopper into shooter
public:
	Shooter(std::shared_ptr<CANTalon>shoot1,std::shared_ptr<CANTalon>shoot2);
	enum State{
		DISABLE=0,
		SHOOT,
		LOAD,
		TEST,
		INTAKE

	};
	void Set(State currentstate);
	bool Ready();
	double GetState();
private:
	State current_;
	double average[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int i=0;


};

#endif /* SRC_SHOOTER_H_ */
