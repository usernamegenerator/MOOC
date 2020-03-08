#include <stdio.h>
#include <stdlib.h>

#define array_length(arr) (sizeof(arr)==0?0:sizeof(arr)/sizeof(arr[0]))

int arr[15] = {9,8,5,1,3,7,6,4,0,9,5,6,2,9,7};

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(unsigned int left, unsigned int right)
{
    unsigned int i, mid;
    int pivot;

    if(left>=right)
        return; //nothing to sort

    //pivot is midpoint; move to left side
    swap(arr+left, arr+ (left+right)/2);
    pivot = arr[mid = left];

    //separate into side<pivot (left+1 to mid)
    //and side >= pivot (mid+1 to right)
    for(i=left+1 ;i<=right; i++)
    {
        if(arr[i] < pivot)
        {
            swap(arr+ ++mid, arr+ i);
        }
    }

    //resotre pivot position
    swap(arr+left,arr+mid);

    //sort two sides
    if(mid > left)
        quick_sort(left,mid-1);
    if(mid<right)
        quick_sort(mid+1,right);
}


int main(void)
{
    int i;
	int len = array_length(arr);
	printf("\nbefore sort:\n");
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }

    quick_sort(0,len - 1);

	printf("\nafter sort:\n");
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
