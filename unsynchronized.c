/**
 * @author AwkNinja
 * 
 * A program to see how you get undesired results if you use an unsynchronized counter with multithreading
 * This program can run one or more threads, each thread increments the counter number of times given by
 * the user. After all threads are finished executing the value of the count is printed and compared to what
 * we should have ideally received. The user inputs the number of threads and the number of increments each
 * thread should increment the count by. Generally when you give a large number of increments you will see
 * a difference e.g 10000
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;
int numberOfThreads = 0;
int numberOfIncrements = 0;

//This method increments the counter everytime it is called
void inc()
{
    count++;    
}

//This is the runner method that will be passed to the threads
//This method calls the inc() method the number of times user wants it to be incremented
void* runner()
{
    for(int i = 0; i < numberOfIncrements; i++)
    {
        inc();
    }
}

int main(int argc, char*argv[])
{

    printf("\nEnter number of threads: ");
    scanf("%d", &numberOfThreads);

    do
    {
        printf("\nEnter number of times each thread will increment the count variable: ");
        scanf("%d", &numberOfIncrements);
        if(numberOfIncrements <= 0)
        {
            printf("Please enter a positive number");
        }
    } while (numberOfIncrements <= 0);
    
    

    pthread_t t[100];

    for(int i = 0; i < numberOfThreads; i++)
    {
        pthread_create(&t[i], NULL, runner, NULL);
    }


    for(int i = 0; i < numberOfThreads; i++)
    {
        pthread_join(t[i], NULL);
    }


    int idealCountValue = numberOfIncrements * numberOfThreads;
    printf("\nThe final value of count should ideally be: %d", idealCountValue);    //the ideal count value
    printf("\nThe final value of count obtained from this program is: %d\n", count);    //the actual count value
}
