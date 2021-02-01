#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 1;
int N;
int T[MAX];
int ans = -1;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> T[i];;
    sort(T, T + N, greater<int>() );
    for (int i = 0; i < N; i++) {
        ans = max(T[i] + i, ans);
    }
    cout << ans + 2;
}
