// https://www.geeksforgeeks.org/check-number-fibonacci-number/
// T.C => O(1)

// any one of these or both (5*(n^2) + 4) , (5*(n^2) – 4) is perfect square
// then it is fibonacci number else no

bool isPerfectSquare(int x) {
	int s = sqrt(x);
	return (s * s == x);
}

bool isFibonacci(int n) {
	// n is Fibinacci if one of 5*n*n + 4 or 5*n*n - 4 or both is a perferct square
	return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}