#include <iostream>
#include <cmath>
using namespace std;

double min(double x,double y)
{
    if(x>y)
        return y;
    else
        return x;
}

double f(double x)
{
    static double pi=3.14159265;
    return exp(-pow(x,2)/2)/sqrt(2*pi);
}

int main()
{
    double xa,xb;
    cout<<"���б����� �Է��Ͻÿ�.\n";
    cin>>xa>>xb;
    int N;
    cout<<"�����Ϸ��� �ұ����� ���� �Է��Ͻÿ�.\n";
    cin>>N;
    double dx=abs(xa-xb)/N;
    
    double* pX;
    pX = new double[N+1];
    for(int i=0;i<=N;i++)
    {
        pX[i]=min(xa,xb)+i*dx;
    }
    
    double sum=0;
    
    for(int i=0;i<N;i+=2)
    {
        sum = sum + (dx/3)*( f(pX[i])+4*f(pX[i+1])+f(pX[i+2]) );
    }
    
    cout<<"I="<<sum<<endl;
    
    delete[] pX;
    return 0;
}
