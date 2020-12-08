// https://www.geeksforgeeks.org/smallest-of-three-integers-without-comparison-operators/
// T.C => O(1)

// Using division operator to find minimum of three numbers
// if y/x == 0 => it means y<x now, if y/z == 0 it means y<z so, y is smaller else z is smaller
// else => it means x<y, it x/z == 0 it means x<z so, x is smaller else z is smaller
int smallest(int x, int y, int z) {
	if (!(y / x)) return (!(y / z)) ? y : z;
	return (!(x / z)) ? x : z;
}