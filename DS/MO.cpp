const int N;
const int MAXN;

struct query {
	int l, r, ix;
	bool operator<(const query &rhs) {
		if(l/bz != rhs.l/bz) {
			return l/bz < rhs.l/bz;
		}
		return r < rhs.r;
	}
} Q[N];

void add(int x) {
    //add element at x to the current solution
}

void rem(int x) {
    //remove element at x from the current solution
}

int main() {
    sort(Q, Q + t);
    int l = 1, r = 0;
    for (int i = 0; i < t; i++) {
        while (r < Q[i].r) add(ar[++r]);
        while (r > Q[i].r) rem(ar[r--]);
        while (l < Q[i].l) rem(ar[l++]);
        while (l > Q[i].l) add(ar[--l]);
        ans[Q[i].idx] = cur;
    }
}
