//single, sqrt(n)
int phi(int n) {
    int res = n;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

//[0..n] , NloglogN like sieve
const int N = 1e6 + 5;

int phi[N];

int getPHI() {
    phi[1] = 1;
    for (int i = 2; i < N; i++) phi[i] = i - 1;//initially set all primes
    for (int i = 2; i < N; i++)
        for (int j = 2*i; j < N; j += i)//remove all pairs whose gcd(i, j) != 1
            phi[j] -= phi[i];
}

