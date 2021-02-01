#include <bits/stdc++.h>
#define MAX 200
#define LIMIT 25
using namespace std;

int n, T;
string p;
string F[MAX];
unsigned long long cnt[MAX];
bool check[MAX] = {false};

unsigned long long count_match(string p, string s){
    if (p.length() > s.length()) return 0;
    unsigned long long cnt = 0;
    for (int i = 0; i < s.length() - p.length() + 1; i++){
        if (s[i] == p[0]){
            bool check = true;
            for (int j = 0; j < p.length(); j++) {
                if (s[i + j] != p[j]) {
                    check = false;
                    break;
                }
            }
            if (check) cnt++;
        }
    }
    return cnt;
}


void initialize(){

    for (int i = 0; i <= LIMIT; i++) {
        cnt[i] = count_match(p, F[i]);
    }
    for (int i = 0; i <= n; i++) check[i] = false;
}


unsigned long long H(int left, int right){
    if (left > LIMIT || right > LIMIT) return H(left - 2, right - 1);

    if (F[left].length() >= p.length() && F[right].length() >= p.length()) return H(left - 2, right - 1);
    //string tmp = F[left] + F[right];
    //cout << left << ' ' << right << '\n';
    return count_match(p, F[left] + F[right]) - cnt[left] - cnt[right];
}

unsigned long long solve(int n){
    if (n <= LIMIT || check[n] == true) return cnt[n];
    else {
        check[n] = true;
        cnt[n] = solve(n - 1) + solve(n - 2) + H(n - 1, n - 2);
        return cnt[n];
    }
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    F[0] = "0"; F[1] = "1";
    for (int i = 2; i <= LIMIT; i++) F[i] = F[i - 1] + F[i - 2];
    //for (int i = 0; i <= LIMIT; i++)  cout << i << ' ' << F[i].length() << '\n';
    int t = 0;

    while (cin >> n >> p){
        //cin >> n;
        //cin >> p;
        initialize();
        cout << "Case " << ++t << ": " << solve(n) << '\n';
    }

}

//G(n) = G(n - 1) + G(n - 2) + H(n - 1, n - 2)
//H(m,n) = H(m - 2, n - 1)
