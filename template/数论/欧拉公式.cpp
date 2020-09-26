inline ll phi(ll n) {
    if (n == 1) return 1;
    ll ans = n, m = sqrt(n);
    for (register ll i = 2; i <= m; i++)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if 	(n > 1) ans = ans / n * (n - 1);
    return ans;
}
