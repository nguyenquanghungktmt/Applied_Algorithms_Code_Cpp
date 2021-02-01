#include <bits/stdc++.h>
#include <algorithm>
#define MAX 100001
using namespace std;


typedef pair<long long, int> P2;

int N, M;
int S, T;
vector< vector<P2> > adj;
priority_queue<P2, vector<P2>,greater<P2> > Q;

void input(){
    freopen("MST.inp", "r", stdin);
    cin >> N >> M;
    adj.resize(N + 1);
    for (int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});

    }
}
/*
void quickSort( int l, int r) //sort from l to r
{
    int x = w[(l + r)/2];
    int i = l; int j = r;

    while (i < j){
        while (w[i] < x) i++;
        while (x < w[j]) j--;
        if (i <= j){
            swap(u[i], u[j]);
            swap(v[i], v[j]);
            swap(w[i], w[j]);
            i++; j--;
        }
    }
    if (l < j) quickSort(l, j);
    if (i < r) quickSort(i, r);
}
*/

void Prim(){
    //quickSort(1, M);
    //sort(edge, edge + M, compare);
    //for (int i = 0; i < M; i++) cout << edge[i].first << ' ' << edge[i].second << ' ' << weigh[edge[i]] << '\n';

    for (int x = 1; x <= N; x++) makeSet(x);
    int cnt = 0;
    for (int i = 0; i < M; i++){
        int ru = findSet(edge[i].first);
        int rv = findSet(edge[i].second);
        if(ru != rv){
            link(ru,rv);
            ans += weigh[edge[i]];
            cnt++;
            if(cnt == N - 1) break;
        }
    }
    cout << ans;

}

int main(){
    input();
    solve();
}
