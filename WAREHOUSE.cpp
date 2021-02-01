#include <iostream>
#define MAX 1001
using namespace std;

int N, T, D;
int a[MAX], t[MAX], value[MAX], time[MAX];
int ans = -1;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("WAREHOUSE.inp", "r", stdin);
    cin >> N >> T >> D;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> t[i];

    value[1] = a[1];
    time[1] = t[1];
    for (int i = 2; i <= N; i++){
        value[i] = a[i];
        time[i] = t[i];
        if (t[i] > T){
            value[i] = 0;
            continue;
        }
        int value_max = -1, j_max = -1;
        for (int j = i - 1; j >= i - D && j > 0; j--){
            if (time[j] + t[i] <= T && value[j] > value_max){
                j_max = j;
                value_max = value[j];
            }
        }
        if (j_max != -1) {
            value[i] += value_max;
            time[i] += t[j_max];
        }
        ans = max(ans, value[i]);
    }
    //for (int i = 1; i <= N; ++i) cout << value[i] << ' '; cout << endl;
    //for (int i = 1; i <= N; ++i) cout << time[i] << ' '; cout << endl;
    cout << ans;
}
