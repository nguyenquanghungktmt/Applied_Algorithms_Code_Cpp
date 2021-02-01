#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int N;
long long M;
int x[MAX];
long long res = 0;

bool check(int H){
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        if (x[i] > H) sum += x[i] - H;
        if (sum >= M) return true;
    }
    return false;
}

void cut(int L, int R){
    if (L > R) return;
    int M = (L + R) / 2;
    if (check(M)){
        res = M;
        cut(M + 1, R);
    }
    else cut(L, M - 1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("EKO.inp", "r", stdin);
    cin >> N >> M;
    //int first = 0, last = -1;
    for (int i = 1; i <= N; i++) {
        cin >> x[i];
        //last = max(last, x[i]);
    }

    cut(0, 1000000000);
    cout << res;
}
