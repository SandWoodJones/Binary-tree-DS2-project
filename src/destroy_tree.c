#include "ap1.h"
#include <stdlib.h>

void destroyTree(Node *root) {
	if (!root) return;
	destroyTree(root->left);
	destroyTree(root->right);
	free(root);
}
