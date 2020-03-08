#include <stdio.h>

#define squared_1(x) x*x
#define squared_2(x) (x*x)
#define squared_3(x) (x)*(x)
#define squared_4(x) ((x)*(x))

int main(void)
{
    double ans_1 = 18.0/squared_1(2+1);
    double ans_2 = 18.0/squared_2(2+1);
    double ans_3 = 18.0/squared_3(2+1);
    double ans_4 = 18.0/squared_4(2+1);

    printf("ans_1 %f\n",ans_1);
    printf("ans_2 %f\n",ans_2);
    printf("ans_3 %f\n",ans_3);
    printf("ans_4 %f\n",ans_4);

    return 0;
}
