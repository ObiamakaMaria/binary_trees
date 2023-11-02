#include "binary_trees.h"


/**
 * binary_tree_is_full - This function checks if a binary tree is full
 * @tree: This is the pointer to the root node of the tree to check
 * Return: Returns 1 if the tree is full OR 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left)) &&
			(binary_tree_is_full(tree->right));

	return (0);
}
