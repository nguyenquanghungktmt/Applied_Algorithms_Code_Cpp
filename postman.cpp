#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, k;
long long am[1002], duong[1002];
int id_am = 0, id_duong = 0;
map< long long, long long> m;
long long visited[10002];
long long res = 0;

void input(){
    freopen("postman.inp", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        if (a < 0) am[id_am++] = a;
        else duong[id_duong++] = a;
        m[a] = b;
    }
    sort(am, am + id_am);
    sort(duong, duong + id_duong, greater<int>());
    //for (int i = 0; i < n; i++) cout << x[i] << ' ' << m[x[i]] << '\n';
}

void solve(int n, long long *x){
    for (int i = 0; i < n; i++) visited[i] = 0;
    //for (int i = 0; i < n; i++) cout << x[i] << ' ' << m[x[i]] << '\n';
    long long carry = k;
    for (int i = 0; i < n; i++){
        long long mi = m[x[i]];

        if (carry < mi) {
            long long xx = (mi - carry) / k;
            if ((mi - carry) % k != 0) xx++;
            //int xx = 0;
            //while (carry + k * xx < mi) xx++;
            /*
            carry + k * xx >= mi;
            k * xx >= mi - carry;
            5 * 3 >= 15
            3 -> 18
            + 5 * 3
            carry = 1;
            mi = 6;
            k = 5;
            (6 - 1 ) / 5 = 0 + 1
            */
            //cout << xx << '\n';
            visited[i] = xx;
            carry = (carry +  xx * k) % mi;
        }
        else {
            visited[i] = 0;
            carry = carry - mi;
        }
        //cout << i << ' ' << visited[i] << ' ' << carry << '\n';
    }

    visited[0]++;
    for (int i = 0; i < n; i++){
        res += abs(x[i]) * visited[i] * 2;
    }
    //cout << res << endl;
}

int main(){
    input();
    solve(id_am, am);
    solve(id_duong, duong);
    cout << res ;
}
