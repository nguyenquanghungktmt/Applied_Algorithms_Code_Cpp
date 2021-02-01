#include <iostream>
using namespace std;

int main(){
    freopen("EKO.inp", "w", stdout);
    cout << "1000000 2000000000\n";
    for (int i = 1; i <= 1000000; i++) cout << rand() % 1000000000 << ' ';
}
