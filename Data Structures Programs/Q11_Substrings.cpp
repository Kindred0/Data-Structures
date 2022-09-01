#include <iostream>
#include <cstring>
using namespace std;
class String
{
    char* word;
    int length;
    public:
    String()
    {
        length = 0;
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
    /*String(String &str)
    {
        cout << "\nCopy Constructor is called";
        length = str.length;
        delete[] word;
        word = new char[length + 1];
        for (int i = 0 ; i <= length ; i++)
        {
            word[i] = str.word[i];
        }
    }*/
    ~String()
    {
        delete[] word;
    }
    void Extract(int pos, int size, String &str)
    {
        str.length = size;
        str.word = new char[size + 1];
        for (int i = 0 ; i < size ; i++)
            str.word[i] = word[pos + i - 1];
        str.word[str.length] = '\0';
        str.display();
    }
    void display(void)
    {
        cout << word;
    }
};
int main()
{
    char word[30];
    int pos, length;
    cout << "\nEnter a word without space\t: ";
    cin >> word;
    String Word(word);
    String subarray;
    Word.display();
    cout << "\nEnter the position of the Subarray\t: ";
    cin >> pos;
    cout << "\nEnter the length of the subarray\t: ";
    cin >> length;
    Word.Extract(pos, length, subarray);
    cout << "\nSubarray\t: ";
    subarray.display();
    return 0;
}