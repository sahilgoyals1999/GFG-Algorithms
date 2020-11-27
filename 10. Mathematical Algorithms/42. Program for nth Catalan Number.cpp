// https://www.geeksforgeeks.org/program-nth-catalan-number/
// T.C => O(n)

// C(0) = 1 and C(n) = (i=0 to i=n-1) C(i)*C(n-i-1) , n >= 1;
// C(n) = C(2*n,n)/(n+1)

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int r) {
	int res = 1;
	// Since C(n, k) = C(n, n-k)
	if (k > n - k) k = n - k;
	// Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

// A Binomial coefficient based function to find nth catalan number
int catalan(int n) {
	// Calculate value of 2nCn
	int c = binomialCoeff(2 * n, n);
	// return 2nCn/(n+1)
	return c / (n + 1);
}