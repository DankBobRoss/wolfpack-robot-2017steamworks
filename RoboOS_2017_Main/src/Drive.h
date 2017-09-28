/*
 * Drive.h
 *
 *  Created on: Jan 28, 2017
 *      Author: AT
 */

#ifndef DRIVE_H_
#define DRIVE_H_
#include "WPILib.h"
#include "CANTalon.h"
#include "math.h"
//need to add solenoids not done yet
class Drive {
public:
	Drive(std::shared_ptr<CANTalon>RightTalon,
			std::shared_ptr<CANTalon>LeftTalon);
	enum State{
		LOWGEAR,
		HIGHGEAR

	};

private:
	std::shared_ptr<Joystick>
		Joystick1{new Joystick(2)};
	std::shared_ptr<Joystick>
		Wheel1{new Joystick(3)};
	std::shared_ptr<XboxController>
		Xbox1{new XboxController(0)};
	std::shared_ptr<DoubleSolenoid>Shifter1_{new DoubleSolenoid(1,6,7)};
	std::shared_ptr<CANTalon>RightFront_;
	std::shared_ptr<CANTalon>LeftFront_;

public:
	void Set(State current);
	double Right();
	double Left();
	void Tele();
	void Do(double power);

};









#endif /* DRIVE_H_ */
