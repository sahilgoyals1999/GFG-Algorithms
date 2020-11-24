// https://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient/
// T.C => O(r)

// C(n, r) == C(n, n-r) if r > n-r

int binomialCoeff(int n, int r) {
	int ans = 1;
	if (r > n - r) r = n - r;
	// Calculate value of [n * (n-1) *---* (n-r+1)] / [r * (r-1) *----* 1]
	for (int i = 0; i < r; ++i) {
		ans *= (n - i);
		ans /= (i + 1);
	}
	return ans;
}