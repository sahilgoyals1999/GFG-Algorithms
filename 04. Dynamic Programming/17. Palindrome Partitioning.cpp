// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
// T.C => O(n^2), S.C => O(n^2)

// Returns the minimum number of cuts needed to partition a string such that every part is a palindrome

/* C[i] = Minimum number of cuts needed for a palindrome partitioning of substring str[0..i]
   P[i][j] = true if substring str[i..j] is palindrome, else false
   Note that C[i] is 0 if P[0][i] is true */

int minPalPartion(string &s) {
	int n = s.length();
	int C[n];
	bool P[n][n];
	// Every substring of length 1 is a palindrome
	for (int i = 0; i < n; ++i) {
		P[i][i] = true;
	}
	// L is substring length, considering all substrings of length starting from 2 to n
	for (int L = 2; L <= n; ++L) {
		// For substring of length L, set different possible starting indexes
		for (int i = 0; i < n - L + 1; ++i) {
			int j = i + L - 1; // Set ending index
			// If L is 2, then we just need to compare two characters.
			// Else need to check two corner characters and value of P[i+1][j-1]
			if (L == 2) P[i][j] = (s[i] == s[j]);
			else P[i][j] = (s[i] == s[j]) && P[i + 1][j - 1];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (P[0][i] == true) C[i] = 0;
		else {
			C[i] = INT_MAX;
			for (int j = 0; j < i; ++j) {
				if (P[j + 1][i] == true && 1 + C[j] < C[i]) C[i] = 1 + C[j];
			}
		}
	}
	// Return the min cut value for complete string. i.e., str[0..n-1]
	return C[n - 1];
}