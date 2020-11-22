// https://www.geeksforgeeks.org/count-numbers-that-dont-contain-3/
//

int count(int n) {
	if (n < 3) return n;
	if (n >= 3 && n < 10) return n - 1;
	// Calculate 10^(d-1) (10 raise to the power (d-1) where d is
	// number of digits in n. po will be 100 for n = 578
	int po = 1, nn = n;
	while (nn > 9) {
		po = po * 10;
		nn /= 10;
	}
	// find the most significant digit (msd is 5 for 578)
	int msd = nn;
	// For 578, total will be 4*count(10^2 - 1) + 4 + count(78)
	if (msd != 3) return count(msd) * count(po - 1) + count(msd) + count(n % po);
	// For 35, total will be equal to count(29)
	else return count(msd * po - 1);
}