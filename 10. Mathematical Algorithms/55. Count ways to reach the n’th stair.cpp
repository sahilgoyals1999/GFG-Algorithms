// https://www.geeksforgeeks.org/count-ways-reach-nth-stair/
// T.C => O(n), S.C => O(1)

#define mod (long)(1e9+7)
long long countWays(int m) {
	if (m == 1) return 1;
	long a = 1;
	long b = 2;
	for (int i = 3; i <= m; ++i) {
		long c = (a % mod + b % mod) % mod;
		a = b % mod;
		b = c % mod;
	}
	return b;
}