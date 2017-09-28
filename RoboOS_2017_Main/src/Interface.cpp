/*
 * Interface.cpp
 *
 *  Created on: Jan 22, 2017
 *      Author: Developer
 */

#include <Interface.h>

Interface::Interface() {
	// TODO Auto-generated constructor stub

}


void Interface::AttemptShoot(){
	Map::Hopper1->Set(Hopper::OFF);
	Map::Shooter1->Set(Shooter::SHOOT);
	if(Map::Shooter1->Ready()==true){
		Map::Hopper1->Set(Hopper::ON);

	}



}
//climb turn off intake start climb
//
