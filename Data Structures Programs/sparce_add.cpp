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
    sparce_matrix(const sparce_matrix &A)
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
        }
        element[0][0] = *A.row;
        element[1][0] = *A.coloumn;
        element[2][0] = *A.length;
        row = &element[0][0];
        coloumn = &element[1][0];
        length = &element[2][0];
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
    friend sparce_matrix add(sparce_matrix A, sparce_matrix B);
};
sparce_matrix add(sparce_matrix A, sparce_matrix B)
{
    sparce_matrix C;
    if (A.element[0][0] != B.element[0][0] || A.element[1][0] != B.element[1][0])
    {
        cout << "\nThe matrices cannot summed";
        return C;
    }
    for (int i = 0 ; i < 3 ; i++)
        {
            delete[] C.element[i];
        }
    C.max_length = A.element[0][0] * A.element[1][0];
    for (int i = 0 ; i < 3 ; i++)
    {
        C.element[i] = new int[C.max_length];
    }
    cout << "\nSuccessfully Entered the funtion";
    C.row = &C.element[0][0];
    C.coloumn = &C.element[1][0];
    C.length = &C.element[2][0];
    int i = 1, j = 1, k = 1;
    int l1 = A.element[2][0];
    int l2 = B.element[2][0];
    while (i <= l1 && j <= l2)
    {
        if (A.element[0][i] < B.element[0][j])
        {
            C.element[0][k] = A.element[0][i];
            C.element[1][k] = A.element[1][i];
            C.element[2][k] = A.element[2][i];
            k++;
            i++;
        }
        else if (B.element[0][j] < A.element[0][i])
        {   
            C.element[0][k] = B.element[0][i];
            C.element[1][k] = B.element[1][i];
            C.element[2][k] = B.element[2][i];
            k++;
            j++;
        }
        else if (A.element[1][i] < B.element[1][j])
        {   
            C.element[0][k] = A.element[0][i];
            C.element[1][k] = A.element[1][i];
            C.element[2][k] = A.element[2][i];
            k++;
            i++;
        }
        else if (B.element[1][j] < A.element[1][j])
        {   
            C.element[0][k] = B.element[0][i];
            C.element[1][k] = B.element[1][i];
            C.element[2][k] = B.element[2][i];
            k++;
            j++;
        }
        else if (A.element[2][i] + B.element[2][j] == 0)
        {
            i++;
            j++;
        }
        else 
        {
            C.element[0][k] = A.element[0][i];
            C.element[1][k] = A.element[1][i];
            C.element[2][k] = A.element[2][i] + B.element[2][i];
            k++;
            i++;
            j++;
        }
        while (i <= l1)
        {   
            C.element[0][k] = A.element[0][i];
            C.element[1][k] = A.element[1][i];
            C.element[2][k] = A.element[2][i];
            k++;
            i++;
        }
        while (j <= l2)
        {
            C.element[0][k] = A.element[0][i];
            C.element[1][k] = A.element[1][i];
            C.element[2][k] = A.element[2][i];
            k++;
            i++;
        }
        C.display();
    }
    return C;
}
int main()
{
    sparce_matrix SC;
    int r, c;
    cout <<"\nEnter the roes and coloumns of the first matrix\t: ";
    cin >> r >> c;
    matrix A(r, c);
    cout << "\nEnter the rows and coloumns of the second matrix\t: ";
    cin >> r >> c;
    matrix B(r,c);
    sparce_matrix SA(A);
    sparce_matrix SB(B);
    cout << "\nThe first sparce matrix\t: \n";
    SA.display();
    cout << "\nThe second sparce matrix\t: \n";
    SB.display();
    SC = add(SA, SB);
    cout << "\nA + B = ";
    SC.display();
    return 0;
}