// https://practice.geeksforgeeks.org/problems/quick-sort/1
// T.C => for worst case => O(n^2) otherwise O(n*log(n))

int partition (int a[], int low, int high) {
	int pivot = a[high];                    // pivot
	int i = (low - 1);                      // Index of smaller element
	for (int j = low; j <= high - 1; ++j) {
		if (a[j] < pivot) {                 // If current element is smaller than the pivot
			++i;                            // increment index of smaller element
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[high]);
	return (i + 1);
}

void quickSort(int a[], int low, int high) {
	if (low < high) {
		// pi is partitioning index, a[p] is now at right place
		int pi = partition(a, low, high);
		// Separately sort elements before / partition and after partition
		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}