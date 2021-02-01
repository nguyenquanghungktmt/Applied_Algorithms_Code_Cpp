#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 1;
int T, n;
int a[MAX], s[MAX];

int main(){
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int i = 1; i <= n; i++) s[i] = 1;
        s[1] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                if (a[i] + 1 == a[j]) s[j] = max(s[j], s[i] + 1);
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) res = max (res, s[i]);
        cout << res << '\n';
    }
}
