// https://www.geeksforgeeks.org/find-whether-a-given-number-is-a-power-of-4-or-not/
// T.C => O(log())

bool isPowerOfFour(int n) {
	int count = 0;
	// Check if there is only one bit set in n
	// n&(n-1) changes rightmost 1 to 0 so it become 0 if it conatain only 1 set bit
	if (n && !(n & (n - 1))) {
		// count 0 bits before set bit
		while (n > 1) {
			n = n >> 1;    // divide by 2
			count++;
		}
		return (count % 2 == 0) ? 1 : 0;
	}
	return 0;
}