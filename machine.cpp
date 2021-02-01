#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

const int MAX = 2e6 + 1;
int n;
int S[MAX];
vector< pair<int, int> > period;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}

void input(){
    cin >> n;
    period.resize(n);
    for (int i = 0; i < n; i++) cin >> period[i].first >> period[i].second;
    sort(period.begin(), period.end(), compare);
}

void print(){
    for (pair<int, int> it : period) cout << it.first << ' ' << it.second << '\n';
}

int C(pair<int, int> p){
    return p.second - p.first;
}

void solve(){
    int ans = -1;
    deque<int> d;
    for (int i = 0; i < n; i++){
        pair<int, int> p = period[i];

        while (!d.empty() && period[d.front()].second >= p.first) d.pop_front();
        while (!d.empty() && C(p) > C[])

    }
}

int main(){
    input();
    print();
}
