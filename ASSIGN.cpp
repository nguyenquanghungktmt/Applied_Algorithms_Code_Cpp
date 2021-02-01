#include <iostream>
#define MAX 202
using namespace std;

int n;
int c[MAX][MAX];
int x[MAX];
bool mark[MAX] = {false};
int res = INT_MAX;
int time = -1;

void input(){
    freopen("ASSIGN.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> c[i][j];
}

void solution(){
    for (int i = 1; i <= n; i++) cout << x[i] << ' '; cout << endl;
}

void TRY(int person){
    for (int job = 1; job <= n; job++){
        if (!mark[job] && c[person][job] < res){
            x[person] = job;
            mark[job] = true;
            int tmp = time;
            //cout << "log: " << person <<' ' << job << " ==> "<< time << ' ' << c[person][job] << ' ';
            //time = max(time, c[person][job]);
            //cout << "result: "  << time << '\n';
            if (person == n) {
                //cout << time << endl;
                //int time_max = -1;
                //for (int i = 1; i <= n; i++) time_max = max(time_max, c[i][x[i]]);
                //cout << "LT: " << time_max << endl;
                if (time < res) {res = time; solution(); }
            }
            else {
                if (time < res) TRY(person + 1);
            }
            mark[job] = false;
            time = min(tmp, c[person][job]);
            //cout << time << endl;
        }
    }
}

int main(){
    input();
    TRY(1  );
    cout << res;
}
