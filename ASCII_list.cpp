#include <iostream>
using namespace std;
int main()
{
    int ul, ll;
    cout << "\nEnter the upper limit\t: ";
    cin >> ul;
    cout << "\nEnter the lower limit\t: ";
    cin >> ll;
    for (int i = ul ; i <= ll ; i++)
    {
        cout << "\n" << i << "\t: " << (char)i;
    }
    return 0;
}