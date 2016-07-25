#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

/*designed to calculate the estimated value of Pi
  using Monte-Carlo method */
  
int main()
{
    int N;
    cout<<"enter the maximum iterative number. "; cin>>N;
    
    double x,y;
    int S=0; //S is equivalent to the area of the unit square
    int C=0; //C is equivalent to the area of the circle
    
    srand((unsigned int)time(NULL));
    
	ofstream out;
	out.open("monte_pi_res.txt");
	
	double pi_est;
	
    for(int i=1;i<=N;i++)
    {
        S=S+1;
        x=(double)rand()/(double)RAND_MAX;
        y=(double)rand()/(double)RAND_MAX;
        
        if(x*x + y*y <1)
            C=C+1;
		
		pi_est = 4*(double) C/(double) S;
		cout<<i<<'\t'<<pi_est<<endl;
		out<<i<<'\t'<<pi_est<<endl;
    }
    
	out.close();
	
	return 0;
  
}
