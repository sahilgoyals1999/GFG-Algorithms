// https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
// T.C => O(log(n))

int setBits(int x) {
	int ans = 0;
	while (x > 0) {
		ans += (x & 1);
		x >>= 1;
	}
	return ans;
}