// https://www.geeksforgeeks.org/calculate-angle-hour-hand-minute-hand/
// T.C => O(1)

int calcAngle(double h, double m) {
	// validate the input
	if (h < 0 || m < 0 || h > 12 || m > 60) cout << "Wrong input\n";
	if (h == 12) h = 0;
	if (m == 60) {
		m = 0;
		h += 1;
		if (h > 12) h = h - 12;
	}
	// Calculate the angles moved by hour and minute hands with reference to 12:00
	float hour_angle = 0.5 * (h * 60 + m);
	float minute_angle = 6 * m;
	// Find the difference between two angles
	float angle = abs(hour_angle - minute_angle);
	// Return the smaller angle of two possible angles
	angle = min(360 - angle, angle);
	return angle;
}