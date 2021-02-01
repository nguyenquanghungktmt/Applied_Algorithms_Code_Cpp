#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt = 0;
int x[10001];
bool mark[10001];

void print(){
    cnt++;
    if (cnt == k){
        for (int i = 1; i <= n; i++) cout << x[i] << ' ';
        exit(0);
    }
}

void TRY(int k){
    for (int v = 1; v <= n; v++){
        if (!mark[v]){
            x[k] = v;
            mark[v] = true;
            if (k == n) print();
            else TRY(k + 1);
            mark[v] = false;
        }
    }
}


int main(){
    cin >> n >> k;
    TRY(1);
    if (cnt < k) cout << -1 << endl;
}
