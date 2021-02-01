#include <iostream>
using namespace std;
const int P = 1e9 + 7;

int add(int a, int b){
    a %= P;
    b %= P;
    int tmp = P - a; //tmp=3
    if (tmp > b) return a + b;
    else return b - tmp;
}

int multy(int a, int b){
    if (b == 0) return 0;
    if (b == 1) return a % P;
    
    int tmp = multy(a, b / 2);
    int c = add(tmp, tmp);
    if (b %2 == 0) return c;
    else return add(c, a);
}

int AmuB(int a, int b){
    if (b == 0) return 1;
    if (b == 1) return a % P;

    int tmp = AmuB(a, b / 2);
    int c = multy(tmp, tmp);
    if (b %2 == 0) return c;
    else return multy(c, a);
}

int main(){
    int a, b;
    cin >> a >> b;
    //cout << add(a, b) << endl;
    //cout << multy(a, b) << endl;
    cout << AmuB(a, b) << endl;
}