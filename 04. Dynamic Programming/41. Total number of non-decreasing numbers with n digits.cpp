// https://www.geeksforgeeks.org/total-number-of-non-decreasing-numbers-with-n-digits/
// T.C => O(10*10*n), S.C => O(10*n)

// dp[i][j] => count of non decreasing numbers ending with digit i and of length j
long long countNonDecreasing(int n) {
	long long dp[10][n + 1] = {};
	// Fill table for non decreasing numbers of length 1
	// Base cases 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	for (int i = 0; i < 10; ++i) {
		dp[i][1] = 1;
	}
	for (int digit = 0; digit <= 9; ++digit) {
		// Compute total numbers of non decreasing numbers of length 'len'
		for (int len = 2; len <= n; ++len) {
			// sum of all numbers of length of len-1 in which last digit x is <= 'digit'
			for (int x = 0; x <= digit; ++x) {
				dp[digit][len] += dp[x][len - 1];
			}
		}
	}
	long long count = 0;
	// There total nondecreasing numbers of length n
	// will be dp[0][n] +  dp[1][n] ..+ dp[9][n]
	for (int i = 0; i < 10; ++i++) {
		count += dp[i][n];
	}
	return count;
}
