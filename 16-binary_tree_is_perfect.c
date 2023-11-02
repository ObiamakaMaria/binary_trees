#include "binary_trees.h"

int recursive_full_check(const binary_tree_t *custom_tree);

/**
 * binary_tree_is_perfect - This function checks if binary
 * tree is perfect
 * @custom_tree: This is the pointer to the node
 * Return: Returns 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *custom_tree)
{
	size_t x, y;

	if (custom_tree == NULL)
	{
		return (0);
	}
	x = binary_tree_is_full(custom_tree) ? 1 : 0;
	y = binary_tree_balance(custom_tree) == 0 ? 1 : 0;
	return (x && y ? 1 : 0);
}

/**
 * binary_tree_is_full - This function check if binary tree is full
 * @custom_tree: This is the pointer to the node
 * Return: Returns 1 if full otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *custom_tree)
{
	if (custom_tree == NULL)
	{
		return (0);
	}
	return (recursive_full_check(custom_tree));
}

/**
 * recursive_full_check - This function checks if it is
 * full recursively
 * @custom_tree: This is the pointer to the node
 * Return: Returns  1 if full, otherwise 0
 */
int recursive_full_check(const binary_tree_t *custom_tree)
{
	if (custom_tree != NULL)
	{
		if ((custom_tree->left != NULL && custom_tree->right == NULL) ||
				(custom_tree->left == NULL && custom_tree->right != NULL) ||
				recursive_full_check(custom_tree->left) == 0 ||
				recursive_full_check(custom_tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_balance - This function calculate the tree balance
 * @custom_tree: This is the pointer to the tree
 * Return: Return balance factor or 0 if NULL
 */
int binary_tree_balance(const binary_tree_t *custom_tree)
{
	if (custom_tree)
	{
		return (binary_tree_height(custom_tree->left) -
				binary_tree_height(custom_tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - This function calculates the
 * height of a binary tree.
 * @custom_tree: This is the pointer to the tree root node.
 * Return: Returns the height or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *custom_tree)
{
	if (custom_tree)
	{
		size_t left_height = custom_tree->left ?
			1 + binary_tree_height(custom_tree->left) : 1;
		size_t right_height = custom_tree->right ?
			1 + binary_tree_height(custom_tree->right) : 1;

		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}
