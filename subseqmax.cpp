#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;

void input(){
    freopen("subseqmax.inp", "r", stdin);
    cin >> n;
    a.resize(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solve(){
    vector<int> s(n, 0); //s[i] : tong doan con max co phan tu ket thuc tai a[i]
    s[0] = a[0];
    int res = a[0];
    for (int i = 1; i < n; i++){
        s[i] = max(s[i - 1] + a[i], a[i]);
        res = max(res, s[i]);
    }
    cout << res << '\n';
}

int main(){
    input();
    solve();
}