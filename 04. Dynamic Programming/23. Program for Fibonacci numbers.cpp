// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
// T.C => O(log(n)), S.C => O(1)
// nth fibonacci number

void multiply(int F[2][2], int M[2][2]) {
	int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

// Optimized version of power() in method 4
void power(int F[2][2], int n) {
	if (n == 0 || n == 1) return;
	int M[2][2] = {{1, 1}, {1, 0}};
	power(F, n / 2);
	multiply(F, F);
	if (n % 2 != 0) multiply(F, M);
}

int fib(int n) {
	if (n == 0) return 0;
	int F[2][2] = {{1, 1}, {1, 0}};
	power(F, n - 1);
	return F[0][0];
}

// T.C => O(1), S.C => O(1)
// Fn = {[(√5 + 1)/2] ^ n} / √5
int fib(int n) {
	double phi = (1 + sqrt(5)) / 2;
	return round(pow(phi, n) / sqrt(5));
}