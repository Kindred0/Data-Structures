#include <iostream>
using namespace std;
class polynomial;
class term
{
    int power;
    int coe;
    term* next;
    public :
    void create(int p, int c)
    {
        power = p;
        coe = c;
        next = NULL;
    }
    friend class polynomial;
    friend polynomial operator+(polynomial P, polynomial Q);
};
class polynomial
{
    int degree;
    term* start;
    term* Find(int power)
    {
        term* loc;
        if (start == NULL)
        {
            loc = NULL;
            return loc;
        }
        if (power < start->power)
        {
            loc = NULL;
            return loc;
        }
        term* save = start;
        term* point = start->next;
        while (point != NULL)
        {
            if (power < point->power)
            {
                loc = save;
                return loc;
            }
            save = point;
            point = point->next;
        }
        loc = save;
        return loc;
    }
    public:
    polynomial()
    {
        degree = 0;
        start = NULL;
    }
    void create(int power, int coe)
    {
        term* New = new term;
        New->create(power, coe);
        New->next = start;
        start = New;
    }
    void get_terms(int d)
    {
        degree = d;
        term* New = new term;
        int coe;
        cout << "\nEnter the coefficients of each terms in decreasing order of degree\t :";
        for (int i = 0; i <= degree ; i++)
        {
            cin >> coe;
            create(i, coe);
        }
        
    }
    void Destroy()
    {
        term* point;
        term* save;
        point = start;
        save = NULL;
        if (point == NULL)
        {
            cout << "\nUnderflow";
            return;
        }
        while(point->next != NULL)
        {
            save = point;
            point = point->next;
            delete save;
        }
        delete point;
        cout << "\nList Destroyed";
    }
    void display()
    {
        term* point = start;
        if (point == NULL)
        {
            cout << "\nNo terms in the equation";
            return;
        }
        cout << point->coe << "X^" << point->power;
        point = point->next;
        while (point != NULL)
        {
            if (point->coe == 0)
            {
                point = point->next;
                continue;
            }
            if (point->power == 0)
            {
                cout << " + " << point->coe;
                point = point->next;
                continue;
            }
            cout << " + " << point->coe << "X^" << point->power; 
            point = point->next;
        }
    }
    friend polynomial operator+(polynomial P, polynomial Q);
};
polynomial operator+(polynomial P, polynomial Q)
{
    polynomial R;
    if (P.start == NULL || Q.start == NULL)
        return R;
    term* point1 = P.start;
    term* point2 = Q.start;
    while(point1 != NULL && point2 != NULL)
    {
        if (point1->power > point2->power)
        {
            R.create(point1->power, point1->coe);
            point1 = point1->next;
        }
        else if (point1->power < point2->power)
        {
            R.create(point2->power, point2->coe);
            point2 = point2->next;
        }
        else
        {
            R.create(point1->power, point1->coe + point2->coe);
            point1 = point1->next;
            point2 = point2->next;
        }
    }
    while(point1 != NULL)
    {
        R.create(point1->power, point1->coe);
        point1 = point1->next;
    }
    while(point2 != NULL)
    {
        R.create(point2->power, point2->coe);
        point2 = point2->next;
    }
    return R;
}
int main()
{
    polynomial P;
    polynomial Q;
    polynomial R;
    int degree, i;
    cout << "\nEnter the degree of the polynomail P\t: ";
    cin >> degree;
    P.get_terms(degree);
    cout << "P\t: ";
    P.display();
    cout << "\nEnter the degree of the polynomial Q\t: ";
    cin >> degree;
    Q.get_terms(degree);
    cout << "Q\t: ";
    Q.display();
    R = P + Q ;
    cout << "\nR = P + Q = ";
    R.display();
    Q.Destroy();
    P.Destroy();
    R.Destroy();
    return 0;
}