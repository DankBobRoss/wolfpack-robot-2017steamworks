#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include "WPIlib.h"


#include <CANTalon.h>
#include "Shooter.h"
#include "RGB.h"
#include "Hopper.h"
#include "Map.h"
#include "Drive.h"
#include "OI.h"
#include "Datalogger.h"
#include "Autonomous.h"
#include "Sensors.cpp"

class WolfpackRobot: public IterativeRobot {
public:
//trying to clean up the datalogging process
double counter = 0;
bool initiate=false;//controls reset and ensures intake functions properly
RGB Light1;
std::shared_ptr<Map>RobotMap;
std::shared_ptr<OI>Operator;
std::shared_ptr<Autonomous>Auto{new Autonomous()};
std::shared_ptr<Datalogger>Log1{new Datalogger()};

std::string standard="/media/sda1/";
std::string shooter="/shooter.txt",time="/time.txt",leftdrive="/leftdrive.txt",rightdrive="/rightdrive.txt",
		gear="/gear.txt", hopper="/hopper.txt";
std::ofstream ShootWrite,TimeWrite,LeftDriveWrite,RightDriveWrite,GearWrite,HopperWrite;
std::ifstream ShooterRead,TimeRead,LeftDriveRead,RightDriveRead,GearRead,HopperRead;
std::string hopper_auto, time_auto,shooter_auto,gear_auto,rightdrive_auto,leftdrive_auto;
std::string hopper_tele, time_tele,shooter_tele,gear_tele,rightdrive_tele,leftdrive_tele,shots_tele;
//if the constructor does nothing
	double FileInput(std::ifstream &file){
		float line;
		if(file.eof()==0){
			file>>line;
			return line;
		}
		else{
			return 0;

		}



	}

	void Close(){
		TimeWrite.close();
		ShootWrite.close();
		HopperWrite.close();
		GearWrite.close();
		RightDriveWrite.close();
		LeftDriveWrite.close();
		ShooterRead.close();
		HopperRead.close();
		GearRead.close();
		TimeRead.close();
		RightDriveRead.close();
		LeftDriveRead.close();
	}
	void RobotInit() {


		RobotMap->Init();
		Map::LeftBack->SetControlMode(CANTalon::kFollower);
		Map::RightBack->SetControlMode(CANTalon::kFollower);
		Map::LeftBack->Set(Map::LeftFront->GetDeviceID());
		Map::RightBack->Set(Map::RightFront->GetDeviceID());//changing the get device id

//		In->Slide->Set(false);

		Map::RightFront->SetPosition(0);
		Map::LeftFront->SetPosition(0);
		Map::RightFront->SetSensorDirection(true);
		CameraServer::GetInstance()->StartAutomaticCapture();
		SmartDashboard::PutNumber("NavX Angle", Map::NavX->GetAngle());
		double AutoMode=SmartDashboard::PutNumber("AutoMode",0);
	//	CameraServer::GetInstance()->StartAutomaticCapture(1);





	}


	void AutonomousInit()  {
		Map::Intake1->Reset();
		std::string file="auto";//static_cast<std::string>(SmartDashboard::GetNumber("PlaybackMode",1));"

		hopper_auto=standard+file+hopper;
		shooter_auto=standard+file+shooter;
		gear_auto=standard+file+gear;
		time_auto=standard+file+time;
		rightdrive_auto=standard+file+rightdrive;
		leftdrive_auto=standard+file+leftdrive;
		ShooterRead.open(shooter_auto);
		HopperRead.open(hopper_auto);
		GearRead.open(gear_auto);
		TimeRead.open(time_auto);
		RightDriveRead.open(rightdrive_auto);
		LeftDriveRead.open(leftdrive_auto);
		Map::PlaybackTimer->Reset();
		Map::PlaybackTimer->Start();
		initiate=false;

//		In->Slide->Set(true);
	}

	void AutonomousPeriodic() {
		Auto->Mode(Auto->State::CROSS);
//		//
//		double ticks = 50;
//		double power = .5;
//		if(counter <= 50){
//			Map::LeftFront->Set(-.3);
//			Map::RightFront->Set(-.3);
//		}
//		if(){
//			Map::LeftFront->Set(-power);
//			Map::RightFront->Set(.3);
//		}else if(counter > 80 && counter<= 100){
//			Map::LeftFront->Set(-.3);
//			Map::RightFront->Set(-.3);
//		}else if(counter > 110){
//			Map::LeftFront->Set(0);
//			Map::RightFront->Set(0);
//		}
//		counter++;
//		Auto->TurnToAngle(45);
//		Auto->Mode(Auto->State(CROSS));
/*		double angle=SmartDashboard::GetNumber("desiredangle",100);
		Auto->TurnAngle(angle);
		double AutoMode=SmartDashboard::GetNumber("AutoMode",5);//7
		SmartDashboard::PutNumber("CurrentAutonomousRoutine",AutoMode);
		if(AutoMode!=-1){
		Auto->Mode(static_cast<Autonomous::State>(AutoMode));
		}
		SmartDashboard::PutNumber("speedright",Map::RightFront->GetSpeed());
		SmartDashboard::PutNumber("speedleft", Map::LeftFront->GetSpeed());
		SmartDashboard::PutNumber("rightposition",Map::RightFront->GetPosition());
		SmartDashboard::PutNumber("leftposition",Map::LeftFront->GetPosition());
		SmartDashboard::PutNumber("angle",Map::NavX->GetAngle());
		SmartDashboard::PutNumber("gearsharp", Map::Gear1->GetSharp());

		double right, left,intake,hopper,gear,shoot,currentTime,timeRead;
		if(AutoMode==-1){
		if(initiate==false){
			TimeRead>>timeRead;
			ShooterRead>>shoot;
			GearRead>>gear;
			HopperRead>>hopper;
			RightDriveRead>>right;
			LeftDriveRead>>left;
			initiate=true;
			Map::PlaybackTimer->Start();
			Map::PlaybackTimer->Reset();
		}
		currentTime=Map::PlaybackTimer->Get();
		if(currentTime>timeRead){
			timeRead=FileInput(TimeRead);
			shoot=FileInput(ShooterRead);
			gear=FileInput(GearRead);
			hopper=FileInput(HopperRead);
			right=FileInput(RightDriveRead);
			left=FileInput(LeftDriveRead);

		}
		Map::Shooter1->Set(static_cast<Shooter::State>(shoot));


		Map::Gear1->Set(static_cast<Gear::State>(gear));
		Map::Hopper1->Set(static_cast<Hopper::State>(hopper));
		SmartDashboard::PutNumber("PlaybackTimeRead",timeRead);
		Map::RightFront->SetControlMode(CANTalon::kPercentVbus);
		Map::RightFront->Set(right);
		Map::LeftFront->SetControlMode(CANTalon::kPercentVbus);
		Map::LeftFront->Set(left);

		}
*/

}

