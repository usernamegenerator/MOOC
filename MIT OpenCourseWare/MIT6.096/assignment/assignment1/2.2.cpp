#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    if(argc!=2)
    {
        cout << "wrong parameter numbers" << endl;
        return 0;
    }

    const int n = atoi(argv[1]);
    cout << n << endl;
    const char* hello_world = "Hello, world!";
    int i = n;
    while(i>0)
    {
        cout << hello_world << endl;
        i--;
    }
    i = n;
    for(i;i>0;i--)
    {
        cout << hello_world << endl;
    }
    i = n;
    do
    {
        cout << hello_world << endl;
        i--;
    }while(i>0);



    return 0;
}
