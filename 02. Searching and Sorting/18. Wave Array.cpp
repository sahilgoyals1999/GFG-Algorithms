// https://practice.geeksforgeeks.org/problems/wave-array/0
// T.C => O(n)

// a[0] >= a[1] <= a[2] >= a[3] ....
void sort_in_wave(int a[], int n) {
	// Traverse all even elements
	for (int i = 0; i < n; i += 2) {
		// If current even element is smaller than previous
		if (i > 0 && a[i - 1] > a[i] ) swap(a[i], a[i - 1]);
		// If current even element is smaller than next
		if (i + 1 < n && a[i] < a[i + 1] ) swap(a[i], a[i + 1]);
	}
}