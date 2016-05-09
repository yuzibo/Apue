/*************************************************************************
     File Name: fcntl.c
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2016年01月09日 星期六 02时07分46秒
 ************************************************************************/

#include<stdio.h>
#include "fcntl.h"
#include "apue.h"
int main(int argc,char **argv)
{
	if(argc != 2)
		printf("short than 2");
	if(access(argv[1],R_OK) < 0)
		printf("access error for %s",argv[1]);
	else
		printf("read access for %s\n",argv[1]);
	if (open(argv[1],O_RDONLY) < 0)
		printf("open error for %s",argv[1]);
	else printf("open for reading OK\n");
	exit(0);
}
