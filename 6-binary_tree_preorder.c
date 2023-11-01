#include "binary_trees.h"

/**
 * binary_tree_preorder - This function traverses through a
 * binary tree using pre-order traversal
 * @tree: This is the pointer to the root node of the tree to traverse
 * @func: This is a pointer to a function to call for each node
 *        The value in the node must be passed
 *        as a parameter to this function
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n); /* A call  to the function with the node's value */
	binary_tree_preorder(tree->left, func);  /* Traversing left subtree */
	binary_tree_preorder(tree->right, func); /* Traverse right subtree */
}
