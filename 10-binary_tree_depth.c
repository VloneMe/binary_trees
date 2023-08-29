#include "binary_trees.h"

/**
 * binary_tree_depth  - This measures the depth of a node in a binary tree.
 *
 * @tree: A pointer to the node to measure the depth.
 * Return: The depth of the node, or 0 if the node is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t depth = 0;

	while (tree->parent != NULL)
	{
		tree = tree->parent;
		depth++;
	}

	return (depth);
}
