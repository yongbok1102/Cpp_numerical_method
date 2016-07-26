#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double f(double x){
    if(x==0)
        return 0.5;
    else
        return (1-cos(x))*pow(x,-2);
}

int main()
{
    int M=0; int N=0;
    double res; double x,y;
    int itr=10000;
    
    srand((unsigned int)time(NULL));
    
    ofstream out;
    out.open("result.txt");
    
    for(int i=1;i<=itr;i++)
    {
        M++;
        x=(double)rand()/RAND_MAX;
        y=(double)rand()/RAND_MAX;
        
        if(y<f(x)){
            N++;
            res = (double)N/(double)M;
        }
		cout << i << '\t' << res << endl;
		out << i << '\t' << res << endl;
    }
    
    out.close();
    return 0;
}
