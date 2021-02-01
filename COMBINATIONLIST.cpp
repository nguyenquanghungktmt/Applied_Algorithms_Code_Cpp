#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int cnt = 0;
int x[10001];
bool mark[10001];

void print(){
    cnt++;
    if (cnt == k){
        for (int i = 1; i <= m; i++) cout << x[i] << ' ';
        exit(0);
    }
}

void TRY(int k){
    for (int v = x[k - 1] + 1; v <= n - m + k; v++){
        if (!mark[v]){
            x[k] = v;
            //mark[v] = true;
            if (k == m) print();
            else TRY(k + 1);
            //mark[v] = false;
        }
    }
}


int main(){
    cin >> n >> m >> k;
    x[0] = 0;
    TRY(1);
    if (cnt < k) cout << -1 << endl;
}
