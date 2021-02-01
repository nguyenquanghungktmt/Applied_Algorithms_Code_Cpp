#include <bits/stdc++.h>
#include <algorithm>
#define MAX 100001
using namespace std;

typedef pair<int, int> p2;

int N, M;
p2 edge[MAX];
map< p2, int > weigh;
int r[MAX], p[MAX];
long long ans = 0;

void input(){
    freopen("MST.inp", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int w;
        cin >> edge[i].first >> edge[i].second >> w;
        weigh[edge[i]] = w;
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

bool compare(p2 x, p2 y){
    return weigh[x] < weigh[y];
}

void solve(){
    //quickSort(1, M);
    sort(edge, edge + M, compare);
    //for (int i = 0; i < M; i++) cout << edge[i].first << ' ' << edge[i].second << ' ' << weigh[edge[i]] << '\n';

    for (int x = 1; x <= N; x++) makeSet(x);
    int cnt = 0;
    for (int i = 0; i < M; i++){
        int ru = findSet(edge[i].first);
        int rv = findSet(edge[i].second);
        if(ru != rv){
            link(ru, rv);
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
