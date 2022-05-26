// Escriba una aplicacion que calcule los valores de la funcion seno para los angulos de 0 a 90 grados, incrementando los grados de uno en uno, y almacene los resultados en un archivo de texto.
#include <stdio.h>
#include <math.h>

main()
{
    FILE *archivo = NULL;
    int i,k;
    int longitud;
    int estado;
    int seno;

    for (i = 0; i <= 90; k++)
    {
        seno = sin(i);
    }

    archivo = fopen("archivoseno.txt", "wt");

    if (archivo != NULL)
    {
        longitud = strlen(seno);
        for (k = 0; k < longitud; k++)
        {
            estado = fputc(seno, archivo);
            if (estado == EOF)
            {
                puts("Ha ocurrido un error al escribir en el archivo");
            }
        }
        fputc('\n', archivo);
    }
    else
    {
        puts("No se pudo abrir el archivo");
    }
}
