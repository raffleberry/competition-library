//<nlogn, logn>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5;
const int LOG = 20;

int n;
int up[N + 1][LOG + 1], depth[N + 1];
vector<int> G[N + 1];

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i <= LOG; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (int u : G[v]) if (u != p) {
        depth[u] += depth[v] + 1;
        dfs(u, v);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    
    int k = depth[a] - depth[b];
    
    for (int i = 0; i <= LOG && a != 0; i++) {
        if (k & (1<<i)) {
            a = up[a][i];
        }
    }
    
    if (a == b) return a;
    
    for (int i = LOG; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    
    return up[a][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    dfs(1, 0);
    
    cout << lca(2, 4) << '\n';
    
    return 0;
}
