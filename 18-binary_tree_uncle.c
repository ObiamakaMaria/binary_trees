#include "binary_trees.h"

/**
 * binary_tree_uncle - This function finds the uncle
 * of a node in a binary tree
 * @node: This is the pointer to the node to find the
 * uncle of a particular node
 * Return: Returns a pointer to the uncle node, or NULL if no uncle exists
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	else if (node->parent->parent->right == node->parent)
		return (node->parent->parent->left);

	return (NULL);
}
