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
    void destroy(node* head)
    {
        if (head->left != NULL)
            destroy(head->left);
        if (head->right != NULL)
            destroy(head->right);
        cout << "\n Node destroyed with info " << head->info;
        delete this;
    }
    void destroy(void)
    {
        destroy(root);
    }
    void insert(int n)
    {
        if (root == NULL)
        {
            root = new node;
            root->create(n);
            return;
        }
        node* leaf = new node;
        leaf->create(n);
        node* head;
        node* child;
        child = root;
        while (true)
        {
            head = child;
            if (child->info >= n)
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
    void reattach(node* node1, node* node2)
    {
        node* child;
        child = node1;
        while (true)
        {
            if (node2->info <= node1->info)
            {
                if (child->left == NULL)
                {
                    child->left = node2;
                    node2->parent = child;
                }
                else 
                    child = child->left;
            }
            else
                if (child->right == NULL)
                {
                    child->right = node2;
                    node2->parent = child;
                }
                else 
                    child = child->right;
        }
    }
    void remove(int n)
    {
        if(root == NULL)
        {
            cout << "\nNo element in the tree";
        }
        node* head;
        node* child;
        node* temp;
        child = root;
        while (child != NULL)
        {
            head = child;
            if (n > child->info)
            {
                child = child->right;
            }
            else if (n < child->info)
            {
                child = child->left;
            }
            else
            {
                if (child->left == NULL && child->right == NULL)
                {
                    if (head->left == child)
                        head->left == NULL;
                    else 
                        head->right == NULL;
                    destroy(child);
                }
                else if (child->left == NULL)
                {
                    if (head->left == child)
                        head->left = child->right;
                    else 
                        head->right = child->right;
                    child->right = NULL;
                    destroy(child);
                }
                else if (child->right == NULL)
                {
                    if (head->left == child)
                        head->left = child->left;
                    else 
                        head->right = child->left;
                    child->left = NULL;
                    destroy(child);
                }
                else 
                {
                    temp = child->left;
                    while(true)
                    {
                        if (temp->left == NULL && temp->right == NULL)
                            break;
                        if (temp->right != NULL)
                            temp = temp->right;
                        else if (temp->left != NULL)
                            temp = temp->left;
                    }
                    if (head->left == child)
                        head->left = temp;
                    else 
                        head->right = temp;
                }
            }
        }

    }
    void inorder()
    {
        if (root != NULL)
            inorder(root);
        else 
            cout << "\nNo element in the Tree";
    }
    void inorder(node* head)
    {
        if (head->left != NULL)
            inorder(head->left);
        cout << head->info <<"\t";
        if (head->right != NULL)
            inorder(head->right);
    }
    void preorder()
    {
        if (root != NULL)
            preorder(root);
        else 
            cout << "\nNo element in the Tree";
    }
    void preorder(node* head)
    {
        cout << head->info << "\t";
        if (head->left != NULL)
            preorder(head->left);
        if (head->right != NULL)
            preorder(head->right);
    }
    void postorder()
    {
        if (root != NULL)
            postorder(root);
        else 
            cout << "\nNo element in the Tree";
    }
    void postorder(node* head)
    {
        if (head->left != NULL)
            postorder(head->left);
        if (head->right != NULL)
            postorder(head->right);
        cout << head->info << "\t";
    }
};
int main()
{
    int n;
    int action;
    cout << "\nEnter the number to be inserted into the tree\t: ";
    cin >> n;
    BST tree(n);
    while (true)
    {
        cout << "\nChoose an option\t: ";
        cout << "\n1 :\tInsert a new node\n2 :\tDelete a node\n3 :\tTraverse through the Tree\n4 :\tExit";
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
            cout << "\nStill not coded thank you :)";
            break;
        }
        else if (action == 3)
        {
            cout << "\nChoose an option\t: ";
            cout << "\n1 :\tPreorder Traversal\n2 :\tInorder Traversal\n3 :\tPostoreder Traversal\n4 :\tExit";
            cout << "\nEnter an action\t: ";
            cin >> action;
            while (true)
            {
                if (action == 1)
                {
                    tree.preorder();
                    break;
                }
                else if (action == 2)
                {   
                    tree.inorder();
                    break;
                }
                else if (action == 3)
                {
                    tree.postorder();
                    break;
                }
                else if (action == 4)
                {
                    break;
                }
                else 
                    cout << "\nWrong Input, Try again";
            }
        }
        else if (action == 4)
        {
            tree.destroy();
            return 0;
        }
        else 
        {
            cout << "\nWrong input, Try again";
        }
    }
}