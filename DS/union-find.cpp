class UnionFind {
  int p[N], sz[N];
  public:
    UnionFind() {
      for (int i = 0; i < N; i++) {
        p[i] = i;
        sz[i] = 1;
      }
    }
    int par(int a) {
      if (p[a] == a)
        p[a] = par(p[a]);
      return p[a];
    }

    void unite(int a, int b) {
      a = par(a);
      b = par(b);
      if (a == b) return;
      if (sz[a] < sz[b]) swap(a, b);
      p[b] = a;
      sz[a] += sz[b];
      sz[b] = -1;
    }
};
