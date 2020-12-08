// https://www.geeksforgeeks.org/compute-modulus-division-by-a-power-of-2-number/
// T.C => O(1)

// This function will return n % d. d must be one of: 1, 2, 4, 8, 16, 32, …
unsigned int getModulo(unsigned int n, unsigned int d) {
	return (n & (d - 1));
}