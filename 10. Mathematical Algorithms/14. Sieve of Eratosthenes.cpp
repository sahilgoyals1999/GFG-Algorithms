// https://www.geeksforgeeks.org/sieve-of-eratosthenes/
// T.C => O(n * log(log(n)))

vector<int> sieveOfEratosthenes(int n) {
	vector<int> ans;
	vector<bool> pp(n + 1, true);
	for (int i = 2; i * i <= n; ++i) {
		if (pp[i]) {
			for (int j = i * i; j <= n; j += i) {
				pp[j] = false;
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (pp[i]) ans.push_back(i);
	}
	return ans;
}