// https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
// T.C => O(n*k), S.C => O(k)

// C(n, k) => PASCALS TRAINGLE[n][k]
int binomialCoeff(int n, int k) {
	int dp[k + 1] = {};
	dp[0] = 1;  // nC0 is 1
	for (int i = 1; i <= n; ++i) {
		// Compute next row of pascal triangle using the previous row
		for (int j = min(i, k); j > 0; --j) {
			dp[j] += dp[j - 1];
		}
	}
	return dp[k];
}