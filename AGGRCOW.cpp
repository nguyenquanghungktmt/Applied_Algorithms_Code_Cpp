#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int N, C, T;
int X[MAX + 1];

bool caculate(int lamda){
    int cnt = 1;
    int first = 2;
    int pre  = X[1];

    while (first <= N){
        if (X[first] - pre >= lamda){
            cnt++;
            pre = X[first];
            first++;
        }
        else first++;

        if (cnt >= C) return true;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("AGGRCOW.inp", "r", stdin);
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> N >> C;
        int d_max = -1;
        for (int i = 1; i <= N; i++){
            cin >> X[i];
            d_max = max(d_max, X[i]);
        }
        sort(X + 1, X + N + 1);

        int res = 0;
        int d_min = 1;
        while (d_min <= d_max){
            int d = (d_min + d_max) / 2;
            if (caculate(d)){
                res = max(res, d);
                d_min = d + 1;
            }
            else d_max = d - 1;
        }

        cout << res << '\n';
    }
}
