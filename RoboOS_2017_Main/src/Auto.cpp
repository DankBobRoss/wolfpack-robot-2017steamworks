
#include "Auto.h"



//
//void Auto::TurnAngle(double goal){
//	double p = SmartDashboard::GetNumber("pangle", 0);
//	double i = SmartDashboard::GetNumber("iangle", 0);
//	double d = SmartDashboard::GetNumber("dangle", 0);
//	AnglePID->Set(p,i,d);
//	float angle=(Map::NavX->GetAngle())/360;
//	SmartDashboard::PutNumber("other",angle);
//	float out=angle -long(angle);
//
//	out=out*360;
//	if(out<0){
//		out+=360;
//
//	}
//	SmartDashboard::PutNumber("outangle",out);
//	if((goal-out)<=abs(goal-360-out)){//add pid
//		Map::RightFront->Set(AnglePID->Calculate(-(goal-out)));
//		Map::LeftFront->Set(AnglePID->Calculate(goal-out));
//	}
//
//	if((goal-out)>abs(goal-360-out)){
//		Map::RightFront->Set(AnglePID->Calculate((goal-360-out)));
//		Map::LeftFront->Set(AnglePID->Calculate(-(goal-360-out)));
//
//
//
//	}
//
//
//
//
//
//
//
//
//}
//void Auto::Mode(State state){
//	switch(state){
//		case CROSS:
//
//
//		break;
//
//		case GEAR:
//
//
//		break;
//
//		case YEOLD40BALLER:
//
//
//		break;
//
//		case GEARBALL:
//
//
//		break;}
//
//
//}
//
//
