// https://www.geeksforgeeks.org/counting-inversions/
// T.C => O(n) using Merge Sort
// Inversion Count => find all pairs where a[i] > a[j] when i < j

int merge(int a[], int temp[], int l, int m, int r) {
	int count = 0;
	int i = l, j = m, k = l;
	while (i <= m - 1 && j <= r) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		// a[i] > a[j] so it contribute to count and
		// (m-i) because number of less element is (m-i)
		else {
			temp[k++] = a[j++];
			count += (m - i);
		}
	}
	while (i <= m - 1) {
		temp[k++] = a[i++];
	}
	while (j <= r) {
		temp[k++] = a[j++];
	}
	for (int i = l; i <= r; ++i) {
		a[i] = temp[i];
	}
	return count;
}

int merge_sort(int a[], int temp[], int l, int r) {
	int inv_count = 0;
	if (l < r) {
		int m = l + (r - l) / 2;
		inv_count += merge_sort(a, temp, l, m);    // from left side
		inv_count += merge_sort(a, temp, m + 1, r); // from right side
		inv_count += merge(a, temp, l, m + 1, r);  // merging
	}
	return inv_count;
}

int inversionCount(int a[], int n) {
	int temp[n]; // for store updated sorted array
	return merge_sort(a, temp, 0, n - 1);
}