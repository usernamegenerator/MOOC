#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_CHAR 20
#define NUM_LINES 2602

int main(int argc, char** argv)
{
    FILE* fp = NULL;
    char state_code_origin[NUM_CHAR];
    char county_code_origin[NUM_CHAR];
    char state_code_dest[NUM_CHAR];
    char county_code_dest[NUM_CHAR];
    char state_abbrv[NUM_CHAR];
    char state_name[NUM_CHAR];
    int return_num;
    int exmpt_num;
    int arre_agi;

    if (argc!=2)
    {
        printf("invalid input\n");
        return -1;
    }

    char* file_name = argv[1];

    fp = fopen(file_name,"r");
    if(fp==NULL)
        printf("can't open\n");

    int i = 0;
    unsigned int sum = 0;
    char* STATE = "STATE";
    char* TOTAL = "TOTAL";
    char* Total = "Total";
    
    printf("%-30s%-10s\n",STATE,TOTAL);
    printf("-------------------------------------\n");
    for(i=0;i<NUM_LINES;i++)
    {
        int ret = fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d",\
                state_code_origin,\
	        	county_code_origin,\
				state_code_dest,\
				county_code_dest,\
				state_abbrv,\
				state_name,\
				&return_num,\
				&exmpt_num,\
				&arre_agi\
              );
    
        if(strcmp(state_code_origin,"\"25\"")==0)
        {
            printf("%-30s%-10d\n",state_name,arre_agi);
            sum += arre_agi;
        }
        
    }

    printf("-------------------------------------\n");
    printf("%-30s%-10d\n",Total,sum);

	fclose(fp);
    return 0;
}
