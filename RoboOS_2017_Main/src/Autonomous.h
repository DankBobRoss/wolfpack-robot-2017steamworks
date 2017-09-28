/*
 * Autonomous.h
 *
 *  Created on: Jan 30, 2017
 *      Author: Developer
 */

#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_
#include <MotionProfileClass.h>
#include "Map.h"
#include "SoftwarePidController.h"
#include "math.h"
#include "Encoder.h"

class Autonomous {
public:


	enum State{
		SIT,
		CROSS,
		CENTERPEG,
		LEFTPEG,
		RIGHTPEG,
		GEAR,
		YEOLD40BALLER,
		GEARBALL,
		MOTIONPROFILE,
		SHOOT,//5
		REDSHOOTCROSS,//6
		BLUESHOOTCROSS, //7
		ENCODER


	};
	Autonomous();
	void Mode(State state);
	void TurnAngle(double angle,double &error);
	void TurnToAngle(double goal);
	void Reset();
private:
	std::shared_ptr<SoftwarePidController>AnglePID{new SoftwarePidController(0,0,0)};
	std::shared_ptr<MotionProfileClass>Profile1{new MotionProfileClass(100,20)};
	std::shared_ptr<Timer>AutoTimer{new Timer()};
//	std::shared_ptr<Encoder> Encode{new Encoder()};

	bool initialize=false;
	int phase=0;
	int Currangle;// = NavX->GetAngle();
	int PosGoal;
	int NegGoal;
	int LeftDistance;
};

#endif /* SRC_AUTONOMOUS_H_ */