	void TeleopInit() {
		Map::Intake1->Reset();
//		Map::PlaybackTimer->Reset();
//		Map::PlaybackTimer->Start();
//		//when adding new file make sure to include all the closes
//
//
//
//		std::string file="auto";//static_cast<std::string>(SmartDashboard::GetNumber("RecordWrite",1));
//		hopper_tele=standard+file+hopper;
//		shooter_tele=standard+file+shooter;
//		gear_tele=standard+file+gear;
//		time_tele=standard+file+time;
//		rightdrive_tele=standard+file+rightdrive;
//		leftdrive_tele=standard+file+leftdrive;
//		ShootWrite.open(shooter_tele);
//		TimeWrite.open(time_tele);
//		HopperWrite.open(hopper_tele);
//		GearWrite.open(gear_tele);
//		RightDriveWrite.open(rightdrive_tele);
//		LeftDriveWrite.open(leftdrive_tele);
//		RightDriveWrite.open(rightdrive_tele);//this line only worked if the file folder already existed on the flashdrive

	}
	void TeleopPeriodic() {
		//double position=0;// no longer used

		//main controls

		Operator->Enable();
		//Map::Drive1->Set(Drive::HIGHGEAR);//for testing purposes



		//dashboard prints
		SmartDashboard::PutNumber("speedright",Map::RightFront->GetSpeed());
		SmartDashboard::PutNumber("speedleft", Map::LeftFront->GetSpeed());
		SmartDashboard::PutNumber("rightposition",Map::RightFront->GetPosition());
		SmartDashboard::PutNumber("leftposition",Map::LeftFront->GetPosition());
		SmartDashboard::PutNumber("angle",Map::NavX->GetAngle());
		SmartDashboard::PutNumber("gearsharp", Map::Gear1->GetSharp());
		SmartDashboard::PutNumber("geardistance", 0);


		//datalogging
//		ShootWrite<<Map::Shooter1->GetState()<<"\n";
//		TimeWrite<<Map::PlaybackTimer->Get()<<"\n";
//		HopperWrite<<Map::Hopper1->GetState()<<"\n";
//		GearWrite<<Map::Gear1->GetState()<<"\n";
//		RightDriveWrite<<Map::RightFront->Get()<<"\n";
//		LeftDriveWrite<<Map::LeftFront->Get()<<"\n";
//		ShootWrite<<Map::Shooter1->GetState()<<"\n";



	}
	void TestInit(){
		Map::PlaybackTimer->Reset();
		Map::PlaybackTimer->Start();
		//Operator->Enable();

		//when adding new file make sure to include all the closes



	std::string file="auto";//static_cast<std::string>(SmartDashboard::GetNumber("RecordWrite",1));
	hopper_tele=standard+file+hopper;
	shooter_tele=standard+file+shooter;
	gear_tele=standard+file+gear;
	time_tele=standard+file+time;
	rightdrive_tele=standard+file+rightdrive;
	leftdrive_tele=standard+file+leftdrive;
	ShootWrite.open(shooter_tele);
	TimeWrite.open(time_tele);
	HopperWrite.open(hopper_tele);
	GearWrite.open(gear_tele);
	RightDriveWrite.open(rightdrive_tele);
	LeftDriveWrite.open(leftdrive_tele);
	RightDriveWrite.open(rightdrive_tele);//this line only worked if the file folder already existed on the flashdrive



	}

	void TestPeriodic() {

		ShootWrite<<Map::Shooter1->GetState()<<"\n";
		TimeWrite<<Map::PlaybackTimer->Get()<<"\n";
		HopperWrite<<Map::Hopper1->GetState()<<"\n";
		GearWrite<<Map::Gear1->GetState()<<"\n";
		RightDriveWrite<<Map::RightFront->Get()<<"\n";
		LeftDriveWrite<<Map::LeftFront->Get()<<"\n";
		ShootWrite<<Map::Shooter1->GetState()<<"\n";





	}
	void DisabledInit(){

//		TimeWrite.close();
//		ShootWrite.close();
//		HopperWrite.close();
//		GearWrite.close();
//		RightDriveWrite.close();
//		LeftDriveWrite.close();
//		ShooterRead.close();
//		HopperRead.close();
//		GearRead.close();
//		TimeRead.close();
//		RightDriveRead.close();
//		LeftDriveRead.close();
	}


};

START_ROBOT_CLASS(WolfpackRobot)
