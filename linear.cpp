#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//Err (?(Y-A*X-B)^2)
double calErr(double x[], double y[], double A, double B, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += pow((y[i] - A*x[i]-B), 2);
	}
	return sum;
}

double minErr(double Err[], int n)
{
	double min = Err[0];
	for (int i = 0; i < n; i++)
	{
		if (min > Err[i])
			min = Err[i];
	}
	return min;
}

int main()
{
	//arbitary point in the region A
	double x1, y1, x2, y2;

	//given data
	double x[5] = { 1,2,3,4,5 };
	double y[5] = { 1.01, 1.995, 3.01, 4.1, 4.95 };

	//iteration number
	int itr = 10000;
	double A, B;

	double* setA;
	setA = new double [itr];
	double* setB;
	setB = new double[itr];
	double* setErr;
	setErr = new double[itr];
	int N;
	ofstream out;
	out.open("data.txt");
    
    int trl = 1000;
    double* A1; A1 = new double[trl];
    double* B1; B1 = new double[trl];
    double* Err1; Err1 = new double[trl];
	for (int i = 0; i < 5; i++)
	{
		out << x[i] << '\t' << y[i] << endl;
	}
	out.close();

    for(int i=0;i<trl;i++)
    {
        N=0;
        srand((unsigned int)time(NULL));
		while (N < itr)
		{
			x1 = (double)rand()*(5 - 1) / RAND_MAX + 1.0;
			y1 = (double)rand()*(4.98 - 1.01) / RAND_MAX + 1.01;
			x2 = (double)rand()*(5 - 1) / RAND_MAX + 1.0;
			y2 = (double)rand()*(4.98 - 1.01) / RAND_MAX + 1.01;

			if (x1 != x2)
			{
				setB[N] = y1-x1*(y2-y1)/(x2-x1);
                B = setB[N];
				setA[N] = (y2-y1)/(x2-x1);
				A = setA[N];
				setErr[N] = calErr(x, y, A, B, 5);
				N++;
			}
		}

		double min = minErr(setErr, itr);
		for (int j = 0; j < itr; j++)
		{
			if (min == setErr[j])
			{
				A1[i]=setA[j];
                B1[i]=setB[j];
                Err1[i]=setErr[j];
				break;
			}
		}
		if((i+1)%100==0)
            cout<<"trial: "<<i+1<<endl;
    }
    out.open("curve.txt");
    double min = minErr(Err1,trl);
    for(int i=0;i<trl;i++)
    {
        if(min==Err1[i])
        {
            cout<<"y="<<A1[i]<<"*x";
            out<<"y="<<A1[i]<<"*x";            
            if(B1[i]>=0){
                cout<<'+'<<B1[i];
                out<<'+'<<B1[i];   
            }
            else{
                cout<<B1[i];
                out<<B1[i];
            }
                cout<<", err"<<Err1[i]<<endl;
                out<<", err"<<Err1[i]<<endl;   
            break;
        }
    }
    out.close();
    
	delete[] setA;
	delete[] setB;
	delete[] setErr;
    delete[] A1;
    delete[] B1;
    delete[] Err1;
	return 0;
}
