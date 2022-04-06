#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* left;                       //set ups nodes
    struct node* right;
    int data;
};

void printCurrentLevel(struct node* root, int level);
int height(struct node* node);                            //creates all the variables to be used and set up a function for current level
struct node* newNode(int data);

void printLevelOrder(struct node* root)                       //prints the level in order
{
    int h = height(root);                                     //use the height to see how many times it goes through                                                  
    int i;
    for (i = 1; i <= h; i++)                                   //for loop
        printCurrentLevel(root, i);                           //prints current level
}

void printCurrentLevel(struct node* root, int level)          //prints current level
{
    if (root == NULL)                                          //checks if roots = null
        return;
    if (level == 1)                                            //prints the level
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);              //goes down the list
        printCurrentLevel(root->right, level - 1);
    }
}

int height(struct node* node)                                        //finds the height of the tree
{
    if (node == NULL)                                                  //checks if node is null
        return 0;
    else {
        int lheight = height(node->left);                             //checks the height of the left root
        int rheight = height(node->right);                           // checks the height of the right root
        if (lheight > rheight)
            return (lheight + 1);                                     //returns the heights
        else
            return (rheight + 1);
    }
}
struct node* newNode(int data)                                           //creates a new node
{
    struct node* node = (struct node*)malloc(sizeof(struct node));       //finds size
    node->data = data;
    node->left = NULL;                                                   //adds node to null value
    node->right = NULL;
 
    return (node);                                                       //returns it to the main function
}

void createTree(struct node** root, int data)                          
{
    struct node* temp=(struct node*)malloc(sizeof (struct node));      //finds size of nodes to create tree
    temp->data =data;
    temp->left =NULL;
    temp->right =NULL;                                                  //creates branches and set their value to null
    struct node* t=*root;
    if (*root ==NULL)
    {
        *root =temp;                                                   //if a root is empty return
        return;
    }
    if(data<t->data)
    createTree(&(t->left),data);                                      //adds data to tree left
    else
    createTree(&(t->right),data);                                    //adds data to tree right
}


void printPostorder (struct node* root)                             //prints postorder
{
    if(root!=NULL)                                                //checks if root is null
    {
        printPostorder(root->left);                                //prints left root
        printPostorder(root->right);                               //prints right root
        printf("%d ",root->data);
    }
}
void printInorder(struct node* node)                            //prints in order
{
    if (node == NULL)                                         //checks if node is null
        return;
    printInorder(node->left);                                //checks left
    printf("%d ", node->data);                              //prints the data
    printInorder(node->right);                               //checks right
}
void printPreorder(struct node* node)                       //prints pre order
{
    if (node == NULL)                                        //checks if node is null
        return;
    printf("%d ", node->data);                              //checks left node
    printPreorder(node->left);
    printPreorder(node->right);                           //checks right node
}

int main()
{
    struct node* root=NULL;                                  //set root to null
    int i,n,data;
    printf("Enter the number of elements: ");                 //asks user for elements (nodes)
    scanf("%d",&n);
    printf("Enter %d elements of the tree: ",n);               //enters elements into a tree
    for (i=0;i<n;i++)                                          //adds data by using a for loop
    {
        scanf("%d",&data);
        createTree(&root,data);
    }
    printf("\nPre-order traversal: \n");                      //prints post traversal
    printPreorder(root);
    printf("\nIn-order traversal: \n");                         //prints in order traversal
    printInorder(root);
    printf("\nPost-order traversal: \n");                      //prints postorder traversal
    printPostorder(root);
    printf("\nBreath-first traversal: \n");                  //prints breath first traversal
    printLevelOrder(root);
}
