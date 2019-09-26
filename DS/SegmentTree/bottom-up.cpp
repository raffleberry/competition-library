const int N = 1e6 + 5;

int n, q;
int tree[N<<1];

void build() {
    for (int i = n - 1; i >= 1; i--)
        tree[i] = tree[2*i] + tree[2*i + 1];
}

int query(int l, int r) {
    int s = 0;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l%2 == 1) s += tree[l++];
        if (r%2 == 0) s += tree[r--];        
    }
    return s;
}

void update(int k) {
    k += n;
    tree[k] = !tree[k];
    for (k /= 2; k > 0 ; k /= 2)
        tree[k] = tree[2*k] + tree[2*k + 1];
}
