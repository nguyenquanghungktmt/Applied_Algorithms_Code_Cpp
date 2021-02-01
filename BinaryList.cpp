#include <bits/stdc++.h>
using namespace std;

int n, k, i;
int cnt = 0;
vector<int> x;

void print(){
    cnt++;
    if (cnt == k){
        for (int i = 0; i < n; i++) cout << x[i] << ' ';
        exit(0);
    }
}

void solve(int index, int cnt0, int i){

    if (index == n) print();
    else if (cnt0 == i - 1){
        x[index] = 1;
        solve(index + 1, 0, i);
        }
        else {
            x[index] = 0;
            solve(index + 1, cnt0 + 1, i);
            x[index] = 1;
            solve(index + 1, 0, i);
        }
}


int main(){
    cin >> n >> k >> i;
    x.resize(n + 1);
    solve(0, 0, i);
    if (cnt < k) cout << -1 << endl;
}
