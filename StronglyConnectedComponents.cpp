#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector< vector<int> > adj1;
vector< vector<int> > adj2; // Do thi bu cua do thi G
vector<bool> visited;
vector<int> cs;
int nscc;
vector<int> finish;
int index = 0;

void input(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("SCC.inp", "r", stdin);
    cin >> N >> M;
    adj1.resize(N + 1);
    adj2.resize(N + 1);
    visited.resize(N + 1);
    cs.resize(N + 1);
    finish.resize(N + 1);

    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    /*
    for (int u = 1; u <= N; u++){
        cout << "Node " << u << ": \n";
        for (int v : adj1[u]) cout << v << ' '; cout << '\n';
    }
    */
}

void initialize(){
    nscc = 0;
    for (int i = 1; i <= N; i++) visited[i] = false;
}

void DFS1(int u){
    visited[u] = true;
    //cs[u] = nscc + 1;
    for (int v : adj1[u]){
        if (!visited[v]) DFS1(v);
    }
    finish[index++] = u;
}

void DFS1(){
    for (int u = 1; u <= N; u++){
        if (!visited[u]){
            DFS1(u);
        }
    }
    /*
    for (int cc = 1; cc <= nscc; cc++){
        cout << "Connected Component " << cc << ":\n";
        for (int u = 1; u <= N; u++)
            if (cs[u] == cc) cout << u << ' ';
        cout << '\n';
    }
    */
}

void DFS2(int u){
    visited[u] = true;
    cs[u] = nscc + 1;
    for (int v : adj2[u]){
        if (!visited[v]) DFS2(v);
    }
    //finish[++index] = u;
}

void DFS2(){
    for (int i = index - 1; i >= 0; i--){
        int u = finish[i];
        if (!visited[u]){
            DFS2(u);
            nscc++;
        }
    }
    /*
    for (int cc = 1; cc <= nscc; cc++){
        cout << "Connected Component " << cc << ":\n";
        for (int u = 1; u <= N; u++)
            if (cs[u] == cc) cout << u << ' ';
        cout << '\n';
    }
    */
}

int main(){
    input();
    initialize();
    DFS1();
    initialize();
    DFS2();
    cout << nscc;
}
