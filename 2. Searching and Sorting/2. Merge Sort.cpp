// https://practice.geeksforgeeks.org/problems/merge-sort/1
// T.C => O(nlog(n)) , S.C => O(n)

void merge(int a[], int l, int m, int r) {
	int n1 = m - l + 1; // (l to m)
	int n2 = r - m; // (m+1 to r)
	int A[n1], B[n2];
	int k = 0;
	// split it into 2 arrays A & B
	for (int i = l; i <= m; ++i) {
		A[k++] = a[i];
	}
	k = 0;
	for (int i = m + 1; i <= r; ++i) {
		B[k++] = a[i];
	}
	// Merge them
	int i = 0, j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (A[i] < B[j]) a[k++] = A[i++];
		else a[k++] = B[j++];
	}
	while (i < n1) a[k++] = A[i++];
	while (j < n2) a[k++] = B[j++];
}

// l=0 , r=n-1;
void mergeSort(int a[], int l, int r) {
	if (l < r)   {
		int m = l + (r - l) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(arr, l, m, r);
	}
}