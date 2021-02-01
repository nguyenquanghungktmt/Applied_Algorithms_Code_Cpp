#include <iostream>
#include <vector>
using namespace std;

int n, L1, L2;
vector<int> a, s;

void input(){
    cin >> n >> L1 >> L2;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void process(){
    s.resize(n + 1);
    for (int i = 1; i <= n; i++) s[i] = a[i];
    for (int i = L1 + 1; i <= n; i++){
        for (int j = max(i - L2, 1); j <= i - L1; j++)
            s[i] = max(s[i], s[j] + a[i]);
    }
}

int main(){
    input();
    process();
    int res = -1;
    for (int i = 1; i <= n; i++) res = max(res, s[i]);
    cout << res << endl;
}
