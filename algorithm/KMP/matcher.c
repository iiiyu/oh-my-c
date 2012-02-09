/******************************************************************
 ** File Name:matcher.c

 ** Copyright(c)2005-2011	ChenYu Xiao	

 ** Created: ChenYu Xiao  <yunsn0303@gmail.com>

 ** Modified by:

 ** Date:2010.09.05

 ** Description: kmp algorithm

 ** Version:

 ******************************************************************/



#include "matcher.h"



static void
compute_prefix_function(const char *, int *);



static void
compute_prefix_function(const char *pattern, int *next)
{
        int i = 0;
        int j = -1;
 
        next[0] = -1;
        while (i < strlen(pattern) - 1)
        {
                if (-1 == j || pattern[i] == pattern[j])
                {
                        ++i;
                        ++j;
                        next[i] = j;    
                }
                else
                {
                        
                        j = next[j];
                }
                
        }
}

char *
kmp_matcher(const char *target, const char *pattern)
{
        int i = 0;
        int j = 0;
        int targetlen;
        int patternlen;
        int *next = NULL;
    
        targetlen = strlen(target);
        patternlen = strlen(pattern);
 
        next = (int *)malloc(patternlen * sizeof(int));
        if (NULL == next)
                return NULL;
 
        compute_prefix_function(pattern, next);
 
        while (i < targetlen && j < patternlen)
        {
                if (-1 == j || target[i] == pattern[j])
                {
                        ++i;
                        ++j;
                }
                else
                {
                        j = next[j];
                }
                
        }

        free(next);
        next = NULL;
 
        if (j >= patternlen)
        {
                
                return (char *)&target[i - patternlen];
        }
        else
        {
                return NULL;
        }
        
}



#if 0
int main()
{
        char *target = "abababaababacb";
        char *pattern = "a";
        char *p = NULL;
        char *test = "ababababca";
        int *ta = NULL;
        int i = 0;

        ta = (int *)malloc(strlen(test) *sizeof(int));

        compute_prefix_function(test, ta);

        printf("Target    : %s\nPattern : %s\n", target, pattern);
        p = kmp_matcher(target, pattern);
        if (p)
                printf("Pattern found at position : %d\n", p - target);
        else
                printf("Pattern not found!\n");


        for(i = 0; i < 10; i++)
        {
                printf("%d\t", *(ta + i));
        }

        printf("\n");
        
                
	return 0;
}
#endif



