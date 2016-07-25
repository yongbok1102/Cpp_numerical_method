#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
/* B/A = ln(2)*/

double f(double x)
{
    return 1/(1+x);
}

int main()
{
    double x,y;
    int A=0; int B=0;
    int N;
    cout<<"enter the maximum iterative number ";cin>>N;
    srand((unsigned int)time(NULL));
    ofstream out;
    out.open("ln2.txt");
    
    double ln2;
    for(int i=1;i<=N;i++)
    {
        A=A+1;
        x=(double)rand()/RAND_MAX;
        y=(double)rand()/RAND_MAX;
        if(y<f(x))
            B=B+1;
        ln2 = (double)B/(double)A;
        cout<<i<<'\t'<<ln2<<endl;
        out<<i<<'\t'<<ln2<<endl;
    }
    
    out.close();
    return 0;
}
