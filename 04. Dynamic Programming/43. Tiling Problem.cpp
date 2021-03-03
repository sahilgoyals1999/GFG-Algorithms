// https://www.geeksforgeeks.org/tiling-problem/
// T.C => O(log(n)), S.C => O(1)

// Same as n-th Fibonacci Number
// count(n) = n if n = 1 or n = 2
// count(n) = count(n-1) + count(n-2)

#define ll long long
#define mod (long long)(1e9+7)

void multiply(ll F[2][2], ll M[2][2]) {
	ll x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % mod;
	ll y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % mod;
	ll z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % mod;
	ll w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % mod;
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(ll F[2][2], ll n) {
	if (n == 0 || n == 1) return;
	ll M[2][2] = {{1, 1}, {1, 0}};
	power(F, n / 2);
	multiply(F, F);
	if (n % 2 != 0) multiply(F, M);
}

ll fib(ll n) {
	if (n == 0) return 0;
	ll F[2][2] = {{1, 1}, {1, 0}};
	power(F, n - 1);
	return F[0][0];
}

ll numberOfWays(ll n) {
	return fib(n + 1);
}