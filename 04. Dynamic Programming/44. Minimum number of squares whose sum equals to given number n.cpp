// https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/
// T.C => O(n*sqrt(n)), S.C => O(n)

// dp[i] => min count for number i
// Returns count of minimum squares that sum to n
int getMinSquares(int n) {
	if (n <= 3) return n;
	int dp[n + 1];
	// Base Case
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	// getMinSquares rest of the table using recursive formula
	for (int i = 4; i <= n; ++i) {
		// max value is i as i can always be represented as 1*1 + 1*1 + ...
		dp[i] = i;
		// Go through all smaller numbers to recursively find minimum
		for (int x = 1; x <= ceil(sqrt(i)); ++x) {
			int temp = x * x;
			if (temp > i) break;
			else dp[i] = min(dp[i], 1 + dp[i - temp]);
		}
	}
	return dp[n];
}