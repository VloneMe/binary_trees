#include "binary_trees.h"

/**
 * bst_find_min - This finds the minimum value node in a BST.
 *
 * @node: A pointer to the root node of the BST.
 * Return: A pointer to the minimum value node.
 */
bst_t *bst_find_min(bst_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * bst_remove - This removes a node from a Binary Search Tree (BST).
 *
 * @root: A pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 * Return: A pointer to the new root node after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
		else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		bst_t *temp = bst_find_min(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
