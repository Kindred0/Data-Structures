#include <iostream>
using namespace std;
void swap(int &a , int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
/*wchar_t unicode(int number)
{
    if (number == 1)
        return '0x00B9';
    else if (number == 2)
        return '0x00B2';
    else if (number == 3)
        return '0x00B3';
    else 
        return '0x2070' + number;
}*/
void print_unicode(int number)
{
    if (number == 1)
        cout << "\u00B9";
    else if (number == 2)
        cout << "\u00B2";
    else if (number == 3)
        cout << "\u00B3";
    else if (number == 4)
        cout << "\u2074";
    else if (number == 5)
        cout << "\u2075";
    else if (number == 6)
        cout << "\u2076";
    else if (number == 7)
        cout << "\u2077";
    else if (number == 8)
        cout << "\u2078";
    else if (number == 9)
        cout << "\u2079";
}
class polynomial
{
    int* coe;
    int* power;
    int terms , max_terms ;
    public :
    polynomial(int n)
    {
        int temp;
        max_terms = n;
        terms = 0;
        coe = new int[n];
        power = new int[n];
        for (int i = 0 ; i < n; i++)
        {
            cout <<"\nEnter the power of the term " << i + 1 << "\t\t: ";
            cin >> temp;
            for (int k = 0 ; k < terms ; k++)
            {
                if (temp == power[k])
                {
                    cout << "Enter the coefficient of the term " << i + 1 <<"\t: ";
                    cin >> temp;
                    coe[k] = coe[k] + temp;
                    goto l1;
                }
            }
            power[terms] = temp;
            cout << "Enter the coefficient of the term " << i+ 1 <<"\t: ";
            cin >> coe[terms];
            terms++;
            l1:
            temp = 0;
        }
        int max;
        for (int i = 0 ; i < n - 1 ; i++)
        {
            max = i;
            for (int k = i ; k < n ; k++)
            {
                if (power[k] > power[max])
                    max = k;
            }
            swap(power[max], power[i]);
            swap(coe[max], coe[i]);
        }
    }
    polynomial()
    {
        terms = 0;
    }
    ~polynomial()
    {
        delete[] coe;
        delete[] power;
    }
    friend void add(polynomial A, polynomial B, polynomial &C);
    void display(void)
    {
        cout << coe[0] << "x^" << power[0];
        for (int i = 1 ; i < terms ; i++)
        {
            //wchar_t wideChar = unicode(power[i]);
            if (power[i] > 0)
            {
                if (coe[i] > 1)
                    cout << " + " << coe[i] << "x^" << power[i];
                //wprintf( L"%c", wideChar);
                //print_unicode(power[i]);
                else if (coe[i] < -1)
                    cout << " - " << coe[i] << "x^" << power[i];
                else if (coe[i] == 1)
                    cout << " + " << "x^" << power[i];
                else if (coe[i] == -1)
                    cout << " - " << "x^" << power[i];
            }
            else if (power[i] == 1)
            {
                if (coe[i] > 1)
                    cout << " + " << coe[i] << "x";
                else if(coe[i] < -1)
                    cout << " - " << coe[i] << "x";
                else if (coe[i] == 1)
                    cout << " + " << "x";
                else if (coe[i] == -1)
                    cout << " - " << "x";
            }
            else if (power[i] == 0)
            {
                if (coe[i] > 0)
                    cout << " + " << coe[i];
                else if (coe[i] < 0)
                    cout << " - " << coe[i];
            }
        }
    }
};
void add(polynomial A, polynomial B, polynomial &C)
{
    int terms = A.terms + B.terms;
    int i = 0 , j = 0 , k = 0;
    for (i = 0 ; i < A.terms ; i++)
    {
        for(j = 0 ; j < B.terms ; j++)
        {
            if (A.power[i] == B.power[j])
            {
                terms--;
                if (A.coe[i] + B.coe[j] == 0)
                {
                    terms--;
                }
                break;
            }
        }
    }
    C.terms = terms;
    C.coe = new int[terms];
    C.power = new int[terms];
    i = 0;
    j = 0;
    while ( i < A.terms && j < B.terms)
    {
        if (A.power[i] > B.power[j])
        {
            C.power[k] = A.power[i];
            C.coe[k] = A.coe[i];
            i++;
            k++;
        }
        else if (A.power[i] < B.power[j])
        {
            C.power[k] = B.power[j];
            C.coe[k] = B.coe[j];
            j++;
            k++;
        }
        else if (A.coe[i] + B.coe[j] == 0)
        {
            i++;
            j++;
        }
        else 
        {
            C.power[k] = A.power[i];
            C.coe[k] = A.coe[i] + B.coe[j];
            i++;
            j++;
            k++;
        }
    }
    while (i < A.terms)
    {
        C.power[k] = A.power[i];
        C.coe[k] = A.coe[i];
        i++;
        k++;
    }
    while (j < B.terms)
    {
        C.power[k] = B.power[j];
        C.coe[k] = B.coe[j];
        j++;
        k++;
    }
}
int main()
{
    int n;
    cout << "\nEnter the number of the terms of the first polynomial\t: ";
    cin >> n;
    polynomial p(n);
    cout << "\nEnter the number of the terms of the second polynomial\t: ";
    cin >> n;
    polynomial q(n);
    cout << "\np(n) = ";
    p.display();
    cout << "\nq(n) = ";
    q.display();
    polynomial r;
    add(p, q, r);
    cout << "\nr(n) = p(n) + q(n ) = ";
    r.display();
    return 0;
}