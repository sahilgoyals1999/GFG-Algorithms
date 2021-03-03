// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// T.C => O(n^3), S.C => O(n*n)

/* dp[i, j] = Minimum number of scala multiplications needed
    to compute the matrix A[i]A[i+1]...A[j] = A[i..j] */

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int n) {
	int dp[n][n];
	// cost is zero when multiplying one matrix.
	for (int i = 1; i < n; ++i) {
		dp[i][i] = 0;
	}
	// L is chain length.
	for (int L = 2; L < n; ++L) {
		for (int i = 1; i < n - L + 1; ++i) {
			int j = i + L - 1;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; ++k) {
				// q = cost/scalar multiplications
				int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < dp[i][j]) dp[i][j] = q;
			}
		}
	}
	return dp[1][n - 1];
}