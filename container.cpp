#include <iostream>
using namespace std;

int n, H, W;
int h[15], w[15];

void input(){
    freopen("container.inp", "r", stdin);
    cin >> H >> W;
    cin >> n;
    for (int i = 1; i <=n; i++){
        cin >> h[i] >> w[i];
    }
    //Sap xep giam dan theo h
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++)
            if (h[i] < h[j]){
                swap(h[i], h[j]);
                swap(w[i], w[j]);
            }
    }

}

void solve(int H, int W){

    int it = 1;
    while (it <= n){
        if (h[it] > H || w[it] > W) {
            cout << 0;
            exit(0);
        }
        int sum = 0;
        int tmp = 0;
        int i = it;
        for (i = it; i <= n; i++){
            if (sum + h[i] <= H){
            sum += h[i];
            tmp = max(tmp, w[i]);
            }
            else break;
        }

        //cout << i << '\n';
        W -= tmp;
        //cout << "W= " << W << '\n';
        it = i;
    }
    cout << 1;
}


int main(){
    input();
    solve(H, W);
}
