// https://www.geeksforgeeks.org/multiply-two-polynomials-2/
// T.C => O(n^2)

int multiply(int A[], int B[], int m, int n) {
	int prod[m + n + 1] = {};
	// Take ever term of first polynomial
	for (int i = 0; i < m; ++i) {
		// Multiply the current term of first polynomial with every term of second polynomial.
		for (int j = 0; j < n; ++j) prod[i + j] += (A[i] * B[j]);
	}
	for (int i = 0; i < m + n + 1; ++i) {
		cout << prod[i] << " ";
	}
}