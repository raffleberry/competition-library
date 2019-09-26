//untested
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 5;
const int INF = 1e9;

int n;
int par[N], cap[N][N];
vector<int> G[N];


int bfs(int s, int t) {
    memset(par, -1, sizeof(par));
    par[s] = -2;
    queue<pair<int, int>> Q;
    Q.push({s, INF});
    while (!Q.empty()) {
        int u = Q.front().first;
        int cbn = Q.front().second;
        Q.pop();
        for (int v : G[u]) {
            if (par[v] == -1 && cap[u][v]) {
                par[v] = u;
                int bn = min(cap[u][v], cbn);
                if (v == t)
                    return bn;
                Q.push({v, bn});
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    ll flow = 0;
    for (int c = bfs(s, t); c != 0; c = bfs(s, t)) {
        flow += c;
        for (int v = t; v != s; v = par[v]) {
            cap[par[v]][v] -= c;
            cap[v][par[v]] += c;
        }
    }
    return flow;
}

int main() {
    
    return 0;
}
