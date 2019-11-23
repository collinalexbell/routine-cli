#include "routine.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <linux/limits.h>


void get_home_dir(char *mem)
{
    strcpy(mem, getenv("HOME"));
}

void read_file(char* file_name, char* buf)
{
    char path[256];
    get_home_dir(path);
    strcat(path, "/");
    strcat(path, file_name);

    int c, cur_pos;
    FILE* f;

    f = fopen(path, "r");

    cur_pos = 0;
    while((c = fgetc(f)) != EOF) {
        buf[cur_pos] = (char) c;
        cur_pos++;
    }
    buf[cur_pos] = '\0';
}

struct Strings get_only_files(char* dir) {
    struct Strings rv;
    FILE *fd;
    int i;

    char cmd[256];
    strcpy(cmd, "ls -al ");
    strcat(cmd, dir);
    strcat(cmd, " | grep '^-' | wc -l");

    fd = popen(cmd, "r");
    fscanf(fd, "%d\n", &rv.num);
    rv.ptr = (char**) malloc(sizeof(char*) * rv.num);

    strcpy(cmd, "ls -al ");
    strcat(cmd, dir);
    strcat(cmd, " | grep '^-' | awk '{print $9}'");

    fd = popen(cmd, "r");
    i = 0;
    while(!feof(fd) && !ferror(fd)){
        rv.ptr[i] = malloc(sizeof(char) * PATH_MAX);
        fscanf(fd, "%s\n", rv.ptr[i]);
        i++;
    }

    return rv;
}
