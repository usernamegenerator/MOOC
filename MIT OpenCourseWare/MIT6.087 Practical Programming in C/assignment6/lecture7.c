#include <stdio.h>

struct foo{
    short s;    //2 --? aligned to 4
    union{
        int i;
        char c;
    };          //4
    unsigned int flag_s : 1;
    unsigned int flag_u : 2;        //aligned to 4
    unsigned int bar;               //aligned to 4
};

struct foo2{
    union{
        int i;
        char c;
    };          //4
    unsigned int bar;               //aligned to 4

    short s;    //2

    unsigned int flag_s : 1;
    unsigned int flag_u : 2;        //aligned to 4

};

//swap the pointer itself;
//so that
//a's pointer is pointing to b
//b's pointer is pointing to a
//a and b don't change at all
//the value that a's pointer pointing to is now b
//the value that b's pointer pointing to is now a
void swap(int **a, int **b)
{
    printf("*a=%d, *b=%d\n",*a,*b);
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    printf("%d\n",sizeof(struct foo));
    printf("%d\n",sizeof(struct foo2));

    int a = 1;
    int b = 2;
    printf("&a=%d, &b=%d\n",&a,&b);
    int *app = &a;
    int *bpp = &b;
    printf("*app=%d, *bpp=%d\n",*app,*bpp);
    //printf("&app=%d, &bpp=%d\n",&app,&bpp);
    swap(&app,&bpp);
    printf("a=%d, b=%d\n",a,b);
    printf("*app=%d, *bpp=%d\n",*app,*bpp);

    return 0;
}
