//compute modular inverses [1...M] in O(M) time
void inverses() {
    inv[1] = 1;
    for (int i = 2; i < M; i++)
        inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
}
