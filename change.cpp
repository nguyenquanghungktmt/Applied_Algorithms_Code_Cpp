#include <iostream>
using namespace std;

int N;
int money[6] = {1, 5, 10, 50, 100, 500};
int sum = 0;

int main(){
    int tmp;
    cin >> tmp;
    N = 1000 - tmp;
    for (int i = 5; i >= 0; i--){
        if (N >= money[i]){
            sum += N / money[i];
            N %= money[i];
        }

    }
    cout << sum;
}
