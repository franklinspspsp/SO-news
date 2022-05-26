// Escriba un programa que muestre los atributos de acceso de un archivo.
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

main(int argc, char **argv)
{
    char *ruta;
    ruta = "./archivo.txt";

    if (!access(ruta, R_OK))
    {

        printf("Si permisos de lectura sobre %s\n", ruta);
    }
    else
    {
        printf("No tenemos permisos de lectura sobre %s\n", ruta);
    }
    if (!access(ruta, W_OK))
    {

        printf("Si Tenemos permisos de escritura sobre %s\n", ruta);
    }
    else
    {
        printf("No tenemos permisos de escritura sobre %s\n", ruta);
    }
}