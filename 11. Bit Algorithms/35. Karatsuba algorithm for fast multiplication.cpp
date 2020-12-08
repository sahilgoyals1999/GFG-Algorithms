// https://www.geeksforgeeks.org/karatsuba-algorithm-for-fast-multiplication-using-divide-and-conquer-algorithm/
// T.C => O(n^log2(3))

int makeEqualLength(string &s, string &t) {
	int l1 = s.length();
	int l2 = t.length();
	if (l1 < l2) {
		for (int i = 0 ; i < l2 - l1 ; ++i) {
			s = '0' + s;
		}
		return l2;
	}
	else if (l1 > l2) {
		for (int i = 0 ; i < l1 - l2 ; ++i) {
			t = '0' + t;
		}
	}
	return l1;
}

// The main function that adds two bit sequences and returns the addition
string addBitStrings(string first, string second) {
	string ans;  // To store the sum bits
	// make the lengths same before adding
	int length = makeEqualLength(first, second);
	int carry = 0;  // Initialize carry
	// Add all bits one by one
	for (int i = length - 1 ; i >= 0 ; --i) {
		int firstBit = first[i] - '0';
		int secondBit = second[i] - '0';
		// boolean expression for sum of 3 bits
		int sum = (firstBit ^ secondBit ^ carry) + '0';
		ans = (char)sum + ans;
		// boolean expression for 3-bit addition
		carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
	}
	// if overflow, then add a leading 1
	if (carry)  ans = '1' + ans;
	return ans;
}

// A utility function to multiply single bits of strings a and b
int multiplyiSingleBit(string a, string b) {
	return (a[0] - '0') * (b[0] - '0');
}

// The main function that multiplies two bit strings X and Y and returns result as long integer
long multiply(string X, string Y) {
	// Find the maximum of lengths of x and Y and make length of smaller string same as that of larger string
	int n = makeEqualLength(X, Y);
	// Base cases
	if (n == 0) return 0;
	if (n == 1) return multiplyiSingleBit(X, Y);
	int fh = n / 2;  // First half of string, floor(n/2)
	int sh = (n - fh); // Second half of string, ceil(n/2)
	// Find the first half and second half of first string.
	string Xl = X.substr(0, fh);
	string Xr = X.substr(fh, sh);
	// Find the first half and second half of second string
	string Yl = Y.substr(0, fh);
	string Yr = Y.substr(fh, sh);
	// Recursively calculate the three products of inputs of size n/2
	long P1 = multiply(Xl, Yl);
	long P2 = multiply(Xr, Yr);
	long P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));
	// Combine the three products to get the final result.
	return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}

long karatsubaAlgo(string A, string B) {
	return multiply(A, B);
}