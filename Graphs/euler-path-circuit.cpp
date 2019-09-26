#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;

int n, m;
multiset<int> G[N];
vector<int> ans;

void findPath(int u) {
    while (G[u].size() != 0) {
        int nxt = *G[u].begin();
        G[u].erase(G[u].begin());
        G[nxt].erase(G[nxt].find(u));
        findPath(nxt);
    }
    ans.push_back(u);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].insert(b);
        G[b].insert(a);
    }
    findPath(5);
    for (int i : ans) {
        printf("%d ", i);
    }
    puts("");
    return 0;
}
