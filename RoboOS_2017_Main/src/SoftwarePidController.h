/*
 * SoftwarePidController.h
 *
 *  Created on: Mar 11, 2016
 *      Author: Developer
 */

#ifndef SRC_CONTROLLERS_SOFTWAREPIDCONTROLLER_H_
#define SRC_CONTROLLERS_SOFTWAREPIDCONTROLLER_H_

class SoftwarePidController {
public:
	virtual ~SoftwarePidController();
	SoftwarePidController(double kP, double kI, double kD);
	double Calculate(double error);
	void Set(double p, double i, double d);
private:
	double kP, kI, kD;
	double integral;
	double lastProportional;
};

#endif /* SRC_CONTROLLERS_SOFTWAREPIDCONTROLLER_H_ */
