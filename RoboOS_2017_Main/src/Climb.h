/*
 * Climb.h
 *
 *  Created on: Feb 12, 2017
 *      Author: Long Le
 */

#ifndef SRC_CLIMB_H_
#define SRC_CLIMB_H_
#include "CANTalon.h"
#include "WPILib.h"


class Climb {
public:
	Climb();
	enum State{
	CLIMBUP=0,
	CLIMBDOWN,
	STOP


	};
private:
	std::shared_ptr<CANTalon>climb1_{new CANTalon(10)};//need to find actual right talon
	std::shared_ptr<CANTalon>climb2_{new CANTalon(12)};
public:
	void Set (State currentstate,double speed);
	bool Ready ();
	double GetState ();
private:
	State current_;


};



#endif /* SRC_CLIMB_H_ */
