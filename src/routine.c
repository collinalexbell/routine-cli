#include "routine.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
