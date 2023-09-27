#include "ap1.h"

int main(void) {
	Node *tree;

	processFile("in.txt", &tree);
	
	writeToFile("out.txt", tree);
	
	destroyTree(tree); // dar free em tudo
}
