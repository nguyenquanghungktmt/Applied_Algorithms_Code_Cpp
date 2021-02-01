#include <iostream>
#define P 1000000007
using namespace std;

long long C[1001][1001];

long long CKN(int n, int k){
    long long tmp = C[n][k];
    if (k == 0 || k == n) tmp = 1;
    else if (k == 1) tmp = n;
    else {
        if (tmp == 0) tmp = ( CKN(n - 1, k) + CKN(n - 1, k - 1) ) % P;
    }
    return C[n][k] = tmp;
}

long long CKN2(int n, int k){
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    return ( CKN2(n - 1, k) + CKN2(n - 1, k - 1) ) % P;
}

int main(){
    int n, k;
    cin >> k >> n;
    cout << CKN(n, k) << '\n';
    cout << CKN2(n, k) << '\n';
}
