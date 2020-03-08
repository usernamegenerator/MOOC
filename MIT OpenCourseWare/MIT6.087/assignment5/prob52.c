#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int data;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* talloc(int data)
{
    struct tnode* newNode = (struct tnode*)malloc(sizeof(struct tnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct tnode* addnode(struct tnode* root, int data)
{
    struct tnode* p = NULL;
    //termination condition
    if(root == NULL)
    {
        //allocate node;
        //return new node;
        p = talloc(data);
        return p;
    }
    else if(data < root->data)
        root->left = addnode(root->left,data);
    else
        root->right = addnode(root->right,data);

    return root;
}

//root,left,right
void preorder(struct tnode* root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

//left,root,right
void inorder(struct tnode* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

//left,right,root
void postorder(struct tnode* root)
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int deltree(struct tnode* root)
{
    static int i = 0;

    if(root==NULL)
        return i;

    deltree(root->left);
    deltree(root->right);
    printf("%d ",root->data);
    free(root);
    i++;
    return i;
}

int main(void)
{
    struct tnode* root = NULL;
    root = addnode(root,3);
    root = addnode(root,1);
    root = addnode(root,0);
    root = addnode(root,2);
    root = addnode(root,8);
    root = addnode(root,6);
    root = addnode(root,5);
    root = addnode(root,9);

    printf("\npreorder, root, left , right\n");
    preorder(root);
    printf("\ninorder, left, root , right\n");
    inorder(root);
    printf("\npostorder, left , right, root\n");
    postorder(root);

    printf("\ndel\n");
    deltree(root);

    return 0;
}
