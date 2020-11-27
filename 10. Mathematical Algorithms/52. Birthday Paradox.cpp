// https://www.geeksforgeeks.org/birthday-paradox/
// T.C => O(1)

// Returns approximate number of people for a given probability
int find(double p) {
	return ceil(sqrt(2 * 365 * log(1 / (1 - p))));
}