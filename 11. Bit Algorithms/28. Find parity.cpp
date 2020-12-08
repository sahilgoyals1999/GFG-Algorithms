// https://www.geeksforgeeks.org/program-to-find-parity/
// T.C => O(log(n))

/* Function to get parity of number n. It returns 1
   if n has odd parity, and returns 0 if n has even parity */
bool getParity(unsigned int n) {
	bool parity = 0;
	while (n) {
		parity = !parity;
		n = n & (n - 1);
	}
	return parity;
}