#include <iostream>
#include <stack>
using namespace std;

int n, m, k;
unsigned long long ans = 1;
int p[600];

bool check(unsigned long long mid){

    //vector <int> pos;
    int pos = 0;
    unsigned long long sum = 0;
    for (int i = m; i >= 1; i--){
        if (sum + p[i] <= mid){
            sum += p[i];
        }
        else {
            sum = p[i];
            if (sum > mid) return false;
            pos++;
        }
    }
    if (pos >= k) return false;

    return true;
}

void print_result(unsigned long long value){
    int cnt = k;
    stack <int> pos;
    unsigned long long sum = 0;
    for (int i = m; i >= 1; i--){
        //cout << "i = " << i << " cnt = " << cnt << endl;
        if (i == cnt - 1 && !pos.empty()) {
            cnt--;
            pos.push(i);
            continue;
        }
        sum += p[i];
        if (sum <= value) continue;
        else {
            cnt--;
            pos.push(i);
            sum = p[i];
        }
    }
    //for (int i = 0; i < pos.size(); i++) cout << pos[i] << ' ';
    if (pos.empty()){
        for (int i = 1; i <= m; i++) cout << p[i] << ' ';
    }
    else {
        int tmp = pos.top();
        pos.pop();
        for (int i = 1; i <= m; i++){
            //cout << tmp << endl;
            cout << p[i] << ' ';
            if (i == tmp){
                cout << "/ ";
                if (!pos.empty()){
                    tmp = pos.top();
                    pos.pop();
                }
            }
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> m >> k;
        for (int i = 1; i <= m; i++) cin >> p[i];

        unsigned long long left = 0, right = 1e12;
        while (left <= right){
            unsigned long long mid = (left + right) / 2;
            //cout << left << '-' << right << ' ' << mid << endl;
            if (check(mid)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        //cout << check(17) << endl;
        print_result(ans);
        //cout << ans;
    }

}
