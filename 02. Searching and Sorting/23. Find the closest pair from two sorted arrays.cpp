// https://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/
// T.C => O(n + m)

// a1[0..n-1] and a2[0..m-1] are two given sorted arrays and x is given number.
// find the pair from both arrays such that the sum of the pair is closest to x.
void printClosest(int a1[], int a2[], int n, int m, int x) {
	// Initialize the diff between pair sum and x.
	int diff = INT_MAX;
	int res_l, res_r;
	// Start from left side of a1[] and right side of a2[]
	int l = 0, r = m - 1;
	while (l < n && r >= 0) {
		int sum = a1[l] + a2[r];
		if (abs(sum - x) < diff) {
			res_l = l;
			res_r = r;
			diff = abs(sum - x);
		}
		// if sum is greater than x if we decrease the sum to move left of a2[]
		if (sum > x) --r;
		// else increase the sum to move right of a1[]
		else ++l;
	}
	cout << a1[res_l] << " " << a2[res_r];
}