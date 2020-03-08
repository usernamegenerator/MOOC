#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>

using namespace std;


struct node{
  int data;
  struct node* left;
  struct node* right;
};
struct node* root;

/*
 * Binary search tree
 */
class BST {


 public:

  // DO NOT change the declarations of the given methods.
  
  // constructor
  BST();
  // destructor
  ~BST();

  // inserts "val" into the tree
  void insert(int val);
  // returns true if and only if "val" exists in the tree.
  bool find(int val);
  // prints the tree elements in the in-order traversal order
  void print_inorder();
  
};


BST::BST()
{
  //printf("constructor\n");
}


  BST::~BST()
  {
      //free(root);
  }

void BST::insert(int val)
  {
    
    if(root==NULL)
    {
      struct node* newNode = new node;
      
      newNode->data = val;
      newNode->left = NULL;
      newNode->right = NULL;
      //printf("\n<insert>newNode->data %d\n",newNode->data);
      root = newNode;
      return;
    }

    struct node* tempNode = root;
    struct node* parentNode;

    while(tempNode!=NULL)
    {
        if(val < tempNode->data)
        {
          parentNode = tempNode;
          tempNode = tempNode->left;
        }
        else
        {
          parentNode = tempNode;
          tempNode = tempNode->right;
        }
    }
    struct node* newNode = new node;
    newNode = new node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;    
    if(val < parentNode->data)
      parentNode->left = newNode;
    else
      parentNode->right = newNode;


    return;
  }



    bool BST::find(int val)
  {
       if(root == NULL)
        {
          cout <<  "<find>root == NULL" << endl;
          return false;
        }
        //printf("<find>root->data %d\n",root->data);
    
        struct node* tempNode = root;

        while(tempNode!=NULL)
        {
          if(val < tempNode->data)
          {
            //cout << "<find>go left" << endl;
              tempNode = tempNode->left;
          }
          else if(val > tempNode->data)
          {
            //cout << "<find>go right" << endl;
            tempNode = tempNode->right;
          }
          
          else
          {
            //printf("<find>found! %d\n",tempNode->data);
            return true;
          }
        
        }
        
        return false;

  }


/*
the assignment requirement is not to change any function definition,
since this in order print doesn't take any parameters, so can't use recursion
use stack instead to do non-recursion way
1. create an empty stack S
2. init current node as root
3. Push the current node to S and set current = current->left until current is NULL
4. If current is NULL and stack is not empty then 
    a. pop the top item from stack
    b. print the popped item, set current = popped_item->right
    c. go to step 3
5. if current is NULL and stack is empty then we're done.
*/
   void BST::print_inorder()
  {
    
    printf("\n");
     stack<struct node*> node_stack;  //1.

      struct node* current = root;        //2.
      struct node* poped = root;

      while(current!=NULL)
      {
         node_stack.push(current);
         current = current->left;
      }
      //current becomes empty at this point
     while(!node_stack.empty())
     {
        poped = node_stack.top();
        printf("%d ,",poped->data);
        current =  poped->right;
        node_stack.pop();

        while(current!=NULL)
      {
         node_stack.push(current);
         current = current->left;
      }
     }

     if(current == NULL && node_stack.empty())
      return;

  }