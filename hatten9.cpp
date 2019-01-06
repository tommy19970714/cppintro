#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class case_ins : public string
{
  public:
    case_ins() : string() {}
    case_ins(const char *str) : string(str) {}
    case_ins(const string &s) : string(s) {}

    case_ins &operator=(const char *str)
    {
        string::operator=(str);
        return *this;
    }
    case_ins &operator=(const string &s)
    {
        string::operator=(s);
        return *this;
    }
};

bool operator==(case_ins a, case_ins b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < (int)a.size(); ++i)
    {
        char achar = a[i];
        char bchar = b[i];
        if (achar - bchar == 0 || achar - bchar == 32 || achar - bchar == -32)
        {
            continue;
        }
        return false;
    }
    return true;
}

int main()
{
    case_ins a = "abc", b = "AbC";
    if (a == b)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}