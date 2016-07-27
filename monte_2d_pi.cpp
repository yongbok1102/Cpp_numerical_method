#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "avg.h"

using namespace std;

double f(double x, double y)
{
    if(x*x + y*y <= 1)
        return 1;
    else
        return 0;
}

int main()
{
    double xa=-1; double xb=1;
    double ya=-1; double yb=1;
    
    int itr, exec;
    
    cout<<"Enter the iteration number\n"; cin>>itr;
    cout<<"Enter the execution number\n"; cin>>exec;
    
    double* pRes;
    pRes = new double[exec];
    
    double x,y;
    double sumn=0; double sumf=0;
    
    ofstream out;
    out.open("monte_2d_pi.dat");
    
    //srand((unsigned int)time(NULL));
    
    cout<<"Monte-Carlo calculation started-----------------------\n";
    out<<"Monte-Carlo calculation started-----------------------\n";
    
    for(int i=0;i<exec;i++)
    {
        srand((unsigned int)time(NULL));
        cout<<"execution "<<i+1<<"-------------------\n";     
        for(int j=1;j<=itr;j++)
        {
            x=(xb-xa)*(double)rand()/RAND_MAX + xa;
            y=(yb-ya)*(double)rand()/RAND_MAX + ya;
            sumn++;
            sumf+=f(x,y);
            cout<<j<<'\t'<<(xb-xa)*(yb-ya)*sumf/sumn<<endl;        
        }
        cout<<"----------------------------------\n";
        pRes[i]=(xb-xa)*(yb-ya)*sumf/sumn;
        cout<<i+1<<'\t'<<pRes[i]<<endl;        
        out<<i+1<<'\t'<<pRes[i]<<endl;
        
        sumn=0;
        sumf=0;
    }
    cout<<"----------------------------------------\n";
    out<<"------------------------------------------\n";
    double res = avg(pRes,exec);
    cout<<"average value: "<<res<<endl;
    out<<"average value: "<<res<<endl;
    

    delete[] pRes;
    out.close();    
    return 0;
    
}
