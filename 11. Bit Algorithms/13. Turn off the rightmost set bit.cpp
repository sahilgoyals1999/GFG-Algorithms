// https://www.geeksforgeeks.org/turn-off-the-rightmost-set-bit/
// T.C => O(1)

int fun(int n) {
	return n & (n - 1);
}