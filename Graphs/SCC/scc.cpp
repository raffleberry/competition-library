vector<int> ord, comp;

void dfs1(int u) {
    vis[u] = 1;
    for (int v : G[u]) {
        if (!vis[v])
            dfs1(v);
    }
    ord.push_back(u);
}

void dfs2(int u) {
    vis[u] = 1;
    comp.push_back(u);
    for (int v : G[u]) {
        if (!vis[v])
            dfs2(v);
    }
}

void get() {
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs1(i);
    }
    memset(vis, 0, sizeof(vis));
    int c = 1;
    for (int i : ord) {
        if (!vis[i]) {
            dfs2(i);
            printf("\ncomponent #%d : ", c++);
            for (int k : comp) printf("%d ", k);
            comp.clear();
        }
    }    
}
