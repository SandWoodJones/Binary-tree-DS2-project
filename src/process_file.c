#include "ap1.h"
#include <stdlib.h>

void processFile (const char *filename, Node **root) {
	if (!root) return;

	FILE *file = fopen(filename, "r"); // abre o arquivo em modo de leitura
	if (!file) {
		perror("Erro abrindo arquivo");
		exit(1);
	}
	
	int number;
	char type;
	bool first = true;

	while (1) {
		// Pega o primeiro caractere da linha e checa se é o fim do arquivo
		type = getc(file);
		if (type == EOF) break;
		
		switch (type) {
			case 'i': // caso de insercao
				fscanf(file, "%d", &number);
				if (first) { // se é o primeiro nodo da arvore, não podemos inserir
					createNode(root, number);
					first = false;
				} else {
					Node *new;
					createNode(&new, number);
					insertNode(*root, new);
				}
				break;

			case 'r':
				fscanf(file, "%d", &number);
				*root = removeNode(*root, number);
				break;

			default: break;
		}
		
		// Depois de ler o número, descarta todos os caracteres restantes
		while ((type = getc(file)) != '\n' && type != EOF);
	}

	fclose(file);
}
