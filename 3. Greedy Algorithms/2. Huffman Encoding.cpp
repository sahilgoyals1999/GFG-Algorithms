// https://practice.geeksforgeeks.org/problems/huffman-encoding/0
// T.C => O(n*log(n))

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

class huffman_tree_node {
public:
	char data;
	int freq;
	huffman_tree_node *left, *right;

	huffman_tree_node(char c, int f) {
		data = c;
		freq = f;
		left = right = NULL;
	}
};

class comp {
public:
	bool operator()(huffman_tree_node *a, huffman_tree_node *b) {
		return a->freq > b->freq;
	}
};

huffman_tree_node* generate_tree(priority_queue<huffman_tree_node*, vector<huffman_tree_node*>, comp> pq) {
	while (pq.size() != 1) {
		huffman_tree_node* left = pq.top();
		pq.pop();
		huffman_tree_node* right = pq.top();
		pq.pop();
		huffman_tree_node *node = new huffman_tree_node('$', left->freq + right->freq);
		node->left = left;
		node->right = right;
		pq.push(node);
	}
	return pq.top();
}

void print_codes(huffman_tree_node* root, int a[], int top) {
	if (root->left) {
		a[top] = 0;
		print_codes(root->left, a, top + 1);
	}
	if (root->right) {
		a[top] = 1;
		print_codes(root->right, a, top + 1);
	}
	if (!root->left && !root->right) {
		for (int i = 0; i < top; ++i) {
			cout << a[i];
		}
		cout << " ";
	}
}

void huffman_codes(string s, int freq[], int n) {
	priority_queue<huffman_tree_node*, vector<huffman_tree_node*>, comp> pq;
	for (int i = 0; i < n; ++i) {
		huffman_tree_node *node = new huffman_tree_node(s[i], freq[i]);
		pq.push(node);
	}
	huffman_tree_node *root = generate_tree(pq);
	int a[100], top = 0;
	print_codes(root, a, top);
}

int main() {
	FAST
	file();
	w(t) {
		string s;
		cin >> s;
		int n = s.length();
		int freq[n];
		for (int i = 0; i < n; ++i) {
			cin >> freq[i];
		}
		huffman_codes(s, freq, n);
		cout << "\n";
	}
	return 0;
}