// https://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/
// T.C => O(log(n))

// 32-bit integer
// (x&1) check for last bit is 1 ot not
long long reversedBits(long long x) {
	long long ans = 0;
	int pow = 31;
	while (x > 0) {
		ans += ((x & 1) << pow);
		--pow;
		x >>= 1;
	}
	return ans;
}