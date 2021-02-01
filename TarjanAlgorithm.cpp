#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int N, M;
vector< vector<int> > adj;
bool visited[MAX], mark[MAX];
int num[MAX], low[MAX], p[MAX], nc[MAX];
int cnt = 0;

void input(){
    freopen("tarjan.inp", "r", stdin);
    cin >> N >> M;
    adj.resize(N + 1);

    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    /*
    for (int u = 1; u <= N; u++){
        cout << "node " << u << ": ";
        for (int v : adj[u]) cout << v << ' ';
        cout << '\n';
    }
    */
}

void initialize(){
    for (int u = 1; u <= N; u++) visited[u] = false;
    for (int u = 1; u <= N; u++) num[u] = -1;
}

void DFS(int v){
    visited[v] = true;
    num[v] = ++cnt;
    low[v] = N + 1;
    mark[v] = false;
    for (int u : adj[v]){
        if (!visited[u]){
            p[u] = v;
            nc[v]++;
            visited[v] = true;
            DFS(u);
            //if (low[u] > num[v]) cout << "bridge (" << v << "," << u << ")\n";
            if (low[u] >= num[v]) mark[v] = true;
            low[v] = min(low[v], low[u]);
        }
        else {
            if (p[v] != u) low[v] = min(low[v], num[u]);
        }
    }
}

void solve(){
    for (int u = 1; u <= N; u++){
        if (!visited[u]) {
            DFS(u);
            if (nc[u] < 2) mark[u] = false;
        }
    }
    //for (int u = 1; u <= N; u++) cout << num[u] << ' '; cout << '\n';
    //for (int u = 1; u <= N; u++) cout << nc[u] << ' '; cout << '\n';
    int ans1 = 0, ans2 = 0;

    for (int u = 1; u <= N; u++)
        if (mark[u]){
            //cout << "khop: " << u << "\n";
            ans1++;
        }
    for (int u = 1; u <= N; u++)
        if (num[u] <= low[u] && p[u] != 0){
            ans2++;
            //cout << "bridge (" << p[u] << "," << u << ")\n";
        }
    cout << ans1 << ' ' << ans2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    input();
    initialize();
    solve();
}
