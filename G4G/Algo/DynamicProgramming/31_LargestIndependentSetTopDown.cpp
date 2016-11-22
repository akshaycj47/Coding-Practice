#include <unordered_map>
#include <string>
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

int getMap(int data, bool eligibility, std::unordered_map<std::string, int>& m) {
	std::string query = std::to_string(data) + std::to_string(eligibility);

	// If not found in the map
	if (m.find(query) == m.end()) {
		return -1;
	}
	return m[query];
}

void setMap(int data, bool eligibility, std::unordered_map<std::string, int>& m, int size) {
	std::string query = std::to_string(data) + std::to_string(eligibility);
	m[query] = size;
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
int largestIndependentSetSize(TreeNode* root, bool eligibility, std::unordered_map<std::string, int>& m) {

	// Base condition
	if (root == NULL) {
		return 0;
	}

	// First check the map
	if (getMap(root->data, eligibility, m) != -1) {
		return getMap(root->data, eligibility, m);
	}

	// If this root is eligible, it can either be a part of 
	// optimal solution or not
	if (eligibility == true) {
		int include = 1 + largestIndependentSetSize(root->left, false, m) + largestIndependentSetSize(root->right, false, m);
		int notInclude = largestIndependentSetSize(root->left, true, m) + largestIndependentSetSize(root->right, true, m);
		int maxSize = std::max(include, notInclude);
		setMap(root->data, eligibility, m, maxSize);
		return maxSize;
	}

	// If this root is not eligible, it cannot be a part of 
	// optimal solution
	if (eligibility == false) {
		int maxSize = largestIndependentSetSize(root->left, true, m) + largestIndependentSetSize(root->right, true, m);
		setMap(root->data, eligibility, m, maxSize);
		return maxSize;
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
	std::unordered_map<std::string, int> m;
	assert(largestIndependentSetSize(root, true, m) == 5);

	TreeNode* root2 = newNode(20);
	root2->left = newNode(8);
	root2->left->left = newNode(4);
	root2->left->right = newNode(12);
	root2->left->right->left = newNode(10);
	root2->left->right->right = newNode(14);
	root2->right = newNode(22);
	root2->right->right = newNode(25);
	std::unordered_map<std::string, int> m2;
	assert(largestIndependentSetSize(root, true, m2) == 5);
}