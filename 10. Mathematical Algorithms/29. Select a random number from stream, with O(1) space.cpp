// https://www.geeksforgeeks.org/select-a-random-number-from-stream-with-o1-space/
// T.C => O(1)

// A function to randomly select a item
// from stream[0], stream[1], .. stream[i-1]
int selectRandom(int x) {
	static int res; // The resultant random number
	static int count = 0; // Count of numbers visited so far in stream
	++count; // increment count of numbers seen so far
	// If this is the first element from stream return it
	if (count == 1)  res = x;
	else {
		// Generate a random number from 0 to count - 1
		int i = rand() % count;
		// Replace the prev random number with new number with 1/count probability
		if (i == count - 1) res = x;
	}
	return res;
}