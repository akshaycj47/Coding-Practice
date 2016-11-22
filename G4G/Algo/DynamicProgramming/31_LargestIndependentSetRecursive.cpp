#include <algorithm>
#include <cassert>

/**
* Data structure for a node of Binary Tree
* @members {int} data - Data to be stored in the node
* @members {Pointer to TreeNode} left - Pointer to left subtree
* @members {Pointer to TreeNode} right - Pointer to right subtree
*/
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};

/**
* Utility functions that creates a tree node
* @params {int} data - Data to initialize the node with
* @return {Pointer to TreeNode} pointer to the tree node
*/
TreeNode* newNode(int data) {
	TreeNode* temp = new TreeNode;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/**
* Function that finds size of the Largest Independent Set (LIS) in a given binary
* tree. A subset of all tree nodes is an independent set if there is no edge 
* betwwen any two nodes of the subset.
* @params {Pointer to TreeNode} root - Root of the tree
* @params {bool} eligibility - Whether the current root is eligible or not,
* initially true for the main root node
* @return {int} Minimum cost of searches for an optimal BST
*/
int largestIndependentSetSize(TreeNode* root, bool eligibility) {

	// Base case
	if (root == NULL) {
		return 0;
	}

	// If this root is eligible 
	if (eligibility == true) {
		return std::max(1 + largestIndependentSetSize(root->left, false) + largestIndependentSetSize(root->right, false),     // Include this node
			            largestIndependentSetSize(root->left, true) + largestIndependentSetSize(root->right, true)			  // Don't include this node
						);
	}

	// If this root is not eligible 
	if (eligibility == false) {
		return largestIndependentSetSize(root->left, true) + largestIndependentSetSize(root->right, true);
	}
}

/**
* Starting point of the program
*/
int main() {
	
	TreeNode* root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(50);
	root->right->right = newNode(60);
	root->left->right->left = newNode(70);
	root->left->right->right = newNode(80);
	assert(largestIndependentSetSize(root, true) == 5);

	TreeNode* root2 = newNode(20);
	root2->left = newNode(8);
	root2->left->left = newNode(4);
	root2->left->right = newNode(12);
	root2->left->right->left = newNode(10);
	root2->left->right->right = newNode(14);
	root2->right = newNode(22);
	root2->right->right = newNode(25);
	assert(largestIndependentSetSize(root, true) == 5);
}