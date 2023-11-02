#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the
 * left-child of another node
 * @parent: node parent
 * @value: value of the node
 * Return: the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->left = parent->left;
	new_node->right = NULL;
	new_node->parent = parent;

	if (parent->left != NULL)
	{
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
