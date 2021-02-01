#include <bits/stdc++.h>
using namespace std;

int I, N, M;
int d[2001];

bool BFS(int u, vector< vector<int> > adj){
    queue<int> Q;
    Q.push(u);
    d[u] = 0;
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        for(int x : adj[v]){
            // xet dinh x ke voi v
            if(d[x] > -1){
                if(d[v] % 2 == d[x] % 2) {
                    return false;
                } // cung bac voi dinh cha thi ko thoa man, exit luon
            }
            else{
                d[x] = d[v] + 1;
                Q.push(x);
            }
        }
    }
    return true;
}

void solve(int x){
    cout << "Scenario #" << x << ":\n";
    cin >> N >> M;
    vector< vector<int> > adj(N + 1);
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int u = 1; u <= N; u++) d[u] = -1;
    for(int v= 1; v <= N; v++){
        if(d[v]== -1) {
            if (!BFS(v, adj)){
                cout << "Suspicious bugs found!" << endl;
                return;
            }
        }
    }
    cout << "No suspicious bugs found!" << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> I;
    for (int i = 1; i <= I; i++){
        solve(i);
    }
    return 0;
}
