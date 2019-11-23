#ifndef ROUTINE_H
#define ROUTINE_H

struct Strings {
    char** ptr;
    int num;
};

void get_home_dir(char* mem);
void read_file(char* file_name, char* buf);
struct Strings get_only_files(char* dir);

#endif
