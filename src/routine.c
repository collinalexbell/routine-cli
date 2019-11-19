#include "routine.h"
#include <stdlib.h>

void get_home_dir(char *mem)
{
    strcpy(mem, getenv("HOME"));
}
