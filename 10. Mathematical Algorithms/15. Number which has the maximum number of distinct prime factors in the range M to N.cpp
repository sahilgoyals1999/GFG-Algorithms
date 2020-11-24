// https://www.geeksforgeeks.org/number-which-has-the-maximum-number-of-distinct-prime-factors-in-range-m-to-n/
//

int maximumNumberDistinctPrimeRange(int m, int n) {
	// array to store the number of distinct primes initially 0
	vector<long long>factorCount(n + 1, 0);
	vector<bool> prime(n + 1, true); // for store primes
	for (int i = 2; i <= n; ++i) {
		// condition works only when 'i' is prime,
		// hence for factors of all prime number, the prime status is changed to false
		if (prime[i]) {
			// Number is prime, number of factor of a prime number is 1
			factorCount[i] = 1;
			for (int j = i * 2; j <= n; j += i) {
				// incrementing factorCount[j], because i is prime and i is the factor of j
				factorCount[j]++;
				// and changing prime status to false
				prime[j] = false;
			}
		}
	}
	// Initialize the max and num
	int mx = factorCount[m];
	int num = m;
	// Gets the maximum number
	for (int i = m; i <= n; i++) {
		if (factorCount[i] > mx) {
			mx = factorCount[i];
			num = i;
		}
	}
	return num;
}