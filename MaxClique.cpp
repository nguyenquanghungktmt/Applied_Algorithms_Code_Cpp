#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MAX = 15;
int N, M;
set<int> adj[MAX];
int X[MAX];
int best;

void input(){
    cin >> N >> M;
    //adj.resize(N + 1);
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    /*
    for (int u = 1; u <= N; u++){
        cout << "Edge " << u << " : \n";
        for (int v : adj[u]){
            cout << u << ' ' << v << '\n';
        }
    }
    */
}

bool check(int v, int k){
    for(int i = 1; i <= k - 2; i++){
        if(adj[ X[i] ].find(v) == adj[X[i]].end()) return false; // khong tim duoc v la con cua cac x[i]
    }
    return true;
}

void TRY(int k){
    int u = X[k - 1];
    for (int v : adj[u]){
        if (check(v, k)){
            X[k] = v;
            if (k > best){
                best = k;
                //for (int i = 1; i <= k; i++) cout << X[i] << ' '; cout << '\n';
            }
            if (k < N) TRY(k + 1);
        }
    }
}

void solve(){
    best = 1;
    for (int v = 1; v <= N; v++){
        X[1] = v;
        TRY(2);
    }
    cout << best;
}

int main(){
    input();
    solve();
}
