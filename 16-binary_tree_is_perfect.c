#include "binary_trees.h"

/**
 * binary_tree_height - This function calculates the
 * height of a binary tree
 * @tree: Thus is the pointer to the root node of the tree
 * Return: Returns the height of the tree else, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t l_height = binary_tree_height(tree->left);
	size_t r_height = binary_tree_height(tree->right);

	return (1 + (l_height > r_height ? l_height : r_height));
}

/**
 * binary_tree_is_perfect - This function checks if
 * a binary tree is perfect
 * @tree: This is the pointer to the root node of the tree
 * Return: Returns 1 if the tree is perfect OR 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t l_height = binary_tree_height(tree->left);
	size_t r_height = binary_tree_height(tree->right);

	if (l_height == r_height)
	{
		if (tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
					binary_tree_is_perfect(tree->right));
		else if (tree->left == NULL && tree->right == NULL)
			return (1);
	}

	return (0);
}
