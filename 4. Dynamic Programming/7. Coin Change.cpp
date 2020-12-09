// https://www.geeksforgeeks.org/coin-change-dp-7/
// T.C => O(n*m), S.C => O(n)

// n => target, m => no. of coins
// dp[i] => number of solutions for value i
int count(int S[], int m, int n) {
	int dp[n + 1] = {};
	// Base case
	dp[0] = 1;
	// Pick all coins one by one and update the dp[] values the
	// index greater than or equal to the value of the picked coin
	for (int i = 0; i < m; ++i) {
		for (int j = S[i]; j <= n; ++j) {
			dp[j] += dp[j - S[i]];
		}
	}
	return dp[n];
}