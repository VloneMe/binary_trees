#include "binary_trees.h"

/**
 * binary_tree_is_heap - This check if a binary tree is
 * a valid Max Binary Heap.
 *
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
}
