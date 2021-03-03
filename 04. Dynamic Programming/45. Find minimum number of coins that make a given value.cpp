// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1

// T.C => O(n*v), S.C => O(v)

int minCoins(int coins[], int n, int v) {
	vector<long> dp(v + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = coins[i]; j <= v; ++j) {
			dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
		}
	}
	return dp[v] == INT_MAX ? -1 : dp[v];
}