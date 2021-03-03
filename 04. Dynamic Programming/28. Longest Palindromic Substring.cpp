// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
// T.C => O(), S.C => O()

// dp[i][j] => substring str[i..j] is palindrome or not
// prints the longest palindrome substring also returns the length of the longest palindrome
int longestPalSubstr(string s) {
	int n = s.length();
	int ans = 1, start = -1;
	bool dp[n][n] = {};
	// All substrings of length 1 are palindromes
	for (int i = 0; i < n; ++i) {
		dp[i][i] = true;
	}
	// check for sub-string of length 2.
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = true;
			ans = 2;
			if (start == -1) {
				start = i;
			}
		}
	}
	// Check for lengths greater than 2, L is length of substring
	for (int L = 3; L <= n; ++L) {
		// Fix the starting index
		for (int i = 0; i < n - L + 1; ++i) {
			// Get the ending index of substring from starting index i and length L
			int j = i + L - 1;
			// checking for sub-string from ith index to jth index iff str[i+1] to str[j-1] is a palindrome
			if (dp[i + 1][j - 1] && s[i] == s[j]) {
				dp[i][j] = true;
				if (L > ans) {
					start = i;
					ans = L;
				}
			}
		}
	}
	if (start == -1) start = 0;
	// print
	// for (int i = start; i < start + ans; ++i) {
	// 	cout << s[i];
	// }
	return ans;
}