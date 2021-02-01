#include "iostream"
using namespace  std;

int main(){
    freopen("word.inp", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;        
        int l = str.length();
        if (l >= 10){
            cout << str[0] << l - 2 << str[l - 1] << '\n';
        }
        else {
            cout << str << '\n';    
        }
    }
}