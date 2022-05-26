// Modifique el programa de ejemplo demoMapeo.c para que el nombre del archivo de texto que se analizará pase como argumento al igual que el desplazamiento del carácter que se quiere mostrar. Esto permitirá invocar el programa de la siguiente forma:
// ./demoMapeo <a chivo.txt> <desplazamiento>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

main(int argc, char **argv)
{
    int fd;
    int offset;
    int fdo;
    char *data;
    struct stat sbuf;

    if (argc != 3)
    {

        fprintf(stderr, "Uso: %s <archivo.txt> <desplazamiento> \n", argv[0]);
        exit(1);
    }

    if ((fdo = open(argv[1], O_RDONLY)) < 0)
    {

        perror("No puede abrise el archivo origen");
        exit(1);
    }

    printf("ESTE PROGRAMA MUESTRA EL ENESIMO CARACTER DE UN ARCHIVO PROYECTADO EN MEMORIA\n");

    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        perror("open");
        exit(1);
    }

    if (stat(argv[1], &sbuf) == -1)

    {
        perror("stat");
        exit(1);
    }

    offset = atoi(argv[2]);
    if (offset < 0 || offset > sbuf.st_size - 1)

    {
        fprintf(stderr, "El desplazamiento debe estar en el rango 0-%ld\n", sbuf.st_size - 1);
        exit(1);
    }

    data = mmap((caddr_t)0, sbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (data == (caddr_t)(-1))

    {
        perror("mmap");
        exit(1);
    }

    printf("El byte en la posicion %d es %c\n", offset, data[offset]);
}