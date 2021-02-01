#include <bits/stdc++.h>
#define MAX 1000

using namespace std;


int main(){
    int T, n, m;
    int a[MAX], b[MAX], marka[MAX], markb[MAX];
    //freopen("CAP.inp", "r", stdin);
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; i++) cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        //for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
        //for (int i = 1; i <= m; i++) cout << b[i] << ' '; cout << endl;

        for (int i = 1; i <= n; i++) marka[i] = 0;
        for (int i = 1; i <= m; i++) markb[i] = 0;

        int cnt = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (a[i] == b[j] && marka[i] == 0 && markb[j] == 0) {
                    cnt++;
                    //cout << a[i] << endl;
                    marka[i] = 1;
                    markb[j] = 1;
                }

            }

        }
        cout << cnt << '\n';
    }
}
