// https://www.geeksforgeeks.org/horners-method-polynomial-evaluation/
// T.C => O(n)

// Evaluate value of polynomial using Horner's method
// 2x3 – 6x2 + 2x – 1 => ((2x – 6)x + 2)x – 1
int horner(int poly[], int n, int x) {
	int result = poly[0];  // Initialize result
	for (int i = 1; i < n; ++i) {
		result = result * x + poly[i];
	}
	return result;
}