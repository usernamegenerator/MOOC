#include <iostream>

using namespace std;


void f(const int a = 5)
{
    cout << a*2 << "\n";
}

int a = 123;

int main()
{
    f(1);  //2
    f(a);  //246
    int b =3;
    f(b);   //6
    int a = 4;
    f(a); //8
    f(); //10
}
