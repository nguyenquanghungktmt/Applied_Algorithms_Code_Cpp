#include <bits/stdc++.h>
#define MAX 100002
using namespace std;

int N;
pair<int, int> point[MAX], a, b;
map <pair<int, int> , int> CS;
double d_min = 1e9;

double distance(pair<int, int> p1, pair<int, int> p2){
    //setprecision(6);
    return sqrt( pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2) );
}

bool cmp_x(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}

bool cmp_y(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

void update_result(pair<int, int> p1, pair<int, int> p2){
    double dist = distance(p1, p2);
    if (d_min > dist) {
        d_min = dist;
        a = p1; b = p2;
    }
}

void solve(int l, int r){
    if (l >= r) return;
    if (l + 1 == r){
        //Doan co 2 phan tu
        update_result(point[l], point[r]);
        if (!cmp_y(point[l], point[r])) swap(point[l], point[r]);
    }

    int m = (l + r) / 2;
    double mid_x = point[m].first;
    solve(l, m);
    solve(m + 1, r);

    pair<int, int> tmp[MAX];
    merge(point + l, point + m + 1, point + m + 1, point + r + 1, tmp, cmp_y);
    copy(tmp, tmp + r - l + 1, point + l);

    int tm = 0;
    for (int i = l; i <= r; i++)
        if (abs(point[i].first-mid_x) < d_min) {
        for (int j = tm - 1; j >= 0 && tmp[j].second > point[i].second - d_min; j--)
            update_result(point[i], tmp[j]);
        tmp[tm++] = point[i];
    }
}

void print(){
    for (int i = 0; i < N; i++) cout << point[i].first << ' ' << point[i].second << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    setprecision(6); // cai dat do chinh xac sau dau phay dong4
    cout << fixed;

    freopen("clopair.inp", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++) {
            cin >> point[i].first >> point[i].second;
            CS[point[i] ] = i;
    }
    sort(point, point + N, cmp_x);
    //print();
    solve(0, N - 1);
    //print();
    if (CS[a] < CS[b]) cout << CS[a] << ' ' << CS[b] << ' ';
    else  cout << CS[b] << ' ' << CS[a] << ' ';
    cout << d_min << '\n';
}
