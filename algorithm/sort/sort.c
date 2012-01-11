/*FILE***********************************************************
 *Filename: sort.c
 *Writer: killer_yu
 *Date: 2010/11/04
 *Introduction:
 *Main Fuction List:
 *Modify Log:
 **********************************************************FILE*/

#include "sort.h"
#include <stdio.h>



/*FUN************************************************************
 *Fuction Name:  void insertion_sort(char array[], unsigned int first, unsigned int last)
 *Writer: killer_yu
 *Date: 2010/11/04
 *Introduction: Insertion Sort
 *Input: char array[], unsigned int first, unsigned int last
 *Output: Null
 *Modify Log:
 ***********************************************************FUN*/
void insertion_sort(char array[], unsigned int first, unsigned int last)
{
    int i,j;
    char temp;
	/*从first开始排序到last*/
    for(i = first + 1; i <= last; i++)
    {
	    temp = array[i];
		j = i - 1;
		/*这个很简单，就是从之前排好序的最后一个开始比较。如果前面的大于temp
		 * 并且没有到排序的第一个的时候把array[j - 1] 向后移动一个位置。temp
		 * 插入到array[j]位置*/
		while((j >= first) && (array[j] > temp))
		{
			array[j + 1] = array[j];
			j--;
			array[j + 1] = temp;
		}
    }
}


/*FUN************************************************************
 *Fuction Name: void InsertSort(char array[], unsigned int n)
 *Writer: killer_yu
 *Date: 2010/11/04
 *Introduction: Insertion Sort
 *Input: char array[], unsigned int n 
 *Output: Null
 *Modify Log:
 ***********************************************************FUN*/
void InsertSort(char array[], unsigned int n)
{
	int i,j;
	int temp;
	for(i = 1; i < n; i++)
	{
		temp = array[i];
		for( j = i; j > 0 && temp < array[j - 1]; j--)
		{
			array[j] = array[j - 1];
			array[j - 1] = temp;
		}
	}
}


/*FUN************************************************************
 *Fuction Name: void BubbleSort 
 *Writer: killer_yu
 *Date: 2010/11/04
 *Introduction: Bubble Sort
 *Input: char array[] 
 *Output: Null
 *Modify Log:
 ***********************************************************FUN*/
void BubbleSort(char array[], unsigned int size)
{
	int i,j;
	char temp;
	for(i = 0; i < size; i++)
	{
		for(j = 1 ; j < size; j++)
		{
			if(array[j] < array[j - 1])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}	
}



/*FUN************************************************************
 *Fuction Name: void ShellSort 
 *Writer: killer_yu
 *Date: 2010/11/05
 *Introduction: Shell Sort
 *Input: char array[],unsigned int size 
 *Output: Null
 *Modify Log:
 ***********************************************************FUN*/
void ShellSort(char array[], unsigned int size)
{
	/*
	 * This sequence was made by taking the fibonacci numbers,
	 * leaving out  one of the starting 1's, raising them to 
	 * the power of 2 * the golden ratio. Fractions are removed 
	 * with the floor function. It works particularly well as a
	 * gap sequence for the shell sort algorithm on large arrays.
	 */
	/*a(n) = floor(fibonacci(n+1)^(1+sqrt(5))*/
    unsigned long int gaps[] = {1, 9, 34, 182, 836, 4025, 19001,
	   	90358, 428481,	2034035, 9651787, 45806244, 217378076, 
		1031612713, 2147483647};

	int i, j, k, gap;
	char temp;

	for(k = 0; gaps[k] < size; k++);

	while(--k >= 0)
	{
		gap = gaps[k];
		for(i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while(j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = temp;
		}
	}
}


/*FUN************************************************************
 *Fuction Name: void MergeSort 
 *Writer: killer_yu
 *Date: 2010/11/09
 *Introduction: Bubble Sort
 *Input: char array[], int low, int mid, int high 
 *Output: Null
 *Modify Log:
 ***********************************************************FUN*/
/*
void MergeSort(char array[], unsigned int size)
{
	int i,k;
	int flag = 0; //记录已经排序的个数
	//申请空间，使其大小为两个已经排序序列之和，改空间用来存放合并后的序列
	char *temp = (char *)malloc(size * sizeof(char)); 


	for(k = 0; begin_one <= end_one && begin_two <= end_two; ++k)
	{
		if (array[begin_one] <= array[begin_two])
		{
			printf("%d ",k);
			temp[k] = array[begin_one++];
		}
		else
		{
			printf("%d ",k);
			temp[k] = array[begin_two++];
		}
	}
	
	printf("\n%s\n",temp);

	while(begin_one <= end_one)
	{
		temp[k++] = array[begin_one++];
	}

	while(begin_two <= end_two)
	{
		temp[k++] = array[begin_two++];
	}

	for(i = 0; i < (high - low + 1); i++)
	{
		array[low + i] = temp[i];
	}
	free(temp);
}
*/
