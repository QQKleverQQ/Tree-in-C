#ifndef TREE_H
#define TREE_H

typedef struct tree_p {
    int value;
    struct tree_p* left;
    struct tree_p* right;
} tree_p;

tree_p* start_tree();
tree_p* tree_build(tree_p* left, tree_p* right, int value);
void tree_print(tree_p* tree, int traversal_type);
void formatted_tree_print(tree_p* tree);
void draw_tree(tree_p* node, char canvas[][80], int depth, int x, int offset);
int tree_is_empty(tree_p* tree);
void remove_tree(tree_p** tree);
int get_height(tree_p* tree);
int get_balance(tree_p* tree);
tree_p* rotate_right(tree_p* y);
tree_p* rotate_left(tree_p* x);
tree_p* insert_avl(tree_p* node, int value);

#endif