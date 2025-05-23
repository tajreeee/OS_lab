#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <queue>
#define Max 15
#define BUFFER_SIZE 10

using namespace std;

queue<int>buffer;
sem_t sem_empty;
sem_t sem_full;
pthread_mutex_t mutex;

int item=0;
int count=0;

void* producer(void* arg) 
{
    while(item<Max) 
    {
        sleep(1);
        sem_wait(&sem_empty);
        pthread_mutex_lock(&mutex);
        item++;
        buffer.push(item);
        cout<<"Producer produced: "<<item<<endl;
        pthread_mutex_unlock(&mutex);
        sem_post(&sem_full);
    }
    return nullptr;
}

void* consumer(void* arg) 
{
    while(true) 
    {
        sleep(2);
        sem_wait(&sem_full);
        
        pthread_mutex_lock(&mutex);
        if(!buffer.empty())
        {
              int consumed=buffer.front();
              buffer.pop();
              count++;
              cout<<"Consumer consumed: "<<consumed<<endl;
        }
        pthread_mutex_unlock(&mutex);
        sem_post(&sem_empty);
        sleep(2);

        if(count>=Max)
            break;
    }
    return nullptr;
}

int main() 
{
    pthread_t prod,cons;

    sem_init(&sem_empty,0,BUFFER_SIZE);
    sem_init(&sem_full,0,0);
    pthread_mutex_init(&mutex,nullptr);

    pthread_create(&prod,nullptr,producer,nullptr);
    pthread_create(&cons,nullptr,consumer,nullptr);

    pthread_join(prod,nullptr);
    pthread_join(cons,nullptr);

    sem_destroy(&sem_empty);
    sem_destroy(&sem_full);
    pthread_mutex_destroy(&mutex);
    cout<<"All items produced and consumed."<<endl;
    return 0;
}
