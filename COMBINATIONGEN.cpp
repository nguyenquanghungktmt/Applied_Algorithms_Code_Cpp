#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int n, m;
int a[MAX];

void input(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
}

void solve(){
    for (int i = m; i > 0; i--){
        if (a[i] != n + i - m){
            a[i]++;
            for (int j = i + 1; j <= m; j++) a[j] = a[i] + j - i;
            for (int j = 1; j <= m; j++) cout << a[j] << ' ';
            exit(0);
        }
    }
    cout << -1 << '\n';
}


int main(){
    input();
    solve();
}

