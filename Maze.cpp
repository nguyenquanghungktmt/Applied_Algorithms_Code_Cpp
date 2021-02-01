#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int n, m, r, c, a[MAX][MAX];
bool visited[MAX][MAX];
map< pair<int, int>, int > d;
map< pair<int, int>, pair<int, int> > pre;
queue< pair<int, int> > Q;
int next_r[4] = {-1, 1, 0, 0};
int next_c[4] = {0, 0, -1, 1};

void input(){
    freopen("Maze.inp", "r", stdin);
    cin >> n >> m >> r >> c;
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

void print(pair<int, int> p){
    if (p.first == r && p.second == c){
        cout << r << ' ' << c << '\n';
    }
    else {
        print(pre[p]);
        cout << p.first << ' ' << p.second << '\n';
    }

}

void process(){
    pair<int, int> start (r, c);
    Q.push(start);
    d[start] = 0;
    visited[r][c] = true;
    while (!Q.empty()){
        pair<int, int> p = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++){
            int nr = p.first + next_r[k];
            int nc = p.second + next_c[k];

            if (nr < 1 || nr > n || nc < 1 || nc > m){
                print(p);
                cout << d[p] + 1 << '\n';
                exit(0);
            }
            else if (a[nr][nc] == 0 && visited[nr][nc] == false){
                pair<int, int> np (nr, nc);
                Q.push(np);
                d[np] = d[p] + 1;
                pre[np] = p;
                visited[nr][nc] = true;
            }
        }
    }
}

int main(){
    input();
    initialize();
    process();
}