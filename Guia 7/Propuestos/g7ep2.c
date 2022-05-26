#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<pthread.h>
#include<unistd.h>

#define sleep(x) Sleep(1000 * (x))

void p1()
{
    sleep(round(500*rand()%2)-0.5);
    printf("\tP1\n");
}

void p2()
{
    sleep(round(500*rand()%2)-0.5);
    printf("\tP2\n");
}

void p3()
{
    sleep(round(500*rand()%2)-0.5);
    printf("\tP3\n");
}

void p4()
{
    sleep(round(500*rand()%2)-0.5);
    printf("\tP4\n");
}

main()
{
    srand(time(NULL));
    pthread_t hilo1,hilo2,hilo3,hilo4;

    pthread_create(&hilo1, NULL, &p1, NULL);
    pthread_create(&hilo2, NULL, &p2, NULL);
    pthread_create(&hilo3, NULL, &p3, NULL);
    pthread_create(&hilo4, NULL, &p4, NULL);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);
    pthread_join(hilo4, NULL);
}