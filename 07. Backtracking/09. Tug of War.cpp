// https://www.geeksforgeeks.org/tug-of-war/
// T.C => O()

#include        <bits/stdc++.h>
#include        <ext/pb_ds/assoc_container.hpp>
#include        <ext/pb_ds/tree_policy.hpp>
#define ll      long long
#define ld      long double
#define inf     (long long)(1e18)
#define mod     (long long)(1e9+7)
#define ff      first
#define ss      second
#define pb(i)   push_back(i)
#define pp(i)   pop_back(i)
#define setb(x) __builtin_popcount(x)
#define mk      make_pair
#define ms(i,j) memset(i,j,sizeof(i))
#define all(v)  v.begin(),v.end()
#define sz(v)   (int)v.size()
#define FIO     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

void TOWUtil(int* a, int n, bool* curr_elements, int no_of_selected_elements,
             bool* soln, int* min_diff, int sum, int curr_sum, int curr_position) {
	// checks whether the it is going out of bound
	if (curr_position == n) return;
	// checks that the numbers of elements left are not less than the
	// number of elements required to form the solution
	if ((n / 2 - no_of_selected_elements) > (n - curr_position)) return;
	// consider the cases when current element is not included in the solution
	TOWUtil(a, n, curr_elements, no_of_selected_elements, soln, min_diff, sum, curr_sum, curr_position + 1);
	// add the current element to the solution
	++no_of_selected_elements;
	curr_sum += a[curr_position];
	curr_elements[curr_position] = true;
	// checks if a solution is formed
	if (no_of_selected_elements == n / 2) {
		// checks for better solution so far
		if (abs(sum / 2 - curr_sum) < *min_diff) {
			*min_diff = abs(sum / 2 - curr_sum);
			for (int i = 0; i < n; i++) {
				soln[i] = curr_elements[i];
			}
		}
	}
	else {
		// consider the cases where current element is included in the solution
		TOWUtil(a, n, curr_elements, no_of_selected_elements, soln, min_diff, sum, curr_sum, curr_position + 1);
	}
	// removes current element before returning to the caller of this function => Backtracking
	curr_elements[curr_position] = false;
}

// main function that generate an a
void tugOfWar(int *a, int n) {
	// the boolean array that contains the inclusion and exclusion of an element
	// in current set. The number excluded automatically form the other set
	bool* curr_elements = new bool[n];
	// The inclusion/exclusion array for final solution
	bool* soln = new bool[n];
	int min_diff = INT_MAX;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		curr_elements[i] =  soln[i] = false;
	}
	// Find the solution using recursive function TOWUtil()
	TOWUtil(a, n, curr_elements, 0, soln, &min_diff, sum, 0, 0);
	// Print the solution
	cout << "The first subset is: ";
	for (int i = 0; i < n; i++) {
		if (soln[i]) cout << a[i] << " ";
	}
	cout << "\nThe second subset is: ";
	for (int i = 0; i < n; i++) {
		if (!soln[i]) cout << a[i] << " ";
	}
}

int main() {
	FIO
	file();
	w(t) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		tugOfWar(a, n);
	}
	return 0;
}