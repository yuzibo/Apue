/*************************************************************************
     File Name: atexit.c
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2016年01月28日 星期四 22时16分39秒
	example: demonstrates the use of the func atexit
 ************************************************************************/

#include<stdio.h>
#include "apue.h"
static void my_exit1(void);
static void my_exit2(void);
int main()
{
	if (atexit(my_exit2) != 0)
		printf("can't register my_exit2");
	if (atexit(my_exit1) != 0)
		printf("can't register my_exit1");
	printf("main is done\n");
	return (0);
}
static void my_exit1(void)
{
	printf("first exit handler\n");

}
static void my_exit2(void)
{
	printf("second exit handler\n");
}

