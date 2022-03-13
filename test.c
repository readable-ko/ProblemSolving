//ps huH p <PID_OF_U_PROCESS> | wc -l

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFSIZE 1024
#define FILELEN 1024
int main(int argc, char *argv[])
{
    int fd;
    int start_offset ;
    int read_bytes ;
    char filename[FILELEN] ;
    char buf[BUFSIZE] ;

    strcpy(filename, argv[1]) ;
    start_offset = atoi(argv[2]) ;

    fd = open(filename, O_RDONLY) ;
    if(fd == -1)
    {
        perror(filename) ;
        exit(1) ;
    }

    lseek(fd, start_offset, SEEK_SET) ;

    while((read_bytes = read(fd, buf, BUFSIZE)) > 0)
    {
        write(1, buf, read_bytes) ;
    }
    printf("\n\n") ;
    close(fd);
    return 0 ;
}