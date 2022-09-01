#include <iostream>
using namespace std;
class Queue;
class node
{
    int info;
    node* next;
    public:
    friend class Queue;
    void create(int data)
    {
        info = data;
        next = NULL;
    }
};
class Queue
{
    node* Front;
    node* Rear;
    public: 
    Queue()
    {
        Front = NULL;
        Rear = NULL;
    }
    void push(int data)
    {
        node* New = new node;
        New->create(data);
        if (Front == NULL)
        {
            Front = New;
            Rear = New;
            return;
        }
        Rear->next = New;
        Rear = Rear->next;
    }
    int pop()
    {
        int data = Front->info;
        node* temp = Front;
        if (Front == NULL)
        {
            cout << "\nUnderflow";
            return -1;
        }
        if (Front == Rear)
        {
            Front = NULL;
            Rear = NULL;
        }
        else
        {
            Front = Front->next;
        }
        temp->next = NULL;
        delete temp;
        return data;
    }
    void display()
    {
        cout << "\n";
        node* point = Front;
        while (point != NULL)
        {
            cout << point->info << "\t";
            point = point->next;
        }
    }
    ~Queue()
    {
        node* point;
        node* save;
        point = Front;
        save = NULL;
        while (point == NULL)
        {
            save = point;
            point = point->next;
            delete save;
        }
        cout << "\nQueue destroyed";
    }
};
int main()
{
    Queue Q;
    int action;
    int data;
    while(true)
    {
        cout << "\nChoose an option\t: ";
        cout << "\n1 :\tPush\n2 :\tPop\n3 :\tDisplay\n4 :\tExit";
        cout << "\nEnter an option\t: ";
        cin >> action;
        if (action == 1)
        {
            cout << "\nEnter the element to be pushed\t: ";
            cin >> data;
            Q.push(data); 
        }
        if (action == 2)
        {
            data = Q.pop();
            cout << "\nThe element " << data << " from the list";
        }
        if (action == 3)
        {
            Q.display();
        }
        if (action == 4)
        {
            return 0;
        }
    }
}