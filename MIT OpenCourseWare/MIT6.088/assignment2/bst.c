#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/*
 * Creates a new node from a given value, allocating heap memory for it.
 */
node_t* make_tree(int val) {
  node_t* new_tree = malloc(sizeof(node_t));
  new_tree->val = val;
  new_tree->left = NULL;
  new_tree->right = NULL;
  return new_tree;
}

/*
 * Inserts a new value into a given binary search tree, allocating heap memory
 * for it.
 */
node_t* insert(int val, node_t* cur_root) {
  /* YOUR CODE HERE */
    node_t* temp_node = cur_root;

    if(temp_node==NULL)
    {
      node_t* new_node = (node_t*)malloc(sizeof(node_t));
      new_node->val = val;
      new_node->left=NULL;
      new_node->right=NULL;
      printf("inserted %d\n",new_node->val);
      return new_node;
    }

    if(val < temp_node->val)
    {
        temp_node->left = insert(val,temp_node->left);
    }
    else
    {
        temp_node->right = insert(val,temp_node->right);
    }
}

bool find_val(int val, node_t* root) {
  /* YOUR CODE HERE */
    node_t* temp_node = root;

//recursion solution
    if(temp_node == NULL)
      return FALSE;
    if(temp_node->val==val)
      return TRUE;
    if(val < temp_node->val)
      return find_val(val,temp_node->left);
    if(val > temp_node->val)
      return find_val(val,temp_node->right);

//non-recursion solution
/*
    while(temp_node!=NULL)
    {
        if(val < temp_node->val)
        {
            temp_node = temp_node->left; 
        }
        else if(val > temp_node->val)
        {
            temp_node = temp_node->right;  
        }
        else
        {
          printf("found %d\n",temp_node->val);
          return TRUE;
        }
    }
    printf("not found\n");
    return FALSE;
*/
}

/*
 * Given a pointer to the root, frees the memory associated with an entire tree.
 */
void delete_bst(node_t* root) {
  /* YOUR CODE HERE */
    if(root==NULL)
      return;
    delete_bst(root->left);
    delete_bst(root->right);
    free(root);
}

/* Given a pointer to the root, prints all o fthe values in a tree. */
void print_bst(node_t* root) {
  if (root != NULL) {
    printf("%d ", root->val);
    print_bst(root->left);
    print_bst(root->right);
  }
  return;
}
