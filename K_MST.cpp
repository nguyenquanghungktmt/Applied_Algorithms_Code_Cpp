#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P2;

const int MAX = 31;
int N, M, K;
vector<P2> edge;
long long weight[MAX];
int X[MAX];
int r[MAX], p[MAX];
long long best = INT_MAX, sum = 0;

void input(){
    freopen("K_MST.inp", "r", stdin);
    cin >> N >> M >> K;
    edge.resize(M + 1);
    for (int i = 1; i <= M; i++){
        int u, v, w;
        cin >> edge[i].first >> edge[i].second >> weight[i];
    }
    for (int i = 1; i < M; i++){
        for (int j = i + 1; j <= M; j++){
            if (weight[i] > weight[j]){
                swap(edge[i], edge[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    /*
    cout << "size = " << edge.size() << '\n';
    for (int i = 1; i <= M; i++){
        cout << edge[i].first << ' ' << edge[i].second << ' ' << weight[i] << '\n';
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

bool check(int val, int k){
    // check if add edge val -> create cycle ?
    // k-1 canh x[1],...x[k-1] KHONG tao chu trinh
    for(int u = 1; u <= N; u++) makeSet(u);

    for (int i = 1; i < k; i++){
        int r1 = findSet(edge[ X[i] ].first);
        int r2 = findSet(edge[ X[i] ].second);
        link(r1, r2);
    }

    return findSet(edge[ val ].first) != findSet(edge[ val ].second);
}

bool checkConnected(){
    //check xem result co phai la cay ko

    for(int v = 1; v <= N; v++) makeSet(v);

    for(int i = 1; i <= K; i++){
        link(findSet(edge[ X[i] ].first), findSet(edge[ X[i] ].second));
    }
    int r = -1;
    for(int i = 1; i <= K; i++){
        int u = edge[ X[i] ].first;
        int v = edge[ X[i] ].second;
        int ru = findSet(u);
        int rv = findSet(v);
        if(ru != rv) return false;
        if(r == -1) r = ru;
        else if(r != ru) return false;
    }
    return true;
}

void solution(){
    if (checkConnected()) best = min(best, sum);
}

void TRY(int k){
    for (int value = X[k - 1] + 1; value <= M; value++){ // v de quy tren tap canh, x[k]: stt canh
        if (check(value, k)){
            X[k] = value;
            sum += weight[value];
            if (k == K) {
                solution();
                //if (sum < best) best = sum;
                //for (int i = 1; i <= K; i++) cout << X[i] << ' '; cout << '\n';
            }
            else {
                long long g = sum;
                for (int j = 1; j <= K - k; j++) g += weight[value + j];
                if(g < best)
                    TRY(k + 1);
                //if (sum < best) TRY(k + 1);
            }
            sum -= weight[value];
        }
    }
}

void solve(){
    X[0] = 0;
    TRY(1);
    if (best == INT_MAX) cout << -1; else cout << best;
}

int main(){
    input();
    solve();
}
