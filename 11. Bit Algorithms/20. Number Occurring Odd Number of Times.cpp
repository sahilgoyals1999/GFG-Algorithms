// https://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/
// T.C => O(n)

int getOddOccurrence(int a[], int n) {
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = ans ^ a[i];
	}
	return ans;
}