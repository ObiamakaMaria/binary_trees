#include "binary_trees.h"

/**
 * binary_tree_inorder - This function traverses a binary tree
 * using in-order traversal
 * @tree: This is a pointer to the root node of the tree to traverse
 * @func: This is a pointer to a function call for each node
 *        The value in the node must be passed as a parameter to this function
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n); /* A call to the function with the node's value */
	binary_tree_inorder(tree->right, func);
}
