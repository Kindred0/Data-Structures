#include <iostream>
using namespace std;
class polynomial;
class term
{
    int pos;
    int coe;
    int power;
    term* next;
    public :
    friend class polynomial;
    void create(int p, int c, int r)
    {
        coe = c;
        power = r;
        pos = p;
        next = NULL;
    }
    ~term()
    {
        delete next;
    }
    friend void add(polynomial A , polynomial B , polynomial &C);
};
class polynomial
{
    int terms;
    term* start;
    public :
    polynomial()
    {
        start = NULL;
        terms = 0;
    }
    polynomial(int n)
    {
        int p;
        int c;
        start = new term;
        term* point1;
        term* point = start;
        terms = n;
        for (int i = 1 ; i <= terms ; i++)
        {
            cout << "\nEnter the coefficient of the term " << i << "\t: ";
            cin >> c;
            cout << "\nEnter the power of the term " << i << "\t\t: ";
            cin >> p;
            point1 = start;
            while(point1 != NULL)
            {
                if (point1->power == p)
                {
                    point1->coe = point1->coe + c;
                    i--;
                    goto p1;
                }
            }
            point->create(i, c, p);
            if (i != terms)
            {
                point->next = new term;
                point = point->next;
            }
            p1 :
        }
        sort();
    }
    ~polynomial()
    {
        delete start;
    }
    void display()
    {
        term* point = start;
        cout << point->coe << "x^" << point->power;
        point = point->next;
        
        while (point != NULL)
        {
            cout << " + " << point->coe << "x^" << point->power ;
            point = point->next;
        }
    }
    void sort()
    {
        int temp;
        term* point1 = start;
        term* point2;
        term* max;
        while (point1 != NULL)
        {
            max = point1;
            point2 = point1->next;
            while (point2 != NULL)
            {
               if (max->power < point2->power)
                    max = point2;
                point2 = point2->next;
            }
            temp = point1->power;
            point1->power = max->power;
            max->power = temp;
            temp = point1->coe;
            point1->coe = max->coe;
            max->coe = temp;
            point1 = point1->next;
        }
    }
    friend void add(polynomial A , polynomial B , polynomial &C);
};
void add(polynomial A, polynomial B, polynomial &C)
{
    if (C.start != NULL)
        C.~polynomial();
    C.start = new term;
    int pos = 0;
    term* i = A.start;
    term* j = B.start;
    term* k = C.start;
    while (i != NULL || j != NULL)
    {
        pos++;
        if (i->power > j->power)
        {
            k->create(pos, i->coe, i->power);
            k = k->next;
            i = i->next;
        }
        else if (j->power > i->power)
        {
            k->create(pos, j->coe, j->power);
            k = k->next;
            j = j->next;
        }
        else if (i->coe + j->coe == 0)
        {
            pos--;
            i = i->next;
            j = j->next;
        }
        else 
        {
            k->create(pos, i->coe + j->coe , i->power);
            k = k->next;
            i = i->next;
            j = j->next;
        }
    }
    while (i != NULL)
    {
        pos++;
        k->create(pos, i->coe, i->power);
        k = k->next;
        i = i->next;
    }
    while (j != NULL)
    {
        pos++;
        k->create(pos, j->coe, j->power);
        k = k->next;
        j = j->next;
    }
}
int main()
{
    int n;
    cout << "\nEnter the number of the terms in the polyniomial function \t: ";
    cin >> n;
    polynomial p(n);
    p.display();
    return 0;
}