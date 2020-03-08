#include <stdio.h>

int main(int argc, char** argv)
{
    char c = *argv[1];
    printf("%c\n",c);

    if (c>='a' && c<='z')
        printf("c is lower case letter\n");
    else if (c>='A' && c<= 'Z')
        printf("c is upper case letter\n");
    else if (c>='0' && c<='9')
        printf("c is a digit\n");
    else if(c==' ' || c=='\t' || c== '\n')
        printf("c is a space\n");
    else
        printf("c is nothing\n");

    return 0;
}
