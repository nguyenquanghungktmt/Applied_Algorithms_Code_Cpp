#include <iostream>
#define MAX 200001
using namespace std;
int n, b;
int a[MAX];

void input(){
    freopen("signal.inp", "r", stdin);
    cin >> n >> b;
    for (int i = 1; i <=n; i++) cin >> a[i];
}

void process(){
    int left[MAX], right[MAX];
    int tmp = a[1];
    for (int i = 1; i <= n; i++){
        tmp = max(tmp, a[i]);
        left[i] = tmp;
    }

    tmp = a[n];
    for (int i = n; i >= 1; i--){
        tmp = max(tmp, a[i]);
        right[i] = tmp;
    }

    int res = -1;
    for (int i = 2; i < n; i++){
        if (left[i - 1] - a[i] >= b && right[i + 1] - a[i] >= b) res = i;
    }

    if (res == -1) cout << -1 ;
    else{
        int ans = - INT_MAX;
        for (int i = 2; i < n; i++) ans = max(ans, left[i - 1] + right[i + 1] - 2 * a[i]);
        cout << ans;
    }
}

int main(){
    input();
    process();
}
