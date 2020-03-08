#include <iostream>
void printNum(int number) { std::cout << number;}

void doubleNumber(int &num) {num = num*2;}

const int ARRAY_LEN = 10;

int main()
{
    //printNum(35);
    //int num = 35;
    //doubleNumber(num);
    //std::cout << num << std::endl;

    int arr[ARRAY_LEN] = {10};

    int *xPtr = arr, *yPtr = arr+ARRAY_LEN-1;

    std::cout << *xPtr << " " << *yPtr;

    return 0;
}

