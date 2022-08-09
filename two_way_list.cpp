#include <iostream>
using namespace std;
class TwoWayList;
class Node
{
    int info;
    Node* previous;
    Node* next;
    public :
    ~Node()
    {
        delete previous;
        delete next;
    }
    friend class TwoWayList;
};
class TwoWayList
{
    Node* Start;
    Node* End;
    public :
    ~TwoWayList()
    {
        delete Start;
        delete End;
    }
    TwoWayList(){}
    TwoWayList(int n)
    {
        Start = new Node;
        Start->info = n;
        Start->next = End;
        Start->previous = Start;
        End = Start
    }
}