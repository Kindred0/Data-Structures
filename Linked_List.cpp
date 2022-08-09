#include <iostream>
using namespace std;
class linklist;
class node 
{
    int info;
    node* next;
    public :
    friend class linklist;
    node()
    {
        next = NULL;
    }
    node(int n)
    {
        info = n;
        next = NULL;
    }
    ~node()
    {
        delete next;
    }
};
class linklist
{
    int no;
    node* start;
    public:
    linklist()
    {
        no = 0;
        start = NULL;
    }
    linklist(int n)
    {
        no = 1;
        start = new node;
        start->info = n;
        start->next = NULL;
    }
    ~linklist()
    {
        delete start;
    }
    void insert(int n)
    {
        no++;
        node* point = start;
        while (point->next != NULL)
            point = point->next;
        point->next = new node(n);
    }
    void insert(int n , int pos)
    {
        no++;
        node* temp;
        node* point = start;
        int i = 0;
        while (point->next != NULL && i < pos)
        {
            point = point->next;
            i++;
        }
        temp  = point->next;
        if (point->next != NULL)
            delete point->next;
        point->next = new node;
        point = point->next;
        point->info = n; 
        point->next = temp;
    }
    void display()
    {
        node* point = start;
        if (start == NULL)
        {
            cout << "\nNo elements in the list";
            return;
        }
        cout << "\n" ;
        cout << point->info << "\t";
        int i = 0;
        while (point->next != NULL && i < no)
        {
            point = point->next;
            cout << point->info << "\t";
            i++;
        }
    }
    void remove(int n)
    {
        no--;
        node* temp;
        node* point = start;
        while (point->next != NULL)
        {
            point = point->next;
            if ((point->next)->info == n)
            {
                temp = (point->next)->next;
                delete (point->next)->next;
                delete point->next;
                point->next = temp;
                return;
            }
        }
        cout << "\nNo such element in the list";
        return;
    }
};
int main()
{
    int action;
    int n, pos;
    cout << "\nEnter a number\t: ";
    cin >> n;
    linklist list(n);
    while (true)
    {
        cout << "\nChoose an action\t: ";
        cout << "\n1 :\tInsert a new node\n2 :\tDelete a node\n3 :\tDisplay the list\n4 :\tExit";
        cout << "\nEnter action\t: ";
        cin >> action;
        if (action == 1)
        {
            cout << "\nEnter the element to be inserted\t: ";
            cin >> n;
            cout << "Enter the position of the element to be inserted\t: ";
            cin >> pos;
            list.insert(n, pos);
        } 
        else if (action == 2)
        {
            cout << "\nEnter the element to be deleted\t: ";
            cin >> n;
            list.remove(n);
        }
        else if (action == 3)
            list.display();
        else if (action == 4)
            return 0;
        else 
            cout << "\nInvalid input, try again";
    }
}