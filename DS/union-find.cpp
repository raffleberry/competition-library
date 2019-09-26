int par[N], sze[N];

int get(int x) {
    if (par[x] != x)
        par[x] = get(par[x]);
    return par[x];
}

void init() {
    for (int i = 0; i < N; i++) {
        par[i] = i;
        sze[i] = 1;
    }
}

void unite(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return;
    if (sze[a] < sze[b]) swap(a, b);
    sze[a] += sze[b], sze[b] = -1;
    par[b] = a;
}
