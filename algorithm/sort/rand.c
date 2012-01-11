#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char * rand_str(int in_len)
{
	unsigned char *__r = (unsigned char *)malloc(in_len + 1);

	int i;

	if (__r == 0)
	{
		return 0;
	}

	srand(time(0) + rand());

	for( i = 0; i < in_len; i++)
	{
		__r[i] = rand() % 94 + 32; // 控制得到的随机字符为可以打印的字符
	}

	__r[i] = 0;

	return __r;
}
