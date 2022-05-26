// Escriba un programa que compare dos archivos utilizando archivos proyectados en memoria.
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main(int argc, char **argv)
{
    int fd1, fd2, Distintos, i = 0;
    char *archivo1, *archivo2;
    char *p, *q;
    struct stat sbuf1, sbuf2;

    if (argc != 3)
    {
        fprintf(stderr, "Uso: %s <11> <22> \n", argv[0]);
        exit(1);
    }

    if ((fd1 = open(argv[1], O_RDONLY)) < 0)
    {
        perror("No puede abrirse el archivo");
        return (1);
    }

    if ((fd2 = open(argv[2], O_RDONLY)) < 0)
    {
        perror("No puede abrirse el archivo");
        return (1);
    }

    if (fstat(fd1, &sbuf1) < 0)
    {
        perror("Error en fstat del archivo1");
        close(fd1);
        close(fd2);
        return (1);
    }
    if (fstat(fd2, &sbuf2) < 0)
    {
        perror("Error en fstat del archivo2");
        close(fd2);
        close(fd1);
        return (1);
    }

    if ((archivo1 = mmap((caddr_t)0, sbuf1.st_size, PROT_READ, MAP_SHARED, fd1, 0)) == MAP_FAILED)
    {
        perror("Error en la proyeccion del archivo 1");
        close(fd1);
        close(fd2);
        return (1);
    }
    close(fd1);
    if ((archivo2 = mmap((caddr_t)0, sbuf2.st_size, PROT_READ, MAP_SHARED, fd2, 0)) == MAP_FAILED)
    {
        perror("Error en la proyeccion del archivo 2 \n");
        close(fd1);
        close(fd2);
        return (1);
    }

    close(fd1);
    close(fd2);

    if (sbuf1.st_size != sbuf2.st_size)
    {
        printf("Los archivos son diferentes en tamanio \n");
    }

    if (sbuf1.st_size == sbuf2.st_size)
    {
        printf("Los archivos son iguales en tamanio \n")
    }

    munmap(archivo1, sbuf1.st_size);
    munmap(archivo2, sbuf2.st_size);
}