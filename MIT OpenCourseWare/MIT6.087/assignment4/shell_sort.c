#include <stdio.h>

#define array_length(arr) (sizeof(arr)==0?0:sizeof(arr)/sizeof(arr[0]))

int arr[15] = {9,8,5,1,3,7,6,4,0,9,5,6,2,9,7};
//int arr[1] = {8};

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*move previous elements down until
insertion point reached*/
void shift_element_by_gap(unsigned int i, unsigned int gap)
{
    int ivalue;
    //guard against going outside array
    for(ivalue = arr[i]; i && arr[i-gap] >ivalue; i=i-gap)
    {
        arr[i] = arr[i-gap];      //move element down
    }
    arr[i] = ivalue;            //insert element
}

void shell_sort(void)
{
    unsigned int gap,i,len=array_length(arr);

    //sort, comparing against farther away elements first, then closer elements
    for(gap = len/2;gap>0;gap/=2)
    //do insertion-like sort, but comparing and shifting elements in multiples of gap
    {
        for(i=gap;i<len;i+=gap)
        {
            if(arr[i] < arr[i-gap])
            {
                //out of order, do shift
                shift_element_by_gap(i,gap);
            }
        }
    }
}

int main(void)
{
    unsigned int i,len=array_length(arr);
    printf("\nbefore sort:\n");
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    shell_sort();

    printf("\nafter sort:\n");
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
