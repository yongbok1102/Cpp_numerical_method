#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int C=0; //equivalent to the area of a unit circle
    int S=0; //Equivalent to the area of a unit square
    double pi_rand;
    
    double x,y;
    
    int N;
    cout<<"enter the maximum iteration number ";cin>>N;
    
    srand(10);
    for(int i=1;i<=N;i++)
    {
        x=(double)(rand()%N+1)/(double)N;
        y=(double)(rand()%N+1)/(double)N;
        //cout<<"(x,y)="<<'('<<x<<','<<y<<")\n";
        
        S+=1;
        if(pow(x,2)+pow(y,2) < 1)
        {
            C+=1;
        }       
    }
    pi_rand= 4* (double)C / (double)S;
    cout<<"pi_rand="<<pi_rand<<endl;
    return 0;
}
