#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node
{
   struct node *left;
   int data;
   struct node *right;
   int val;
   struct queue *next;
}*front=NULL, *rear=NULL;

struct node * insert(struct node *root, int item)
{
    struct node *x=root;
    struct node *par=NULL; //only for the first node it is set to null

    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;

    while(x!=NULL)
    {
        par=x;
        if(item < x->data)
        {
            x=x->left;
        }
        else
        {
            x=x->right;
        }
    }

    if(par==NULL)
    {
        par=temp;
    }
    else if(item < par->data)
    {
        par->left=temp;
    }
    else
    {
        par->right=temp;
    }
    return par;
}


void ins(struct node *item)
{
    struct node *temp;
    temp= (struct node *)malloc(sizeof(struct node));
    temp= item;

    if(rear == NULL)
    {
        front= temp;
        rear= temp;
    }
    else
    {
        rear->next= temp;
        rear= rear->next;
    }
}
struct queue* del()
{
   struct node *temp=front;
    if(front==rear)
    {
        front=rear=NULL;
    }
    else
    {
        front=front->next;
    }
    return temp;
}
void levelOrderTraversal(struct node* root)
{
    printf("\nThe level order traversal is:- \n");
    struct node  *temp = root;

    while(temp)
    {
        printf("%d\t", temp->data);

         if(temp->left)
            ins(temp->left);

         if(temp->right)
           ins(temp->right);

           temp = del();
    }
printf("\n\n");
}
int main()
{
    // Let us construct the tree shown in above figure
    int tot;
    struct node *root=NULL;
    printf("\nEnter the total no of nodes to be inserted in BST:- ");
    scanf("%d",&tot);
    int i,item;
    printf("\nEnter the elements:-\n");
    scanf("%d",&item);
    root=insert(root,item);
    for(i=0;i<tot-1;i++)
    {
        scanf("%d",&item);
        insert(root,item);
    }
    levelOrderTraversal( root );
}
