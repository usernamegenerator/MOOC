#include <iostream>

using namespace std;

int main()
{
    int accumulator = 0;
    int dole = 100;
    int bob=1;
    while(true)
    {
        if(dole == 0) break;
        accumulator += ((dole%2 ==1 ) ? bob : 0);
        dole /= 2;
        bob *=2;
        cout << dole << endl;
        cout << bob << endl;
        cout << accumulator << endl;
        cout <<  endl;
    }

    cout << "final " <<  accumulator << endl;
}
