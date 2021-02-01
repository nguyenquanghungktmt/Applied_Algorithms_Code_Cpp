#include <iostream>
using namespace std;

int N;
int x[10];
bool mark[10];
int cnt;

void solution(){
    int sum = x[0] * 100 + x[1] * 10 + x[2] - x[3] * 100 - 62
        + x[4] * 1000 + x[5] * 100 + x[6] * 10 + x[2];
    if (sum == N){
        cnt ++;
        cout << x[0] << x[1] << x[2] << '-' << x[3] << "62+" << x[4] << x[5] << x[6]<<x[2]<< '=' << N;
        cout << '\n';
    }
}

void TRY(int k){
    for (int v = 1; v <= 9; v++)
        if (!mark[v]) {
        x[k] = v;
        mark[v] = true;
        if (k == 6) solution();
        else TRY(k + 1);
        mark[v] = false;
    }
}

int main(){
    cin >> N;
    cnt = 0;
    TRY(0);
    cout << cnt << '\n';
}

