#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
int n, k;
int a[MAX];
//long long sum[MAX];
double ans[MAX];

void process(){
    deque<int> d;
    double sum = 0;

    for (int i = 1; i <= n; i++){


        //if (!d.empty() && d.size() > k - 1 && (sum + a[i]) / (d.size() + 1) > ans[i - 1] )

        d.push_back(a[i]);
        sum += a[i];
        ans[i] = sum / d.size();
        if (i < k) continue;

        while(d.size() > k){
            int tmp = d.front();
            if ((sum - tmp) / (d.size() - 1) >= ans[i]){
                sum -= tmp;
                ans[i] = sum / (d.size() - 1);
                d.pop_front();
            }
            else break;
        }


        //cout << ans[i] << '\n';
    }

    double ans_max = -INT_MAX;
    for (int i = k; i <= n; i++) ans_max = max(ans_max, ans[i]);
    printf("%.5lf", ans_max);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    process();
}
