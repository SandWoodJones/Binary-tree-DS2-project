#include "ap1.h"
#include <stdlib.h>

void writeToFile (const char *filename, Node *root) {
	FILE *file = fopen(filename, "w"); // abre em modo de escrita
	if (!file) {
		perror("Erro abrindo arquivo");
		exit(1);
	}
	
	// escrever a arvore é uma funcao externa pois é recursiva precisamos fechar o arquivo apos a escrita
	writeTreeToFileIO(file, root);

	fclose(file);
}

// escreve uma arvore em ordem para file
void writeTreeToFileIO (FILE *file, Node *root) {
	if (!file || !root) return;

	writeTreeToFileIO(file, root->left);
	fprintf(file, "%d\n", root->key);
	writeTreeToFileIO(file, root->right);
}
