// https://www.geeksforgeeks.org/compute-the-integer-absolute-value-abs-without-branching/
// T.C => O(1)

#define CHARBIT 8
// For negative numbers mask as 1 1 1 1 1 1 1 1 and
// for positive numbers mask as 0 0 0 0 0 0 0 0.
unsigned int getAbs(int n) {
	int const mask = n >> (sizeof(int) * CHARBIT - 1);
	return ((n + mask) ^ mask);
}
