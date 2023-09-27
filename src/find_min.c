#include "ap1.h"

// Acha o menor valor de uma subarvore
Node * findMin (Node *root) {
	while (root->left) root = root->left;

	return root;
}
