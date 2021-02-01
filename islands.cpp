#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n, m;
char a[MAX][MAX];
bool visited[MAX][MAX];
int next_r[4] = {-1, 1, 0, 0};
int next_c[4] = {0, 0, -1, 1};

void input(){
    freopen("islands.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
}

void initialize(){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            visited[i][j] = false;
}

bool check(int x, int y){
    return x >= 1 && x <= n && y >=1 && y <= m && a[x][y] == '1' && visited[x][y] == false;
}

void process(){
    int cnt = 0;
    int res = 0, current_res;
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= m; c++)
        if (a[r][c] == '1' && visited[r][c] == false){
            cnt++;
            current_res = 1;
            queue< pair<int, int> > Q;
            pair<int, int> start (r, c);
            Q.push(start);
            visited[r][c] = true;
            while (!Q.empty()){
                pair<int, int> p = Q.front();
                Q.pop();
                for (int k = 0; k < 4; k++){
                    int nr = p.first + next_r[k];
                    int nc = p.second + next_c[k];

                    if (check(nr, nc)){
                        pair<int, int> np (nr, nc);
                        Q.push(np);
                        current_res++;
                        visited[nr][nc] = true;
                    }
                }
            }
            res = max(res, current_res);
        }
    cout << cnt << '\n' << res << '\n';
}

int main(){
    input();
    initialize();
    process();
}