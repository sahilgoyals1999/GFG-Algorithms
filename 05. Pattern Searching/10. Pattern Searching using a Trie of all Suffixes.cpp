// https://www.geeksforgeeks.org/pattern-searching-using-trie-suffixes/
// T.C => O(m+k), m => length of the pattern,  k => number of occurrences of pattern in text.

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

#define MAX_CHAR 256

class SuffixTrieNode {
private:
	SuffixTrieNode *children[MAX_CHAR];
	list<int> *indexes;
public:
	SuffixTrieNode() { // Constructor
		// Create an empty linked list for indexes of suffixes starting from this node
		indexes = new list<int>;
		// Initialize all child pointers as NULL
		for (int i = 0; i < MAX_CHAR; ++i) {
			children[i] = NULL;
		}
	}
	void insertSuffix(string suffix, int index);
	list<int>* search(string pat);
};

class SuffixTrie {
private:
	SuffixTrieNode root;
public:
	// Constructor (Builds a trie of suffies of the given text)
	SuffixTrie(string txt) {
		// Consider all suffixes of given string and insert them
		for (int i = 0; i < txt.length(); ++i) {
			root.insertSuffix(txt.substr(i), i);
		}
	}
	void search(string pat);
};

void SuffixTrieNode::insertSuffix(string s, int index) {
	// Store index in linked list
	indexes->pb(index);
	// If string has more characters
	if (s.length() > 0) {
		// Find the first character
		char cIndex = s[0];
		// If there is no edge for this character, add a new edge
		if (!children[cIndex]) children[cIndex] = new SuffixTrieNode();
		// Recur for next suffix
		children[cIndex]->insertSuffix(s.substr(1), index + 1);
	}
}

list<int>* SuffixTrieNode::search(string s) {
	if (s.length() == 0) return indexes;
	// if there is an edge from the current node of suffix trie, follow the edge.
	if (children[s[0]]) return children[s[0]]->search(s.substr(1));
	// If there is no edge, pattern doesn’t exist in text
	else return NULL;
}

void SuffixTrie::search(string pat) {
	list<int> *result = root.search(pat);
	// Check if the list of indexes is empty or not
	if (!result) cout << "Not found" << endl;
	else {
		int patLen = pat.length();
		for (auto i = result->begin(); i != result->end(); ++i)
			cout << *i - patLen << "\n";
	}
}

int main() {
	FIO
	file();
	w(t) {
		string txt, pat;
		cin >> txt >> pat;
		SuffixTrie S(txt);
		S.search(pat);
	}
	return 0;
}