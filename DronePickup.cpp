#include <iostream>
#define MAX 3001
using namespace std;

int N, K;
int goods[MAX], energy[MAX], S[MAX], step[MAX];

void input(){
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> goods[i];
    for (int i = 1; i <= N; i++) cin >> energy[i];
}

void solve(){
    for (int i = 1; i <= N; i++) S[i] = 0;
    for (int i = 1; i <= N; i++) step[i] = INT_MAX;

    S[1] = goods[1];
    step[1] = 1;
    for (int i = 1; i <= N; i++){
        for (int j = i + 1; j <= i + energy[i] && j <= N; j++){
            if (j > N) break;
            if (S[i] + goods[j] >= S[j] && step[i] <= step[j] - 1){
                S[j] = S[i] + goods[j];
                step[j] = step[i] + 1;
            }
        }
        //cout << "Step " << i << '\n';
        //for (int i = 1; i <= N; i++) cout << S[i] << ' '; cout << '\n';
    }

    //for (int i = 1; i <= N; i++) cout << S[i] << ' '; cout << '\n';
    //for (int i = 1; i <= N; i++) cout << step[i] << ' '; cout << '\n';

    if (step[N] <= K + 1) cout << S[N]; else cout << -1;
}

int main(){
    input();
    solve();
}
