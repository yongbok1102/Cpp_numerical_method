#include <iostream>
#include <math.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES

using namespace std;

void values(float *pi, int *P, int *Q)
{
    float x(0), y(0);
    x = (double)rand()/(double)RAND_MAX;
    y = (double)rand()/(double)RAND_MAX;
    if(sqrt((x*x)+(y*y))<=1)
    {
        (*P)++;
    }
    (*Q)++;
    *pi = 4.0*(*P)/(*Q);
}

float get_pi(float required_accuracy)
{
    int D(0), N(0);
    float pi_estimate(0), x(0), y(0), temp(0);
    while(N<=RAND_MAX)
    {
        values(&pi_estimate,&D,&N);
    }

    while(1)
    {
        if(4./(N+1.)<((required_accuracy*0.01)*(pi_estimate)))
        {
            cout<<pi_estimate<<endl;
            return (pi_estimate);
        }
        values(&pi_estimate,&D,&N);
    }
}

int main()
{
    for(float a=0.1;a>=1.e-14;a/=10.)
    {
        cout<<"Actual accuracy : "<<(fabs(get_pi(a) - M_PI)/(M_PI))*100.<<endl;
    }
}
