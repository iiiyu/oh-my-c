/******************************************************************
 ** File Name:matcher.c

 ** Copyright(c)2005-2011   ChenYu Xiao 

 ** Created: ChenYu Xiao  <yunsn0303@gmail.com>

 ** Modified by:

 ** Date:2010.09.05

 ** Description: kmp algorithm

 ** Version:

 ******************************************************************/

#include "matcher.h"
#include "replace.h"

int main(int argc, char const *argv[])
{
    char *target = "abababaababacb";
    char *pattern = "a";
    char *p = NULL;
    char *test = "ababababca";
    int *ta = NULL;
    int i = 0;
    char *a = "a";

    ta = (int *)malloc(strlen(test) *sizeof(int));


    printf("Target    : %s\nPattern : %s\n", target, pattern);
    p = kmp_matcher(target, pattern);
    if (p)
            printf("Pattern found at position : %d\n", p - target);
    else
            printf("Pattern not found!\n");


    printf("\n");




    printf("%s\n", replace(a, "a", "1234567890") );
    return 0;
}
