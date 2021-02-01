#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, a0, a1, b0, b1;
    cin >> a >> b;
    a0 = a / 10;
    a1 = a % 10;
    b0 = b / 10;
    b1 = b % 10;
    a0 =  a0 + b0 + (a1 + b1) / 10;
    a1 = (a1 + b1) % 10;
    if (a0 > 0) cout << a0;
    cout << a1 << endl;
}