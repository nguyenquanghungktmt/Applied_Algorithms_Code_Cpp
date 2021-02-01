#include <bits/stdc++.h>
#define MAX 5001
using namespace std;

int N, K;
int C[MAX], D[MAX];
vector<int> adj[MAX];

void input(){
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> C[i] >> D[i];
    for (int i = 0; i < K; i++){
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    input();
}
