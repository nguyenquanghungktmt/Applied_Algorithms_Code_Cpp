#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int N, M;
int u[MAX], v[MAX], w[MAX];
int r[MAX], p[MAX];
long long ans = 0;

void input(){
    freopen("K_MST.inp", "r", stdin);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) cin >> u[i] >> v[i] >> w[i];
}

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

void link(int x, int y){
    if(r[x] > r[y]) p[y] = x;
    else{
        p[x] = y;
        if(r[x] == r[y]) r[y] = r[y] + 1;
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

void solve(){
    quickSort(1, M);
    //for (int i = 1; i <= M; i++) cout << u[i] << ' ' << v[i] << ' ' << w[i] << '\n';
    for (int x = 1; x <= N; x++) makeSet(x);
    int cnt = 0;
    for (int i = 1; i <= M; i++){
        int ru = findSet(u[i]);
        int rv = findSet(v[i]);
        if(ru != rv){
            link(ru,rv);
            ans += w[i];
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
