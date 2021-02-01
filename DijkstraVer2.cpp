#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<long long, int> P2;

int N, M;
int S, T;
vector< vector<P2> > adj;
priority_queue<P2, vector<P2>,greater<P2> > Q;

void input(){
    freopen("Dijkstra.inp", "r", stdin);
    cin >> N >> M;
    adj.resize(N + 1);
    for (int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});

    }
    cin >> S >> T;

    /*
    for (int u = 1; u <= N; u++){
        cout << "Edge " << u << " : \n";
        for (pair<int, int> e : adj[u]){
            cout << u << ' ' << e.first << ' ' << "weigh= " << e.second << '\n';
        }
    }
    */
}

void solve(){
    //Initialize
    vector<long long> distance(N + 1, 1e9);
    distance[S] = 0;
    Q.push({0, S});

    while (!Q.empty()) {
        long long du = Q.top().first;
        int u = Q.top().second;
        Q.pop();
        for (P2 e : adj[u]) {
            int v = e.second;
            long long w = e.first;
            if (distance[v] > du + w) {
                distance[v] = du + w;
                Q.push({distance[v], v});
            }
        }
    }

    cout << distance[T];
}

int main(){
    input();
    solve();
}
