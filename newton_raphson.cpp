#include <iostream>
#include <cmath>
using namespace std;

/*equation to solve is given below
x^3 + x - 1=0 
It'll solve the equation using Newton-Raphson method*/

double f(double x)
{
    return pow(x,3)+x-1;
}

double fdot(double x)
{
    return 3*pow(x,2)+1;
}

int main()
{
    double x=0.6;
    double xold=0.7;
    double tol=1e-08;
    while(abs(x-xold)>tol)
    {
        xold=x;
        x=x-f(x)/fdot(x);
        cout<<"x="<<x<<endl;
    }
    
    return 0;
}
