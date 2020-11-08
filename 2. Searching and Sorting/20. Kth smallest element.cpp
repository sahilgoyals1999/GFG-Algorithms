// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// T.C => O(k + (n-k)*Logk)

int kthSmallest(int a[], int l, int r, int k) {
	// Push first k elements in Max Heap for maintainng the small k elements
	priority_queue<int> pq(a + l, a + k);
	// Traverse for other elements
	for (int i = k; i <= r; ++i) {
		// if we found a element which is less then top of pq then pop it and push new element
		if (a[i] < pq.top()) {
			pq.pop();
			pq.push(a[i]);
		}
	}
	return pq.top();
}