#include "PID.h"
#include <Arduino.h>
//#include <ctime>
//#include <iostream>

	/*Creates controller object,default to zero unless specified*/
	PID::PID(double P, double I, double D, double* in, double* out, double* set,double max,double min) {
		
		proportional = P;
		integral = I;
		derivative = D;

		
		i_correction = 0.0;
		

		output = out;
		signal = in;
		target = set;
		
		setLimits(max, min);
	}
	

	/*lets gains for real-time tuning*/
	void PID::set_gains(double& P, double& I, double& D) {
		proportional = P;
		integral = I;
		derivative = D;
	}

	void PID::setLimits(double max, double min) {
		maximum = max;
		minimum = min;
	}

	/*Calculates the corrected signal*/
	void PID::doMath() {

		//clock_t time = std::clock();
		double time = millis();
		double error = target - signal;

		//double elapsed_time = double(time - previous_time) / CLOCKS_PER_SEC;
		double elapsed_time = double(time - previous_time);
		double p_correction = proportional * error;
		double i_correction =+  (integral * error);
		double d_correction = derivative * ((error - previous_error) / elapsed_time);

		previous_error = error;
		previous_time = time;

		double sum = p_correction + i_correction + d_correction;

		/*Sets to limit*/
		if (sum > maximum) { sum = maximum; }
		else if (sum < minimum) { sum = minimum; }

		*output = sum;
	}

	/*Return current gains for display*/
	double PID::get_p() { return proportional; }
	double PID::get_i() { return integral; }
	double PID::get_d() { return derivative; }


