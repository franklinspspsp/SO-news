#include<stdio.h>
#include<string.h>

main()
{
    FILE* archivo=NULL;
    int i;
    int longitud;
    int estado;
    char cadena[]="Cadena que se almacena en el archivo.";

    archivo=fopen("archivo.txt","wt");

    if(archivo!=NULL)
    {
        longitud=strlen(cadena);
        for(i=0;i<longitud;i++)
        {
            estado=fputc(cadena[i],archivo);
            if (estado==EOF)
            {
                printf("Ha ocurrido un error al escribir en el archivo.");
            }
        }
        fputc('\n',archivo);
    }
    else
    {
        printf("No se pudo abrir el archivo.");
    }
}