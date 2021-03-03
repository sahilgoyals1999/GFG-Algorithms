// https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/
// T.C => O(n*(log(n)^2))

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
#define mod     (long)(1e9+7)
#define ninf    (long long)(-1e18)
#define ff      first
#define ss      second
#define pb(i)   push_back(i)
#define pp(i)   pop_back(i)
#define setb(x) __builtin_popcount(x)
#define mk      make_pair
#define ms(i,j) memset(i,j,sizeof(i))
#define all(v)  v.begin(),v.end()
#define sz(v)   (int)v.size()
#define pii     pair<int,int>
#define FAST    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define w(t)    int t; cin>>t; while(t--)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void file() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class Point {
public:
	int x, y;
};

int compX(Point &a, Point &b) {
	return a.x < b.x;
}

int compY(Point &a, Point &b) {
	return a.y < b.y;
}

// for finding distance between two points
float dist(Point &a, Point &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// for finding smallest distance between two points in P[] of size n
float bruteForce(Point P[], int n) {
	float mn = FLT_MAX;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			mn = min(mn, dist(P[i], P[j]));
		}
	}
	return mn;
}

// for find the distance beween the closest points of strip of given size.
// All points in strip[] are sorted accordint to y coordinate.
// They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(Point strip[], int size, float d) {
	float mn = d;
	sort(strip, strip + size, compY);
	// Pick all points one by one and try the next points till the difference
	// between y coordinates is smaller than d.
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < mn; ++j) {
			mn = min(mn, dist(strip[i], strip[j]));
		}
	}
	return mn;
}

// A recursive function to find the smallest distance.
// The array P contains all points sorted according to x coordinate
float closestUtil(Point P[], int n) {
	// If there are 2 or 3 points, then use brute force
	if (n <= 3) return bruteForce(P, n);
	// Find the middle point
	int mid = n / 2;
	Point midPoint = P[mid];
	// Consider the vertical line passing through the middle point
	// calculate the smallest distance dl on left of middle point and dr on right side
	float dl = closestUtil(P, mid);
	float dr = closestUtil(P + mid, n - mid);
	// Find the smaller of two distances
	float d = min(dl, dr);
	// Build an array strip[] that contains points close (closer than d)
	// to the line passing through the middle point
	Point strip[n];
	int size = 0;
	for (int i = 0; i < n; i++) {
		if (abs(P[i].x - midPoint.x) < d) strip[size++] = P[i];
	}
	// Find the closest points in strip.
	// Return the minimum of d and closest distance is strip[]
	return min(d, stripClosest(strip, size, d));
}

float closest(Point P[], int n) {
	sort(P , P + n , compX);
	return closestUtil(P, n);
}

int main() {
	FAST
	file();
	w(t) {
		int n;
		cin >> n;
		Point P[n];
		for (int i = 0; i < n; ++i) {
			cin >> P[i].x >> P[i].y;
		}
		cout << closest(P, n);
	}
	return 0;
}