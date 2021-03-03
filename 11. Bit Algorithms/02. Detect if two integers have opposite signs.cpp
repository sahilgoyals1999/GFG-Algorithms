// https://www.geeksforgeeks.org/detect-if-two-integers-have-opposite-signs/
// T.C => O(1)

// The sign bit is 1 in negative numbers, and 0 in positive numbers.
// The XOR of x and y will have the sign bit as 1 iff they have opposite sign.
bool oppositeSigns(int x, int y) {
	return ((x ^ y) < 0);
}