#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<pair<int, int>> wall;
unsigned long int quanDichConLai = 0;
priority_queue<int> remain;

void input()
{
    freopen("test.inp", "r", stdin);
    cin >> n >> s;
    long int a, k;
    for(long int i = 1; i <= n; i++){
        cin >> a >> k;
        if(k > a) k = a;
        quanDichConLai += a;
        wall.push_back({k, a});
    }
    sort(wall.begin(), wall.end(), greater<pair<long int, long int>>());
    //for (pair<long int, long int> it : wall) cout << it.first << ' ' << it.second << '\n';
}

void solve(){
    int i = 0;
    while (i < n && s > 0){
        int k = wall[i].first;
        int a = wall[i].second;
        int need = a / k;
        int du = a % k;

        if (!remain.empty()){
            int tmp = remain.top(); // phan du cua cac thanh truoc
            if (tmp >= k){
                quanDichConLai -= tmp;
                s--;
                remain.pop();
                if (s == 0) break;
                continue;
            }
        }

        need = (s >= need) ? need : s;
        quanDichConLai -= need * k;
        s -= need;

        if (du != 0){ // co du
            remain.push(du);
        }
        i++;
    }
}

int main(){
    input();
    solve();
    cout << quanDichConLai;
}
