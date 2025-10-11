#include <iostream>
using namespace std;

int g[6][6] = { 0 };
bool v[6] = { false };

void dfs(int n) {
    v[n] = true;
    cout << n << " ";

    for (int i = 0; i < 6; i++) {
        if (g[n][i] == 1 && v[i] == false) {
            dfs(i);
        }
    }
}

int main() {
    g[0][1] = 1;
    g[0][2] = 1;
    g[2][1] = 1;
    g[1][3] = 1;
    g[2][3] = 1;
    g[3][4] = 1;
    g[3][5] = 1;
    

    cout << "DFS: ";
    dfs(0);
    cout << endl;

    return 0;
}
