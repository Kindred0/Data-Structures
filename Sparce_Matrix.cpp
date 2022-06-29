#include <iostream>
using namespace std;
class sparce_matrix;
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
};
class sparce_matrix
{
    int* row;
    int* coloumn;                   // The rows and coloumns of the original matrix
    int* length;                    // The length of the sparce matrix ie the no of non zero elements
    int max_length;                 // The maximum length of the sparce matrix
    int* element[3];
    //friend class matrix;
    public :
    sparce_matrix()
    {
        max_length = 5;
        for (int i = 0 ; i < 3 ; i++)
        {
            element[i] = new int[max_length];
        }
        row = &element[0][0];
        coloumn = &element[1][0];
        length = &element[2][0];
        element[0][0] = 0;
        element[1][0] = 0;
        element[2][0] = 0;
    }
    void convert(matrix A)
    {
        int count = 0;
        for (int i = 0 ; i < A.row ; i++ )
        {
            for (int k = 0 ; k < A.coloumn ; k++)
            {
                if (A.element[i][k] != 0)
                    count = count + 1;
            }
        }
        max_length =  (5 * ((count + 1) / 5)) + 5;
        for (int i = 0 ; i < 3 ; i++)
        {
            delete[] element[i];
            element[i] = new int[max_length];
        }
        element[0][0] = A.row;
        element[1][0] = A.coloumn;
        element[2][0] = count;
        row = &element[0][0];
        coloumn = &element[1][0];
        length = &element[2][0];
        int m = 1;
        for (int i = 0 ; i < *row ; i++)
        {
            for (int k = 0 ; k < *coloumn ; k++)
            {
                if (A.element[i][k] != 0)
                {
                    element[0][m] = i;
                    element[1][m] = k;
                    element[2][m] = A.element[i][k];
                    m = m + 1;
                }
            }
        }
    }
    sparce_matrix(const sparce_matrix& A)
    {
        cout << "\nCopy Constructor is called\n";
        max_length = A.max_length;
        for (int i = 0 ; i < 3 ; i++)
        {
            delete[] element[i];
            element[i] = new int[max_length];
            for (int k = 1 ; k <= A.element[2][0] ; k++)
            {
                element[i][k] = A.element[i][k];
            }
            element[0][0] = *A.row;
            element[1][0] = *A.coloumn;
            element[2][0] = *A.length;
            row = &element[0][0];
            coloumn = &element[1][0];
            length = &element[2][0]; 
        }
    }
    sparce_matrix(matrix A)
    {
        int count = 0;
        for (int i = 0 ; i < A.row ; i++ )
        {
            for (int k = 0 ; k < A.coloumn ; k++)
            {
                if (A.element[i][k] != 0)
                    count = count + 1;
            }
        }
        max_length =  (5 * ((count + 1) / 5)) + 5;
        for (int i = 0 ; i < 3 ; i++)
        {
            element[i] = new int[max_length];
        }
        element[0][0] = A.row;
        element[1][0] = A.coloumn;
        element[2][0] = count;
        row = &element[0][0];
        coloumn = &element[1][0];
        length = &element[2][0];
        int m = 1;
        for (int i = 0 ; i < *row ; i++)
        {
            for (int k = 0 ; k < *coloumn ; k++)
            {
                if (A.element[i][k] != 0)
                {
                    element[0][m] = i;
                    element[1][m] = k;
                    element[2][m] = A.element[i][k];
                    m = m + 1;
                }
            }
        }
    }
    void display(void)
    {
        for (int i = 0 ; i < 3 ; i++)
        {
            for (int k = 0 ; k <= *length ; k++)
                cout << element[i][k] << "\t";
            cout << "\n";
        }
    }
    ~sparce_matrix()
    {
        cout << "\nDestructor initialized\n";
        for (int i = 0 ; i < 3 ; i++)
        {
            delete[] element[i];
        }
    }
    sparce_matrix transpose(void)
    {
        sparce_matrix A;
        if (A.max_length != max_length)
        {
            for (int i = 0 ; i < 3 ; i++)
            {
                delete[] A.element[i];
                A.element[i] = new int[max_length];
            }
        }
        A.element[0][0] = *coloumn;
        A.element[1][0] = *row;
        A.element[2][0] = *length;
        A.row = &A.element[0][0];
        A.coloumn = &A.element[1][0];
        A.length = &A.element[2][0];
        int m = 1;
        for (int i = 0 ; i < *coloumn ; i++)
        {
            for (int k = 1 ; k <= *length ; k++)
            {
                if (i == element[1][k])
                {
                    A.element[0][m] = element[1][k];
                    A.element[1][m] = element[0][k];
                    A.element[2][m] = element[2][k];
                    m = m + 1;
                }
            }
        }
        A.display();
        return A;
    }
    
};
int main()
{
    int r, c;
    cout << "\nEnter the rows and coloumns of the matrix\t: ";
    cin >> r >> c;
    matrix A(r, c);
    cout << "\nThe matrix\t: \n";
    A.display();
    sparce_matrix B(A);
    cout << "\nThe sparce matrix\t: \n";
    B.display();
    cout << "\nThe transposed sparce matrix\t: \n";
    sparce_matrix C;
    C = B.transpose();
    cout << "\nTry again\n";
    C.display();
    return 0;
}