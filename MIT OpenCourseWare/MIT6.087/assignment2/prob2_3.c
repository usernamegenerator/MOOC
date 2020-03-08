#include <stdio.h>

int main(void)
{
    const int val = 0xCAFE;
    const int on = 0x01;
    int numOfOn = 0;

    //test if at least three of last four bits are on
    if(val & on)
        numOfOn++;
    if(val & on << 1)
        numOfOn++;
    if(val & on << 2)
        numOfOn++;
    if(val & on << 3)
        numOfOn++;

    if(numOfOn>=3)
        printf("at least three of last bit are on %d\n",numOfOn);
    else
        printf("num of ON %d\n",numOfOn);

    //reverse the byte order to produce 0xFECA
    int reverse = ((val & 0xFF) << 8) | ((val >> 8) & 0xFF);
    printf("reverse %x\n",reverse);

    //rotate fourbits to produce val = 0xECAF
    int rotate = ((val & 0xF) << 12) | ((val >> 4) & 0xFFF);
    printf("rotate four bits %x\n",rotate);

    return 0;

}
