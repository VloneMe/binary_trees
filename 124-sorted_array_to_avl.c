#include "binary_trees.h"

/**
 * build_avl_tree - This create the AVL tree using
 * a portion of the sorted array.
 *
 * @parent: Parent of the node to create.
 * @sorted_array: Sorted array.
 * @start: Starting index of the array.
 * @end: Ending index of the array.
 * Return: Pointer to the root of the tree created.
 */
avl_t *build_avl_tree(avl_t *parent, int *sorted_array, int start, int end)
{
	avl_t *root;
	binary_tree_t *aux;
	int middle = 0;

	if (start <= end)
	{
		middle = (start + end) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, sorted_array[middle]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = build_avl_tree(root, sorted_array, start, middle - 1);
		root->right = build_avl_tree(root, sorted_array, middle + 1, end);
		return (root);
	}

	return (NULL);
}

/**
 * sorted_array_to_avl - This create an AVL tree from a sorted array.
 *
 * @array: Sorted array.
 * @size: Size of the sorted array.
 * Return: Pointer to the root of the AVL tree created.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (build_avl_tree(NULL, array, 0, ((int)(size)) - 1));
}
