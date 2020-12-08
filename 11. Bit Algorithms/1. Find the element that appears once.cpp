// https://www.geeksforgeeks.org/find-the-element-that-appears-once/
// T.C => O(n), S.C => O(1)

int getSingle(int a[], int n) {
	int ones = 0, twos = 0;
	for (int i = 0; i < n; i++) {
		/* The expression "one & a[i]" gives the bits that are
		there in both 'ones' and new element from a[].
		We add these bits to 'twos' using bitwise */
		twos = twos | (ones & a[i]);
		// XOR the new bits with previous'ones' to get all bits appearing odd number of times
		ones = ones ^ a[i];
		/* The common bits are those bits which appear third time
		So these bits should not be there in both 'ones' and 'twos'.
		common_bit_mask contains all these bits as 0, so that the bits can
		be removed from 'ones' and 'twos' */
		int common_bit_mask = ~(ones & twos);
		// Remove common bits (the bits that appear third time) from 'ones'
		ones &= common_bit_mask;
		// Remove common bits (the bits that appear third time) from 'twos'
		twos &= common_bit_mask;
	}
	return ones;
}