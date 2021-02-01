#include <iostream>
#define MAX 30
using namespace std;

int n, K, cnt = 0;
int x[MAX], c[MAX][MAX];
bool mark[MAX];
int res = INT_MAX, sum = 0, c_min = INT_MAX;

void input(){
    freopen("CBUS.inp", "r", stdin);
    cin >> n >> K;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++){
            cin >> c[i][j];
            if(c[i][j] != 0) c_min = min(c[i][j] , c_min);
        }
    }
}

bool check(int v, int k){
    if (c[ x[k - 1] ][ v ] == 0) return false;
    if (v > n) return !mark[v] && mark[v - n];
    if (cnt >= K) return false;
    return !mark[v];
}

void solution(){
    //int sum = 0;
    //for (int i = 1; i <= 2*n; i++) sum += c[ x[i-1] ][ x[i] ];
    //sum += c[ x[2*n]][0];
    res = min(res, sum + c[ x[2*n]][0]);
    //for (int i = 1; i <= 2*n; i++) cout << x[i] << ' '; cout << "sum = " << sum << '\n';
    //exit(0);
}

void TRY(int k){
    //if (sum > res) return;
    for (int v = 1; v <= 2 * n; v++){
        if (check(v, k)){
            x[k] = v;
            sum += c[ x[k-1] ][ x[k] ];
            mark[v] = true;
            if (v <= n) cnt++; else cnt--;
            if (k == 2 * n) res = min(res, sum + c[ x[2*n]][0]);
            else {
                if (sum + c_min * (2 * n - k + 1) < res) TRY(k + 1);
            }
            sum -= c[ x[k-1] ][ x[k] ];
            if (v <= n) cnt--; else cnt++;
            mark[v] = false;
        }
    }
}

int main(){
    input();
    x[0] = 0;
    TRY(1);
    cout << res << '\n';
}
