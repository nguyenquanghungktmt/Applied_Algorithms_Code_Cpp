#include <iostream>
using namespace std;

int n, m;
int x[20], c[20], a[20][20], sum[20];
bool mark[20];
int res = INT_MAX;
int current_max = -1;

bool check(int course, int period){
    for(int i = 1; i < course; i++){
		if(a[i][course] == 1 && x[i]>= period) return false;
		if(a[course][i] == 1 && x[i] <= period) return false;
	}
	return true;
}

void solution(){
    int tmp_max = -1;
    for (int i = 1; i <= m; i++) tmp_max = max(tmp_max, sum[i]);
    res = min(tmp_max, res);
}

void TRY(int course){
    //if (course == 1) current_max = -1;
    for (int period = 1; period <= m; period++){
        if (check(course, period)){
            x[course] = period;
            sum[period] += c[course];
            //current_max = max(current_max, sum[period]);
            //cout << sum[period] << ' ' << res << '\n';
            //if (current_max >= res) return;
            if (course == n) solution();
            else {
                TRY(course + 1);
            }
            sum[period] -= c[course];
        }
    }
}
int main(){
    freopen("BACP.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++)
         for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) mark[j] = true;
         }
    //for (int i = 1; i <= m; i++) sum[i] = 0;
    //for (int i = 1; i <= n; i++) cout << mark[i] << ' '; cout << endl;
    TRY(1);
    cout << res << '\n';
}
