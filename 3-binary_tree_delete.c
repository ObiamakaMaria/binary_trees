#include "binary_trees.h"

/**
 * binary_tree_delete - This function deletes a binary tree
 * @tree: This is a pointer to the root node of the tree to be deleted.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->left); /* left subtree deleted */
	binary_tree_delete(tree->right); /* right subtree deleted */

	free(tree);
}
