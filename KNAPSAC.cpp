#include <iostream>
#define MAX 31
using namespace std;

int n, b;
int F[31][1000001], a[MAX], c[MAX];//F[i][j]: tong gia tri lon nhat khi chon cac goi tu 1 den i va tong trong luong khong qua j

void input(){
    freopen("KNAPSAC.inp", "r", stdin);
    cin >> n >> b;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
}

void solve(){
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= b; j++){
            F[i][j] = F[i - 1][j];
            if (j >= a[i] && F[i][j] < F[i - 1][j - a[i]] + c[i]){
                F[i][j] = F[i - 1][j - a[i]] + c[i];
            }
        }
    }

    cout << F[n][b];
}

int main(){
    input();
    solve();
}


