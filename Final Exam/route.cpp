#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
int n, Q, index;
int a[MAX];
int d[MAX][MAX];
int x[MAX], x_best[MAX];
bool visited[MAX];
long long sum = 0, value = 0, value_min = INT_MAX;
long long cmin = INT_MAX;

void input (){
    cin >> n >> Q;
    long long S = 0;
    for (int i = 1; i <= n; i++) { cin >> a[i]; S += a[i];}
    if (S < Q) {
        cout << -1;
        exit(0);
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            cin >> d[i][j];
            //if (i != j) cmin = min(cmin, d[i][j]);
        }

    cmin = Q / n;
    //cout << cmin << endl;
    /*
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++) cout << d[i][j] << ' ';
        cout << endl;
    }
    */
}

void solution(int k){

    int u = x[k];
    value += d[u][0];
    if (value < value_min){
        value_min = value;
        index = k;
        for (int i = 1; i <= k; i++) x_best[i] = x[i] <<' ';
    }

    value -= d[u][0];
}

void TRY(int k){
    for (int v = 1; v <= n; v++)
    if (!visited[v]){
        x[k] = v;
        sum += a[v];
        visited[v] = true;
        value += d[x[k - 1]][v];

        if (k == n || sum >= Q){
            solution(k);
        }
        else
        {
            if (value + cmin * (n - k + 1) < value_min) TRY(k + 1);
        }

        sum -= a[v];
        value -= d[x[k - 1]][v];
        visited[v] = false;
    }
}

void init(){
    sum = 0;
    value = 0;
    value_min = INT_MAX;
    for (int i = 0; i <= n; i++) visited[i] = false;
}

int main(){
    freopen("input_9.txt", "r", stdin);
    freopen("output_9.txt", "w", stdout);
    input();
    TRY(1);
    cout << value_min << '\n' << index << '\n';
    for (int i = 1; i <= index; i++) cout << x_best[i] << ' ';
}
