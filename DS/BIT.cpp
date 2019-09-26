void build() {
    for (int i = 1; i <= n; i++) {
        j = i + (i & -i);
        if (j <= n)
            bit[j] += bit[i];
    }
}

void add(int k, int x) {
    while (k <= x) {
        bit[k] += x;
        k += k & -k;
    }
}

void sum(int k) {
    int s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

