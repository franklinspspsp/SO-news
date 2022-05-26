#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

main(int argc, char **argv)
{
    int i;
    int fdo;
    int fdd;
    char *org;
    char *dst;
    char *p;
    char *q;
    struct stat bstat;

    if(argc != 3)
    {
        printf(stderr,"Uso: %s orig dest \n", argv[0]);
        exit(1);
    }

    if((fdo = open(argv[1], O_RDONLY)) < 0)
    {
        perror("No puede abrirse el archivo origen");
        exit(1);
    }

    if((fdd = open(argv[2], O_CREAT|O_TRUNC|O_RDWR)) < 0)
    {
        perror("No puede Crearse el archivo destino");
        exit(1);
    }

    if(fstat(fdo, &bstat) < 0)
    {
        perror("Error en fstat del archivo origen");
        close(fdo);
        close(fdd);
        unlink(argv[2]);
        exit(1);
    }

    if(ftruncate(fdd, bstat.st_size) < 0)
    {
        perror("Error en ftruncate del archivo destino");
        close(fdo);
        close(fdd);
        unlink(argv[2]);
        exit(1);
    }

    if((org=mmap((caddr_t)0,bstat.st_size,PROT_READ,MAP_PRIVATE,fdo,0)) == MAP_FAILED)
    {
        perror("Error en la proyeccion del archivo origen");
        close(fdo);
        close(fdd);
        unlink(argv[2]);
        exit(1);
    }

    if((dst=mmap((caddr_t)0,bstat.st_size,PROT_WRITE,MAP_SHARED,fdd,0)) == MAP_FAILED)
    {
        perror("Error en la proyeccion del archivo destino");
        close(fdo);
        close(fdd);
        unlink(argv[2]);
        exit(1);
    }

    close(fdo);
    close(fdd);

    p=org;
    q=dst;

    for(i=0;i<bstat.st_size;i++)
    {
        *q++ = *p++;
    }

    munmap(org,bstat.st_size);
    munmap(dst,bstat.st_size);
}