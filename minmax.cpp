#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "max.h"
#include "min.h"
using namespace std;

double f(double x)
{
    return pow((x-1),2)-1;
}

int main()
{
    double a=0; double b=3;
    int itr;
    
    cout<<"Enter the Iteration number\n";cin>>itr;
    
    ofstream out;
    out.open("minmax.txt");
    
    double* pItr;
    pItr = new double[itr];
 
    double x;
    cout<<"Monte Carlo simulation started---------------\n";
    out<<"Monte Carlo simulation started---------------\n";    

    srand((unsigned int)time(NULL));
    for(int j=0;j<itr;j++)
    {
		x=(b-a)*(double)rand()/RAND_MAX + a;
        pItr[j]=f(x);
        cout<<j+1<<'\t'<<pItr[j]<<endl;
    }
    cout<<"-------------------------------------\n";
	double res1 = max(pItr,itr);
	double res2 = min(pItr,itr);
	cout<<"minimum: "<<res2<<endl; out<<"minimum: "<<res2<<endl;
	cout<<"maximum: "<<res1<<endl; out<<"maximum: "<<res1<<endl;
	
	out.close();
	delete[] pItr;
	return 0;
	
}
