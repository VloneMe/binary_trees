#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - This calculate the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 * Return: Height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_balance - This calculate the balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 * Return: Balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_is_avl_recursive - This recursive helper function to check if
 * a binary tree is a valid AVL Tree.
 *
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum value allowed in the tree.
 * @max: Maximum value allowed in the tree.
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl_recursive(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	int balance = binary_tree_balance(tree);

	if (balance < -1 || balance > 1)
		return (0);

	if (tree->n < min || tree->n > max)
		return (0);

	return (binary_tree_is_avl_recursive(tree->left, min, tree->n - 1) &&
			binary_tree_is_avl_recursive(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - This check if a binary tree is a valid AVL Tree.
 *
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl_recursive(tree, INT_MIN, INT_MAX));
}
