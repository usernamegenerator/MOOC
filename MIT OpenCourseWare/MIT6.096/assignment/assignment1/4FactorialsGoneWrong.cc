#include <iostream>

using namespace std;

int main()
{
    short number;
    cout << "enter a number: ";
    cin >> number;
    //4.2
    if(number < 0)
    {
        cout << "The factorial of a negative number is undefined\n";
        return 1;
    }

    //4.2 end
    cout << "The factorial of " << number << " is ";

    //4.3
    //overflow
    //int accumulator = 1;
    long long accumulator = 1;
    //4.3
    for(; number > 0; accumulator *= number--);
    cout<< accumulator << ".\n";

    return 0;
}
