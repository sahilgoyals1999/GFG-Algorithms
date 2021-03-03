// https://www.geeksforgeeks.org/minimum-adjacent-swaps-to-move-maximum-and-minimum-to-corners/
// T.C => O(n)

void solve(int a[], int n) {
	int mx = a[0], mn = a[0], l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		// Index of leftmost largest element
		if (a[i] > mx) {
			mx = a[i];
			l = i;
		}
		// Index of rightmost smallest element
		if (a[i] <= mn) {
			mn = a[i];
			r = i;
		}
	}
	if (r < l) cout << l + (n - r - 2);
	else cout << l + (n - r - 1);
}