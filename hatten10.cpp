#include <iostream>
#include <random>
using namespace std;

template <class X, size_t SIZE>
X max(X (&a)[SIZE])
{
    X largest = a[0];
    for (int i = 1; i < SIZE; i++)
    {
        if (largest < a[i])
        {
            largest = a[i];
        }
    }
    return largest;
}

int main()
{
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << max(a) << endl;

    double b[4] = {1.0, 2.0, 3.0, 4.0};
    cout << max(b) << endl;

    float c[3] = {3.0, 9.0, 5.0};
    cout << max(c) << endl;
}