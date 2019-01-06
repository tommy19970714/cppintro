/* sample 3 */
#include <iostream>
using namespace std;

class person
{
  public:
    string address;
    string name;
};

class addressbook
{
    person friends[100];
    int numberOfFriends;

  public:
    addressbook();
    void listFriends();
    void addFriend(string n);
    void addFriend(string n, string a);
    person find(string query);
};

// constructor
addressbook::addressbook()
{
    numberOfFriends = 0;
}

void addressbook::addFriend(string n)
{
    friends[numberOfFriends].name = n;
    numberOfFriends++;
}

void addressbook::addFriend(string n, string a)
{
    friends[numberOfFriends].name = n;
    friends[numberOfFriends].address = a;
    numberOfFriends++;
}

void addressbook::listFriends()
{
    for (int i = 0; i < numberOfFriends; i++)
    {
        cout << friends[i].name << "\n";
    }
}

person addressbook::find(string query)
{
    for (int i = 0; i < numberOfFriends; i++)
    {
        if (friends[i].name == query)
        {
            return friends[i];
        }
    }
    person no_one;
    return no_one;
}

int main()
{
    addressbook abook;
    string name;
    string address;
    string query;

    while (1)
    {
        cout << "住所録に登録する名前を入力してください（終了するにはquitと入力してください）: ";
        cin >> name;
        //   cout << "name.length() = " << name.length() << "\n";
        if (name == "quit")
            break;
        cout << "住所を入力してください";
        cin >> address;
        abook.addFriend(name, address);
    }

    cout << "\n名前リスト:\n";
    abook.listFriends();

    cout << "検索する名前を入力してください";
    cin >> query;
    person found = abook.find(query);
    cout << found.name << ":" << found.address;
}
