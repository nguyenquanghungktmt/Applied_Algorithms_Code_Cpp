#include <iostream>
#include <string.h> // thu vien chua ham memset
#define MAX 24
using namespace std;

int n, m, cnt;
int x[12];
bool mark[12][12], markColumn[12], markCheo1[MAX], markCheo2[MAX];

bool check(int v, int k){
    return !mark[k][v] && !markColumn[v] && !markCheo1[k + v] && !markCheo2[k - v + n];
}

void TRY(int k){
    for (int v = 0; v <= n; v++){
        if (check(v, k)){
            x[k] = v;
            //cout << k << " === " << v << '\n';
            markColumn[v] = markCheo1[v + k] = markCheo2[k - v + n] = true;
            if (k == n) cnt++;
            else TRY(k + 1);
            markColumn[v] = markCheo1[v + k] = markCheo2[k - v + n] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(true){
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        memset(mark, 0, sizeof(mark));
        memset(markColumn, 0, sizeof(markColumn));
        memset(markCheo1, 0, sizeof(markCheo1));
        memset(markCheo2, 0, sizeof(markCheo2));
        for (int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            mark[--x][--y] = true;
        }
        n--;
        cnt = 0;
        TRY(0);
        cout << cnt << '\n';
    }
}
