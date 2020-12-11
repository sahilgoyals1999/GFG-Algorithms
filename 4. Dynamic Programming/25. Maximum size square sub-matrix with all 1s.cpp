// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
// T.C => O(n*m), S.C => O(n*m)

#define R 6
#define C 5

void printMaxSubSquare(bool M[R][C]) {
	int dp[R][C];
	// first column
	for (int i = 0; i < R; i++) {
		dp[i][0] = M[i][0];
	}
	// first row
	for (int j = 0; j < C; ++j) {
		dp[0][j] = M[0][j];
	}
	for (int i = 1; i < R; ++i) {
		for (int j = 1; j < C; ++j) {
			if (M[i][j] == 1) dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
			else dp[i][j] = 0;
		}
	}
	// Find the maximum entry, and indexes of maximum entry in dp[][]
	int max_of_s = S[0][0]; max_i = 0; max_j = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (max_of_s < S[i][j]) {
				max_of_s = S[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	// Print
	for (int i = max_i; i > max_i - max_of_s; --i) {
		for (int j = max_j; j > max_j - max_of_s; --j) {
			cout << M[i][j] << " ";
		}
		cout << "\n";
	}
}