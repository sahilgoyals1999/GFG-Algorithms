// https://practice.geeksforgeeks.org/problems/insertion-sort/1
// T.C => O(n^2) , S.C => O(1)

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void insert(int a[], int i) {
	int j = i - 1;
	while (j >= 0 && a[j] > a[j + 1]) {
		swap(a[j], a[j + 1]);
		--j;
	}
}

void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		insert(a, i);
	}
}