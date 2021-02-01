#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M;
vector< vector<int> >adj;
vector<bool> visited;
vector<int> cs;
int ncc;

void input(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("graph.inp", "r", stdin);
    cin >> N >> M;
    adj.resize(N + 1);
    visited.resize(N + 1);
    cs.resize(N + 1);

    for (int i = 0; i < M; i++){
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

void initializer(){
    ncc = 0;
    for (int i = 1; i <= N; i++) visited[i] = false;
}

void BFS(int u){
    visited[u] = true;
    stack<int> S;
    S.push(u);
    while (!S.empty()){
        u = S.top();
        S.pop();
        cs[u] = ncc + 1;
        for (int v : adj[u]){
            if (!visited[v]){
                S.push(v);
                visited[v] = true;
            }
        }
    }
}

void solve(){
    for (int u = 1; u <= N; u++){
        if (!visited[u]){
            BFS(u);
            ncc++;
        }
    }
    /*
    for (int cc = 1; cc <= ncc; cc++){
        cout << "Connected Component " << cc << ":\n";
        for (int u = 1; u <= N; u++)
            if (cs[u] == cc) cout << u << ' ';
        cout << '\n';
    }
    */
}

int main(){
    input();
    solve();
    cout << ncc;
}
