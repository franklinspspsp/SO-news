#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdbool.h>

main(int argc, char* argv[])
{
    struct stat info;
    int ret;

    if(argc<2)
    {
        fprintf(stderr,"Uso del programa: %s <archivo>\n",argv[0]);
        return 1;
    }

    ret=stat(argv[1],&info);

    if(ret)
    {
        perror("stat");
        return 1;
    }

    printf("%s es de %ld bytes\n",argv[1],info.st_size);
}