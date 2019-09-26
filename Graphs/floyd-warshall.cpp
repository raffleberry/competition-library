
const int inf = 0x3f3f3f3f;

int G[N][N], dis[N][N];


void chkneg() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1;j <= n; j++) {
            for (int c = 1; c <= n; c++) {
                if (d[i][c] < inf && d[t][t] < 0 && d[c][j] < inf)
                    d[i][j] = -inf;
            }
        }
    }
}

void fw() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dis[i][j] = 0;
            else if (G[i][j]) dis[i][j] = G[i][j];
            else dis[i][j] = inf;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] < inf && dis[k][j] < inf)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    chkneg();
}

