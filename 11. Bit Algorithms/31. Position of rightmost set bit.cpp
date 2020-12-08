// https://www.geeksforgeeks.org/position-of-rightmost-set-bit/
// T.C => O(1)

unsigned int getFirstSetBit(int n) {
	return log2(n & -n) + 1;
}