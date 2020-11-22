// https://www.geeksforgeeks.org/find-day-of-the-week-for-a-given-date/
// T.C => O(1)

// d = 23, m = 11, y = 2020
string getDayOfWeek(int d, int m, int y) {
	int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;
	int res = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
	if (res == 0) return "Sunday";
	if (res == 1) return "Monday";
	if (res == 2) return "Tuesday";
	if (res == 3) return "Wednesday";
	if (res == 4) return "Thursday";
	if (res == 5) return "Friday";
	return "Saturday";
}