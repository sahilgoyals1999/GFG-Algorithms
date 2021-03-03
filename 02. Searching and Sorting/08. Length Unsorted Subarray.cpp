// https://practice.geeksforgeeks.org/problems/length-unsorted-subarray3022/1
// T.C => O(n)

vector<int> printUnsorted(int a[], int n) {
	vector<int> ans(2, 0);
	int s = 0, e = n - 1;
	// Step: 1(a) find starting index(s) which is voilates the sorting order
	for (s = 0; s < n - 1; ++s) {
		if (a[s] > a[s + 1]) break;
	}
	if (s == n - 1) return ans; // array is already sorted
	// Step: 1(b) find ending index(e) which is voilates the sorting order
	for (e = n - 1; e > 0; --e) {
		if (a[e] < a[e - 1]) break;
	}
	// Step 2(a) find the max and min value between s and e
	int mx = a[s];
	int mn = a[s];
	for (int i = s + 1; i <= e; ++i) {
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	// Step 2(b) find first element which is greater than min in o to s-1
	for (int i = 0; i < s; ++i) {
		if (a[i] > mn) {
			s = i;
			break;
		}
	}
	// Step 2(c) find last element which is less than max in e+1 to n-1
	for (int i = n - 1; i >= e + 1; --i) {
		if (a[i] < mx) {
			e = i;
			break;
		}
	}
	ans[0] = s;
	ans[1] = e;
	return ans;
}