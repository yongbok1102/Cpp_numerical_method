double avg(double x[], int N)
{
    double sum=0;
    for(int i=0;i<N;i++)
    {
        sum+=x[i];
    }
    
    return sum/N;
}
