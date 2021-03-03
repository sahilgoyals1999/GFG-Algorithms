// https://www.geeksforgeeks.org/partition-problem-dp-18/
// T.C => O(n*target),  S.C => O(target)

// Returns true if a[] can be partitioned in two subsets of equal sum, otherwise false
bool findPartiion(int a[], int n) {
	int sum = 0;
	// Calculate sum of all elements
	for (int i = 0; i < n; ++i) {
		sum += a[i];
	}
	if (sum % 2 != 0) return false;
	int target = sum / 2;
	bool dp[target + 1];
	for (int i = 0; i <= target; ++i) {
		dp[i] = false;
	}
	for (int i = 0; i < n; ++i) {
		// the element to be included in the sum cannot be greater than the sum
		for (int j = target; j >= a[i]; --j) {
			// check if sum - a[i] could be formed from a subset using elements before index i
			if (dp[j - a[i]] == 1 || j == a[i]) dp[j] = 1;
		}
	}
	return dp[target];
}