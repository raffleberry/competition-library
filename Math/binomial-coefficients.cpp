//compute modular inverses [1...M] in O(M) time
void inverses() {
    inv[1] = 1;
    for (int i = 2; i < M; i++)
        inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
}

const int N = 100;

ll ncr[N+1][N+1];

void calc() {
  for (int i = 1; i <= N; i++) {
    ncr[i][0] = ncr[i][i] = 1;
    for (int j = 1; j < i; j++) {
      ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
    }
  }
}
