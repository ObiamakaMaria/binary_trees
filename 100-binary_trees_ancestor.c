#include "binary_trees.h"

/**
 * binary_trees_ancestor - This function finds the lowest common
 * ancestor of two nodes
 * @node1: This is the pointer to the first node
 * @node2: This is the pointer to the second node
 * Return: Returns a pointer to the lowest common ancestor
 * node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *node1, const binary_tree_t *node2)
{
	const binary_tree_t *temp1, *temp2;
	size_t depth1 = 0, depth2 = 0;

	if (node1 == NULL || node2 == NULL)
		return (NULL);

	temp1 = node1;
	while (temp1)
	{
		temp1 = temp1->parent;
		depth1++;
	}

	temp2 = node2;
	while (temp2)
	{
		temp2 = temp2->parent;
		depth2++;
	}

	while (depth1 > depth2)
	{
		node1 = node1->parent;
		depth1--;
	}

	while (depth2 > depth1)
	{
		node2 = node2->parent;
		depth2--;
	}

	while (node1 != node2 && node1 && node2)
	{
		node1 = node1->parent;
		node2 = node2->parent;
	}

	return ((binary_tree_t *)node1);
}
