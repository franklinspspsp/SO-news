// Escriba un programa que muestre la fecha de creación y ultima modificación de un archivo.
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

main(int argc, char *argv[])
{
    struct stat info;
    int ret;

    if (argc < 2)
    {
        fprintf(stderr, "uso del programa: %s <archivo>\n", argv[0]);
        return 1;
    }

    ret = stat(argv[1], &info);

    if (ret)
    {
        perror("stat");
        return 1;
    }

    printf("%s La fecha de creacion fue:  %s\n", argv[1], ctime(&info.st_ctime));
    printf("%s La ultima fecha de Modificacion fue: %s\n", argv[1], ctime(&info.st_mtime));
    printf("%s El ultimo Acceso fue:  %s\n", argv[1], ctime(&info.st_atime));
}