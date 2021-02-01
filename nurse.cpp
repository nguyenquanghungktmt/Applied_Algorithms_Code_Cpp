#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n, k1, k2;
int x[MAX];
int cnt = 0;

void solve(int i, int cnt0, int cnt1){

    if (i > n) cnt++;
    else if (cnt0 == 1){
        if (i > n - k1 + 1) return;
        x[i] = 1;
        solve(i+1, 0, 1);
    }
    else {
        if (cnt1 == 0){
            x[i] = 0;
            solve(i + 1, 1, 0);
            x[i] = 1;
            solve(i + 1, 0, cnt1 + 1);
        }
        else if (cnt1 < k1){
            x[i] = 1;
            solve(i + 1, 0, cnt1 + 1);
        }
        else if ( cnt1 >= k2){
                x[i] = 0;

                solve(i + 1, 1, 0);
        }
        else {
            x[i] = 0;
            solve(i + 1, 1, 0);
            x[i] = 1;
            solve(i + 1, 0, cnt1 + 1);
        }
    }
}


int main(){
    cin >> n >> k1 >> k2;
    solve(1, 0, 0);
    cout << cnt << '\n';
}
