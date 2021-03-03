// https://practice.geeksforgeeks.org/problems/searching-a-number0324/1
// T.C => O(n) , S.C => O(1)
int search(int a[], int n, int k) {
	for (int i = 0; i < n; ++i) {
		if (a[i] == k) return i + 1;
	}
	return -1;
}