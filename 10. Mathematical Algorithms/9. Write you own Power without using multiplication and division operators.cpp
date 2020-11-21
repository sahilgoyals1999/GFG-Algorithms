// https://www.geeksforgeeks.org/write-you-own-power-without-using-multiplication-and-division/
//

int multiply(int x, int y) {
	if (y == 0) return 0;
	return (x + multiply(x, y - 1));
}

// A recursive function to get a^b works only if a >= 0 and b >= 0
int pow(int a, int b) {
	if (b == 0) return 1;
	return multiply(a, pow(a, b - 1));
}