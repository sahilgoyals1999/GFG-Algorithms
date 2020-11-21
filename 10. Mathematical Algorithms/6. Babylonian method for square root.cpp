// https://www.geeksforgeeks.org/square-root-of-a-perfect-square/
// T.C =>

float squareRoot(float n) {
	float x = n;
	float y = 1;
	float e = 0.000001; // e decides the accuracy level
	while (x - y > e) {
		x = (x + y) / 2;
		y = n / x;
	}
	return x;
}