/*
 *     File Name: detail.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2016年06月24日 星期五 05时02分29秒
 */
#include<stdio.h>
#include "apue.h"

int main(int argc, char *argv[])
{
	int	j;
	struct stat buf;
	char	*ptr;
	for(j = 1; j < argc; j++){
		printf("%s:",argv[j]);
		if(lstat(argv[j], &buf) < 0){
				printf("lstat error");
			continue;
		}
		if(S_ISREG(buf.st_mode))
			ptr = "regular";
		else if(S_ISDIR(buf.st_mode))
			ptr = "direct";
		else if(S_ISCHR(buf.st_mode))
			ptr = "character specical";
		else if (S_ISBLK(buf.st_mode))
			ptr = "block special";
		else if(S_ISLNK(buf.st_mode))
			ptr = "symbolicc link";
		else if(S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else
			ptr = "** unknown mode **";
		printf("%s\n", ptr);



	}
	exit(0);

}
