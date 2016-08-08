#include <iostream>
#include <fstream>

using namespace std;

/*-----------------------------------*/
/*This code is designed to solve     */
/*Laplace equation using FDM         */
/*Boundary conditions are given below*/
/*u(0,y)=u(1,y)=u(x,1)=0, u(x,0)=1   */

int main()
{
  double x[21]; double y[21];
  double u[21][21];
  
  double dx=1./20;
  double dy=1./20;
  
  //cartesian coordinates for solving PDE
  for(int i=0;i<=20;i++)
  {
    x[i]=i*dx;
    y[i]=i*dy;
  }
  
  //initialization of solutions
  for(int i=0;i<=20;i++)
  {
    for(int j=0;j<=20;j++)
    {
      u[i][j]=0;
    }
  }
  
  for(int itr=1; itr<=4000; itr++)
  {
    for(int i=1;i<=10;i++){cout<<'-';}cout<<'\n';
    for(int i=0;i<=20;i++)
    {
      for(int j=0;j<=20;j++)
      {
        //Boundary condition
        if(i==0){u[i][j]=1;}
        else if(i==20){u[i][j]=0;}
        else if(j==0 && i>=1 && i<=19){u[i][j]=0;}
        else if(j==20 && i>=1 && i<=19){u[i][j]=0;}
        
        //Gauss-Seidel Iteration
		    else { u[i][j] = (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1]) / 4.; }
        cout<<x[i]<<'\t'<<y[j]<<'\t'<<u[i][j]<<endl;
        }
      }
    }
    
    for(int i=1;i<=10;i++){cout<<'-';}cout<<'\n';
    
    
   ofstream out;
   out.open("laplace.txt");
   for(int i=0;i<=20;i++)
   {
      for(int j=0;j<=20;j++)
      {
         cout<<x[i]<<'\t'<<y[j]<<'\t'<<u[i][j]<<endl;
         out<<x[i]<<'\t'<<y[j]<<'\t'<<u[i][j]<<endl;   
      }
   }
   out.close();
   return 0;
}
