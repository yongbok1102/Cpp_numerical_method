#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return 1./x;
}

int powMin1(int i){
  if(i%2==0)
    return 1;
   else
    return -1;
}

double Fdot(double x, double a, double b){
    return f(x) - (f(b)-f(a))*(x-a)/(b-a) - f(a);
}
int main(){
    double pi = 3.14159265359;
    
    double a1, a3, a5;
    double xm;
    double a, b;
    cout<<"Enter the two end points of interval\n";
    cin>>a>>b;
    
    int N;
    int n;
    cout<<"Enter the number of intervals\n";
    cin>>N;
    cout<<"Enter the number of terms of Fourier Series\n";
    cin>>n;
    
    double* A; A = new double[n];
    
    double dx = (b-a)/N;
    
    double* x; x = new double[N+1];
    
    for(int i=0; i<=N; i++){
        x[i] = a + i*dx;
    }
    
    double sum = 0;
    
    for(int i=1; i<=N; i++){
        sum += 0.5*dx*(f(x[i])+f(x[i-1]));
        xm = 0.5*(x[i]+x[i-1]);
        for(int j=0; j<n; j++){
          A[j] = 2*Fdot(xm,x[i-1],x[i])*powMin1(j);
        }
        for(int j=0; j<n; j++){
          sum += dx*(2./pi)*A[j]/(2*j+1);
        }
    }
    cout.precision(15);
    cout<<"ln("<<(b/a)<<")="<<sum<<endl;
    
    return 0;
}
