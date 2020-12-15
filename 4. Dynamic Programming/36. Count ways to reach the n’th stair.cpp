// https://www.geeksforgeeks.org/count-ways-reach-nth-stair/
// T.C => O(n*m), S.C => O(n)

// Returns number of ways to reach s'th stair
int countWays(int n, int m) {
	int res[n + 1] = {};
	res[0] = 1;
	res[1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= m && j <= i; ++j) {
			res[i] += res[i - j];
		}
	}
	return res[n];
}