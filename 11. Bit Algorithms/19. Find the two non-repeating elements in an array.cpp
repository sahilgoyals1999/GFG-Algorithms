// https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/
// T.C => O(n)

// function sets the values of x and y to non-repeating elements in an array a[] of size n
void get2NonRepeatingNos(int a[], int n) {
	// Will hold Xor of all elements
	int Xor = a[0];
	// Get the Xor of all elements
	for (int i = 1; i < n; ++i) {
		Xor ^= a[i];
	}
	// Will have only single set bit of Xor, Get the rightmost set bit in set_bit_no
	int set_bit_no = Xor & ~(Xor - 1);
	int x = 0, y = 0;
	// Now divide elements in two sets by comparing rightmost set bit of Xor with bit at same position in each element.
	for (int i = 0; i < n; ++i) {
		// Xor of first set
		if (a[i] & set_bit_no) {
			x = x ^ a[i];
		}
		// Xor of second set
		else {
			y = y ^ a[i];
		}
	}
	cout << x << " " << y;
}