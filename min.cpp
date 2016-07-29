double min(double X[], int N)
{
	double min;
    min = X[0];
	
	for(int i=0;i<N;i++)
	{
		if(min<X[i])
			min=min;
		else
			min=X[i];
	}
	
	return min;
}