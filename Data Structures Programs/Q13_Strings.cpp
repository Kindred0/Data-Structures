#include <iostream>
using namespace std;
class String
{
    char* word;
    int length;
    public:
    String()
    {
        length = 0;
        word = new char[1];
    }
    String(char* str)
    {
        length = 0;
        for(int i = 0 ; str[i] != '\0' ; i++)
            length++;
        word = new char[length + 1];
        for (int i = 0 ; i <= length ; i++)
            word[i] = str[i];
    }
    ~String()
    {
        delete[] word;
    }
    void insert(String str, int pos)
    {
        int i, k;
        int shift = str.length;
        char* tempword = new char[length + 1];
        for (i = 0 ; i <= length ; i++)
            tempword[i] = word[i];
        delete[] word;
        length = length + shift;
        word = new char[length + 1];
        i = 0;
        k = 0;
        while (i <= length)
        {
            if (i == pos)
            {
                for (int m = 0 ; m < shift ; m++)
                {
                    word[i] = str.word[m];
                    i++;
                }
            }
            word[i] = tempword[k];
            i++;
            k++;
        }
        delete[] tempword;
    }
    void remove(int pos, int n)
    {
        int i;
        char* tempword = new char[length - n + 1];
        for (i = 0 ; i < pos ; i++)
            tempword[i] = word[i];
        while (i + n <= length)
        {
            tempword[i] = word[i + n];
            i++;
        }
        delete[] word;
        length = length - n;
        word = new char[length + 1];
        for (i = 0 ; i <= length ; i++)
            word[i] = tempword[i];
        delete[] tempword;
    }
    void display(void)
    {
        cout << word;
    }
};
int main()
{
    int length;
    int action;
    int pos;
    char str[30], substring[15];
    cout << "\nEnter a string\t: ";
    cin >> str;
    String STR(str);
    while (true)
    {
        cout << "\nChoose an option\t: ";
        cout << "\n1 :\tInsert a string\n2 :\tRemove a substring\n3 :\tExit";
        cout << "\nEnter an action\t: ";
        cin >> action;
        if (action == 1)
        {
            cout << "\nEnter a string to be inserted\t: ";
            cin >> substring;
            String Substring(substring);
            cout << "\nEnter the position to be inserted\t: ";
            cin >> pos;
            STR.insert(substring, pos);
            cout << "\nThe new string\n";
            STR.display();
        }
        else if (action == 2)
        {
            cout << "\nEnter the position of substring to be removed from the string\t: ";
            cin >> pos;
            cout << "\nEnter the length of the substring to be removed\t: ";
            cin >> length;
            STR.remove(pos, length);
            cout << "\nThe new string\n";
            STR.display();
        }
        else if (action == 3)
            return 0;
        else 
            cout << "\nInvalid action, try again";
    }
    return 0;
}