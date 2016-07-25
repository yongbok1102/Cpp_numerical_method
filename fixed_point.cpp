#include <iostream>
#include <cmath>
using namespace std;

/* equation to solve is given below
x^3+x=1, x=1/(1+x^2) 
It'll solve the equation using fixed point iteration method*/

double f(double x)
{
    return 1/(1+pow(x,2));
}

int main()
{
    double x=0.7; double xold=x+0.1;
    double tol=1e-08;
    while(abs(x-xold)>tol)
    {
        xold=x;
        x=f(x);
        cout<<"x="<<x<<endl;
    }
    
    return 0;
}
