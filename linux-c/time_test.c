#include <stdio.h>
#include <time.h>

int main()
{
	char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	char *tp = "1314162778";
        time_t timep = atoi(tp);
        struct tm *p;
        //time(&timep);
        p=localtime(&timep); /*取得当地时间*/
        printf ("%d%d%d ", (1900+p->tm_year),( 1+p->tm_mon), p->tm_mday);
        printf("%s %d:%d:%d\n", wday[p->tm_wday],p->tm_hour, p->tm_min, p->tm_sec);
        return 0;
}
