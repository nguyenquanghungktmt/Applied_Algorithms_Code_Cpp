#include <iostream>
using namespace std;

unsigned long long comb(unsigned long long n, unsigned long long k)
{
    if (k>n) return 0;
    unsigned long long result = 1;
    for (unsigned long long i = 1; i<=k; ++i, --n)
        result = result * n / i;
    return result;
}

int main(){
    unsigned long long n, m, k, T;
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> n >> k >> m;
        cout << comb(n, k) % m<< '\n';
    }
}

