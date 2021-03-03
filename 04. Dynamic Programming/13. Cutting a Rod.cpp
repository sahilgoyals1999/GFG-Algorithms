// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
// T.C => O(n), S.C => O(n)

// A rod of length n and price[] as prices of different pieces
int cutRod(int price[], int n) {
	int dp[n + 1];
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = INT_MIN;
		for (int j = 0; j < i; ++j) {
			dp[i] = max(dp[i], price[j] + dp[i - j - 1]);
		}
	}
	return dp[n];
}