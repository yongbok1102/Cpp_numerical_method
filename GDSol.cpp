#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

double calRes(double AX[], double b[], int n){
    double sumAx = 0; double sumB = 0;
    
    for(int i=0; i<n; i++){
        sumAx += (AX[i]-b[i])*(AX[i]-b[i]);
        sumB += b[i]*b[i];
    }
    return sqrt(sumAx/sumB);
}
double Norm(double A[], int n)
{
    double sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += A[i]*A[i];
    }
    return sqrt(sum);
}
    
double innerProd(double x[], double y[], int n)
{
    double sum = 0;
    for(int i=0; i<n; i++)
    {
           sum += x[i]*y[i];
    }
    return sum;
}
int main(){
    int n;
    cout<<"Enter the number of unknowns: ";
    cin>>n;
    cout<<endl;
    
    double** A;
    
	A = new double* [n]; //create the matrix A
	for(int i=0; i<n; i++){
		A[i] = new double[n];
	}
    
	for(int i = 0; i<n; i++){
		cout<<"Enter "<<n<<" numbers for row number "<<(i+1)<<": ";
		for(int j = 0; j<n; j++){
			cin>>A[i][j];
		}
		cout<<endl;
	}
	cout<<"A=\n";
	for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            cout<<A[i][j]<<'\t';
        }
        cout<<endl;
    }
    
	double* x; x = new double [n];
    cout<<"Enter the initial value of x\n";
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    
    double* b; b = new double[n];
    cout<<"Enter the vector b: ";
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    cout<<endl;
    cout<<"b=\n";
    for(int i=0; i<n; i++){
        cout<<b[i]<<endl;
    }
    cout<<'\n';
    
    double* xold; xold = new double[n];
    double* xoold; xoold = new double[n];
    double* sumAx; sumAx = new double[n];
    double* sumAxold; sumAxold = new double[n];
    double* sumAxoold; sumAxoold = new double[n];        
    double* grad; grad = new double[n];
    double* gradold; gradold = new double[n];
    double* gradoold; gradoold = new double[n];
    double* difx; difx = new double[n];
    double* difgrad; difgrad = new double[n];   
    
    int itr = 0;   
    double stp;
    
    cout<<"Enter the initial step parameter\n";
    cin>>stp;

    double tol = 1e-013;
        
    for(int i=0;i<n;i++)
    {
        sumAx[i] = 0;
        grad[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        xold[i] = x[i];
    }
        
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sumAx[i] += A[i][j]*x[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            grad[i] +=A[j][i]*(sumAx[j] - b[j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        x[i] = x[i] - stp*grad[i];
    }
    for(int i=0;i<n;i++)
    {
        sumAx[i] = 0;
    }
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sumAx[i] += A[i][j]*x[j];
        }
    }
    double res = calRes(sumAx,b,n);
    itr = itr + 1;
    
    ofstream out;
    out.open("resid.dat");
    if(res<=tol){
        cout<<"itr: "<<itr<<endl;
        for(int i=0; i<n; i++){
            cout<<"x_"<<(i+1)<<" = "<< x[i] <<endl;
        }
        cout<<"resid: "<<res<<endl;
        out<<itr<<'\t'<<res<<endl;
    }
    else{
        while(res>tol){
            itr++;
            for(int i=0; i<n; i++)
            {
                xoold[i] = xold[i];
            }
                
            for(int i=0; i<n; i++)
            {
                xold[i] = x[i];
            }
                
            for(int i=0; i<n; i++){
                sumAx[i] = 0;
                sumAxold[i] = 0;
                sumAxoold[i] = 0;
                grad[i] = 0;
                gradold[i] = 0;
                gradoold[i] = 0;
            }
                
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    sumAxold[i] += A[i][j]*xold[j];
                    sumAxoold[i] += A[i][j]*xoold[j];                    
                }
            }
                
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    gradold[i] += A[j][i]*(sumAxold[j] - b[j]);
                    gradoold[i] += A[j][i]*(sumAxoold[j] - b[j]);
                }
            }
                
            for(int i=0; i<n; i++)
            {
                difgrad[i] = gradold[i] - gradoold[i];
                difx[i] = xold[i] - xoold[i];
            }
            if(Norm(difgrad,n)<=1e-011)
                stp = 1;
            else
                stp = innerProd(difx, difgrad,n)
                * pow(Norm(difgrad,n),-2);
                
            for(int i=0; i<n; i++)
            {
                x[i] = xold[i] - stp*gradold[i];
            }
                
            for(int i=0;i<n;i++)
            {
                sumAx[i] = 0;
            }
            for(int i=0; i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    sumAx[i] += A[i][j]*x[j];
                }
            }
                
            res = calRes(sumAx,b,n);
                
            if(itr%10==0)
            {
                cout<<"itr: "<<itr<<", resid: "<<res<<endl;
                out<<itr<<'\t'<<res<<endl;
            }
        }
    }
    if(itr%10!=0)
    {
        cout<<"itr: "<<itr<<", resid: "<<res<<endl;
        cout<<"x="<<endl;
        for(int i=0; i<n; i++){
            cout<<x[i]<<endl;
        }
        out<<itr<<'\t'<<res<<endl;
    }
    out.close();
    
    return 0;
}
