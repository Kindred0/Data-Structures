#include <iostream>
using namespace std;
class Linklist;
class node
{
    int info;
    node* next;
    public:
    void create(int n)
    {
        info = n;
        next = NULL;
    }
    friend class Linklist;
};
class Linklist
{
    int count;
    node* start;
    node* Find(int item)
    {
        node* loc;
        if (start == NULL)
        {
            loc = NULL;
            return loc;
        }
        if (item < start->info)
        {
            loc = NULL;
            return loc;
        }
        node* save = start;
        node* point = start->next;
        while (point != NULL)
        {
            if (item < point->info)
            {
                loc = save;
                return loc;
            }
            save = point;
            point = point->next;
        }
        loc = save;
        return loc;
    }
    public:
    Linklist()
    {
        count = 0;
        start = NULL;
    }
    void insert(int item)
    {
        node* loc = Find(item);
        node* New = new node;
        New->create(item);
        if (loc == NULL)
        {
            New->next = start;
            start = New;
        }
        else
        {
            New->next = loc->next;
            loc->next = New;
        }
    }
    void remove(int item)
    {
        node* save;
        node* point;
        if (start == NULL)
        {
            point = NULL;
            save = NULL;
            goto l1;
        }
        if (start->info == item)
        {
            point = start;
            save = NULL;
            goto l1;
        }
        save = start;
        point = start->next;
        while (point != NULL)
        {
            if (point->info == item)
            {
                break;
            }
            else
            {
                save = point;
                point = point->next;
            }
        }
        l1:
        if (point == NULL)
        {
            cout << "\nElement not in list or underflow";
        }
        if (save == NULL)
        {
            start = start->next;
            point->next = NULL;
            delete point;
        }
        else 
        {
            save->next = point->next;
            point->next = NULL;
            delete point;
        }
    }
    int search(int data)
    {
        int tempcount = 1;
        node* point = start;
        if (start == NULL)
        {
            cout << "\nUnderflow";
            return 0;
        }
        if (data == point->info)
            return 1;
        while(point->next != NULL)
        {
            tempcount++;
            point = point->next;
            if (point->info == data)
                return tempcount;
        }
        return -1;
    }
    void Destroy()
    {
        node* point;
        node* save;
        point = start;
        save = NULL;
        if (point == NULL)
        {
            cout << "\nUnderflow";
            return;
        }
        while(point->next != NULL)
        {
            save = point;
            point = point->next;
            delete save;
        }
        delete point;
        cout << "\nList Destroyed";
    }
    void display()
    {
        node* point = start;
        if (point == NULL)
        {
            cout << "\nNo element in the list";
            return;
        }
        cout << point->info << "\t";
        while (point->next != NULL)
        {
            point = point->next;
            cout << point->info << "\t";
        }
    }
};
int main()
{
    Linklist List;
    int data;
    int action;
    int pos;
    while (true)
    {
        cout << "\n1 :\tInsert an element to the list\n2 :\tRemove an element from the list\n3 :\tDisplay the list\n4 :\tSearch for an element\n5 :\tExit";
        cout << "\nSelect an option\t: ";
        cin >> action;
        if (action == 1)
        {
            cout << "\nEnter the element to be inserted\t: ";
            cin >> data;
            List.insert(data);
        }
        else if (action == 2)
        {
            cout << "\nEnter the element to be removed\t: ";
            cin >> pos;
            List.remove(pos);
        }
        else if (action == 3)
        {
            List.display();
        }
        else if (action == 4)
        {
            cout << "\nEnter the element to be searched\t: ";
            cin >> data;
            pos = List.search(data);
            if (pos == -1)
                cout << "\nThe element is not in the list";
            else if (pos == 0)
                cout << "\nThe list is empty";
            else if(pos > 0)
                cout << "\nThe element is in the position " << pos;
        }
        else if (action == 5)
        {
            List.Destroy();
            return 0;
        }
        else
        {
            cout << "Invalid action, Try again";
        }
    }
}
