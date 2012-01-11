#include <stdio.h>
#include <time.h>
#include "rand.h"
#include "sort.h"

//#define MAXSIZE 100000


int main(int argv, char **argc)
{

	char *p = rand_str(MAXSIZE);
        int i = 0;
	int t_beg, t_end;
    //printf("%s\n",p); 
	t_beg = clock();
//	InsertSort(p, MAXSIZE);
//	insertion_sort(p,0, MAXSIZE);
    BubbleSort(p, MAXSIZE);
    //ShellSort(p, MAXSIZE);
//	MergeSort(p, 0, MAXSIZE / 2, MAXSIZE);
	t_end = clock();
    //printf("%s\n",p);	
	printf("%dms\n",t_end - t_beg);
	return 0;
}
