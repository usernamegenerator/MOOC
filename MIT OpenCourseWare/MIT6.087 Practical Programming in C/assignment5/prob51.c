#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

//struct node* head;

//create a new node
struct node* nalloc(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode!=NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

//add elements to the front
struct node* addFront(struct node* head, int data)
{
    struct node* newNode = nalloc(data);
    if(newNode!=NULL)
    {
        if(head==NULL)
            return newNode;
        else
            newNode->next = head;
    }
    else
    {
        return head;
    }
    //return the new head;
    return newNode;
}

//displays all the elements of the list
void display(struct node* head)
{
    if(head == NULL)
    {
        printf("NULL head\n");
        return;
    }

    for(struct node* p = head; p!=NULL; p = p->next)
    {
        printf("%d ",p->data);
    }
    printf("\n");
}

struct node* addback(struct node* head, int data)
{
    struct node* newNode = nalloc(data);

    if(head==NULL)
        return newNode;

    struct node* p = head;
    while(p->next!=NULL)
        p=p->next;
    p->next = newNode;
    newNode = NULL;

    return head;
}

struct node* find(struct node* head, int data)
{
    for(struct node* p = head; p!=NULL; p = p->next)
    {
        if(p->data == data)
            return p;
    }
    return NULL;
}

struct node* delnode(struct node* head, struct node* pelement)
{
    struct node* found = find(head,pelement->data);
    if(found==NULL)
    {
        return head;
    }
    else if(found == head)
    {
        if(head->next == NULL)
        {
            free(head);
            return NULL;
        }
        head = head->next;
        return head;
    }
    else
    {
        struct node* pre = head;
        while(pre->next != NULL)
        {
            if(pre->next->data == pelement->data)
            {
                break;
            }
            pre = pre->next;
        }
        pre->next = found->next;
        free(found);
        return head;
    }
}

void freelist(struct node* head)
{
    struct node* toDel = NULL;
    while(head->next != NULL)
    {
        toDel  = head->next;
        head->next = toDel->next;
        delnode(head,toDel);
    }
    //delnode(head,head->next);
    delnode(head,head);
}

int main(void)
{
    printf("\ntest nlloc\n");
    struct node* head = nalloc(5);
    struct node* temp = NULL;
    printf("\ntest addback, addFront, and display\n");
    head = addback(head,6);
    head = addFront(head,4);
    head = addback(head,7);
    head = addFront(head,3);
    head = addback(head,8);
    display(head);
    head = addFront(head,2);
    head = addFront(head,1);
    head = addback(head,9);
    display(head);

    printf("\ntest find with valid in middle;\n");
    temp = find(head,7);
    if(temp==NULL) printf("found NULL\n");
    else printf("found temp %d\n",temp->data);

    printf("\ntest find with invalid;\n");
    temp = find(head,18);
    if(temp==NULL) printf("found NULL\n");
    else printf("found temp %d\n",temp->data);

    printf("\ntest find with valid at head;\n");
    temp = find(head,1);
    if(temp==NULL) printf("found NULL\n");
    else printf("found temp %d\n",temp->data);

    printf("\ntest find with valid at tail;\n");
    temp = find(head,9);
    if(temp==NULL) printf("found NULL\n");
    else printf("found temp %d\n",temp->data);


    printf("\ntest delnode at head\n");
    display(head);
    temp = find(head,1);
    head = delnode(head,temp);
    display(head);

    printf("\ntest delnode at tail\n");
    temp = find(head,9);
    head = delnode(head,temp);
    display(head);

    printf("\ntest delnode in the middle\n");
    temp = find(head,4);
    head = delnode(head,temp);
    display(head);

    printf("\ntest freelist\n");
    freelist(head);
    //wild pointer head;
}
