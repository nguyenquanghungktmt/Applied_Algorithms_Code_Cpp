#include <bits/stdc++.h>
#define PI 3.141593
using namespace std;

int N, F;
double r[10001];
//const double pai = acos(-1);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    setprecision(6); // cai dat do chinh xac sau dau phay dong4
    cout << fixed;

    int T;
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> N >> F;
        F++; // number 0f friends + 1
        for (int i = 1; i <= N; i++) {
            int tmp;
            cin >> tmp;
            r[i] = tmp * tmp * PI;
        }

        double left = 0.0, right = 1e10, mid;
        int cnt = 0;
        while (left < right){
            mid = (left + right) / 2;
            cnt = 0;
            for (int i = 1; i <= N; i++){
                cnt += (int)floor(r[i] / mid); // calculate the number of people
            }

            if (cnt < F) right = mid - 1e-6;
            else left = mid + 1e-6;
        }

        cout << left << '\n';
    }
}
