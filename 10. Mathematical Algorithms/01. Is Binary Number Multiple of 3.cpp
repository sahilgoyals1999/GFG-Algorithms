// https://www.geeksforgeeks.org/write-an-efficient-method-to-check-if-a-number-is-multiple-of-3/
// T.C => O(log2(n))

// if the count of set bit at even and position is divisible of 3
// then the number is also divisible of 3
int isDivisible(string s) {
	int odd = 0, even = 0;
	int n = s.length();
	for (int i = 0; i < n; i += 2) {
		if (s[i] == '1') ++even;
		if (i + 1 < n && s[i + 1] == '1') ++odd;
	}
	return abs(odd - even) % 3 == 0;
}