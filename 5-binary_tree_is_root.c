#include "binary_trees.h"

/**
 * binary_tree_is_root- Checks if a node is a root
 * @node: Pounter to the node to check
 * Return: 1 if node is a root, 0 of otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
