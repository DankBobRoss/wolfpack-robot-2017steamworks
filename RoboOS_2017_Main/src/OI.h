/*
 * OI.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Developer
 */

#ifndef SRC_OI_H_
#define SRC_OI_H_
#include "WPIlib.h"
#include "Hopper.h"
#include "Gear.h"
#include "Shooter.h"
#include "Intake.h"
#include "Map.h"
#include "Interface.h"


class OI {
public:
	std::shared_ptr<Intake>In{new Intake()};
	void Enable();
	bool hopperTrump_=false;


};

#endif /* SRC_OI_H_ */
