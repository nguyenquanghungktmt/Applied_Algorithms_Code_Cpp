#include <bits/stdc++.h>
using namespace std;
int n, a ,b, c;
bool visited[1001][1001];
queue< pair<int, int> > Q;
pair<int, int> res;
map< pair<int, int>, pair<int, int> > parent;

bool check(pair<int, int> p){
    if(p.first == c || p.second == c){
        res = p;
        return true;
    }
    else return false;
}

bool fullCup1(pair<int, int> p){
    pair<int, int> np (a, p.second);
    if (visited[np.first][np.second]) return false;
    Q.push(np);
    parent[np] = p;
    visited[np.first][np.second] = true;
    if (check(np)) return true;
    else return false;
}

bool fullCup2(pair<int, int> p){
    pair<int, int> np (p.first, b);
    if (visited[np.first][np.second]) return false;
    Q.push(np);
    parent[np] = p;
    visited[np.first][np.second] = true;
    if (check(np)) return true;
    else return false;
}

bool emptyCup1(pair<int, int> p){
    pair<int, int> np (0, p.second);
    if (visited[np.first][np.second]) return false;
    Q.push(np);
    parent[np] = p;
    visited[np.first][np.second] = true;
    if (check(np)) return true;
    else return false;
}

bool emptyCup2(pair<int, int> p){
    pair<int, int> np (p.first, 0);
    if (visited[np.first][np.second]) return false;
    Q.push(np);
    parent[np] = p;
    visited[np.first][np.second] = true;
    if (check(np)) return true;
    else return false;
}

bool moveCup1toCup2(pair<int, int> p){
    pair<int, int> np (0, p.first + p.second);
    if (np.second > b){
        np.first = np.second - b;
        np.second = b;
    }
    if (visited[np.first][np.second]) return false;
    Q.push(np);
    parent[np] = p;
    visited[np.first][np.second] = true;
    if (check(np)) return true;
    else return false;
}

bool moveCup2toCup1(pair<int, int> p){
    pair<int, int> np (p.first + p.second, 0);
    if (np.first > a){
        np.second = np.first - a;
        np.first = a;
    }
    if (visited[np.first][np.second]) return false;
    Q.push(np);
    parent[np] = p;
    visited[np.first][np.second] = true;
    if (check(np)) return true;
    else return false;
}

int countStep( pair<int, int> p){
    if (p.first == 0 && p.second == 0) return 0;
    else return 1 + countStep(parent[p]);
}

void initialize(){
    while (!Q.empty()) Q.pop();
    for (int i = 0; i <= a; i++){
        for (int j = 0; j <= b; j++)
            visited[i][j] = false;
    }
    res = pair< int, int > (0, 0);
}

void process(){
    Q.push(pair<int, int> (0, 0));
    visited[0][0] = true;
    while (!Q.empty()){
        pair<int, int> p = Q.front();
        Q.pop();
        //cout << p.first <<' ' << p.second << '\n';
        //if (check(p)) exit(0);
        //if (i++ == 5) break;
        if (fullCup1(p)) break;
        if (fullCup2(p)) break;
        if (emptyCup1(p)) break;
        if (emptyCup2(p)) break;
        if (moveCup1toCup2(p)) break;
        if (moveCup2toCup1(p)) break;
    }

    //cout << res.first << ' ' << res.second << '\n';
    cout << countStep(res) << endl;
}

int main(){
    cin >> a >> b >> c;
    if ( c > a && c > b) cout << -1 << '\n';
    else {
        initialize();
        process();
    }
}
