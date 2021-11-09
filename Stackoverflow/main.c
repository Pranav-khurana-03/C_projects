#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct tree_node {
  char *data;
  struct tree_node *left;
  struct tree_node *right;
} tree_node;

tree_node* insert(tree_node* root, tree_node* element) {
  if (root == NULL)
    return element;
  else {
    if (strcmp(element->data, root->data) > 0) {
      if (root->right != NULL)
        root->right = insert(root->right, element);
      else
        root->right = element;   
    }
    else {
      if (root->left != NULL)
        root->left  = insert(root->left, element);
      else
        root->left = element;
    }

    return root;
  }
}

void inorder(tree_node *current_ptr) {
  if (current_ptr != NULL) {
    inorder(current_ptr->left);
    printf("%s ", current_ptr->data);
    inorder(current_ptr->right);
  }
}

tree_node* create_node(char* val) {
  tree_node* temp;
  temp = (tree_node*)malloc(sizeof(tree_node));
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp; 
}

int main(void) {
  tree_node *my_root = NULL, *temp_node;

  char* element;
  element = malloc(sizeof(char) * MAX);

  printf("Enter a word to insert in the tree: ");
  scanf("%s", element);

  while(1) {
    temp_node = create_node(element); 

    my_root = insert(my_root, temp_node);
      
    printf("In-order traversal: ");
    inorder(my_root);

    printf("\nEnter a word to insert in the tree: ");
    element = malloc(sizeof(char) * MAX);
    scanf("%s", element);   
  }

  return 0;
}