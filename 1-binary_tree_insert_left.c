#include "binary_trees.h"

/**
 * binary_tree_insert_left - This function inserts a node as
 * the left-child of another node
 * @parent: This is the pointer to the node to insert the left-child in
 * @value: This is the value to store in the new node
 * Return: The function returns a pointer to the created node,
 * or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *left_new_node;

    if (parent == NULL)
        return (NULL);

    left_new_node = binary_tree_node(parent, value);
    if (left_new_node == NULL)
        return (NULL);

    if (parent->left != NULL)
    {
        left_new_node->left = parent->left;
        parent->left->parent = left_new_node;
    }

    parent->left = left_new_node;

    return (left_new_node);
}
