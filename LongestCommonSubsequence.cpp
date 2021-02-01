#include <iostream>
#define MAX 10001
using namespace std;

int n, m;
int X[MAX], Y[MAX];
int result[MAX][MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> X[i];
    for (int j = 1; j <= m; j++) cin >> Y[j];
}

void solve(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (X[i] == Y[j]){
                result[i][j] = result[i - 1][j - 1] + 1;
            }
            else result[i][j] = max(result[i - 1][j], result[i][j - 1]);
        }
    }

}

int main(){
    input();
    solve();
    cout << result[n][m];
}
