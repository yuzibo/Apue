/*
 *     File Name: ioefficiency.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2016年05月17日 星期二 05时07分35秒
 */
#include<stdio.h>
#include "apue.h"
#define BUFSIZE 4096
int main(){
	int	n;
	char	buf[BUFSIZE];
	while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			printf("write error\n");
	if (n < 0)
		printf("read error");
	exit(0);
}

