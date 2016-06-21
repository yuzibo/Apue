/*************************************************************************
     File Name: echo.c
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2016年01月28日 星期四 22时32分58秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[]){
	int i;
	for (i = 0; i < argc; i ++)
		printf("argv[%d]: %s\n", i, argv[i]);
	exit(0);
}
