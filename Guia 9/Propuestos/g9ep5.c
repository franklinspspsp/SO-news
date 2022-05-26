// Escriba un programa que lea dos archivos de texto y cree uno tercero con las líneas de los dos primeros archivos intercaladas.
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main(int argc, char **argv)
{
    int i, j;
    int t1, t2, total;
    int fdo1;
    int fdo2;
    int fdd;
    char *org1;
    char *org2;
    char *dst;
    char *p;
    char *r;
    char *q;
    struct stat bstat1, bstat2;

    if (argc != 4)
    {
        fprintf(stderr, "Uso: %s origen1 y origen2 dest \n", argv[0]);
        exit(1);
    }

    if ((fdo1 = open(argv[1], O_RDONLY)) < 0)
    {
        perror("No puede abrise el archivo origen 1");
        exit(1);
    }
    if ((fdo2 = open(argv[2], O_RDONLY)) < 0)
    {
        perror("No puede abrise el archivo origen 2");
        exit(1);
    }

    if ((fdd = open(argv[3], O_CREAT | O_TRUNC | O_RDWR)) < 0)
    {
        perror("No puede crearse el archivo destino");
        close(fdo1);
        close(fdo2);
        exit(1);
    }
    if (fstat(fdo1, &bstat1) < 0)
    {
        perror("Error en fstat del archivo origen");
        close(fdo1);
        close(fdo2);
        close(fdd);
        unlink(argv[3]);
        exit(1);
    }
    t1 = bstat2.st_size;
    if (fstat(fdo2, &bstat2) < 0)
    {
        perror("Error en fstat del archivo origen");
        close(fdo1);
        close(fdo2);
        close(fdd);
        unlink(argv[3]);
        exit(1);
    }
    t2 = bstat2.st_size;

    total = t1 + t2;
    if (ftruncate(fdd, bstat1.st_size + bstat2.st_size) < 0)
    {
        perror("Error en ftruncate del archivo destino");
        close(fdo1);
        close(fdo2);
        close(fdd);
        unlink(argv[3]);
        exit(1);
    }

    if ((org1 = mmap((caddr_t)0, bstat1.st_size, PROT_READ, MAP_PRIVATE, fdo1, 0)) == MAP_FAILED)
    {
        perror("Error en la proyeccion del archivo origen");
        close(fdo1);
        close(fdo2);
        close(fdd);
        unlink(argv[3]);
        exit(1);
    }
    if ((org2 = mmap((caddr_t)0, bstat2.st_size, PROT_READ, MAP_PRIVATE, fdo2, 0)) == MAP_FAILED)
    {
        perror("Error en la proyeccion del archivo origen");
        close(fdo1);
        close(fdo2);
        close(fdd);
        unlink(argv[3]);
        exit(1);
    }

    if ((dst = mmap((caddr_t)0, bstat1.st_size + bstat2.st_size, PROT_WRITE, MAP_SHARED, fdd, 0)) == MAP_FAILED)
    {
        perror("Error en la proyeccion del archivo destino");
        close(fdo1);
        close(fdo2);
        close(fdd);
        unlink(argv[3]);
        exit(1);
    }

    close(fdo1);
    close(fdo2);
    close(fdd);

    p = org1;
    r = org2;
    q = dst;
    for (i = 0; i < bstat1.st_size; i++)
    {
        *q++ = *p++;
    }
    for (j = 0; j < bstat2.st_size; j++)
    {
        *q++ = *r++;
    }

    munmap(org1, bstat1.st_size);
    munmap(org2, bstat2.st_size);
    munmap(dst, total);
}