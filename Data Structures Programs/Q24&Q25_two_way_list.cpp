#include <iostream>
using namespace std;
class TwoWayList;
class Node
{
    int info;
    Node* previous;
    Node* next;
    public :
    void create(int data)
    {
        info = data;
        previous = NULL;
        next = NULL;
    }
    friend class TwoWayList;
};
class TwoWayList
{
    int count;
    Node* Left;
    Node* Right;
    Node* Find(int item)
    {
        Node* loc;
        if (Left == NULL)
        {
            loc = NULL;
            return loc;
        }
        if (item < Left->info)
        {
            loc = NULL;
            return loc;
        }
        Node* save = Left;
        Node* point = Left->next;
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
    public :
    TwoWayList()
    {
        Left = NULL;
        Right = NULL;
        count = 0;
    }
    void insert(int item)
    {
        Node* New = new Node;
        New->create(item);
        if (Left == NULL)
        {
            Left = New;
            Right = New;
            return;
        }
        Node* loc = Find(item);
        if (loc == NULL)
        {
            New->next = Left;
            Left = New;
        }
        if (loc == Right)
        {
            New->previous = loc;
            Right = New;
        }
        else
        {
            New->next = loc->next;
            New->previous = loc;
            (loc->next)->previous = New;
            loc->next = New;
        }
    }
    void remove(int item)
    {
        Node* save;
        Node* point;
        if (Left == NULL)
        {
            point = NULL;
            save = NULL;
            goto l1;
        }
        if (Left->info == item)
        {
            point = Left;
            save = NULL;
            goto l1;
        }
        save = Left;
        point = Left->next;
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
            Left = Left->next;
            Right = Right->previous;
            point->next = NULL;
            point->previous = NULL;
            delete point;
        }
        else 
        {
            save->next = point->next;
            (point->next)->previous = save;
            point->next = NULL;
            point->previous = NULL;
            delete point;
        }
    }
    int search(int data)
    {
        int tempcount = 1;
        Node* point = Left;
        if (Left == NULL)
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
        Node* point;
        Node* save;
        point = Left;
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
        Node* point;
        point = Left;
        if (Left == NULL)
        {
            cout << "\nNo element in the list";
            return;
        }
        cout << "\n";
        while(point->next != NULL)
        {
            cout << point->info << "\n";
            point = point->next;
        }
    }
};
int main()
{
    TwoWayList List;
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
            List.remove(data);
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