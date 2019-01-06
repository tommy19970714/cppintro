#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    string fn;
    cout << "ファイル名を入力してください.";
    cin >> fn;
    ifstream fin(fn);
    ofstream fout(fn + ".backup");
    if (!fin)
    {
        cout << "入力ファイルが開けません";
        return 1;
    }
    fout << fin.rdbuf();
    fout.close();
    fin.close();
    return 0;
}