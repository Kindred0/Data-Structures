#include <iostream>
using namespace std;
class node
{
    int info;
    node* next;
    node* previous;
    public :
    void create(int data)
    {
        info = data;
        next = NULL;
        previous = NULL;
    }
    friend class Twowaylist;
};
class Twowaylist
{
    node* beg;
    node* end;
    public :
    Twowaylist()
    {
        beg = NULL;
        end = NULL;
    }
    node* get_address(int pos)
    {
        node* point = beg;
        while(point != NULL && pos > 0)
        {
            point = point->next;
            pos--;
        }
        return point;
    }
    void insert(int data, node* loc)
    {
        node* New = new node;
        New->create(data);
        if (beg == NULL)
        {
            beg = New;
            end = New;
            return;
        }
        New->next = loc->next;
        New->previous = loc;
        loc->next->previous = New;
        loc->next = New;
    }
    void display()
    {
        node* point = beg;
        cout << "\n";
        while (point != NULL)
        {
            cout << point->info << "\t";
            point = point->next;
        }
    }
    void Destroy()
    {
        node* point = beg;
        node* save = NULL;
        while(point != NULL)
        {
            save = point;
            point = point->next;
            delete save;
        }
        cout << "\nList destroyed";
    }
};
int main()
{
    int action;
    int data;
    int pos;
    Twowaylist list;
    while(true)
    {
        cout << "\nChoose an action\t: ";
        cout << "\n1 :\tInsert\n2 :\tRemove\n3 1:\tDisplay\n4 :\tSearch\n5 :\tExit";
        cout << "\nEnter option";
        cin >> action;
        if (action == 1)
        {
            cout << "\nEnter the element";
            cin >> data;
            cout << "\nEnter the position";
            cin >> pos;
            list.insert(data, list.get_address(pos));
        }
        else if (action == 2)
        {
            cout << "\nWork in progress";
        }
        else if (action == 3)
        {
            list.display();
        }
        else if (action == 4)
        {
            cout << "\nWork in progress";
        }
        else if (action == 5)
        {
            list.Destroy();
            return 0;
        }
        else 
        {
            cout << "\nInvalid Input, Try Again";
        }
    }
}