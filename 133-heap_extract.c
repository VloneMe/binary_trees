#include "binary_trees.h"

/**
 * heapify_down - This rebalances the heap by moving the value down.
 *
 * @root: Double pointer to the root node of the heap.
 */
void heapify_down(heap_t **root)
{
	heap_t *parent = *root;
	heap_t *largest = NULL;

	while (1)
	{
		largest = parent;

		if (parent->left && parent->left->n > largest->n)
			largest = parent->left;

		if (parent->right && parent->right->n > largest->n)
			largest = parent->right;

		if (largest == parent)
			break;

		parent->n ^= largest->n;
		largest->n ^= parent->n;
		parent->n ^= largest->n;

		parent = largest;
	}
}

/**
 * heap_extract - This extracts the root node of a Max Binary Heap.
 *
 * @root: Double pointer to the root node of the heap.
 * Return: Value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *tmp = NULL;
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	tmp = *root;

	if ((*root)->left)
		(*root)->n = heap_extract(&((*root)->left));
	else if ((*root)->right)
		(*root)->n = heap_extract(&((*root)->right));
	else
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	heapify_down(root);
	free(tmp);
	return (value);
}
