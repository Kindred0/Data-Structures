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
        cout << "\nThe list is successfully deleted";
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
            type temp;
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
    void insertion_sort(void)
    {
        count = 0;
        if (!Sort)
        {
            Sort =true;
            int k ;
            type temp;
            for (int i = 1 ; i < length ; i++)
            {
                count = count + 1;
                temp = list[i];
                k = i - 1;
                while (k >= 0 && list[k] > temp)
                {
                    count = count + 1;
                    list[k + 1] = list[k];
                    k = k - 1;
                }
                list[k + 1] = temp;
            }
        }
    }
    void merge(int beg, int mid, int end)
    {
        int i , j = 0, k = beg;
        int n1 = mid - beg + 1;
        int n2 = end - mid;
        int leftlist[n1], rightlist[n2];
        for (i = 0 ; i < n1 ; i++)
        {
            count = count + 1;
            leftlist[i] = list[beg + i];
        }
        for (i = 0 ; i < n2 ; i++)
        {
            count = count + 1;
            rightlist[i] = list[mid + 1 + i];
        }
        i = 0;
        while (i < n1)
        {
            count = count + 1;
            if (leftlist[i] <= rightlist[j])
            {
                list[k] = leftlist[i];
                i = i + 1;
            }
            else 
            {
                list[k] = rightlist[j];
                j = j + 1;
            }
            k = k + 1;
        }
        while (i < n1)
        {
            count = count + 1;
            list[k] = leftlist[i];
            i = i + 1;
            k = k + 1;
        }
        while (j < n2)
        {
            count = count + 1;
            list[k] = rightlist[j];
            j = j + 1;
            k = k + 1;
        }
    }
    void merge_sort(int beg , int end) 
    {
        int mid;
        if (beg < end)
        {
            count = count + 1;
            mid = (beg + end)/ 2;
            merge_sort(beg, mid);
            merge_sort(mid + 1, end);
            merge(beg, mid ,end);
        }
    }
    void merge_sort(void)
    {
        count = 0;
        if (!Sort)
        {
            merge_sort(0, length - 1);
            Sort = true;
        }
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
};
int main()
{
    int n;
    cout << "\nEnter the number of elements in the array\t: ";
    cin >> n;
    List <int>A(n);
    cout << "\nSelection Sort\t:\n";
    A.selection_sort();
    A.print();
    cout << "\nComparisons done\t: " << A.get_count();
    cout << "\nEnter the number of elements in the array\t: ";
    cin >> n;
    List <int>B(n);
    cout << "\nBubble Sort\t:\n";
    B.bubble_sort();
    B.print();
    cout << "\nComparisons done\t: " << B.get_count();
    cout << "\nEnter the number of elements in the array\t: ";
    cin >> n;
    List <int>C(n);
    cout << "\nInsertion Sort\t:\n";
    C.insertion_sort();
    C.print();
    cout << "\nComparisons done\t: " << C.get_count();
    cout << "\nEnter the number of elements in the array\t: ";
    cin >> n;
    List <int>D(n);
    cout << "\nMerge Sort\t:\n";
    D.merge_sort();
    D.print();
    cout << "\nComparisons done\t: " << D.get_count();
    return 0;
}