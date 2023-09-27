#include "ap1.h"
#include <stdlib.h>

// dado um ponteiro de ponteiro para um no, aloca espaco necessario e seta as variaveis
void createNode (Node **node, int nodeKey) {
	Node *new = (Node *) malloc(sizeof(Node));
	if (!new) return;

	new->key = nodeKey;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;

	*node = new;
}
