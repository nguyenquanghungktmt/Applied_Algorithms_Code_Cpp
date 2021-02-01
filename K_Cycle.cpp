#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MAX = 31;
int N, M, K;
vector<int> adj[MAX];
int X[MAX];
bool visited[MAX];
int cnt = 0;

void input(){
    freopen("K_Cycle.inp", "r", stdin);
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int u = 1; u <= N; u++) adj[0].push_back(u);

    /*
    for (int u = 0; u <= N; u++){
        cout << "Edge " << u << " : \n";
        for (int v : adj[u]){
            cout << u << ' ' << v << '\n';
        }
    }
    */
}

bool checkSolution(){
    for(int v : adj[ X[K] ]){
        if (v == X[1]) return true;
    }
    return false;
}

void TRY(int k){
    for (int value : adj[ X[k - 1] ]){
        if (!visited[value]){
            visited[value] = true;
            X[k] = value;
            if (k == K) {
                if (checkSolution()) {
                    cnt++;
                    for (int i = 1; i <= K; i++) cout << X[i] << ' '; cout << '\n';
                }
            }
            else TRY(k + 1);
            visited[value] = false;
        }
    }
}

void solve(){
    cnt = 0;
    X[0] = 0;
    TRY(1);
    cout << cnt / K / 2;
}

int main(){
    input();
    solve();
}
