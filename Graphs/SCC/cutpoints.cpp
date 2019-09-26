const int N = 1005;

vector<int> G[N];
int vis[N], fn[N], tin[N];
int timer, ans;

void dfs(int v, int p = -1) {
    vis[v] = 1;
    fn[v] = tin[v] = timer++;
    int des = 0;
        
    for (int to : G[v]) {
        if (p == to) continue;
        if (vis[to]) {
            fn[v] = min(fn[v], tin[to]);
        } else {
            dfs(to, v);
            fn[v] = min(fn[v], fn[to]);
            if (fn[to] >= tin[v] && p != -1)
                ans++;
            ++des;
        }
    }
    
    if (p == -1 && des > 1)
        ans++;
}

