#include <stdio.h>
#define P 1000000000

int n;
int a[1005];
long long F[1005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    F[0] = 1;

    for (int i = 1; i <= n + 1; i++)
    {
        if (a[i] == 0)
        {
            F[i] = F[i - 1] + F[i - 2];
            if (a[i - 3] == 0)
                F[i] += F[i - 3];
        }
        else if (a[i] == 1)
        {
            F[i] = F[i - 1];
        }

        F[i] %= P;
    }

    printf("%lld", F[n + 1] % P);

    return 0;
}
