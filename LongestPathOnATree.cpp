#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<long long, int> P2;

int N;
vector< vector<P2> > adj;
vector< long long > d;
int des = -1;
long long d_max = -1;

void input(){
    //freopen("Dijkstra.inp", "r", stdin);
    cin >> N;
    adj.resize(N + 1);
    d.resize(N + 1);
    for (int i = 1; i < N; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w});
        adj[v].push_back({ u, w});
    }

    /*
    for (int u = 1; u <= N; u++){
        cout << "Edge " << u << " : \n";
        for (pair<int, int> e : adj[u]){
            cout << u << ' ' << e.first << ' ' << "weigh= " << e.second << '\n';
        }
    }
    */
}

void init(){
    for (int u = 1; u <= N; u++) d[u] = -1;
}

void DFS(int u){
    for (P2 e : adj[u]){
        int v = e.first;
        if (d[v] == -1){
            d[v] = d[u] + e.second;
            if (d[v] > d_max){
                d_max = d[v];
                des = v;
            }
            DFS(v);
        }
    }
}

void solve(){
    for (int u = 1; u <= N; u++) d[u] = -1;
    d[1] = 0;
    DFS(1);
    //cout << des << '\n';

    for (int u = 1; u <= N; u++) d[u] = -1;
    d[des] = 0;
    DFS(des);
    cout << d[des] << '\n';

    //for (int u = 1; u <= N; u++) cout << d[u] << ' '; cout << endl;
}


int main(){
    input();
    solve();
}
