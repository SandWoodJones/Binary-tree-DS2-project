#include "ap1.h"

// Printa a árvore pré ordem
void printTreePO (Node *root) {
	if (!root) return;

	printf("%d ", root->key);
	printTreeIO (root->left);
	printTreeIO (root->right);
}

// Printa a árvore em ordem
void printTreeIO (Node *root) {
	if (!root) return;
	
	printTreeIO (root->left);
	printf("%d ", root->key);
	printTreeIO (root->right);
}
