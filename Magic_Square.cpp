#include <iostream>
using namespace std;
class Magic_Square 
{
    int order;
    int** square;
    int sum;
    public :
    Magic_Square(const int n)
    {
        int i;
        int k;
        order = n;
        sum = (n * ((n * n ) + 1)) / 2;
        square = new int*[n];
        for (i = 0 ; i < n ; i++)
        {
            square[i] = new int[n];
            for (k = 0 ; k < n ; k++)
                square[i][k] = 0;
        }
        i = n / 2;
        k = n - 1;
        int element = 1;
        while (element <= (n * n))
        {
            if (i == -1 && k == n)
            {
                i = 0;
                k = n - 2;
            }
            else
            {
                if (i == -1)
                {
                    i = n - 1;
                }
                if (k == order)
                {
                    k = 0;
                }
            }
            if (square[i][k] == 0)
            {
                square[i][k] = element;   
            }
            else 
            {
                i++;
                k = k - 2;
                square[i][k] = element;
            }
            i--;
            k++;
            element++;
        }

    }
    ~Magic_Square()
    {
        for (int i = 0 ; i < order ; i++)
            delete[] square[i];
        delete[] square;
    }
    int get_sum()
    {
        return sum;
    }
    void display()
    {
        for (int i = 0 ; i < order ; i++)
        {
            cout << endl;
            for (int k = 0 ; k < order ; k++)
            {
                cout << square[i][k] << "\t";
            }
        }
    }
};
int main()
{
    int n;
    cout << "\nEnter the order of the magic square(Only odd orders)\t: ";
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "Not possible to obtain magic squares of even orders";
        return 0;
    }
    if (n < 3 )
    {
        cout << "Not possible to obtain magic squares of order less than 3";
        return 0;
    }
    Magic_Square M(n);
    cout << "Magic Square of order " << n << " * " << "n " << "with sum of " << M.get_sum();
    M.display();
    return 0;
}