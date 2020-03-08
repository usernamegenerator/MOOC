#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("char %lu\n",sizeof(char));
    printf("unsigned char %lu\n",sizeof(unsigned char));
    printf("short %lu\n",sizeof(short));
    printf("int %lu\n",sizeof(int));
    printf("unsigned int %lu\n",sizeof(unsigned int));
    printf("unsigned long %lu\n",sizeof(unsigned long));
    printf("float %lu\n",sizeof(float));

    return 0;
}
