const long long mod = 1000000007;

long long binexp(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<long long> fact;

void init_fact(int n) {
    fact.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    long long num = fact[n];
    long long den = fact[r] * fact[n - r] % mod;
    return num * binexp(den, mod - 2) % mod;
}