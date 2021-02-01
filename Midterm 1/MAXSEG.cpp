#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
int n, k;
int a[MAX];
long long s[MAX];
int cs[MAX];

void process(){
    s[1] = a[1];
    cs[1] = 1;
    int res = a[0];
    for (int i = 1; i <= n; i++){
        //s[i] = max(s[i - 1] + a[i], a[i]);
        if (s[i - 1] + a[i] > a[i]){
            s[i] = s[i - 1] + a[i];
            cs[i] = cs[i - 1] + 1;
        }
        else {
            s[i] = a[i];
            cs[i] = 1;
        }
        //res = max(res, s[i]);
    }

    //for (int i = 1; i <= n; i++) cout << s[i] << ' '; cout << '\n';
    //for (int i = 1; i <= n; i++) cout << cs[i] << ' '; cout << '\n';

    double ans = -INT_MAX;
    for (int i = 1; i <= n; i++)
    if (cs[i] >= k){
        ans = max(ans, (double)s[i] / cs[i] );
    }
    printf("%.5lf", ans);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //setprecision(4);
    //cout << fixed;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    process();
}


