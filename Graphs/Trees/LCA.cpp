#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 5;


int n, sz;

vector<int> G[N];
int F[N], H[N];
vector<int> tour, st;

void euler(int u, int p, int d) {
    F[u] = tour.size();
    H[u] = d;
    tour.push_back(u);
    for (int v : G[u]) {
        if (v == p) continue;
        euler(v, u, d + 1);
        tour.push_back(u);
    }
}

void build() {
    sz = tour.size();
    st.resize(3 * sz);
    for (int i = 0; i < sz; i++) st[i + sz] = tour[i];
    for (int i = sz-1; i >= 1; i--) {
        int tl = 2*i, tr = tl + 1;
        st[i] = H[st[tl]] < H[st[tr]] ? st[tl] : st[tr];
    }
}

int query(int l, int r) {
    l = F[l] + sz, r = F[r] + sz;
    if (r < l) swap(l, r);
    int ans = 0;
    while (l <= r) {
        if (l%2 == 1) {
            ans = H[ans] < H[st[l]] ? ans : st[l];
            l++;
        }
        if (r%2 == 0) {
            ans = H[ans] < H[st[r]] ? ans : st[r];
            r--;
        }
        l /= 2, r /= 2;
    }
    return ans;
}

void lca(int rt) {
    H[0] = inf;
    euler(rt, -1, 1);
    build();
}

int main() {
    ifstream in("emaxx-eng-lca-example.txt");
    in >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        in >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    lca(1);
    
    for (int i = 0; i < int(tour.size()); i++) {
        cout << tour[i] << " ";
    } cout << endl;
    for (int i = 0; i < int(tour.size()); i++) {
        cout << H[tour[i]] << " ";
    } cout << endl;
    
    cout << "\n\n\nQUERIES:\n\n\n";
    in.close();
    while (1) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
    return 0;
}
