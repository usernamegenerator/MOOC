#include <iostream>

using namespace std;

int arrayLen(char*arr){
    int i = 0;
    while(arr[i]!='\0')
    {
        i++;
    }
    return i;
}


void swapInt(int &a,int &b)
{
    int temp = a;
    a =b;
    b=temp;
}

void swapInt2(int *a,int *b)
{
    int temp = *a;
    *a =*b;
    *b=temp;
}


void swap3(int **ptr1,int **ptr2)
{
    int * temp = *ptr1;
    *ptr1 = *ptr2;
    * ptr2 = temp;
}

int main()
{
    char* arr = "helloworld";
    cout << arrayLen(arr) << endl;
    int a =3;
    int b=4;
    swapInt(a,b);
    cout << a << " " << b << endl;
    swapInt2(&a,&b);
    cout << a << " " << b << endl;


    int x = 5, y =6;
    int *ptr1 = &x, *ptr2 = &y;
    swap3(&ptr1,&ptr2);
    cout << *ptr1 << " " << *ptr2 << endl; //"print 6 5"


    //7.5
    char* oddOrEven = "Never odd or even";
    //1
    char* nthCharPtr = &oddOrEven[5];
    //2
    nthCharPtr = &oddOrEven[3];
    //3
    cout << *nthCharPtr << endl;
    //4
    char ** pointerPtr = &nthCharPtr;
    //5
    cout << pointerPtr << endl;
    //6
    cout << **pointerPtr << endl;
    //7
    nthCharPtr = nthCharPtr +1;
    //8
    cout <<  nthCharPtr - oddOrEven << endl;
}
