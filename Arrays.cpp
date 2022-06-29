#include <iostream>
using namespace std;
template <class type>
class List
{
    int length, max_length, count;
    bool Sort = false;
    type* list;
    public:
    List(int n)
    {
        length = n;
        max_length = (5 * (length / 5)) + 5;
        list = new type[max_length];
        cout << "\nEnter " << n << " elements seperated by space\t: ";
        for (int i = 0 ; i < length ; i++)
            cin >> list[i];
    }
    ~List()
    {
        delete[] list;
        cout << "The list is successfully deleted";
    }
    void insert(type element, int position)
    {
        Sort = false;
        if (position > length + 1)
            position = length + 1;
        int i;
        length = length + 1;
        if (length % 5 == 0)
        {
            max_length = max_length + 5;
            type* templist = new type[length - 1];
            for (i = 0 ; i < length - 1; i++)
                templist[i] = list[i];
            delete[] list;
            list = new type[max_length];
            for (i = 0 ; i < position - 1 ; i++ )
                list[i] = templist[i];
            list[position - 1] = element;
            for (i = position ; i < length ; i++)
                list[i] = templist[i - 1];
            delete[] templist;
        }
        else 
        {
            for (i = length - 2 ; i >= position - 1 ; i--)
            {
                list[i + 1] = list[i]; 
            }
            list[position - 1] = element;
        }
        
    }
    void insert(type element)
    {
        length = length + 1;
        if (Sort)
        {
            for (int i = 0 ; i < length ; i++)
            {
                if (element <= list[i])
                {
                    if (length % 5 == 0)
                    {
                        max_length = max_length + 5;
                        type* templist = new type[length];
                        for (int k = 0 ; k < i ; k++)
                            templist[k] = list[k];
                        templist[i] = element;
                        for (int k = i + 1 ; k < length ; k++)
                            templist[k] = list[k-1];
                        delete[] list;
                        list = new type[max_length];
                        for (int k = 0 ; k < length ; k++)
                            list[k] = templist[k];
                        delete[] templist;
                    }
                    else 
                    {
                        for (int k = length - 2 ; k >= i ; k--)
                        {
                            list[k + 1] = list[k]; 
                        }
                        list[i] = element;
                    }
                    break;
                }
            }
        }
        else 
        {
            if (length % 5 == 0)
            {
                max_length = max_length + 5;
                type* templist = new type[length];
                for (int i = 0 ; i < length - 1 ; i++)
                    templist[i] = list[i];
                templist[length - 1] = element;
                delete[] list;
                list = new type[max_length];
                for (int i = 0 ; i < length ; i++)
                    list[i] = templist[i];
                delete[] templist;
            }
            else
                list[length - 1] = element;
        }
    }
    void deletion(type element)
    {
        int position = linear_search(element);
        if (position == -1)
        {
            cout << "\nNo such element in the list";
            return;
        }
        length = length - 1;
        int i;
        if (length % 5 == 4)
        {
            max_length = max_length - 5;
            type* templist = new type[length];
            for (i = 0 ; i < position - 1; i++)
                templist[i] = list[i];
            for (i = position - 1 ; i < length ; i++)
                templist[i] = list[i+1];
            delete[] list;
            list = new type[max_length];
            for (i = 0 ; i < length ; i++)
                list[i] = templist[i];
            delete[] templist;
        }
        else
        {
            for (i = position - 1 ; i < length ; i++)
            {
                list[i] == list[i+1];
            }
        }
    }
    int linear_search(type element)
    {
        count = 0;
        for (int i = 0 ; i < length ; i++)
        {
            count = count + 1;
            if (list[i] == element)
                return (i + 1);
        }
        return -1;
    }
    int binary_search(type element)
    {
        count = 0;
        if (!Sort)
        {
            cout << "\nThe list is not sorted";
            return -1;
        }
        int mid;
        int lower_bound = 0 ;
        int upper_bound = length - 1;
        while (lower_bound <= upper_bound)
        {
            count = count + 1;
            mid = (lower_bound + upper_bound)/2;
            if (list[mid] == element)
                return mid + 1;
            else if (list[mid] > element)
                upper_bound = mid - 1;
            else 
                lower_bound = mid + 1;
        }
        return -1;
    }
    void selection_sort(void)
    {
        count = 0;
        if (!Sort)
        {
            Sort = true;
            type temp;
            int min;
            for( int i = 0 ; i < length - 1 ; i++)
            {
                min = i;
                count = count + 1;
                for (int k = i + 1 ; k < length ; k++)
                {
                    count = count + 1;
                    if (list[k] < list[min])
                        min = k;
                }
                temp = list[min];
                list[min] = list[i];
                list[i] = temp;
            }
        }
    }
    void bubble_sort(void)
    {
        count = 0;
        if (!Sort)
        {
            int temp;
            Sort = true;
            for (int i = 0 ; i < length - 1 ; i++)
            {
                count = count + 1;
                for (int k = 0 ; k < length - i - 1 ; k++)
                {
                    count = count + 1;
                    if (list[k] > list[k+1])
                    {
                        temp = list[k];
                        list[k] = list[k+1];
                        list[k+1] = temp;
                    }
                }
            }
        }
    }
    void print_max(void)
    {
        cout << "Maximum Length of the list is " << max_length << "\n";
    }
    void print(void)
    {   
        for (int i = 0 ; i < length ; i ++)
            cout << list[i] << " ";
    }
    int get_count(void)
    {
        return count;
    }
    bool Is_sorted(void)
    {
        return Sort;
    }
};
int main()
{
    int n, element, position, action;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    List<int> Array(n);
    Array.print_max();
    while (true) 
    {
        cout << "\n1 :\tPrint List\n2 :\tAdd element to List\n3 :\tDelete element from List\n4 :\tSearch for an element\n5 :\tSort the list\n6 :\tPrint Maximum length\n7 :\tExit";
        cout <<"\n\nEnter an action\t: ";
        cin >> action;
        if (action == 1)
        {
            cout << "\n";
            Array.print();
        }
        else if (action == 2)
        {
            cout << "\nEnter the number to be inserted into the array\t: ";
            cin >> element;
            cout << "\nChoose action\nEnter 0 to automatically add the element in the appropriate position or \nEnter numbers other than 0 to forcefully add the element in the respective position\nEnter the action\t: ";
            cin >> position;\
            if (position < 0)
                position = position * -1;
            if (position == 0)
                Array.insert(element);
            else
                Array.insert(element, position);
        }
        else if (action == 3)
        {
            cout << "\nEnter the number to be deleted\t: ";
            cin >> element;
            Array.deletion(element);
        }
        else if (action == 4)
        {
            while (true)
            {
                cout << "\nEnter the type of search";
                cout << "\n1 :\tLinear Search\n2 :\tBinary Search\n3 :\tExit";
                cout << "\nEnter the action\t: ";
                cin >> action;
                cout << "Enter the element to be searched\t: ";
                cin >> element;
                if (action == 1)
                {
                    position = Array.linear_search(element);
                    if (position == -1)
                        cout << "\nThe entered element is not in the list";
                    else
                        cout << "\nThe element is in the position " << position;
                    cout << "\nComparisons done\t: " << Array.get_count();
                    break;
                }
                else if (action == 2)
                {
                    position = Array.binary_search(element);
                    if (position == -1)
                        cout << "\nThe entered element is not in the list or the list is not sorted";
                    else 
                        cout << "\nThe element is in the position " << position;
                    cout << "\nComparisons done\t: " << Array.get_count();
                    break;
                }
                else if (action == 3)
                {
                    break;
                }
                else 
                    cout << "\nInvalid input, Try again";
            }
        }
        else if (action == 5)
        {
            while (true)
            {
                cout << "\nEnter the type of sort";
                cout << "\n1 :\tSelection Sort\n2 :\tBubble Sort\n3 :\tExit";
                cout << "\nEnter the action\t: ";
                cin >> action;
                if (action == 1)
                {
                    Array.selection_sort();
                    Array.print();
                    cout << "\nComparisons done\t: " << Array.get_count();
                    break;
                }
                else if (action == 2)
                {
                    Array.bubble_sort();
                    Array.print();
                    cout << "\nComparisons done\t: " << Array.get_count();
                    break;
                }
                else if (action == 3)
                    break;
                else 
                    cout << "\nInvalid action, Try again";
            }
        }
        else if (action == 6)
        {
            Array.print_max();
        }
        else if (action == 7)
        {
            return 0;
        }
        else
        {
            cout << "Invalid action, try again";
        }
    }
} 