#pragma once


class PID {
	
	
protected:
	/*Gain variables*/
	double proportional;
	double integral;
	double derivative;
	/*Calculation variables*/
	double i_correction;
	

	double previous_error = 0.0;
	double previous_time = 0.0;
	double* output;
	/*Real-time variables*/
	double* signal; double* target; 
	double maximum, minimum;

public:
	

	/*Creates controller object,default to zero unless specified*/
	PID(double P, double I, double D, double* signal, double* output, double* set,double max,double min);
	
	
	/*lets gains for real-time tuning*/
	void set_gains(double& P, double& I, double& D);

	void setLimits(double max=0,double min=0);

	/*Calculates the corrected signal*/
	void doMath();

	/*Return current gains for display*/
	double get_p();
	double get_i();
	double get_d();

};
