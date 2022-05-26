#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<pthread.h>
#include<unistd.h>

#define sleep(x) Sleep(1000 * (x))

struct HiloHerencia
{
    char *palabra;
    int pausa;
};

void* run(void* param)
{
    int i;
    struct HiloHerencia* hilo = (struct HiloHerencia*)param;

    for(i=0;i<100;++i)
    {
        printf("%s\n", hilo->palabra);
        sleep(hilo->pausa);
    }
}

main()
{
    struct HiloHerencia hilo1;
    hilo1.palabra = "Liebre";
    hilo1.pausa = 1;

    struct HiloHerencia hilo2;
    hilo2.palabra = "Tortuga";
    hilo2.pausa = 4;

    pthread_t h1, h2;

    pthread_create(&h1, NULL, run, &hilo1);
    pthread_create(&h2, NULL, run, &hilo2);

    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
}
