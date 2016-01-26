/*************************************************************************
     File Name: stat.c
     Author: yubo
     Mail: yuzibode@126.com
     Created Time: 2016年01月07日 星期四 18时42分37秒
 ************************************************************************/
/*
 *stat.c in command line display file status
 *
 *
 * @A: int lstat(const char *path, struct stat *buf);
 *	现在才明白,虽然这本书现在我看来很难懂,然而更深的细节没有介绍,
 *	比如,这个lstat的参数struct stat *buf如何实现的? if we used the stat
 *	function,we would never see symbolic link ~_~ >
 * @B: S_ISxxx 宏在早期的版本中没有,它是由st_mode 和掩码s_IFMT利用逻辑 AND实
 *      现,这样:
 *
 *      #define S_ISDIR(mode) ((mode) & S_IFMT == S_IFDIR)
 *
 *      这个S_IFDIR从stat.h中定义.
 *
 *
 */
#include<stdio.h>
#include "apue.h"
int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	char *ptr;
	/*form 1 rather than 0*/
	for(i = 1; i < argc; i++){
		printf("%s:",argv[i]);
		if (lstat(argv[i],&buf) < 0){
			/* @A */
			printf("lstat error");
			continue;
		}
		if (S_ISREG(buf.st_mode))
			ptr = "regular";
			/* @B */
		else if (S_ISDIR(buf.st_mode))
			ptr = "directory";
		else if (S_ISCHR(buf.st_mode))
			ptr = "character special";
		else if (S_ISBLK(buf.st_mode))
			ptr = "block special";
		else if (S_ISFIFO(buf.st_mode))
			ptr = "fifo";
		else if (S_ISLNK(buf.st_mode))
			ptr = "symbolic link";
		else if (S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else
			ptr ="**unknown mode **";
		printf("%s\n",ptr);

	}
	exit(0);

}
