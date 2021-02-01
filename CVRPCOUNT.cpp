#include <iostream>
#define P 1000000007
#define MAX 15
using namespace std;

int n, K, Q;
int d[MAX], x[MAX], y[MAX], load[MAX] = {0};
bool visited[MAX] = {false};
long long res = 0, segment = 0;


bool checkY(int v, int k){
    if (visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

bool checkX(int v, int i, int k){
    if (v > 0 && visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    if (v == 0 && k == K && segment + 1 < n + K) return false; // segment < N + K
    return true;
}

void solution(){
    cout << ++res << '\n';
    cout << "segment = " << segment << '\n';
    cout << "visited: "; for (int i = 1; i <= n; i++) cout << visited[i] << ' '; cout << '\n';
    //cout << checkX(1, 3, 2) << endl;
    for (int k = 1; k <= K; k++){
        cout << "route " << k << ": ";
        int next = y[k];
        while (next > 0){
            cout << next << ' ';
            next = x[next];
        }
        cout << '\n';
    }
}

void TRY_X(int i, int k){
    for (int v = 0; v <= n; v++){
        if (checkX(v, i, k)){
            x[i] = v;
            visited[v] = true;
            segment++;
            load[k] += d[v];
            if (v > 0) TRY_X(v, k);
            else {
                if (k == K) res++;
                else TRY_X(y[k + 1], k + 1);
            }
            visited[v] = false;
            segment--;
            load[k] -= d[v];
        }
    }
}

void TRY_Y(int k){
    for (int v = y[k - 1] + 1; v <= n; v++){
        if (checkY(v, k)){
            //cout << v << '\n';
            y[k] = v;
            visited[v] = true;
            segment++;
            load[k] += d[v];
            if (k == K){
                TRY_X(y[1], 1);
            }
            else TRY_Y(k + 1);
            visited[v] = false;
            segment--;
            load[k] -= d[v];
        }
    }
}

int main(){
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++) cin >> d[i];
    y[0] = 0;
    TRY_Y(1);
    cout << res % P ;
}
