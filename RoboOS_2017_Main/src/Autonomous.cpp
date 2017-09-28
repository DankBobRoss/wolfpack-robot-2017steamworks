/*
 * Autonomous.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: Developer
 */

#include <Autonomous.h>

Autonomous::Autonomous(){
	int counter;
}
//left side is negated change on actual robot
void Autonomous::Reset(){
	 initialize=false;
}
void Autonomous::TurnToAngle(double goal){
	Map::NavX->Reset();
	double p = SmartDashboard::GetNumber("pangle", 0);
	double ivalue = SmartDashboard::GetNumber("iangle", 0);
	double d = SmartDashboard::GetNumber("dangle", 0);
	AnglePID->Set(p,ivalue,d);
	int PosGoal=goal;
//	int PosGoal= SmartDashboard::GetNumber("Turn to angle goal", );
	int Currangle = Map::NavX->GetAngle();
	int RDistance;
	int NegGoal = PosGoal - 360;
	 LeftDistance = NegGoal -Currangle;
	 LeftDistance = LeftDistance *-1;
	 LeftDistance = LeftDistance%360;
	 LeftDistance = LeftDistance *-1;
	if((PosGoal - Currangle)<0){
		//RDistance = (-1*((-1*(PosGoal - Currangle))%360))+360;
		RDistance = PosGoal - Currangle;
		RDistance = RDistance *-1;
		RDistance = RDistance%360;
		RDistance = RDistance* -1;
		RDistance = RDistance +360;
	}else{
		RDistance = PosGoal - Currangle;
	}
//	int LeftDistance = -1*((-1*(NegGoal - Currangle))%360);
	if(abs(LeftDistance) < abs(RDistance)){
			if(Currangle < goal){
				Map::LeftFront->Set(-.5);
				Map::RightFront->Set(.5);
			}else if(Currangle >= goal){
				Map::LeftFront->Set(0);
				Map::RightFront->Set(0);
			}
//	    	Map::RightFront->Set(AnglePID->Calculate(PosGoal-Currangle));
//			Map::LeftFront->Set(AnglePID->Calculate(PosGoal-Currangle));
//			error = LeftDistance;
	 }else{
			if (Currangle <= goal) {
				Map::LeftFront->Set(.5);
				Map::RightFront->Set(-.5);
			}else if(Currangle >= goal){
				Map::LeftFront->Set(0);
				Map::RightFront->Set(0);
			}

//	    	Map::RightFront->Set(AnglePID->Calculate(PosGoal-Currangle));
//			Map::LeftFront->Set(AnglePID->Calculate(PosGoal-Currangle));
//			error= RDistance;
	 }
//	Map::RightFront->Set(AnglePID->Calculate(error));
//	Map::LeftFront->Set(-(AnglePID->Calculate(error)));


}

//beginning of awesome pidness
//end :( of awesome pidness

