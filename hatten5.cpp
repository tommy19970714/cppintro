#include <iostream>
using namespace std;

class movie
{
    string title;
};

class copyprotection
{
    string code;
};

class protectedMovie : public movie, copyprotection
{
  public:
    protectedMovie(string title, string code);
};

protectedMovie::protectedMovie(string title, string code)
{
    title = title;
    code = code;
}

int main()
{
    protectedMovie pm = protectedMovie("title", "1234");
};
