#include <stdio.h>
#include <stlib.h>

int main( int argc, char** argv)
{
    int buf_size = 0;
    int buf_used = 0;

    char* buf = NULL;
    char* tmp = NULL;    

    char c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (buf_used == buf_size) {
             //need more space in the array

             buf_size += 20;
             tmp = realloc(buf, buf_size); // get a new larger array
             if (!tmp) fatal_error();

             buf = tmp;
        }

        buf[buf_used] = c; // pointer can be indexed like an array
        ++buf_used;
    }

    puts("\n\n*** Dump of stdin ***\n");

    for (i = 0; i < buf_used; ++i) {
        putchar(buf[i]);
    }

    free(buf);

    return 0;
}

void fatal_error(void)
{
    fputs("fatal error - out of memory\n", stderr);
    exit(1);
}
