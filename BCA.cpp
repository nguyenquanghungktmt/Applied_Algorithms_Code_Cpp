#include <iostream>
#define MAX 40
#include <set>
using namespace std;

int n, m;
set<int> subject[MAX];
bool mark[MAX][MAX];
int x[MAX];
int res = INT_MAX;
int teach[MAX];

void input(){
    freopen("BCA.inp", "r", stdin);
    cin >> m >> n;

    int k;
    for (int i = 1; i <= m; i++){
        cin >> k;
        for (int j = 1; j <= k; j++){
            int sub;
            cin >> sub;
            subject[sub].insert(i); // mon hoc j co chua giao vien i
        }
    }

    cin >> k;
    for (int i = 0; i< k; i++){
        int x, y;
        cin >> x >> y;
        mark[x][y] = true;
        mark[y][x] = true;
    }

}

bool check(int teacher, int sub){
    for (int i = 1; i < sub; i++){
        if (mark[sub][i] && x[i] == teacher) return false;
    }
    return true;
}

void solution(){
    int tmp = -1;
    for (int i = 1; i <= m; i++) tmp = max(tmp, teach[i]);
    res = min(res, tmp);
}

void TRY(int sub){
    for (auto teacher : subject[sub]){
        if (check(teacher, sub)){
            x[sub] = teacher;
            teach[teacher]++;
            if (teach[teacher] > res) {
                teach[teacher]--;
                return;
            }
            if (sub == n) solution();
            else {
                TRY(sub + 1);
            }
            teach[teacher]--;
        }

    }
}

int main(){
    input();
    TRY(1);
    if (res != INT_MAX) cout << res << '\n'; else cout << -1 << '\n';
}
