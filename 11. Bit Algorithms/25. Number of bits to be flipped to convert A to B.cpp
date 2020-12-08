// https://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/
// T.C => O(log(n))

// a^b contains all diff set bits
int countBitsFlip(int a, int b) {
	int x = a ^ b, ans = 0;
	while (x > 0) {
		ans += (x & 1);
		x >>= 1;
	}
	return ans;
}