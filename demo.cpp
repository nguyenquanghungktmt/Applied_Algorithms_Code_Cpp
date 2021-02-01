#include <iostream>
using namespace std;

int n, m;
int a[5001];
int F[5001]; // tong lon nhat ket thuc tai vi tri a[i] khong qua n
int trace[5001];

void print( int k){
    if (trace[k] == 0) cout << a[k]<< ' ' ;
    else {
        print(trace[k]);
        cout << a[k] << ' ';
    }
}

int main(){
    freopen("demo.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
    int res = a[1];

    F[1] = a[1];
    for (int i = 2; i <= m; i++){
        int j_max = 0, j = i - 1;
        int tmp = -INT_MAX;

        for (j = i - 1; j > 0; j--){
            if (F[j] + a[i] <= n && F[j] >= tmp){
                tmp = F[j];
                j_max = j;
            }
        }
        //cout << j_max << endl;
        if (j_max != 0) F[i] = F[j_max] + a[i];
        else F[i] = a[i];
        trace[i] = j_max;

        //if (F[i] <= n) res = max(res, F[i]);
    }

    int it = 1;
    for (int i = 1; i<= n; i++)
    if (F[i] <= n){
        if (res < F[i]){
            res = F[i];
            it = i;
        }
    }

    print(it);

     //for (int i = 1; i <= m; i++) cout << F[i] << ' '; cout << endl;
     //for (int i = 1; i <= m; i++) cout << trace[i] << ' '; cout << endl;
    cout << res << '\n';
}
