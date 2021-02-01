#include <iostream>
#include <algorithm>
using namespace std;

int n, K, a[5001];

void solve1(){
    long long res = 0;
    for (int i = 1; i <= n - 2; i++){
        int l = i + 1;
        int r = n;
        int sum = K - a[i];
        if (sum < 0) continue;
        while (l < r){
            int tmp = a[l] + a[r];
            if (tmp == sum){
                //cout << a[i] << ' ' << a[l] << ' ' << a[r] << '\n';
                res++;
                //l++;
                if (a[l] == a[l + 1]) l++; else r--;
            }
            else if (tmp < sum) l++;
            else r--;
        }
    }
    cout << res << endl;
}

int bSearch(int L, int R, int target){
    if (L > R) return 0;
    int M = (L + R) / 2;
    if (a[M] == target){
        return 1 + bSearch(L, M - 1, target) + bSearch(M + 1, R, target);
    }
    else if (a[M] < target) return bSearch(M + 1, R, target);
    else return bSearch(L, M - 1, target);
}

void solve2(){
    unsigned long long res = 0;
    for (int i = 1; i <= n - 2; i++){
        for (int j = i + 1; j <= n - 1; j++){
            int target = K - a[i] - a[j];
            res += bSearch(j + 1, n, target);
        }
    }
    cout << res << endl;
}

int main(){
    freopen("triple.inp", "r", stdin);
    cin >> n >> K;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    //for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';

    //solve1();
    solve2();
}
