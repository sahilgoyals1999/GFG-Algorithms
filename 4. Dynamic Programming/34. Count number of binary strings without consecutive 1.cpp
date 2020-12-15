// https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
// T.C => O(n), S.C => O(n)

// a[i] => binary strings of length i which do not contain any two consecutive 1’s and which end in 0.
// Similarly, b[i] be the number of such strings which end in 1

int countStrings(int n) {
	int a[n], b[n];
	a[0] = b[0] = 1;
	for (int i = 1; i < n; ++i) {
		a[i] = a[i - 1] + b[i - 1];
		b[i] = a[i - 1];
	}
	return a[n - 1] + b[n - 1];
}