// https://practice.geeksforgeeks.org/problems/who-will-win/0
// T.C => O(log(n)) , S.C => O(1)

int binary_search(int a[], int n, int k) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == k) return 1;
		if (a[mid] > k) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}