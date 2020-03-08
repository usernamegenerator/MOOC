#include <stdio.h>
//#include <string.h>
//strpos
//???????????
/*
char* strtok(char* text, const char* delims)
{
    char p
    if(!text)
        text = pnexttoken;
    //find start of token in text
    text += strspn(text,delims);
    if(*text == '\0')
        return NULL;
    //find end of token in text
    pnexttoken = text + strcspn(text,delims);
    //insert null-terminator at end
    if(*pnexttoken != '\0')
        *pnexttoken++ = '\0';
    return text;
}
*/

//computes the index of the first non-delimiter char in string
int _strpos(const char* str, const char ch)
{
    const char* cpointer = str;
    int i = 0;
    while(*cpointer != ch)
    {
        cpointer++;
        i++;
        if(*cpointer == '\0')
            return -1;
    }
    return i;
}

unsigned int _strspn(const char * str, const char * delims)
{
    const char* cpointer = NULL;
    int pos = -1;
    int pos_null_terminator = 0;
    //iterate chars in str;
    for(cpointer = str; (*cpointer)!='\0';cpointer++)
    {
        //printf("*cpointer = %c ",*cpointer);
        //find char position in delims
        pos = _strpos(delims,*cpointer);
        //printf("pos in delims = %d\n",pos);
        //if found(return non -1 value) means it's not what we're looking for,keep going
        //if not found, then this is what we want
        if(pos == -1)
        {
            //so return the position of this char in our string;
            //printf("pos in string %d\n",_strpos(str,*cpointer));
            return _strpos(str,*cpointer);
        }
        pos_null_terminator++;
    }
    //if the string contains only delimiters, return the index of '\0'
    return pos_null_terminator;
}

unsigned int _strcspn(const char* str, const char* delims)
{
    const char* cpointer = NULL;
    int pos_null_terminator = 0;
    int pos = -1;
    for(cpointer = str; (*cpointer)!='\0';cpointer++)
    {
        pos = _strpos(delims,*cpointer);
        if(pos != -1)
            return _strpos(str,*cpointer);
        pos_null_terminator++;
    }
    return pos_null_terminator;
}

int main(void)
{
    //printf("%d\n",_strpos("This is a SB",'I'));
    //printf("%d\n",_strspn(" . This"," ."));
    //printf("%d\n",_strspn(" . ..."," ."));
    //printf("%d\n",_strcspn("abababa"," ."));
}
