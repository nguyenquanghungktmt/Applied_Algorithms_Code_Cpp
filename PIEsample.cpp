#include <stdio.h>
#include <math.h>

const double pai = acos(-1);

int main()
{
	int n, i, k;
	double min, max, mid;
	double len[10001];
	int cnt, cas;

	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d",&n,&k);
		k++;
		for(i = 0; i < n; i++)
		{
			scanf("%lf",&len[i]);
			len[i] *= len[i];
		}
		min = 0.0; max = 100000000.0;

		while(min + 1e-6< max)
		{
			mid = (max+min)/2;
			cnt = 0;
			for(i = 0; i < n; i++)
			{
				cnt += (int)floor(len[i]/mid);
			}
			if(cnt < k)
				max = mid;
			else
				min = mid;
		}
		min *= pai;
		printf("%.6lf\n",min);
	}
	return 0;
}

