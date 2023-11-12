#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 * If the tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, *current;
	int front, rear, flag;

	if (!tree)
		return (0);
	/* Create a queue for level-order traversal */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	front = 0;
	rear = 0;
	flag = 0; /* Indocates whether non-full node is encountered */
	/* Enqueue the root node */
	queue[rear++] = (binary_tree_t *)tree;
	/* Traverse the tree using levrl-order traversal */
	while (front < rear)
	{
		current = queue[front++];
		/* If a non-full node is encountered */
		/* after a full node, not a complete tree */
		if (!current)
		{
			flag = -1;
		}
		else
		{
			if (flag)
			{
				free(queue);
				return (0);
			}

			/* Enque the left child */
			queue[rear++] = current->left;
			/* Enqueue the right child */
			queue[rear++] = current->right;
		}
	}
	/* Free the allocated queue */
	free(queue);
	/* If loop completes without returning, the tree is complete */
	return (1);
}


