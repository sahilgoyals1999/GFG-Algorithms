// https://www.geeksforgeeks.org/how-to-turn-off-a-particular-bit-in-a-number/
// T.C => O(1)

// 1-based indexing
// 1 << (k-1) gives a number in which kth bit is 1 and other are 0
// its negation gives a number in which kth bit is 0 and other are 1
int turnOffK(int n, int k) {
	// k must be greater than 0
	if (k <= 0) return n;
	// Do & of n with a number with all set bits except the k'th bit
	return (n & ~(1 << (k - 1)));
}