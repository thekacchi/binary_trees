#include "binary_trees.h"

/**
 * binary_tree_levelorder - Next line
 * Goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue;
	int front, rear;
	const binary_tree_t *current;

	if (!tree || !func)
		return;

	/* Use an array as a simple queue */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	front = 0;
	rear = 0;

	/* Enqueue the root node */
	queue[rear++] = tree;

	/* Traverse the tree using level-order transversal */
	while (front < rear)
	{
		current = queue[front++];

		/* Call the function for the current node */
		func(current->n);

		/* Enqueue the left child of it exists */
		if (current->left)
			queue[rear++] = current->left;

		/* Enqueue the right child if it exists */
		if (current->right)
			queue[rear++] = current->right;
	}

	/* Free the allocated queue */
	free(queue);
}
