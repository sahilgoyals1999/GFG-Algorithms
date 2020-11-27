// https://www.geeksforgeeks.org/find-smallest-number-whose-digits-multiply-given-number-n/
// T.C => O(n)

// prints the smallest number whose digits multiply to n
void findSmallest(int n) {
	int i, j = 0;
	// To store digits of result in reverse order
	int res[MAX];
	// Case 1: If number is smaller than 10
	if (n < 10) {
		cout << n + 10;
		return;
	}
	// Case 2: Start with 9 and try every possible digit
	for (i = 9; i > 1; --i) {
		// If current digit divides n, then store all occurrences of current digit in res
		while (n % i == 0) {
			res[j] = i;
			n = n / i;
			++j;
		}
	}
	// If n could not be broken in form of digits (prime factors of n are greater than 9)
	if (n > 10) {
		cout << "Not possible";
		return;
	}
	// Print the result array in reverse order
	for (i = j - 1; i >= 0; --i) {
		cout << res[i];
	}
}