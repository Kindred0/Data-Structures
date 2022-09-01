#include <iostream>
using namespace std;
template <class type>
class List
{
    int length, count;
    type* list;
    public:
    List(int n)
    {
        length = n;
        list = new type[length];
        cout << "\nEnter " << n << " elements seperated by space\t: ";
        for (int i = 0 ; i < length ; i++)
            cin >> list[i];
        type temp;
        for (int i = 0 ; i < length - 1 ; i++)
        {
            for (int k = 0 ; k < length - i - 1 ; k++)
            {
                if (list[k] > list[k+1])
                {
                    temp = list[k];
                    list[k] = list[k+1];
                    list[k+1] = temp;
                }
            }
        }
    }
    ~List()
    {
        delete[] list;
        cout << "\nThe list is successfully deleted";
    }
    List()
    {
        length = 0; 
        list = new type[1];
    }
    void print(void)
    {   
        for (int i = 0 ; i < length ; i ++)
            cout << list[i] << " ";
    }
    void merge(List A , List B)
    {
        delete[] list;
        length = A.length + B.length;
        list = new type[length];
        int i = 0 , k = 0 , m = 0 ;
        while ( k < A.length && m < B.length)
        {
            if (A.list[k] < B.list[m])
            {
                list[i] = A.list[k];
                k = k + 1;
            }
            else 
            {
                list[i] = B.list[m];
                m = m + 1;
            }
            i = i + 1;
        }
        if (k < A.length)
        {
            while (k < A.length)
            {
                list[i] = A.list[k];
                i = i + 1;
                k = k + 1;
            }
        }
        if (m < B.length)
        {
            while (m < B.length)
            {
                list[i] = B.list[m];
                i = i + 1;
                m = m + 1;
            }
        }
    } 
};
int main()
{
    int size;
    cout << "\nEnter the size of the first array A\t: ";
    cin >> size;
    List <int>A(size);
    cout << "\nEnter the size of the second array B\t: ";
    cin >> size;
    List <int>B(size);
    cout << "\nSorted array A\t: \n";
    A.print();
    cout << "\nSorted array B\t: \n";
    B.print();
    List <int>C;
    C.merge(A, B);
    cout << "\nMerged array\t: \n";
    C.print();
    return 0;
}