/*************************************************************************
     File Name: copy.c
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2016年01月04日 星期一 23时45分33秒
 ************************************************************************/
#include "apue.h"
#define bufsize 4096
#include<stdio.h>
int main()
{
	int n;
	char buf[bufsize];
	while ((n = read(STDIN_FILENO, buf, bufsize)) > 0)
		if (write(STDIN_FILENO, buf, n) != n)
			printf("write error");
	if(n < 0)
		printf("read error");
	exit(0);
}
