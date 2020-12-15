// https://www.geeksforgeeks.org/largest-independent-set-problem-dp-26/
// T.C => O(n), S.C => O(1)

// LISS(X) = MAX { (1 + sum of LISS for all grandchildren of X), (sum of LISS for all children of X) }

// A binary tree node has data, pointer to left child and a pointer to right child
class node {
public:
	int data;
	int liss;            // 0
	node *left, *right;  // Null
};

// A memoization function returns size of the largest independent set in a given binary tree
int LISS(node *root) {
	if (!root) return 0;
	if (root->liss) return root->liss;
	if (!root->left && !root->right) return (root->liss = 1);
	// Calculate size excluding the current node
	int liss_excl = LISS(root->left) + LISS(root->right);
	// Calculate size including the current node
	int liss_incl = 1;
	if (root->left) liss_incl += LISS(root->left->left) + LISS(root->left->right);
	if (root->right) liss_incl += LISS(root->right->left) + LISS(root->right->right);
	// Maximum of two sizes is LISS, store it for future uses.
	root->liss = max(liss_incl, liss_excl);
	return root->liss;
}