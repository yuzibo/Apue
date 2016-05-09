/*************************************************************************
     File Name: a.c
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2016年01月04日 星期一 23时16分23秒
 ************************************************************************/

#include<stdio.h>
#include "apue.h"
int main()
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("cannot seek\n");
	else
		printf("seek OK\n");
	exit(0);
}
