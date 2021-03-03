// https://practice.geeksforgeeks.org/problems/selection-sort/1
// T.C => O(n^2) , S.C => O(1)

void selection_sort(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		int min_idx = i;
		// Finding min value index in (i+1) to (n-1)
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[min_idx]) min_idx = j;
		}
		// swap it with a[i]
		swap(&a[i], &a[min_idx]);
	}
}