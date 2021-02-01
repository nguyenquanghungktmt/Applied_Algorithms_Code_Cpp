#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
int n;
int a[MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    a[n] = -INT_MAX;

    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] <= a[i - 1]) cnt++;
    }
    cout << cnt ;
}

