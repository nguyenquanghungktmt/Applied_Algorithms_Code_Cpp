#include <iostream>
using namespace std;

int cnt = 0;
int n, k;
int mang[10001];

void solution(){
    cnt++;
    if (cnt == k) {
        for (int i = 0; i < n; i++) cout << mang[i] << ' '; cout << '\n';
        exit(0) ;
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) mang[i] = i + 1;
    solution();

    for(int i = n - 1; i > 0; i--)
    {
        // neu gap mang[i] > mang[i - 1]
        if(mang[i] > mang[i - 1])
        {
            int j;

            // tim trong bo cuoi giam dan phan tu vua du lon hon mang[i - 1] sau do swap.
            for(j = n - 1; j >= i; j--)
            {
                if(mang[j] > mang[i - 1])
                {
                    int temp = mang[j];
                    mang[j] = mang[i - 1];
                    mang[i - 1] = temp;
                    break;
                }
            }

            // dao nguoc bo cuoi
            for(j = n - 1; j > ((n - 1 + i) / 2); j--)
            {
                int temp = mang[i + n - 1 - j];
                mang[i + n - 1 - j] = mang[j];
                mang[j] = temp;
            }

            // in ra bo hoan vi moi
            solution();

            // i = n de khi thoat vong lap hien tai i-- thanh i = n - 1; va vong lap chay lai tu dau.
            i = n;
        }
    }
    if (cnt < k) cout << -1;
}
