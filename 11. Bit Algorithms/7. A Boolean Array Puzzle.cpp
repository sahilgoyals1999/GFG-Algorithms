// https://www.geeksforgeeks.org/a-boolean-array-puzzle/
// T.C => O(1)

void changeToZero(int a[2]) {
	a[0] = a[a[0]];
	a[1] = a[0];
}