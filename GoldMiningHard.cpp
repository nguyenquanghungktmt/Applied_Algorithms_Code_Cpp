#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

int n, L1, L2;
int a[MAX], S[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = -1;

    deque<int> d;
    for (int i =1 ; i <= n; i++){
        while (!d.empty() && d.front() < i - L2) d.pop_front();
        int j = i - L1;
        if (j >= 1){
            while (!d.empty() && S[j] > S[d.back()]) d.pop_back();
            d.push_back(j);
        }

        if (!d.empty()) S[i] = S[d.front()] + a[i]; else S[i] = a[i];
        ans = max(S[i], ans);

    }
    cout << ans;
}
