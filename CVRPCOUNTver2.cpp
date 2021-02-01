#include <iostream>
#define P 1000000007
using namespace std;

int n, K, Q;
int d[11];
int x[11][6];
bool mark[11];
int cnt = 0;
int sum[6];
int counter[6];
int counter2[11];

void solution(){
    for (int i = 1; i <= K; i++) if (counter[i] == 0) return;
    //for (int i = 1; i <= n; i++) if (counter2[i] != 0) return;
    //for (int i = 1; i <= n; i++) if (!mark[i]) return;
    cout << ++cnt << '\n';
    for (int i = 1; i <= n; i++)  cout << mark[i] << ' '; cout << '\n';
    for (int i = 1; i <= K; i++){
        for (int j = 1; j <= n; j++) cout << x[j][i] << ' ';
        cout << '\n';
    }
}
bool check(int client, int truck, int v){
    if (v == 0) return true;
    else if (mark[client] == false && sum[truck] + d[client] <= Q) return true;
    else return false;

    if (v == 1){
        if (mark[client]) return false;
        if (sum[truck] + d[client] > Q) return false;
    }
    return true;
}

void TRY(int client, int truck){
    for (int v = 0; v <= 1; v++){
        if (check(client, truck, v)){
            x[client][truck] = v;
            //sum[truck] += d[client];
            if (v == 1) { mark[client] = true; counter[truck]++; counter2[client]++; sum[truck] += d[client];}
            if (client == n && truck == K) solution();
            else if (client == n && truck < K) TRY(1, truck + 1);
            else TRY(client + 1, truck);
            //sum[truck] -= d[client];
            if (v == 1) { mark[client] = false; counter[truck]--; counter2[client]--; sum[truck] -= d[client];}
        }
    }
}

int main(){

    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++) cin >> d[i];
    cout << n << K << Q << '\n';
    TRY(1, 1);
    //cout << (res / 2) % P << '\n';
}
