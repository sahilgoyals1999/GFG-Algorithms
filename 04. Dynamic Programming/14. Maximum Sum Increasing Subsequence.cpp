// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
// T.C => O(n^2), S.C => O(n)

// returns the maximum sum of increasing subsequence in a[] of size n
int maxSumIS(int a[], int n) {
	int dp[n];
	for (int i = 0; i < n; ++i) {
		dp[i] = a[i];
		for (int j = 0; j < i; ++j) {
			if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
		}
	}
	return *max_element(dp, dp + n);
}