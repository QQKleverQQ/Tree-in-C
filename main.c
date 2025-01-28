#include <stdio.h>
#include "tree.h"

int main() {
    int values[] = { 0, 10, 20, 30, 40, 50, 25, 8, 9, 67, 88 };
    int n = sizeof(values) / sizeof(values[0]);

    tree_p* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert_avl(root, values[i]);
    }

    printf("Tree Print:\n");
    formatted_tree_print(root);

    printf("\nPreorder Traversal:\n");
    tree_print(root, 1);

    printf("\nInorder Traversal:\n");
    tree_print(root, 2);

    printf("\nPostorder Traversal:\n");
    tree_print(root, 3);

    remove_tree(&root);
    printf("\nTree removed. Is tree empty? %s\n", tree_is_empty(root) ? "Yes" : "No");

    return 0;
}