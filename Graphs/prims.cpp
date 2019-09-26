vector< pair<int, int> > G[N];//vertex, weight
int used[N];

ll prim(int v) {
	priority_queue< pair<int, int> > pq;//weight, vertex
	used[v] = 1;
	for (int i = 0; i < G[v].size(); i++)
		pq.push({-G[v][i].S, G[v][i].F});
	int c = 0;
	ll ans = 0;
	while (!pq.empty()) {
		if (used[pq.top().S]) {
			pq.pop();
			continue;
		}
		int w = -pq.top().F, to = pq.top().S;
		used[to] = 1;
		ans += w;
		for (int i = 0; i < G[to].size(); i++) {
			if (!used[G[to][i].F]) {
				pq.push({-G[to][i].S, G[to][i].F});
			}
		}
	}
	return ans;
}

