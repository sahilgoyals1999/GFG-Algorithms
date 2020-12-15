// https://www.geeksforgeeks.org/bellman-ford-algorithm-simple-implementation/
// T.C => O(n*m), S.C => O(n)

// finds shortest distances from src to all other vertices
// The function also detects negative weight cycle
// The row graph[i] represents i-th edge with three values u, v and w.
void BellmanFord(int graph[][3], int n, int m, int src) {
	// Initialize distance of all vertices as infinite.
	int dis[n];
	for (int i = 0; i < n; ++i) {
		dis[i] = INT_MAX;
	}
	// initialize distance of source as 0
	dis[src] = 0;
	// Relax all edges n - 1 times
	// A simple shortest path from src to any other vertex can have at-most n - 1 edges
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]]) {
				dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
			}
		}
	}
	// check for negative-weight cycles
	// The above step guarantees shortest distances if graph doesn't contain negative weight cycle
	// If we get a shorter path, then there is a cycle
	for (int i = 0; i < m; ++i) {
		int x = graph[i][0];
		int y = graph[i][1];
		int weight = graph[i][2];
		if (dis[x] != INT_MAX && dis[x] + weight < dis[y]) {
			cout << "Graph contains negative weight cycle\n";
		}
		cout << "Vertex Distance from Source\n";
		for (int i = 0; i < n; ++i) {
			cout << i << " " << dis[i] << "\n";
		}
	}