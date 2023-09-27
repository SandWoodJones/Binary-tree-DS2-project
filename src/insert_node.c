#include "ap1.h"

void insertNode (Node *root, Node *newNode) {
	if (!root || !newNode) return;
	
	if (root->key > newNode->key) {
		// Menor, vamos para esquerda
		if (!root->left) {
			newNode->parent = root;
			root->left = newNode;
		}
		else insertNode(root->left, newNode);
	} else {
		// Maior, vamos para a direita
		if (!root->right) {
			newNode->parent = root;
			root->right = newNode;
		}
		else insertNode(root->right, newNode);
	}
}
