#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

//typedef pair<long long, int> P2;
typedef pair<int, int> edge;

int N, M;
int S, T;
vector<edge> adj[MAX];

//priority_queue< P2 > Q;

void input(){
    freopen("Dijkstra.inp", "r", stdin);
    cin >> N >> M;

    for (int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});

    }
    cin >> S >> T;

    for (int u = 1; u <= N; u++){
        cout << "Edge " << u << " : \n";
        for (edge e : adj[u]){
            cout << u << ' ' << e.first << ' ' << "weigh= " << e.second << '\n';
        }
    }
}

void initialize(){

}

void solve(){

}

int main(){
    input();
    initialize();
    solve();
    //for (int t = 1; t <= N && t != S; t++) cout << d[pair<int, int>(S, t)] << '\n';
}
