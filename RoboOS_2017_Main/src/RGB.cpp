#include <RGB.h>
RGB::RGB(){
	lightTimer.Start();
	pulseTimer.Start();
	red.reset(new PWM(0));
	green.reset(new PWM(1));
	blue.reset(new PWM(2));
//	red.reset(new DigitalOutput(0));
//	green.reset(new DigitalOutput(1));
//	blue.reset(new DigitalOutput(2));
}
//void RGB::Pulse(double value,std::shared_ptr<DigitalOutput>out){
//if(value!=255&&value!=0){
//	if(pulse==false){
//	if(pulseTimer.HasPeriodPassed(r/1000)){
//			out->Set(true);
//			pulse=true;
//		}
//	}
//	if(pulse==true){
//		if(pulseTimer.HasPeriodPassed((255-r)/1000)){
//			out->Set(false);
//			pulse=false;
//		}
//	}
//
//
//
//
//}
//if(value==255){
//	out->Set(true);
//}
//if(value==0){
//	out->Set(false);
//}
//
//
//
//}
void RGB::SetRGB(Color value){
	switch(value){
	case YELLOW:
		r = 255; g = 255; b = 0;
		break;
	case BLUE:
		r = 0; g = 0; b = 255;
		break;
	case GREEN:
		r = 0; g = 255; b = 0;
		break;
	case RED:
		r = 255; g = 0; b = 0;
		break;
	case ORANGE:
		r = 255; g = 165; b = 0;
		break;
	case PURPLE:
		r = 128; g = 0; b = 128;
		break;
	case MAGENTA:
		r = 255; g = 0; b = 255;
		break;
	case GOLD:
		r = 255; g = 215; b = 0;
		break;
	case WHITE:
		r = 255; g = 255; b = 255;
		break;
	case CYAN:
		r = 0; g = 255; b = 255;
		break;
	case LIGHT_GREEN:
		r = 144; g = 238; b = 144;
		break;
	case NEON_YELLOW:
		r = 243; g = 243; b = 21;
		break;
	case NEON_GREEN:
		r = 57; g = 255; b = 20;
		break;
	case NEON_ORANGE:
		r = 255; g = 131; b = 0;
		break;
	case NEON_PINK:
		r = 255; g = 105; b = 180;
		break;
	case OFF:
		r = 0; g = 0; b = 0;
		break;
	}
}
void RGB::SetValue(int red1, int green1, int blue1){
	red->SetRaw(red1);
	green->SetRaw(green1);
	blue->SetRaw(blue1);
}
void RGB::Set(RGB::Color value){

	currentColor_ = value;
	SetRGB(value);

	red->SetRaw(r);
	green->SetRaw(g);
	blue->SetRaw(b);


}



void RGB::Set(Color value, double ms){
		currentColor_ = value;
		SetRGB(currentColor_);
		if(lightTimer.HasPeriodPassed(ms / 1000)){

			flashState = !flashState;
		}
		if(flashState==false){
			SetRGB(OFF);
		}
	red->SetRaw(r);
	green->SetRaw(g);
	blue->SetRaw(b);
}
