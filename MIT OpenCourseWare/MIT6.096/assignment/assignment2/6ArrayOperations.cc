#include <iostream>
using namespace std;

void printArray(int arr[], int len){
    for(int i = 0; i< len;i++){
        if(i!=len-1)
            cout << arr[i] << ", ";
        else
            cout << arr[i] << endl;
    }
}

void swapElements(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverseArray(int arr[], int len){
    for(int i=0;i<len/2;i++){
        //swapElements(&arr[i],&arr[len-1-i]);
        swapElements(arr+i,arr+len-1-i);
    }

}

const int WIDTH = 4; //4 rows
const int LENGTH = 3; //3 cols

void transpose(const int input[][LENGTH],int output[][WIDTH]){
    for(int i = 0;i<WIDTH;i++){
        for(int j =0;j<LENGTH;j++){
            output[j][i] = input[i][j];
        }
    }
}


int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    printArray(a,10);
    reverseArray(a,10);
    printArray(a,10);


    const int input[WIDTH][LENGTH] = {
                                {1,2,3},
                                {4,5,6},
                                {7,8,9},
                                {10,11,12}
                                };
    int output[LENGTH][WIDTH];

    transpose(input,output);
}
