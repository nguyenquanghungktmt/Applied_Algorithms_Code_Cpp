#include <iostream>
using namespace std;

string add(string a, string b){
    int size = max(a.length(), b.length());
    while (a.length() < size) a = '0' + a;
    while (b.length() < size) b = '0' + b;
    
    int carry = 0;
    string res = "";
    for (int i = size - 1; i >= 0; i--){
        int x = (int)a[i] - 48; // convert char type into int type
        int y = (int)b[i] - 48;
        x = x + y + carry;
        if (x > 9) {
            x -= 10;
            carry = 1;
        }
        else carry = 0;
        char c = (char)(x + 48);
        res = c + res;
    }
    if (carry == 1) res = "1" + res;
    
    return res;
}

int main(){
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
}