// https://www.geeksforgeeks.org/replace-0-5-input-integer/
// T.C => O(log(n))

// Returns the number to be added to the input to replace all zeroes with five
int calculateAddedValue(int n) {
	// Amount to be added
	int res = 0;
	// Unit decimal place
	int d = 1;
	if (n == 0) {
		res += (5 * d);
	}
	while (n > 0) {
		if (n % 10 == 0) {
			// A number divisible by 10, then this is a zero occurrence in the input
			res += (5 * d);
		}
		// Move one decimal place
		n /= 10;
		d *= 10;
	}
	return res;
}

int replace0with5(int n) {
	return n += calculateAddedValue(n);
}