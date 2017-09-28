#include "Map.h"
using namespace frc;//strange it is wanting the frc:: sometimes but not others
	std::shared_ptr<CANTalon>Map::Talon1;
	std::shared_ptr<CANTalon>Map::Talon2;
	std::shared_ptr<CANTalon>Map::Talon3;
	std::shared_ptr<CANTalon>Map::RightFront;
	std::shared_ptr<CANTalon>Map::RightBack;
	std::shared_ptr<CANTalon>Map::LeftFront;
	std::shared_ptr<CANTalon>Map::LeftBack;
	std::shared_ptr<Hopper>Map::Hopper1;
	std::shared_ptr<Shooter>Map::Shooter1;
	std::shared_ptr<Gear>Map::Gear1;
	std::shared_ptr<Timer>Map::PlaybackTimer;
	std::shared_ptr<Timer>Map::MotionProfileTimer;
	std::shared_ptr<XboxController>Map::Xbox1;
	std::shared_ptr<XboxController>Map::Xbox2;
	std::shared_ptr<AHRS>Map::NavX;
	std::shared_ptr<Drive>Map::Drive1;
	std::shared_ptr<Intake>Map::Intake1;
	std::shared_ptr<Relay>Map::Flashlight1;
	std::shared_ptr<Climb>Map::Climb1;
	//std::shared_ptr<Interface>Map::Interface1;




void Map::Init(){
	Talon1.reset(new CANTalon(6,1));
	Talon2.reset(new CANTalon(7));
	Talon3.reset(new CANTalon(3));//originally for mag will prob be changed
	RightFront.reset(new CANTalon(5));//was 4
	RightBack.reset(new CANTalon(4));//was 5
	LeftFront.reset(new CANTalon(2));
	LeftBack.reset(new CANTalon(1));
	Hopper1.reset(new Hopper(0,0));
	Shooter1.reset(new Shooter(Talon1,Talon2));
	Gear1.reset(new Gear());
	PlaybackTimer.reset(new Timer());
	MotionProfileTimer.reset(new Timer());
	Xbox1.reset(new XboxController(0));
	Xbox2.reset(new XboxController(1));
	Drive1.reset(new Drive(RightFront,LeftFront));//need to change so it is fed the proper talons
	NavX.reset(new AHRS(SPI::Port::kMXP));
	Intake1.reset(new Intake());
	Flashlight1.reset(new Relay(0,Relay::kForwardOnly));
	Climb1.reset(new Climb());
	//Interface1.reset(new Interface());



}


