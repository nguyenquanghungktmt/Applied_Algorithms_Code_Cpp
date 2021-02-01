#include <iostream>
#include <math.h>

using namespace std;

const int MAX = 1e6 + 1;
int n, m;
int a[MAX];
int M[MAX][30];

void prepare(){
    for (int i = 0; i < n; i++) M[i][0] = a[i];

    for (int j = 1; (1 << j) <= n; j++){
        for (int i = 0; i < n; i++){
            if (i + (1 << j - 1) < n){
               if (M[i][j - 1] < M[i + (1 << j - 1)][j - 1])
                    M[i][j] = M[i][j - 1];
                else M[i][j] = M[i + (1 << j - 1)][j - 1];
            }

        }
    }
    /*
    for (int j = 0; (1 << j) <= n; j++){
        for (int i = 0; i < n; i++) cout << M[i][j] << ' '; cout << '\n';
    }
    */
}

int RMQ(int l, int r){
    int k = log2( r - l + 1);
    //cout << M[l][k] << ' ' << M[r - (1 << k)][k] << '\n';
    return min(M[l][k], M[r - (1 << k) + 1][k]);
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie();
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    prepare();

    int ans = 0;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        //cout << RMQ(l, r) << '\n';
        ans += RMQ(l, r);
    }
    printf("%d", ans);
}
