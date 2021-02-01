#include "iostream"
using namespace std;

int main(){
    int n;
    string str;
    cin >> n;
    cin >> str;
    bool flag = false;
    for (int i = n - 1; i >= 0; i--){
        if (str[i] == '0'){
            str[i] = '1';
            flag = true;
            break;
        }
        else str[i] = '0';
    }
    if (flag == true) cout << str <<'\n';
    else cout << -1 << '\n';
}