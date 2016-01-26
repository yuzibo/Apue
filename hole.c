/*************************************************************************
     File Name: hole.c
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2016年01月04日 星期一 23时20分49秒
 ************************************************************************/

#include<stdio.h>
#include "apue.h"
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main()
{
	int fd;
	if ((fd = creat("file.hole",FILE_MODE)) < 0)
		printf("creat error");
	if (write(fd, buf1, 10) != 10)
		printf("buf1 write error");
	if (lseek(fd, 16384, SEEK_SET) == -1)
		printf("LSEEK error");
	if (write(fd, buf2, 10) != 10)
		printf("buf2 write error");
	exit (0);

}
