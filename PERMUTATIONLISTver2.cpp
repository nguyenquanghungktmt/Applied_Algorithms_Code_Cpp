#include <iostream>
using namespace std;

int n, k, cnt = 0;
int a[10002];

void solution(){
    cnt++;
    if (cnt == k) {
        for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
        exit(0) ;
    }
}

int main(){
    cin >> n >> k;
    if (n == 0) {
        cout << -1 << '\n';
        exit(0);
    }
    for (int i = 1; i <= n; i++) a[i] = i;

    int i = n;
    do{
        solution();
        i = n - 1;
        while ( i > 0 && a[i] > a[i + 1]) i--;
        if (i > 0){
            int k = n;
            while (a[k] < a[i]) k--;
            swap(a[k], a[i]);

            int p = i + 1, q = n;
            while (p < q){
                swap(a[p], a[q]);
                p++;
                q--;
            }
        }
    } while (i > 0);
    cout << -1 << '\n';
}
