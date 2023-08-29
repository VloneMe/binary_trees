#include "binary_trees.h"

/**
 * binary_tree_insert_right - This inserts a node as
 * the right-child of another node.
 *
 * @parent: A pointer to the parent node.
 * @value: The value to be stored in the new node.
 *
 * Return: A pointer to the newly created node,
 * or NULL on failure or if the parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		new_node->right->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
