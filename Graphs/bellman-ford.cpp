const int N = 1005;
const int inf = 0x3f3f3f3f;

vector< tuple<int, int, int> > G;
int dis[N], par[N];

void bf(int src) {
    memset(dis, inf, sizeof(dis));
    dis[src] = 0;
    for (int i = 1, f = 1; i < n; i++) {
        if (f == 0) break;
        f = 0;

        for (auto e : G) {
            int fr, to, w;
            tie(fr, to, w) = e;

            if (dis[to] < dis[fr] + w) {
                dis[to] = dis[fr] + w;
                par[to] = par[fr];
                f = 1;                
            }
        }
    }
}
