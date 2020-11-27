// https://www.geeksforgeeks.org/print-first-k-digits-1n-n-positive-integer/
// T.C => O(k)

void print(int n, int k) {
	int rem = 1; // Initialize remainder
	// Run a loop k times to print k digits
	for (int i = 0; i < k; ++i) {
		// The next digit can always be obtained as doing (10*rem)/10
		rem *= 10;
		cout << rem / n;
		// Update remainder
		rem = rem % n;
	}
}