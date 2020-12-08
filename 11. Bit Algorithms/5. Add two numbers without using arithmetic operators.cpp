// https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
// T.C => O(1)

// Half Adder
// x ^ y gives sum of x and y
// (x & y << 1) gives set of all carry bits
int Add(int x, int y) {
	// Base Case
	if (y == 0) return x;
	return Add(x ^ y, (x & y) << 1);
}