#include <iostream>
using namespace std;
class matrix
{
    int row, coloumn;
    int** element;
    friend class sparce_matrix;
    public :
    matrix(int r , int c)
    {
        row = r;
        coloumn = c;
        element = new int*[row];
        for (int i = 0 ; i < row ; i++)
        {
            element[i] = new int[coloumn];
            cout << "\nEnter " << coloumn << " elements seperated by space for row "<< i + 1 << "\t: ";
            for (int k = 0 ; k < coloumn ; k++)
            {
                cin >> element[i][k];
            }
        }

    }
    ~matrix()
    {
        for (int i = 0 ; i < row ; i++)
            delete[] element[i];
        delete[] element;
    }
    void display(void)
    {
        cout << "\n";
        for (int i = 0 ; i < row ; i++)
        {
            for (int k = 0 ; k < coloumn ; k++)
            {
                cout << element[i][k] << "\t";
            }
            cout << "\n";
        }
    }
    void saddlepoint(void)
    {
        int min, m, n;
        for (int i = 0 ; i < row ; i++)
        {
            min = element[i][0];
            m = 0;
            for (int k = 0 ; k < coloumn ; k++)
            {
                if (element[i][k] < min)
                {
                    min = element[i][k];
                    m = k;
                }
            }
            for (n = 0 ; n < row ; n++)
            {
                if (element[n][m] > min)
                    break;
            }
            if (n == row)
            {
                cout << "\nSaddle point at location [" << i+1 << "][" << m+1 << "] with element "<< min; 
            }
        }
    }
};
int main()
{
    int row , coloumn;
    cout << "\nEnter the rows and coloumns of the matrix respectivelyt: ";
    cin >> row >> coloumn;
    matrix M(row, coloumn);
    M.display();
    M.saddlepoint();
    return 0;
}
