#include <iostream>
#define MAX 30
using namespace std;

int n, m;
int c[MAX][MAX], x[MAX];
bool mark[MAX] = {false};
int best = INT_MAX;

void input(){
    freopen("TSP.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y, value;
        cin >> x >> y >> value;
        c[x][y] = value;
    }
}

bool check(int i, int v, int sum){
    if (mark[v]) return false;
    if (c[x[i - 1]][v] == 0) return false;
    if (sum + c[x[i - 1]][v] >= best) return false;
    return true;
}

void duyet(int i, int sum){
    if (i == n + 1){
        if (c[x[n]][1] == 0) return;
        if (sum + c[x[n]][1] < best) best = sum + c[x[n]][1];
        //cout << "-----\n";
        //for (int i = 1; i <= n; i++) cout << x[i] << ' '; cout << '\n';
        return;
    }

    for (int v = 2; v <= n; v++){
        if (check(i, v, sum)){
            x[i] = v;
            mark[v] = true;
            duyet(i + 1, sum + c[x[i - 1]][v]);
            mark[v] = false;
        }
    }
}

int main(){
    input();
    x[1] = 1;
    mark[1] = true;
    duyet(2, 0);
    cout << best << '\n';
}
