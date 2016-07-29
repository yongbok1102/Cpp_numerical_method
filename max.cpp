double max(double X[], int N)
{
	double max;
    max = X[0];
	
	for(int i=0;i<N;i++)
	{
		if(max>X[i])
			max=max;
		else
			max=X[i];
	}
	
	return max;
}
