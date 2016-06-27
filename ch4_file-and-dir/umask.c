/*
 *     File Name: umask.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2016年06月27日 星期一 03时29分40秒
 */
#include<stdio.h>
#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(){
	umask(0);
	if(creat("foo",RWRWRW) < 0)
		err_sys("create error for foo");
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(creat("bar", RWRWRW) < 0)
		err_sys("create error for bar");
	exit(0);

}
