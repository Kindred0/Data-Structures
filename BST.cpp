#include <iostream>
using namespace std;
class BST;
class node
{
    int info;
    node* right;
    node* left;
    node* parent;
    public :
    friend class BST;
    void create(int n )
    {
        info = n;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};
class BST
{
    node* root;
    public:
    BST(int n)
    {
        root = new node;
        root->create(n);
    }
    void insert(int n)
    {
        node* leaf = new node;
        leaf->create(n);
        node* head;
        node* child;
        child = root;
        while (true)
        {
            head = child;
            if (child->info <= n)
            {
                if (child->left == NULL)   
                {
                    child->left = leaf;
                    leaf->parent = child;
                    return;
                }
                else
                    child = child->left;
            }
            else 
            {
                if (child->right == NULL)   
                {
                    child->right = leaf;
                    leaf->parent = child;
                    return;
                }
                else
                    child = child->right;
            }
        }
    }
    void inorder()
    {
        inorder(root);
    }
    void inorder(node* head)
    {
        if (head->left != NULL)
            inorder(head->left);
        cout << head->info <<"\t";
        if (head->right != NULL)
            inorder(head->right);
    }
};
int main()
{
    int n;
    int action;
    cout << "\nEnter th number to be inserted into the trer\t: ";
    cin >> n;
    BST tree(n);
    while (true)
    {
        cout << "\nChoose an option\t: ";
        cout << "\n1\t: Insert a new node\n2\t: Delete a node\n3\t : Search for a node\n4\t: Exit";
        cout << "\nEnter an option\t: ";
        cin >> action;
        if (action == 1)
        {
            cout << "\nEnter a number to be inserted\t: ";
            cin >> n;
            tree.insert(n);
        }
        else if (action == 2)
        {
            return 0;
        }
        else if (action == 3)
        {
            cout << "\nChoose an option\t: ";
            cout << "\n2\t: Inorder Traversal";
            cin >> action;
            if (action == 2)
            {
                tree.inorder();
                break;
            }
            else 
                break;
        }
        else if (action == 4)
            return 0;
        else 
        {
            cout << "\nWrong input, Try again";
        }
    }
}