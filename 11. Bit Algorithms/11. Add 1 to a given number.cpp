// https://www.geeksforgeeks.org/fundamentals-of-algorithms/
// T.C => O(log(n))

// flip all the bits after the rightmost 0 bit.
// Finally, flip the rightmost 0 bit also to get the answer
int addOne(int x) {
	int m = 1;
	// traverse until we find a 0
	while (x & m) {
		x = x ^ m;   // flip bit
		m = m << 1;  // multiply by 2
	}
	// flip the rightmost 0 bit
	x = x ^ m;
	return x;
}