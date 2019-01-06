#include <iostream>
using namespace std;

enum ReadType
{
    soon,
    after,
    ever,
    other,
};

string read2String(ReadType read)
{
    switch (read)
    {
    case soon:
        return "すぐ読む";
    case after:
        return "あとで読む";
    case ever:
        return "積ん読";
    default:
        return "";
    }
}

ReadType int2type(int num)
{
    switch (num)
    {
    case 0:
        return soon;
    case 1:
        return after;
    case 2:
        return ever;
    default:
        return other;
    }
}

class bookshelf
{
  public:
    string top = "";
    string middle = "";
    string bottom = "";

    string &getShelf(string destination);
    void showShelves();
};

void bookshelf::showShelves()
{
    cout << "top: " << top << endl;
    cout << "middle: " << middle << endl;
    cout << "buttom: " << bottom << endl;
}

string &bookshelf::getShelf(string destination)
{
    if (read2String(soon) == destination)
    {
        return top;
    }
    else if (read2String(after) == destination)
    {
        return middle;
    }
    else
    {
        return bottom;
    }
}

int main()
{
    bookshelf bs = bookshelf();
    string bookname;
    int selectType;

    while (true)
    {
        cout << "本の名前を入力: ";
        cin >> bookname;
        cout << "いつ読みますか(0:すぐ読む/1:あとで読む/2:積ん読): ";
        cin >> selectType;

        bs.getShelf(read2String(int2type(selectType))) = bookname;
        bs.showShelves();
    }
}
