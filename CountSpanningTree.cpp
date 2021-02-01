#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P2;

const int MAX = 30;
int N, M;
vector<P2> edge;
int X[MAX];
int r[MAX], p[MAX];
int ans;

void input(){
    freopen("CountSpanningTree.inp", "r", stdin);
    cin >> N >> M;
    edge.resize(M + 1);
    for (int i = 1; i <= M; i++){
        int u, v;
        cin >> edge[i].first >> edge[i].second;
    }
    /*
    cout << "size = " << edge.size() << '\n';
    for (P2 e : edge){
        cout << e.first << ' ' << e.second << '\n';
    }
    */
}
void link(int x, int y){
    if(r[x] > r[y]) p[y] = x;
    else{
        p[x] = y;
        if(r[x] == r[y]) r[y]++;
    }
}

void makeSet(int x){
    p[x] = x;
    r[x] = 0;
}

int findSet(int x){
    if(x != p[x]) p[x] = findSet(p[x]);
    return p[x];
}

bool check(int val, int k){ // check if add edge val -> create cycle ?
    if(k == 1) for(int u = 1; u <= N; u++) makeSet(u);

    int u = edge[val].first;
    int v = edge[val].second;
    int ru = findSet(u);
    int rv = findSet(v);
    if(ru == rv) return false;// node u and v belong to the same set --> creating a cycle
    link(ru, rv);// otherwise, link two sets together
    return true;
}

void TRY(int k){
    for (int value = X[k - 1] + 1; value <= M; value++){ // v de quy tren tap canh, x[k]: stt canh
        if (check(value, k)){
            X[k] = value;
            if (k == N - 1) {
                ans++;
                //for (int i = 1; i <= N - 1; i++) cout << X[i] << ' '; cout << '\n';
            }
            else TRY(k + 1);
        }
    }
}

void solve(){
    ans = 0;
    X[0] = 0;
    TRY(1);
    cout << ans;
}

int main(){
    input();
    solve();
}
