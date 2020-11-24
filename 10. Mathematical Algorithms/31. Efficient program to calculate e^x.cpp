// https://www.geeksforgeeks.org/program-to-efficiently-calculate-ex/
// T.C => O(n)

// e^x = 1 + x/1! + x^2/2! + x^3/3! + ......
// e^x = 1 + (x/1) (1 + (x/2) (1 + (x/3) (........) ) )
// Returns approximate value of e^x using sum of first n terms of Taylor Series
// Here n is the number of terms to be consider
float exponential(int n, float x) {
	float sum = 1.0f; // initialize sum of series
	for (int i = n - 1; i > 0; --i) {
		sum = 1 + x * sum / i;
	}
	return sum;
}