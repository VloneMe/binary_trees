#include "binary_trees.h"

/**
 * array_to_bst - This builds a Binary Search Tree (BST) from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root;

	root = NULL;
	if (size == 0)
		return (NULL);
	for (; i < size; i++)
	{
		if (i == 0)
			bst_insert(&root, array[i]);
		else
			bst_insert(&root, array[i]);
	}
	return (root);
}
