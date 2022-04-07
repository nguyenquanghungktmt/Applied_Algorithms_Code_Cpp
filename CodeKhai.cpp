#include <stdio.h>

int main()
{
	int n;
	float a[10000], max;
	scanf("%d", &n);
	if(n <= 1)
		printf("ERROR");
	else
	{
		for(int i = 0; i < n; i++)
			scanf("%f", &a[i]);
		max = (a[0] + a[1])/2.0;
		for(int i = 1; i < n-1; i++)
			if((a[i] + a[i+1])/2.0 > max)
				max = (a[i] + a[i+1])/2.0;
		printf("%.3lf", max);
	}
	return 0;
}
