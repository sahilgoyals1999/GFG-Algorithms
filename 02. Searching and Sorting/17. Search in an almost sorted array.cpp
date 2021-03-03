// https://www.geeksforgeeks.org/search-almost-sorted-array/
// T.C => O(log(n))
// Given an array which is sorted,
// but after sorting some elements are moved to either of the adjacent positions
// i.e., arr[i] may be present at arr[i+1] or arr[i-1].

int binarySearch(int a[], int l, int r, int x) {
	if (l <= r) {
		int m = l + (r - l) / 2;
		// If the element is present at one of the middle 3 positions
		if (a[m] == x) return m;
		if (m > l && a[m - 1] == x) return (m - 1);
		if (m < r && a[m + 1] == x) return (m + 1);
		// If element is smaller than mid, then it can only be present in left subarray
		if (a[m] > x) return binarySearch(a, l, m - 2, x);
		// Else the element can only be present in right subarray
		return binarySearch(a, m + 2, r, x);
	}
// We reach here when element is not present in array
	return -1;
}