/*
 * SoftwarePidController.cpp
 *
 *  Created on: Mar 11, 2016
 *      Author: Developer
 */

#include <SoftwarePidController.h>

SoftwarePidController::~SoftwarePidController() {
	// TODO Auto-generated destructor stub
}

SoftwarePidController::SoftwarePidController(double kP, double kI, double kD) :
		kP(kP), kI(kI), kD(kD), integral(0), lastProportional(0) {
	// TODO Auto-generated constructor stub

}
void SoftwarePidController::Set(double p, double i, double d){
	kP=p;kI=i;kD=d;


}
double SoftwarePidController::Calculate(double value) {
	double e = value;
	double der = (e - lastProportional) * 50;
	integral +=  e;
	return kP * e + kI * integral + kD * der;
}
