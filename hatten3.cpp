#include <iostream>
using namespace std;

void func(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int a = 10, b = 20;
    func(a, b);
    cout << a << "\n";
}
