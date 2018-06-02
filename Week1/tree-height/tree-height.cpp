#include<bits/stdc++.h>
using namespace std;
 
// A tree node
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// Utility function to create new Node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}
 int maxDepth(struct Node* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
       /* use the larger one */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 
// Creates a node with key as 'i'.  If i is root, then it changes
// root.  If parent of i is not created, then it creates parent first
void createNode(int parent[], int i, Node *created[], Node **root)
{
    // If this node is already created
    if (created[i] != NULL)
        return;
 
    // Create a new node and set created[i]
    created[i] = newNode(i);
 
    // If 'i' is root, change root pointer and return
    if (parent[i] == -1)
    {
        *root = created[i];
        return;
    }
 
    // If parent is not created, then create parent first
    if (created[parent[i]] == NULL)
        createNode(parent, parent[i], created, root);
 
    // Find parent pointer
    Node *p = created[parent[i]];
 
    // If this is first child of parent
    if (p->left == NULL)
        p->left = created[i];
    else // If second child
        p->right = created[i];
}
 
// Creates tree from parent[0..n-1] and returns root of the created tree
Node *createTree(int parent[], int n)
{
    // Create an array created[] to keep track
    // of created nodes, initialize all entries
    // as NULL
    Node *created[n];
    for (int i=0; i<n; i++)
        created[i] = NULL;
 
    Node *root = NULL;
    for (int i=0; i<n; i++)
        createNode(parent, i, created, &root);
 
    return root;
}
 
//For adding new line in a program
inline void newLine(){
    cout << "\n";
}
 

 
// Driver method
int main()
{    int n;
     cin>>n;
     int parent[n];
     for(int i=0;i<n;i++){
     	cin>>parent[i];
     }
    //int n = sizeof parent / sizeof parent[0];
    Node *root = createTree(parent, n);
    
    //inorder(root);
    cout<<maxDepth(root);
    newLine();
}
