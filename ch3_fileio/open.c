/*************************************************************************
     File Name: open.c
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2016年05月09日 星期一 02时58分40秒
 ************************************************************************/
/*
 * here, you must first open or creat a file
 *
 */
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd = open("/root/Apue/fileio/create.txt",O_RDONLY);
	if(fd == -1){
		printf("can't open the file\n");
	}
	else {
		printf("Ok,open...The return value is %d\n",fd);
	}

	off_t currpos = lseek(fd, 0, SEEK_CUR);
	printf("The offset is %d\n",currpos);

	int fd_close = close(fd);
	if (fd_close != -1)
		printf("successfully close\n");
/* here use pipe: ./exe < /etc/passwd */
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("can't seek\n");
	else
		printf("seek OK\n");
	int fd2 = creat("/root/Apue/fileio/create.txt",O_RDWR);
	if (fd2 == -1){
		printf("create fail\n");

	}
	else
		printf("suessfully\n");

}
