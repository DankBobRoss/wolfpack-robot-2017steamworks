/*
 * MotionProfileClass.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: David
 */

#include "MotionProfileClass.h"

MotionProfileClass::MotionProfileClass(double v, double a):V_max(v), A_max(a) {
finished=false;

}


void MotionProfileClass::SetGoal(double distance){
	distance_=distance;
}
void MotionProfileClass::Init(){
	finished=false;
	ProfileTimer->Start();
	ProfileTimer->Reset();

}
double MotionProfileClass::GetVelocity(){
	T_cruising = ((distance_ -(V_max*V_max)/A_max))/(V_max);
	T_current=ProfileTimer->Get();
	if(T_current<V_max/A_max){
		V_current=A_max*T_current;
	}
	if(T_current>=V_max/A_max && (T_current<(T_cruising + (V_max/A_max)))){
		V_current=V_max;
	}
	if((T_current>=(T_cruising + (V_max/A_max)))){
		V_current=V_max-A_max*(T_current-(T_cruising+(V_max/A_max)));
			if(V_current<0){
				V_current=0;
				ProfileTimer->Stop();
				ProfileTimer->Reset();
				finished=true;//why
			}
	}
	SmartDashboard::PutNumber("T_current",T_current);
	return V_current;







}
bool MotionProfileClass::IsFinished(){
	return finished;

}
