// https://www.geeksforgeeks.org/find-position-of-the-only-set-bit/
// T.C => O(1)

int isPowerOfTwo(unsigned n) {
	return n && (!(n & (n - 1)));
}

int findPosition(int n) {
	if (!isPowerOfTwo(n)) return -1;
	return log2(n) + 1;
}