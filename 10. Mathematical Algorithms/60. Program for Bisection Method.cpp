// https://www.geeksforgeeks.org/program-for-bisection-method/
// T.C => O()

#define EPSILON 0.01

// An example function whose solution is determined using Bisection Method.
// The function is x^3 - x^2  + 2
double func(double x) {
	return x * x * x - x * x + 2;
}

// Prints root of func(x) with error of EPSILON
void bisection(double a, double b) {
	if (func(a) * func(b) >= 0) {
		cout << "Wrong Input\n";
		return;
	}
	double c = a;
	while ((b - a) >= EPSILON) {
		// Find middle point
		c = (a + b) / 2;
		// Check if middle point is root
		if (func(c) == 0.0) break;
		// Decide the side to repeat the steps
		else if (func(a) * func(c) < 0) b = c; // Left Side
		else a = c;                            // Right Side
	}
	cout << "The value of root is : " << c;
}