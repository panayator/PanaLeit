#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int global[2];
int prod;

void *prod_thread(void *arg)
{
    int *args_array;
    args_array = arg;

    int n1,n2;
    n1=args_array[0];
    n2=args_array[1];
    prod = n1*n2;

    

    return NULL;
}

int main() 
{
    printf("First number: ");
    scanf("%d",&global[0]);

    printf("Second number: ");
    scanf("%d",&global[1]);

    pthread_t tid_prod;
    pthread_create(&tid_prod,NULL,prod_thread,global); 
    pthread_join(tid_prod,NULL);
    printf("N1 * N2 = %d\n",prod);

    return 0;
}