#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

double f(double x)
{
    static double pi=3.14159265;
    return exp(-0.5*pow(x,2))/sqrt(2*pi);
}

double min(double x, double y)
{
    if(x>y)
        return y;
    else
        return x;
}

int main()
{
    double a,b;
    cout<<"적분구간을 입력하시오.\n";
    cin>>a>>b;
    double l=abs(a-b);
    double x,y;
    ofstream out;
    out.open("gaussian.txt");
    int N=10000; double X=0; double Y=0;
    
    srand((unsigned int)time(NULL));
    
    for(int i=1;i<=N;i++)
    {
        x = l*(double)rand()/RAND_MAX + min(a,b);
        y = (double)rand()/RAND_MAX;
        X++;
        if(y<f(x)){
            Y++;
        }
        cout<<i<<'\t'<<l*Y/X<<endl;
        out<<i<<'\t'<<l*Y/X<<endl;
    }
    
    out.close();
    return 0;
}
