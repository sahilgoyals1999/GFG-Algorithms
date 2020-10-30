// https://practice.geeksforgeeks.org/problems/bubble-sort/1
// T.C => O(n^2) , S.C => O(1)
// in a phase a max number in range 0 to n-i-1 will place to the end og the array

void bubble_sort(int a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		// (n-i-1) because i+1 elemnts become place at its location
		for (int j = 0; j < n - i - 1; ++j) {
			if (a[j] > a[j + 1]) swap(&a[j], &a[j + 1]);
		}
	}
}