// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
// T.C => O(n^2), S.C => O(n)

// dp[i] => max length of LIS ending at ith postion
int LIS(int a[n], int n) {
	int dp[n], ans = 0;
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], 1 + dp[j]);
				ans = max(ans, dp[i]);
			}
		}
	}
	return ans;
}