void Autonomous::TurnAngle(double goal,double &error){
	double p = SmartDashboard::GetNumber("pangle", 0);
	double ivalue = SmartDashboard::GetNumber("iangle", 0);
	double d = SmartDashboard::GetNumber("dangle", 0);
	AnglePID->Set(p,ivalue,d);
//	float angle=(Map::NavX->GetAngle())/360;
//	SmartDashboard::PutNumber("other",angle);
//	float out=angle -long(angle);
//
//	out=out*360;
//
//	SmartDashboard::PutNumber("outangle",out);
////	if((goal-out)<=abs(goal-360-out)){//add pid
////		Map::RightFront->Set(AnglePID->Calculate(-(goal-out)));
////		Map::LeftFront->Set(-(AnglePID->Calculate(goal-out)));
////	}
////
////	if((goal-out)>abs(goal-360-out)){
////		Map::RightFront->Set(AnglePID->Calculate((goal-360-out)));
////		Map::LeftFront->Set(AnglePID->Calculate((goal-360-out)));//should be - if wasn't switched
////
////
////
////	}
//	Map::RightFront->Set(-(AnglePID->Calculate(-(goal-out))));
//	Map::LeftFront->Set((AnglePID->Calculate(goal-out)));

	double desired,i,newgoal,actual;
	desired=goal;
	actual=Map::NavX->GetAngle();

//	i=long(actual/360);
//	if(actual<0){
//
//		newgoal=360*-i+actual;//was absolute before don't think it needs to be
//		std::cout<<i;
//		std::cout<<"\n";
//		if(newgoal<0){
//			newgoal+=360;
//		}
//
//	}
//	if(actual>0){
//		newgoal=360*-i+actual;
//		std::cout<<i;
//		std::cout<<"\n";
//		if(newgoal<0){
//			newgoal-=360;
//		}
//	}
//	if(desired-newgoal>180){
//		Map::LeftFront->Set(AnglePID->Calculate(desired-newgoal-360));//on old robot negate left
//		Map::RightFront->Set(AnglePID->Calculate(-(desired-newgoal-360)));
//	}
//	else{
//		Map::LeftFront->Set(AnglePID->Calculate(desired-newgoal));//on old robot negate left
//		Map::RightFront->Set(AnglePID->Calculate(-(desired-newgoal)));
//	}

Map::RightFront->Set(AnglePID->Calculate(desired-actual));
Map::LeftFront->Set(AnglePID->Calculate(desired-actual));
error=desired-actual;





}
void Autonomous::Mode(State state){
	double stuff;
	SmartDashboard::PutNumber("AUTOSTATE",phase);
	switch(state){

	case SIT:
		//does nothing

	break;
	case CROSS:
		if(initialize = false){
			AutoTimer->Reset();
			AutoTimer->Start();
			initialize = true;
		if(AutoTimer->Get() < 2){
			Map::LeftFront->Set(-.3);
			Map::RightFront->Set(-.3);
		}
		if(AutoTimer->Get() > 2 ){
			Map::LeftFront->Set(0);
			Map::RightFront->Set(0);
		}
//	if(Encode->Get() == ){
//
//
//	}
//		if(counter < 25){
//					Map::LeftFront->Set(.5);
//					Map::RightFront->Set(.5);
//				}else if(counter >=5){
//					Map::LeftFront->Set(0);
//					Map::RightFront->Set(0);
//				}
//				counter++;

	break;
	case SHOOT:
			Map::Shooter1->Set(Shooter::SHOOT);
			if(Map::Shooter1->Ready()==true){
				Map::Hopper1->Set(Hopper::AUTO);
			}
			if(Map::Shooter1->Ready()==false){
				Map::Hopper1->Set(Hopper::OFF);
			}
			if(Map::Hopper1->GetAmp() > 25){
				Map::Hopper1->Set(Hopper::OFF);
			}
	//		if(SmartDashboard::GetNumber("Hopper Amperage", 1)){
	//			Map::Hopper1->Set(Hopper::OFF);
	//		}
			break;
//	case CENTERPEG:
//		double geardistance=frc::SmartDashboard::GetNumber("geardistance",1000);//this number needs to be found,slamming into the wall is aok
//		Map::RightFront->SetControlMode(CANTalon::kPosition);
//		Map::LeftFront->SetControlMode(CANTalon::kPosition);
//		Map::RightFront->Set(geardistance);
//		Map::LeftFront->Set(geardistance);
//
//	break;
//
//	case LEFTPEG:
//
//	break;
//
//	case RIGHTPEG:
//
//	break;
//	case ENCODER:
//		Map::RightFront->SetControlMode(CANTalon::kPosition);
//		Map::LeftFront->SetControlMode(CANTalon::kPosition);
//
//
//	break;


}}
























































//blue shoot from a while ago did not work properly
//if(initialize==false){
//						AutoTimer->Reset();
//						AutoTimer->Start();
//						initialize=true;
//					}
//					switch(phase){
//							case 0:
//
//							Map::Shooter1->Set(Shooter::SHOOT);
//							if(Map::Shooter1->Ready()==true){
//								Map::Hopper1->Set(Hopper::AUTO);
//
//							}
//							if(Map::Shooter1->Ready()==false){
//								Map::Hopper1->Set(Hopper::OFF);
//							}
//							if(AutoTimer->Get()>5){
//								phase=1;
//								Map::Shooter1->Set(Shooter::DISABLE);
//								Map::Hopper1->Set(Hopper::OFF);
//
//							}
//							break;
//							case 1:
//								Map::LeftFront->Set(.5);
//								Map::RightFront->Set(.5);
//								if(AutoTimer->Get()>8.5){
//									phase =2;
//								}
//							break;
//							case 2:
//								Map::LeftFront->Set(-.5);
//								Map::RightFront->Set(.5);
//								if(AutoTimer->Get()>9.75){
//									phase =3;
//								}
//							break;
//							case 3:
//								Map::LeftFront->Set(.5);
//								Map::RightFront->Set(.5);
//								if(AutoTimer->Get()>12.75){
//									phase =4;
//								}
//
//
//							break;
//							case 4:
//								Map::LeftFront->Set(0);
//								Map::RightFront->Set(0);
//							break;
//					}




//
//
//
//
//red shoot worked ish
//	case REDSHOOTCROSS:
//			SmartDashboard::PutNumber("state",phase);
//			if(initialize==false){
//				AutoTimer->Reset();
//				AutoTimer->Start();
//				initialize=true;
//			}
//			switch(phase){
//					case 0:
//
//					Map::Shooter1->Set(Shooter::SHOOT);
//					if(Map::Shooter1->Ready()==true){
//						Map::Hopper1->Set(Hopper::AUTO);
//
//					}
//					if(Map::Shooter1->Ready()==false){
//						Map::Hopper1->Set(Hopper::OFF);
//					}
//					if(AutoTimer->Get()>8){
//						phase=1;
//						Map::Shooter1->Set(Shooter::DISABLE);
//						Map::Hopper1->Set(Hopper::OFF);
//
//					}
//					break;
//					case 1:
//						Map::LeftFront->Set(-.5);
//						Map::RightFront->Set(-.5);
//
//						if(AutoTimer->Get()>8.5){
//							phase =2;
//						}
//					break;
//					case 2:
//						Map::Drive1->Set(Drive::LOWGEAR);
//						Map::LeftFront->Set(.5);
//						Map::RightFront->Set(-.5);
//						if(AutoTimer->Get()>9.125){
//							phase =3;
//						}
//					break;
//					case 3:
//						//Map::Drive1->Set(Drive::HIGHGEAR);
//
//						Map::LeftFront->Set(.5);
//						Map::RightFront->Set(.5);
//						if(AutoTimer->Get()>10.3125){
//							phase =4;
//						}
//
//
//					break;
//					case 4:
//						//Map::Drive1->Set(Drive::HIGHGEAR);
//						Map::LeftFront->Set(0);
//						Map::RightFront->Set(0);
//					break;


}
