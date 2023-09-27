#include "ap1.h"

bool searchTree (Node *root, int value) {
	if (!root) return false;

	if (root->key == value) return true;
	if (root->key > value) return searchTree (root->left, value);
	else return searchTree (root->right, value);
}
