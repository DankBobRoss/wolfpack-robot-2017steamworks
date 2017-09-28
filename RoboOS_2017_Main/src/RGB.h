#ifndef SRC_RGB_H_
#define SRC_RGB_H_

#include "WPILib.h"
#include <Timer.h>
#include <iostream>
#include <memory>

class RGB{
public:
	enum Color{
		YELLOW,
		BLUE,
		GREEN,
		RED,
		ORANGE,
		PURPLE,
		MAGENTA,
		GOLD,
		WHITE,
		CYAN,
		LIGHT_GREEN,
		NEON_YELLOW,
		NEON_GREEN,
		NEON_PINK,
		NEON_ORANGE,
		NEON_PURPLE,
		OFF
	};
	RGB();
	void Set(Color value);
	void Set(Color value, double ms);
	void SetRGB(Color value);
	void SetValue(int red, int green, int blue);
//	void Pulse(double value, std::shared_ptr<DigitalOutput>out);
private:
	double r;
	double g;
	double b;
	bool pulse=false;
	std::shared_ptr<PWM>red;
	std::shared_ptr<PWM>green;
	std::shared_ptr<PWM>blue;
//	std::shared_ptr<DigitalOutput>red;
//	std::shared_ptr<DigitalOutput>green;
//	std::shared_ptr<DigitalOutput>blue;
	Timer lightTimer;
	Timer pulseTimer;
	bool flashState = false;
	Color currentColor_;
};


#endif /* SRC_RGB_H_ */
