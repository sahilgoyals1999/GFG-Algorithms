// https://www.geeksforgeeks.org/fundamentals-of-algorithms/
// T.C => (log3(n)) , S.C = O(1)

int ternary_search(int a[], int l, int r, int k) {
	if (r >= l) {
		int x = (r - l) / 3;
		int mid1 = l + x;
		int mid2 = mid1 + x;
		if (a[mid1] == k)  return mid1;
		if (a[mid2] == k)  return mid2;
		if (a[mid1] > k) return ternary_search(a, l, mid1 - 1, k);
		if (a[mid2] < k) return ternary_search(a, mid2 + 1, r, k);
		return ternarySearch(a, mid1 + 1, mid2 - 1, k);
	}
	return -1;
}