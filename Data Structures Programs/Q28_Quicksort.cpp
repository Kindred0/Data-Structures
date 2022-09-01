#include <iostream>
using namespace std;

int Quick_Scan(int* Array, int beg, int end)
{
    int temp;
    int loc = beg;
    int left = beg;
    int right = end;
    l1 :
    while (Array[loc] <= Array[right] && loc != right)
        right--;
    if (loc == right)
        return loc;
    else if (Array[loc] > Array[right])
    {
        temp = Array[loc];
        Array[loc] = Array[right];
        Array[right] = temp;
        loc = right;
    }
    while (Array[loc] >=Array[left] && left != loc)
        left++;
    if (loc == left)
        return loc;
    else if (Array[loc] < Array[left])
    {
        temp = Array[loc];
        Array[loc] = Array[left];
        Array[left] = temp;
        loc = left;
        goto l1;
    }
    return -1;
}

void Quick_sort(int* Array, int length)
{
    int upper[15];
    int lower[15];
    int top = -1;
    int beg = 0; 
    int end = length - 1;
    int loc;
    top++;
    upper[top] = end;
    lower[top] = beg;
    while (top != -1)
    {
        beg = lower[top];
        end = upper[top];
        top--;
        loc = Quick_Scan(Array, beg, end);
        if (beg < loc - 1)
        {
            top++;
            lower[top] = beg;
            upper[top] = loc - 1;
        }
        if (loc + 1 < end)
        {
            top++;
            lower[top] = loc + 1;
            upper[top] = end;
        }
    }
}
int main()
{
    int Array[10];
    int i;
    cout << "\nEnter 10 elements seperated by space\t: ";
    for (i = 0 ; i < 10 ; i++)
        cin >> Array[i];
    cout << "\nThe Entered list\t: \n";
    for (i = 0 ; i < 10 ; i++)
        cout << Array[i] << "\t";
    Quick_sort(Array, 10);
    cout << "\nThe sorted list\t: \n";
    for (i = 0; i < 10 ; i++)
        cout << Array[i] << "\t";
    return 0;
}