#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int n;
int a[MAX];

void input(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    for (int i = n - 1; i > 0; i--){
        if (a[i] < a[i + 1]){
            //cout << i << '\n';
            int j_min = i + 1;
            for (int j = i + 1; j <= n; j++)
                if (a[j] > a[i]){
                    if (a[j_min] > a[j]) j_min = j;
                }
            swap(a[i], a[j_min]);
            sort(a + i + 1, a + n + 1);
            //cout << j_min << ' ' << a[j_min] << '\n';
            for (int k = 1; k <= n; k++) cout << a[k] << ' ';
            exit(0);
        }
    }
    cout << -1 << '\n';
}


int main(){
    input();
    solve();
}
