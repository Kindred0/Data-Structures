#include <iostream>
using namespace std;
class head;
class node
{
    int info;
    node* next;
    head* start;
    public:
    void create(int n)
    {
        info = n;
        next = NULL;
    }
    friend class head;
};
class head
{
    int count;
    head* start;
    node* next;
    public:
};
int main()
{

}