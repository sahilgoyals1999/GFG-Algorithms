// https://www.geeksforgeeks.org/program-add-two-polynomials/
// T.C => O(n+m)

int *add(int A[], int B[], int m, int n) {
	int size = max(m, n);
	int *sum = new int[size];
	// Initialize the porduct polynomial
	for (int i = 0; i < m; ++i) {
		sum[i] = A[i];
	}
	// Take ever term of first polynomial
	for (int i = 0; i < n; ++i) {
		sum[i] += B[i];
	}
	return sum;
}