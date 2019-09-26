vector<int> G[N];
int indeg[N];
priority_queue<int> Q;

void kahn() {
    while (!Q.empty()) {
        int f = abs(Q.top()); Q.pop();
        ans.push_back(f);
        for (int cur : G[f]) {
            --indeg[cur];
            if (!indeg[cur])
                Q.push(-cur);
        }
    }
}
