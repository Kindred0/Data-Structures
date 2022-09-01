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
    friend int pattern_matching(const String &str, const String &pattern);
};
int pattern_matching(const String &str, const String &pattern)
{
    int k;
        for (int i = 0 ; i < str.length ; i++ )
        {
            for (k = 0 ; k < pattern.length ; k++)
            {
                if (pattern.word[k] != str.word[i + k])
                    break;
            }
            if (k == pattern.length)
                return i + 1;
        }
        return -1;
}
int main()
{
    int loc;
    char str[30], pattern[30];
    cout << "\nEnter a string\t: ";
    cin >> str;
    String Str(str);
    cout << "\nEnter a pattern\t :";
    cin >> pattern;
    String Pattern(pattern);
    loc = pattern_matching(Str, Pattern);
    if (loc == -1)
        cout << "\nThe pattern is not in the string";
    else 
        cout << "\nThe pattern is in the location of " << loc << " in the String";
    return 0;
}