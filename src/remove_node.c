#include "ap1.h"
#include <stdlib.h>

Node * removeNode (Node *root, int value) {
	if (!root || !searchTree(root, value)) return NULL;

	Node *temp = NULL;
	if (root->key > value) root->left = removeNode(root->left, value); // Valor menor, pega esquerda
	else if (root->key < value) root->right = removeNode(root->right, value); // Valor maior, pega direita
	
	// Valor igual, nó a ser deletado
	else {
		// Nó com 1 ou 0 filhos
		if (!root->left) {
			temp = root->right;
			free(root);
			return temp;
		} else if (!root->right) {
			temp = root->left;
			free(root);
			return temp;
		}

		// Nó com 2 filhos - sucessor (menor na subarvore direita)
		temp = findMin(root->right);
		// Substitui pelo sucessor
		root->key = temp->key;
		// Deleta o sucessor
		root->right = removeNode(root->right, temp->key);
	}
	
	return root;
}
