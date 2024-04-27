#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void PreOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
        
    }
}
struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node)); // allocating memory in heap
    n->data = data;                                              // create a node
    n->left = NULL;                                              // left null
    n->right = NULL;                                             // right null
    return n;
}

int main()
{
    // constructing a tree
    //     4
    //    / \
//       7   9
    //  / \
//     8   2
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    PreOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);

    return 0;
}
