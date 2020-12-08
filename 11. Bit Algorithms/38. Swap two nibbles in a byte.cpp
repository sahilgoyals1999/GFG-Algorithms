// https://www.geeksforgeeks.org/swap-two-nibbles-byte/
// T.C => O(1)

// “x & 0x0F” gives us last 4 bits of x.
// “x & 0xF0” gives us first 4 bits of x.

int swapNibbles(int x) {
	return ((x & 0x0F) << 4 | (x & 0xF0) >> 4);
}