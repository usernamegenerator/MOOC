#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

//reference
/*
typedef struct bst {
  int* vals;
  int size;
} bst_t;
*/

/* Returns a bst_t structure with an int array vals of size "size" and the
 * size field set appropriately. */
bst_t* make_tree(int size)
{
    bst_t* bst = (bst_t*)malloc(sizeof(bst_t));
    bst->size = size;
    bst->vals = (int*)malloc(sizeof(int)*size);
}

/*
 * Initialize the binary search tree.
 * HINT: What should we initialize values to?  What requirements might we have
 * to add to the tree specification?
 */

//assume a tree always has positive int
//assume no repeat number
//take -1 as NULL
void init_tree(bst_t* tree)
{
  for(int i; i<tree->size;i++)
  {
    tree->vals[i] = -1;
  }
}

/*
 * Inserts a new value into a given tree.
 */

//vals[0] is the root
//vals[2n+1] is the left
//vals[2n+2] is the right
void insert(int val, bst_t* tree)
{
  //empty tree
  if(tree->vals[0] == -1)
  {
    tree->vals[0] = val;
    return;
  }

  //index points to the root first
  int index = 0;

  //if still in bound
  while(index < tree->size)
  {
    if(tree->vals[index] == -1)
    {
      tree->vals[index] = val;
      return; 
    }
    //go left
    if(val < tree->vals[index])
    {
      index = 2*index+1;
    }
    else//go right
    {
      index = 2*index+2;
    }
  }

  printf("insert fail\n");
  return;

}

bool find_val(int val, bst_t* tree)
{
    int index = 0;
    while(index<tree->size)
    {
      if(tree->vals[index] == val)
      {
        return TRUE;
      }

      if(val < tree->vals[index])
      {
        index = 2*index+1;
      }
      else
      {
        index = 2*index+2; 
      }
    }
    return FALSE;
}

/*
 * Given a pointer to the root, frees the memory associated with an entire list.
 */
void delete_bst(bst_t* tree)
{
  free(bst->vals);
  free(bst);
  return;
}

/* Given a pointer to the root, prints all of the values in a list. */
void print_bst(bst_t* tree)
{
  for(int i = 0;i < tree->size;i++)
  {
      if(tree->vals[i] == -1)
        continue;

      printf("%d at index %d, ",tree->vals[i],i);
  }
}
