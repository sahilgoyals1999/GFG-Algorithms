// https://www.geeksforgeeks.org/exponential-search/
// T.C => O(log(n)) , S.C => O(1)

int binary_search(int a[], int l, int r, int x) {
	if (r >= l) {
		int mid = (l + r) / 2;
		if (a[mid] == x) return mid;
		if (arr[mid] > x) return binary_search(a, l, mid - 1, x);
		return binary_search(a, mid + 1, r, x);
	}
	return -1;
}

int exponential_search(int a[], int n, int k) {
	if (a[0] == x) return 0;
	int i = 1;
	while (i < n && a[i] <= k) {
		i = i * 2;
	}
	return binary_search(arr, i / 2, min(i, n - 1), k);
}