#include <iostream>
#define MAX 30
using namespace std;

int n, cnt = 0;
int x[MAX], c[MAX][MAX];
bool mark[MAX], flag = false;
int res = INT_MAX, sum = 0, c_min = INT_MAX;

void input(){
    freopen("TAXI.inp", "r", stdin);
    cin >> n;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++){
            cin >> c[i][j];
            if(c[i][j] != 0) c_min = min(c[i][j] , c_min);
        }
    }
}

bool check(int v, int k){
    //if (c[ x[k - 1] ][ v ] == 0) return false;
    if (v > n) return flag && !mark[v] && mark[v - n];
    return !mark[v] && !flag;
}

void solution(){
    //int sum = 0;
    //for (int i = 1; i <= 2*n; i++) sum += c[ x[i-1] ][ x[i] ];
    //sum += c[ x[2*n]][0];
    res = min(res, sum + c[ x[2*n]][0]);
    for (int i = 1; i <= 2*n; i++) cout << x[i] << ' '; cout << "sum = " << sum << '\n';
    //exit(0);
}

void TRY(int k){
    //if (sum > res) return;
    for (int v = 1; v <= 2 * n; v++){
        if (check(v, k)){
            x[k] = v;
            sum += c[ x[k-1] ][ x[k] ];
            mark[v] = true;
            if (v <= n) flag = true; else flag = false;
            if (k == 2 * n) solution();
            else {
                if (sum + c_min * (n - k) < res) TRY(k + 1);
            }
            sum -= c[ x[k-1] ][ x[k] ];
            if (v <= n) flag = false; else flag = true;
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

