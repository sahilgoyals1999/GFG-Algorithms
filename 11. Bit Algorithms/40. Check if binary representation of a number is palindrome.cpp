// https://www.geeksforgeeks.org/check-binary-representation-number-palindrome/
// T.C => O(log(n)/2)

// This function returns true if k'th bit in x is set or not
bool isKthBitSet(long long x, int k) {
	return (x & (1 << (k - 1))) ? true : false;
}

// This function returns true if binary representation of x is palindrome.
int isPallindrome(long long x) {
	int l = 1;                        // Initialize left position
	int r = log2(x) + 1;              // initialize right position
	// One by one compare bits
	while (l < r) {
		if (isKthBitSet(x, l) != isKthBitSet(x, r)) return 0;
		l++;
		r--;
	}
	return 1;
}