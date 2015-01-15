#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <stdio.h>
#include <dlfcn.h>

#ifdef DARWIN
#include <sys/param.h>
#include <sys/mount.h>
#else
#include <sys/vfs.h>
#endif

#include <stdint.h>
#include <limits.h>

#include "dso.h"
#include "policy.h"
#include "selinux_internal.h"

char *selinux_mnt = NULL;
int selinux_page_size = 0;

void set_selinuxmnt(const char *mnt)
{
	selinux_mnt = strdup(mnt);
}

hidden_def(set_selinuxmnt)


