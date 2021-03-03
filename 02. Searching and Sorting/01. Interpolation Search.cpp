// https://www.geeksforgeeks.org/interpolation-search/
// T.C => if elements are uniformally distributed => O(log(log(n))) else O(n) , S.C => O(1)
// if the numbers are repeated it gives the left most position

int interpolation_search(int a[], int n, int k) {
	int left = 0, right = (n - 1);
	while (left <= right && k >= a[left] && k <= a[right]) {
		if (left == right) {
			if (a[left] == k) return left;
			return -1;
		}
		int pos = left + (((double)(right - left) / (a[right] - a[left])) * (k - a[left]));
		if (a[pos] == k) return pos;
		if (a[pos] < k) left = pos + 1;
		else right = pos - 1;
	}
	return -1;
}