#include <iostream>
using namespace std;
class stack
{
    int* list;
    int size;
    int top;
    public:
    stack(int n)
    {
        top = -1;
        size = n;
        list = new int[n];
    }
    ~stack()
    {
        cout << "\nStack deleted";
        delete[] list;
    }
    void push(int n)
    {
        top++;
        if (top == size)
        {
           cout << "\nStack Overflow";
           top--;
           return; 
        }
        list[top] = n;
    }
    int pop()
    {
        int n;
        if (top == -1)
        {
            cout << "\nStack Underflow";
            return 0;
        }
        n = list[top];
        top--;
        return n;
    }
};
int main()
{
    int action;
    int n;
    cout << "\nEnter the size of the stack\t: ";
    cin >> n;
    stack S(n);
    while(true)
    {
        cout << "\nChoose option\n";
        cout << "\n1 :\tPush\n2 :\tPop\n3 :\tExit";
        cout << "\n\nEnter an action\t: ";
        cin >> action;
        if (action == 1)
        {
            cout << "\nEnter the element to be stored\t: ";
            cin >> n;
            S.push(n);
        }
        else if (action == 2)
        {
            n = S.pop();
            cout << "\nElement " << n << " popped from the list";
        }
        else if (action == 3)
        {
            return 0;
        }
        else 
        {
            cout << "\nInvalid action, try again";
        }
    }
}