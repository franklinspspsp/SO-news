// Escriba un programa que muestre la frecuencia de aparición de los caracteres del alfabeto ingles contenidos en un archivo de texto proyectado en memoria.
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

main(int argc, char *argv[])
{
    int fdo;
    int fd;
    int offset;
    char *data;
    int i, j, k, c = 0;
    char abc[] = {"abcdefghijklmnopqrstuvwxyz"};
    int cont[26];
    struct stat sbuf;
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <archivo.txt> \n");
        exit(1);
    }
    if ((fdo = open(argv[1], O_RDONLY)) < 0)
    {
        perror("No puede abrise el archivo origen");
        exit(1);
    }

    printf("ESTE PROGRAMA MUESTRA EN UN ALFABETO CUANTAS VECES SE REPITE UN ENESIMO CARACTER DE UN ARCHIVO PROYECTADO EN MEMORIA\n");

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

    data = mmap((caddr_t)0, sbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (data == (caddr_t)(-1))
    {
        perror("mmap");
        exit(1);
    }

    for (j = 0; j < 26; j++)
    {
        for (i = 0; i < sbuf.st_size; i++)
        {
            if (data[i] == abc[j])
            {
                c = c + 1;
            }
        }
        printf("La letra %c se repite %d \n", abc[j], c);
        c = 0;
    }
}