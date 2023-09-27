#ifndef AP_1_DS2_H
#define AP_1_DS2_H

#include <stdbool.h>
#include <stdio.h>

typedef struct Node {
	int key;
	struct Node *parent, *left, *right;
} Node;

void processFile (const char *filename, Node **root);

void writeToFile (const char *filename, Node *root);
void writeTreeToFileIO (FILE *file, Node *root);

void createNode (Node **node, int nodeKey);
void destroyTree (Node *root);

Node * findMin (Node *root);

void insertNode (Node *root, Node *newNode);
bool searchTree (Node *root, int value);
Node * removeNode (Node *root, int value);

void printTreeIO (Node *root);
void printTreePO (Node *root);

#endif
