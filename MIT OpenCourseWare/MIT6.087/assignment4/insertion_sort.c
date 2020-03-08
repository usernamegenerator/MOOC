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
void shift_element(unsigned int i)
{
    int ivalue;
    //guard against going outside array
    for(ivalue = arr[i]; i && arr[i-1] >ivalue; i--)
    {
        arr[i] = arr[i-1];      //move element down
    }
    arr[i] = ivalue;            //insert element
}

/* int *pElement  - pointer to the element
    int arr(type int[]) that is out of place
*/
void shift_element_pointer(int* pElement)
{
    int ivalue;
    for(ivalue = *pElement; (pElement > arr) && (*(pElement-1) > ivalue); pElement--)
    {
        *pElement = *(pElement-1);
    }
    *(pElement) = ivalue;
}

/* iterate until out of order element found
shift the element, and continue iterating
*/
void insertion_sort(void)
{
    unsigned int i;
    unsigned int len = array_length(arr);
    for(i = 1; i<len;i++)
        if(arr[i] < arr[i-1])
            shift_element(i);
}

void insertion_sort_pointer(void)
{
    int* pElement = NULL;
    unsigned int len = array_length(arr);
    for(pElement=arr+1; pElement < arr+len; pElement++)
    {
        if(*pElement < *(pElement - 1))
        {
            shift_element_pointer(pElement);
        }
    }
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
    printf("\n");
    //printf("insertion_sort\n"); insertion_sort();


    printf("insertion_sort_pointer\n"); insertion_sort_pointer();

	printf("\nafter sort:\n");
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}


