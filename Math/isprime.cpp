bool isprime(int x) {
    if (x % 2 == 0 && x != 2) return false;
    for (int i = 3; 1LL*i*i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

