/******************************************************************
 ** File Name:replace.c

 ** Copyright(c)2005-2011	ChenYu Xiao	

 ** Created: ChenYu Xiao  <yunsn0303@gmail.com>

 ** Modified by:

 ** Date:2012.02.09

 ** Description: replace string 

 ** Version:

 ******************************************************************/



#include "replace.h"
#include "matcher.h"


char * 
replace(const char *str, const char *findstr, const char *replacestr)
{
    char *oldstr = str;
    char *newstr = NULL;
    char *plocation = NULL;
    int newstrlen = 0;
    int findstrlen = 0;
    int replacestrlen = 0;
    int diff = 0;
    int location = 0;
    int cplocation = 0;

    newstrlen = strlen(oldstr);
    findstrlen = strlen(findstr);
    replacestrlen = strlen(replacestr);

    diff = replacestrlen - findstrlen;
    if(diff <= 0)
    {
        diff = 0;
    }

    if((newstr = (char *)malloc(sizeof(char) * newstrlen)) == NULL)
    {
        printf("malloc failed.\n");
        exit(0);
    }

    memset(newstr, '\0', sizeof(newstr));

    do
    {
        plocation = kmp_matcher(oldstr, findstr);
        if (plocation)
        {
            newstrlen += diff;
            location = plocation - oldstr;
            if ((newstr = (char *)realloc(newstr, sizeof(char) * newstrlen)) == NULL)   
            {
                printf("realloc failed.\n");
                exit(0);
            }
            strncpy(newstr + cplocation, oldstr, location);

            cplocation += location;
            oldstr += location;
            oldstr += findstrlen;

            strncpy(newstr + cplocation, replacestr, replacestrlen);
            cplocation += replacestrlen;
        } 
        else
        {
            strncpy(newstr + cplocation, oldstr, strlen(oldstr));
            strncpy(newstr + cplocation + strlen(oldstr),  "\0", 1);
        }
    } while (plocation != NULL);

    return newstr;

}



#if 0
int main()
{
    char *a = "a";

    printf("%s\n", replace(a, "a", "1234567890") );

       
        
                
	return 0;
}
#endif



