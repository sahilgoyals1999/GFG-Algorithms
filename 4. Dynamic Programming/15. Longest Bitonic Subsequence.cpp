// https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
// T.C => O(n^2), S.C => O(n)

/* lbs() returns the length of the Longest Bitonic Subsequence in a[] of size n.
    The function mainly creates two temporary arrays
    lis[] and lds[] and returns the maximum lis[i] + lds[i] - 1.
    lis[i] ==> Longest Increasing subsequence ending with a[i]
    lds[i] ==> Longest decreasing subsequence starting with a[i] */

int lbs(int a[], int n) {
	int lis[n], lds[n];
	// Compute LIS values from left to right
	for (int i = 0; i < n; ++i) {
		lis[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i] && lis[i] < lis[j] + 1) lis[i] = lis[j] + 1;
		}
	}
	// Compute LDS values from right to left
	for (int i = n - 1; i >= 0; --i) {
		lds[i] = 1;
		for (int j = n - 1; j > i; --j) {
			if (a[i] > a[j] && lds[i] < lds[j] + 1) lds[i] = lds[j] + 1;
		}
	}
	// Return the maximum value of lis[i] + lds[i] - 1
	int ans = lis[0] + lds[0] - 1;
	for (int i = 1; i < n; ++i) {
		if (lis[i] + lds[i] - 1 > ans) ans = lis[i] + lds[i] - 1;
	}
	return ans;
}