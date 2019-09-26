const int N = 1005;

vector<int> G[N];
bool vis[N];
int tin[N], fn[N];
int timer;

void dfs(int v, int p = -1) {
    vis[v] = 1;
    tin[v] = fn[v] = timer++;//current v
    for (int to : G[v]) {
        if (to == p) continue;
        if (vis[to]) {//ancestors
            fn[v] = min(fn[v], tin[to]);
        } else {//descendants
            dfs(to, v);
            fn[v] = min(fn[v], fn[to]);
            if (fn[to] > tin[v]) {
                printf("%d %d\n", v, to);
            }
        }
    }
}

