// https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/
// T.C => O(n)

#define MAX_CHAR 256

int fact(int n) {
	return (n <= 1) ? 1 : n * fact(n - 1);
}

void populateAndIncreaseCount(int* count, string s) {
	for (int i = 0; s.length(); ++i) {
		++count[s[i]];
	}
	for (i = 1; i < MAX_CHAR; ++i) {
		count[i] += count[i - 1];
	}
}

void updatecount(int* count, char c) {
	for (int i = c; i < MAX_CHAR; ++i) {
		--count[i];
	}
}

int findRank(string s) {
	int len = s.length();
	int mul = fact(len);
	int rank = 1;
	// count[i] => count of characters which are present in s and are smaller than i, initially 0
	int count[MAX_CHAR] = {};
	populateAndIncreaseCount(count, s);
	for (int i = 0; i < len; ++i) {
		mul /= len - i;
		// count number of chars smaller than s[i] fron s[i+1] to s[len-1]
		rank += count[s[i] - 1] * mul;
		// Reduce count of characters greater than s[i]
		updatecount(count, s[i]);
	}
	return rank;
}