#include <iostream>
#define MAX 202
using namespace std;

int n;
int c[MAX][MAX];
int x[MAX];
bool mark[MAX] = {false};
int res = INT_MAX;

void input(){
    freopen("ASSIGN.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> c[i][j];
}

void solution(){
    int tmp = -1;
    for (int i = 1; i <= n; i++) tmp = max(tmp, c[i][ x[i] ]);
    res = min(tmp, res);
}

void TRY(int person){
    for (int job = 1; job <= n; job++){
        if (!mark[job]){
            x[person] = job;
            mark[job] = true;
            if (person == n) solution();
            else TRY(person + 1);
            mark[job] = false;
        }
    }
}

int main(){
    input();
    TRY(1);
    cout << res;
}

