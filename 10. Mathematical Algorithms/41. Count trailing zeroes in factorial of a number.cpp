// https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
//

// Function to return trailing 0s in factorial of n
int findTrailingZeros(int n) {
	int count = 0;
	// Keep dividing n by powers of 5 and update count
	for (int i = 5; n / i >= 1; i *= 5) {
		count += (n / i);
	}
	return count;
}