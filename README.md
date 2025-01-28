# AVL Tree Implementation in C

This project implements an AVL tree in C, which is a self-balancing binary search tree. The program provides functions for inserting elements, performing different types of tree traversals, printing the tree in a formatted way, and managing memory properly.

## Features

1. **Insert elements into an AVL tree** (self-balancing).
2. **Preorder Traversal**: Root -> Left -> Right.
3. **Inorder Traversal**: Left -> Root -> Right.
4. **Postorder Traversal**: Left -> Right -> Root.
5. **Formatted Tree Print**: Print the tree in a graphical structure.
6. **Check if the tree is empty**.
7. **Remove the entire tree**.

## File Structure

- **tree.h**: Header file containing the definition of the `tree_p` structure and function prototypes.
- **tree.c**: Implementation of the AVL tree functions, including rotations, insertions, and traversals.
- **main.c**: The main program that demonstrates the use of the AVL tree by inserting values and displaying traversals.

## Functions

- `tree_p* start_tree()`  
  Initializes an empty tree. Returns `NULL`.

- `tree_p* tree_build(tree_p* left, tree_p* right, int value)`  
  Creates a new node with the given value and connects it with its left and right children.

- `void tree_print(tree_p* tree, int traversal_type)`  
  Prints the tree based on the specified traversal type:
  - `1`: Preorder Traversal
  - `2`: Inorder Traversal
  - `3`: Postorder Traversal

- `void formatted_tree_print(tree_p* tree)`  
  Prints the tree in a graphical structure to represent its shape.

- `void draw_tree(tree_p* node, char** canvas, int depth, int x, int offset)`  
  Helper function to draw the tree structure visually.

- `int tree_is_empty(tree_p* tree)`  
  Checks if the tree is empty. Returns `1` if the tree is empty, otherwise `0`.

- `void remove_tree(tree_p** tree)`  
  Recursively frees all memory allocated for the tree.

- `int get_height(tree_p* tree)`  
  Calculates the height of the tree.

- `int get_balance(tree_p* tree)`  
  Computes the balance factor of the node. Helps in balancing the tree during insertions.

- `tree_p* rotate_right(tree_p* y)`  
  Performs a right rotation on the subtree rooted at `y`.

- `tree_p* rotate_left(tree_p* x)`  
  Performs a left rotation on the subtree rooted at `x`.

- `tree_p* insert_avl(tree_p* node, int value)`  
  Inserts a new value into the AVL tree while maintaining its balance.

## Usage

1. Compile the program using a C compiler like `gcc`:
   ```bash
   gcc main.c tree.c -o avl_tree
