#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector< vector<int> >adj;
vector<int> d;

void input(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("BIPARTIE_GRAPH.inp", "r", stdin);
    cin >> N >> M;
    adj.resize(N + 1);
    d.resize(N + 1);

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

void BFS(int u){
    queue<int> Q;
    Q.push(u);
    d[u] = 0;
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        for(int x : adj[v]){
            // xet dinh x ke voi v
            if(d[x] > -1){
                if(d[v] % 2 == d[x] % 2) {
                    cout << 0;
                    exit(0);
                } // cung bac voi dinh cha thi ko thoa man, exit luon
            }
            else{
                d[x] = d[v] + 1;
                Q.push(x);
            }
        }
    }
}

void solve(){
    for(int v= 1; v <= N; v++) d[v] = -1;
    for(int v= 1; v <= N; v++){
        if(d[v]== -1) BFS(v);
    }
    cout << 1;
}

int main(){
    input();
    solve();
}
