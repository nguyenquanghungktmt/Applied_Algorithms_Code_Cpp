#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
int n, K;
int a[MAX];
long long sum[MAX];
double ans = -INT_MAX;

void process(){
    for (int k = K; k <= n; k++){
        double current_ans = -INT_MAX;
        for (int i = k; i <= n; i++){
            long long sum_max = -INT_MAX;
            sum_max = max(sum_max, sum[i] - sum[i - k]);
            current_ans = max(current_ans, (double)sum_max / k);
        }
        ans = max(ans, current_ans);
    }
    printf("%.5lf", ans);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    process();
}

//Do phuc tap O(n * (n - k))
