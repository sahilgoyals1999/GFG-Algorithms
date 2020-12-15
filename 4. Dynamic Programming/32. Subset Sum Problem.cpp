// https://www.geeksforgeeks.org/subset-sum-problem-osum-space/
// T.C => O(n^2), S.C => O(sum)

// dp[i%2][j] will be true if there exists a subset of sum j in a[0, 1, ...., i-1]

bool isSubsetSum(int a[], int n, int sum) {
	bool dp[2][sum + 1];
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= sum; ++j) {
			// A subset with sum 0 is always possible
			if (j == 0) dp[i % 2][j] = true;
			// If there exists no element no sum is possible
			else if (i == 0) dp[i % 2][j] = false;
			else if (a[i - 1] <= j) dp[i % 2][j] = dp[(i + 1) % 2][j - a[i - 1]] || dp[(i + 1) % 2][j];
			else dp[i % 2][j] = dp[(i + 1) % 2][j];
		}
	}
	return dp[n % 2][sum];
}