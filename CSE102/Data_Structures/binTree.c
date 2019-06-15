#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data, key;
	struct Node *right, *left;
} node_t;

node_t *create_node(int data) {
	node_t *rtr = malloc(sizeof(node_t));

	rtr->data = data;
	rtr->key = data;
	rtr->right = rtr->left = NULL;

	return rtr;
}

node_t *search_key(node_t *root, int key) {

	if(root == NULL || root->key == key) {
		return root;

	}

	if(root->key < key) {
		return search_key(root->right, key);

	}

	return search_key(root->left, key);

}

void inorder(node_t *root) {

	if(root != NULL) {
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);

	}

}

node_t * remove(node_t **root, int key) {

	node_t *rtr

	if(root->key != key) {
		remove((*root)->left, key);
		
		remove((*root)->right, key);

	}

}

node_t *insert(node_t *root, int key) {

	if(root == NULL) return create_node(key);

	if(key < root->key) {
		root->left = insert(root->left, key);

	} else if(key > root->key) {
		root->right = insert(root->right, key);

	}

}

int main() {

	node_t *root = create_node(5);
	insert(root, 6);
	insert(root, 7);
	insert(root, 8);
	insert(root, -3);
	insert(root, 100);
	insert(root, -50);
	insert(root, 9);

	inorder(root);

	//printf("%d\n", search_key(root,100)->key);

	remove(&root, 8);


}