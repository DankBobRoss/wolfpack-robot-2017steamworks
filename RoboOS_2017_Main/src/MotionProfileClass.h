/*
 * MotionProfileClass.h
 *
 *  Created on: Feb 12, 2017
 *      Author: David
 */

#ifndef MOTIONPROFILECLASS_H_
#define MOTIONPROFILECLASS_H_
#include "WPILib.h"
class MotionProfileClass {
public:
	MotionProfileClass(double v, double a);
	void SetGoal(double distance);
	double GetVelocity();
	bool IsFinished();
	void Init();

private:
	double V_max;
	double A_max;
	double V_current;
	double distance_;
	double T_current;
	double T_cruising;
	bool finished;
	std::shared_ptr<Timer>ProfileTimer{new Timer()};

};

#endif /* MOTIONPROFILECLASS_H_ */
