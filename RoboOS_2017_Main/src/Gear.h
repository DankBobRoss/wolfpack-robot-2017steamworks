/*

 * Gear.h
 *
 *  Created on: Jan 23, 2017
 *      Author: Developer
 */

#ifndef SRC_GEAR_H_
#define SRC_GEAR_H_
#include "WPILib.h"
#include <memory>

class Gear {
public:
	Gear();
	enum State{
		HOLD=0,
		SCORE,
		AUTO,
		INTAKE,
		BALLINTAKE
	};
	void Set(State state);
	void Set();
	double GetState();
	double GetSharp();
private:
	State current_=HOLD;//may need to change
	std::shared_ptr<DoubleSolenoid>GearSolenoid{new DoubleSolenoid(1,4,5)};
	std::shared_ptr<DoubleSolenoid>Flappy{new DoubleSolenoid(2,1,4)};//1 to 4//changed 2 to 1
	std::shared_ptr<Solenoid>Bally1{new Solenoid(2,2)};//3 needs to be plugged in
	std::shared_ptr<Solenoid>Bally2{new Solenoid(1,3)};
	std::shared_ptr<AnalogInput>Sharp{new AnalogInput(0)};

};

#endif /* SRC_GEAR_H_ */
