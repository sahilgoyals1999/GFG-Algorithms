// https://www.geeksforgeeks.org/smallest-power-of-2-greater-than-or-equal-to-n/
// T.C => O(log(n))

long long nearestPowerOf2(long long n) {
	long long ans = 1;
	// for only 1 set bit numbers like 1, 2, 4, 8 ...
	if (n && !(n & (n - 1))) return n;
	while (ans < n) {
		ans <<= 1;
	}
	return ans;
}