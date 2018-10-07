#include "PID.h"
#include <stdio.h>
#include <math.h>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;

    p_error = 0;
    d_error = 0;
    i_error = 0;   
}

void PID::UpdateError(double cte) {
    if(fabs(cte)<0.0001){
        p_error = 0;
    }
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    double total_err =  Kp*p_error + Kd * d_error + Ki * i_error;
    return total_err;
}

