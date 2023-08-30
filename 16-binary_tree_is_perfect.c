#include "binary_trees.h"

/**
 * is_leaf - This checks if a node is a leaf in a binary tree.
 *
 * @node: A pointer to the node to check.
 * Return: 1 if the node is a leaf, otherwise 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - This calculates the depth of a node in a binary tree.
 *
 * @tree: A pointer to the node to measure the depth of.
 * Return: The depth of the node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * find_leaf - This locates a leaf node in a binary tree.
 *
 * @tree: A pointer to the root node of the tree to find a leaf in.
 * Return: A pointer to the first encountered leaf node.
 */
const binary_tree_t *find_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? find_leaf(tree->left) : find_leaf(tree->right));
}

/**
 * is_perfect_recursive - This checks if a binary tree
 * is perfectly balanced recursively.
 *
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of a leaf node in the binary tree.
 * @level: The current level of the node.
 * Return: 1 if the tree is perfectly balanced, otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - This checks if a binary tree is perfectly balanced.
 *
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfectly balanced, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(find_leaf(tree)), 0));
}
