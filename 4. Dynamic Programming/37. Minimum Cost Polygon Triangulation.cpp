// https://www.geeksforgeeks.org/minimum-cost-polygon-triangulation/
// T.C => O(n^3), S.C => O(n^2)

class Point {
	int x, y;
};

// function to find distance between two points in a plane
double dist(Point &p1, Point &p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// function to find cost of a triangle. The cost is considered
// as perimeter (sum of lengths of all edges) of the triangle
double cost(Point &p1, Point &p2, Point &p3) {
	return dist(p1, p2) + dist(p2, p3) + dist(p3, p1);
}

// A Dynamic programming based function to find minimum cost for convex polygon triangulation.
double mTCDP(Point points[], int n) {
	// There must be at least 3 points to form a triangle
	if (n < 3) return 0;
	// dp[i][j] stores cost of triangulation of points from i to j.
	// dp[0][n-1] => the final result.
	double dp[n][n];
	// the array is filled in diagonal fashion i.e., from diagonal elements to dp[0][n-1].
	for (int gap = 0; gap < n; ++gap) {
		for (int i = 0, j = gap; j < n; ++i, ++j) {
			if (j < i + 2) dp[i][j] = 0.0;
			else {
				dp[i][j] = MAX;
				for (int k = i + 1; k < j; ++k) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cost(points[i], points[j], points[k]));
				}
			}
		}
	}
	return dp[0][n - 1];
}