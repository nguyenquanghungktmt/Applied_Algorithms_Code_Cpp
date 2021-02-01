#include <iostream>
#include <deque>
using namespace std;

int n;
string s;
deque<int> Chuong, HanhLang;

void process(){

    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'C'){
            if (!Chuong.empty()){
               int dino = Chuong.front();
                Chuong.pop_front();
                HanhLang.push_back(dino);
            }

        }
        else {
            if (!HanhLang.empty()){
                int dino = HanhLang.front();
                HanhLang.pop_front();
                Chuong.push_front(dino);
            }

        }
    }

    while(!Chuong.empty()){
        cout << Chuong.front() << ' ';
        Chuong.pop_front();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        Chuong.push_back(tmp);
    }
    cin >> s;
    process();
}

