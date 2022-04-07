#include <iostream>
#include <time.h>

using namespace std;

int main(){
    freopen("GenTest.inp", "w", stdout);
    int n = 1000;
    cout << n << endl;
    srand((int)time(0) +n);
    for (int i = 1; i <= n; i++){
        long tmp = rand()%10000 + 1;
        cout << (float)tmp/8 << " ";
    }
}
