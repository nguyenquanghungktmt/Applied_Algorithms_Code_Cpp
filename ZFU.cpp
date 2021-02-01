#include <bits/stdc++.h>
using namespace std;

int n, Q;
string S;
vector<int> value;

int find(int index){
    int cnt = 0;
    for (int i = index; i < n; i++){
        if (S[i - index] == S[i]) cnt++;
        else break;
    }
    return cnt;
}

void process(){
    value.resize(n + 1);
    for (int i = n - 1; i >= 0; i--){
        value[i] = max(value[i + 1], find(i));
    }
}

int main(){
    //freopen("ZFU.inp", "r", stdin);
    cin >> S;
    n = S.length();

    process();
    
    cin >> Q;
    for (int i = 0; i < Q; i++){
        int location;
        cin >> location;
        if (location < 1 && location > n) cout << 0 << endl;
        else cout << value[location - 1] << endl;
    }
}

//Do phuc tap O(n^2)