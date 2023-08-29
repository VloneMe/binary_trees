#include "binary_trees.h"

/**
 * binary_tree_depth  - This measures the depth of a node in a binary tree.
 *
 * @tree: A pointer to the node to measure the depth.
 * Return: The depth of the node, or 0 if the node is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
