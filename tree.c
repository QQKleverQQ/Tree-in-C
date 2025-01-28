#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define WIDTH 35
#define HEIGHT 10

tree_p* start_tree() {
    return NULL;
}

tree_p* tree_build(tree_p* left, tree_p* right, int value) {
    tree_p* new_node = (tree_p*)malloc(sizeof(tree_p));
    if (new_node == NULL) {
        perror("ERROR | Check memory!");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

void tree_print(tree_p* tree, int traversal_type) {
    if (tree == NULL) return;

    switch (traversal_type) {
    case 1:
        printf("%d ", tree->value);
        tree_print(tree->left, 1);
        tree_print(tree->right, 1);
        break;
    case 2:
        tree_print(tree->left, 2);
        printf("%d ", tree->value);
        tree_print(tree->right, 2);
        break;
    case 3:
        tree_print(tree->left, 3);
        tree_print(tree->right, 3);
        printf("%d ", tree->value);
        break;
    default:
        fprintf(stderr, "ERROR | Check traversal!\n");
        break;
    }
}

void formatted_tree_print(tree_p* root) {
    if (root == NULL) return;

    const int width = WIDTH;
    const int height = HEIGHT;

    char** canvas = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        canvas[i] = (char*)malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            canvas[i][j] = ' ';
        }
    }

    draw_tree(root, canvas, 0, width / 2, width / 4);

    for (int i = 0; i < height; i++) {
        printf("%.*s\n", width, canvas[i]);
        free(canvas[i]); 
    }
    free(canvas);
}

void draw_tree(tree_p* node, char** canvas, int depth, int x, int offset) {
    if (node == NULL || depth >= HEIGHT || x < 0 || x >= WIDTH) return;

    if (x + 1 < WIDTH) {
        canvas[depth][x] = node->value / 10 + '0';
        canvas[depth][x + 1] = node->value % 10 + '0';
    }

    if (node->left && x - offset >= 0) {
        canvas[depth + 1][x - offset / 2] = '/';
        draw_tree(node->left, canvas, depth + 2, x - offset, offset / 2);
    }

    if (node->right && x + offset < WIDTH) {
        canvas[depth + 1][x + offset / 2] = '\\';
        draw_tree(node->right, canvas, depth + 2, x + offset, offset / 2);
    }
}

int tree_is_empty(tree_p* tree) {
    return tree == NULL;
}

void remove_tree(tree_p** tree) {
    if (tree && *tree) {
        remove_tree(&(*tree)->left);
        remove_tree(&(*tree)->right);
        free(*tree);
        *tree == NULL;
    }
}

int get_height(tree_p* tree) {
    if (!tree) return 0;
    int left_height = get_height(tree->left);
    int right_height = get_height(tree->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

int get_balance(tree_p* tree) {
    if (!tree) return 0;
    return get_height(tree->left) - get_height(tree->right);
}

tree_p* rotate_right(tree_p* y) {
    tree_p* x = y->left;
    tree_p* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

tree_p* rotate_left(tree_p* x) {
    tree_p* y = x->right;
    tree_p* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

tree_p* insert_avl(tree_p* node, int value) {
    if (!node) return tree_build(NULL, NULL, value);

    if (value < node->value)
        node->left = insert_avl(node->left, value);
    else if (value > node->value)
        node->right = insert_avl(node->right, value);
    else
        return node;

    int balance = get_balance(node);

    if (balance > 1 && value < node->left->value)
        return rotate_right(node);

    if (balance < -1 && value > node->right->value)
        return rotate_left(node);

    if (balance > 1 && value > node->left->value) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if (balance < -1 && value < node->right->value) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}