#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define sleep(x) Sleep(1000 * (x))

sem_t oFinP1, oFinP3;

void *p1()
{
    sleep(round(500*rand()%2)-0.5);
    printf("\tP1\n");
    sem_post(&oFinP1);
    sem_post(&oFinP1);
}

void *p2()
{
    sem_wait(&oFinP1);
    sem_wait(&oFinP3);
    sleep(round(500*rand()%2)-0.5);
    printf("\tP2\n");
}

void *p3()
{
    sleep(round(500*rand()%2)-0.5);
    printf("\tP3\n");
    sem_post(&oFinP3);
    sem_post(&oFinP3);
}

void *p4()
{
    sem_wait(&oFinP1);
    sem_wait(&oFinP3);
    sleep(round(500*rand()%2)-0.5);
    printf("\tP4\n");
}

main()
{
    srand(time(NULL));
    sem_init(&oFinP1, 0, 0);
    sem_init(&oFinP3, 0, 0);

    pthread_t proceso1, proceso2, proceso3, proceso4;

    pthread_create(&proceso1, NULL, &p1, NULL);
    pthread_create(&proceso2, NULL, &p2, NULL);
    pthread_create(&proceso3, NULL, &p3, NULL);
    pthread_create(&proceso4, NULL, &p4, NULL);

    pthread_join(proceso1, NULL);
    pthread_join(proceso2, NULL);
    pthread_join(proceso3, NULL);
    pthread_join(proceso4, NULL);
}