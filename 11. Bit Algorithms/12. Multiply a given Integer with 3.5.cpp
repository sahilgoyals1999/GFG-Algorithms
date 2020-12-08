// https://www.geeksforgeeks.org/multiply-an-integer-with-3-5/
// T.C => O(1)

// 3.5*x == 2*x + x + x/2
int multiplyWith3Point5(int x) {
	return (x << 1) + x + (x >> 1);
}