#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<errno.h>

main(int argc, char *argv[])
{
    int fd;
    int offset;
    char *data;
    struct stat sbuf;

    if(argc != 2)
    {
        fprintf(stderr,"Uso: g9e2 <desplazamiento>\n");
        exit(1);
    }

    printf("Este programa muestra el enesimo caracter de un archivo proyectado en memoria\n");

    if(fd = open("g9e2.c", O_RDONLY) == -1)
    {
        perror("open");
        exit(1);
    }

    if(stat("g9e2.c", &sbuf) == -1)
    {
        perror("stat");
        exit(1);
    }

    offset = atoi(argv[1]);

    if(offset < 0 || offset > sbuf.st_size-1)
    {
        fprintf(stderr,"El desplazamiento debe estar en el rango 0-%d\n", sbuf.st_size-1);
        exit(1);
    }

    data = mmap((caddr_t)0, sbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);

    if(data == (caddr_t)(-1))
    {
        perror("mmap");
        exit(1);
    }

    printf("El byte en la posicion %d es %c\n", offset, data[offset]);
}