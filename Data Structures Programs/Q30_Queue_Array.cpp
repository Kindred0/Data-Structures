#include <iostream>
using namespace std;
class Queue
{
    int list[10];
    int Front;
    int Rear;
    public:
    Queue()
    {
        Front = -1;
        Rear = -1;
    }
    void push(int data)
    {
        if (Front == Rear + 1 || (Front == 0 && Rear == 9))
        {
            cout << "\nOverflow";
            return;
        }
        if (Front == -1)
        {
            Front = 0;
            Rear = 0;
        }
        else if(Rear == 9)
            Rear = 0;
        else 
            Rear++;
        list[Rear] = data;
    }
    int pop()
    {
        if (Front == -1)
        {
            cout << "\nUnderflow";
            return -1;
        }
        int data;
        data = list[Front];
        if (Front == Rear)
        {
            Front = -1;
            Rear = -1;
        }
        else if (Front == 9)
            Front = 0;
        else 
            Front++;
        return data;
    }
    void display()
    {
        int point = Front;
        if (point == -1)
        {
            cout << "\nUnderflow";
            return;
        }
        cout <<"\n";
        while (point != Rear)
        {
            cout << list[point] << "\t";
            if (point == 9)
                point = 0;
            else 
                point++;
        }
        cout << list[Rear];
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
            cout << "\nEnter the data item\t: ";
            cin >> data;
            Q.push(data);
        }
        else if (action == 2)
        {
            data = Q.pop();
            cout << "\nThe element " << data << " popped from the list";
        }
        else if (action == 3)
        {
            Q.display();
        }
        else if (action == 4)
        {
            cout << "\nQueue destroyed";
            return 0;
        }
        else 
        {
            cout << "\nInvalid action, Try again";
        }
    }
}