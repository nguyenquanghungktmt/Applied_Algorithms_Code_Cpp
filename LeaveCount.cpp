#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector< vector<int> >adj;
vector<bool> visited;
vector<int> d;

void input(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("LeaveCount.inp", "r", stdin);
    cin >> N;
    adj.resize(N + 1);
    visited.resize(N + 1);
    d.resize(N + 1);

    for (int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*
    for (int u = 1; u <= N; u++){
        cout << "Node " << u << ": \n";
        for (int v : adj[u]) cout << v << ' '; cout << '\n';
    }
    */
}

void BFS(int u){
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int x : adj[v]){
            // xet dinh x ke voi v
            if(!visited[x]){
                visited[x] = true;
                d[v]++;
                Q.push(x);
            }
        }
    }
}

void solve(){
    for(int v = 1; v <= N; v++) {visited[v] = false; d[v] = 0;}
    BFS(1);
    int ans = 0;
    for(int v = 1; v <= N; v++) if (d[v] == 0) ans++;
    cout << ans;
}

int main(){
    input();
    solve();
}
