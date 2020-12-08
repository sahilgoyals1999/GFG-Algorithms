// https://www.geeksforgeeks.org/swap-all-odd-and-even-bits/
// T.C => O(1)

// 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0.
// 0x55555555 is a 32 bit number with all even bits set as 0 and all odd bits as 1.

// Function to swap even and odd bits
unsigned int swapBits(unsigned int x) {
	// Get all even bits of x
	unsigned int even_bits = x & 0xAAAAAAAA;
	// Get all odd bits of x
	unsigned int odd_bits = x & 0x55555555;
	even_bits >>= 1;                // Right shift even bits
	odd_bits <<= 1;                 // Left shift odd bits
	return (even_bits | odd_bits);  // Combine even and odd bits
}