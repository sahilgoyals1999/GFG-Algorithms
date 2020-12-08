// https://www.geeksforgeeks.org/rotate-bits-of-an-integer/
// T.C => O(1)

#define INT_BITS 32

// Function to left rotate n by d bits
int leftRotate(int n, unsigned int d) {
	/* In n<<d, last d bits are 0.
	To put first d bits of n at
	last, do bitwise or of n<<d
	with n >> (INT_BITS - d) */
	return (n << d) | (n >> (INT_BITS - d));
}

/*Function to right rotate n by d bits*/
int rightRotate(int n, unsigned int d) {
	/* In n>>d, first d bits are 0.
	To put last d bits of at
	first, do bitwise or of n>>d
	with n << (INT_BITS - d) */
	return (n >> d) | (n << (INT_BITS - d));
}