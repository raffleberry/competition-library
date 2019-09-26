ll dji(int sou, int des) {
    bool vis[n + 1] = {0};
    ll dis[n + 1];
    priority_queue< pair<ll, int> > Q;
    
    memset(dis, INF, sizeof(dis));
    vis[so] = 1, dis[so] = 0;
    Q.push({0, so});
    
    while (!Q.empty()) {
        int f = Q.top().second; Q.pop();
        if (vis[f]) continue;
        vis[f] = true;
        //if (f == des) return dis[f];
        for (auto x : G[f]) {
            int t = x.to, w = x.we;
            if (dis[t] > dis[f] + w) {
                dis[t] = dis[f] + w;
                Q.push({-dis[t], t});
            }
        }
    }
}
