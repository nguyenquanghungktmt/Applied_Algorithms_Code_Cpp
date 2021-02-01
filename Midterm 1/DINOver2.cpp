#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
int n;
int p[MAX];
string s;

void process(){
    deque<int> HanhLang;
    stack<int> Chuong;
    for (int i = n; i >= 1; i--) Chuong.push(p[i]);

    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'C'){
            if (!Chuong.empty()){
                int dino = Chuong.top();
                Chuong.pop();
                HanhLang.push_back(dino);
            }

        }
        else {
            if (!HanhLang.empty()){
                int dino = HanhLang.front();
                HanhLang.pop_front();
                Chuong.push(dino);
            }
        }
    }

    while(!Chuong.empty()){
        cout << Chuong.top() << ' ';
        Chuong.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    cin >> s;
    process();
}
