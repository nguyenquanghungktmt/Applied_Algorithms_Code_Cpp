#include <iostream>
#include <queue>

using namespace std;

struct edge{
    int first, second, value;
};

struct compare{
    bool operator() (edge e1, edge e2){ return e1.value > e2.value; }
};


void solve(){
    priority_queue<edge, vector<edge>, compare > Q;

    freopen("priority_queue.inp", "r", stdin);
    int N, M;
    edge e;
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        cin >> e.first >> e.second >> e.value;
        Q.push(e);
    }

    while (!Q.empty()){
        e = Q.top();
        cout << e.first << ' ' << e.second << ' ' << e.value << '\n';
        Q.pop();
    }
}

int main(){
    solve();
}

