#include <iostream>

using namespace std;

const long long P = 1e9 + 7;
int N, M;
int a[101];
long long F[101][501] = {0};

void solve(){
    F[0][0] = 1;
    for (int i = 1; i <= N; i++){
        for (int j = a[i]; j <= M; j++){
            for (int k = j - a[i]; k >= 0; k -= a[i])
                F[i][j] += F[i - 1][k] % P;
        }
    }
    cout << F[N][M] % P;
}

int main(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> a[i];
    solve();
}

/*
F[i,j] số cách chia i đơn vị thành j phần
F[i, j] = tổng F[i - k, j - 1] với k chia hết cho a[j]

hoặc F[i, j] = F[i - a[j], j - 1]
*/
