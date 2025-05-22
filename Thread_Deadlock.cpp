#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t resource1;
pthread_mutex_t resource2;

void* Thread1(void* arg) 
{
    pthread_mutex_lock(&resource1);
    cout<<"Thread1 locked resource1"<<endl;
    sleep(1);
    cout<<"Thread1 trying to lock resource2"<<endl;
    pthread_mutex_lock(&resource2);
    cout<<"Thread1 locked resource2"<<endl;
    pthread_mutex_unlock(&resource2);
    pthread_mutex_unlock(&resource1);
    return NULL;
}

void* Thread2(void* arg) 
{
    pthread_mutex_lock(&resource2);
    cout<<"Thread2 locked resource2"<<endl;
    sleep(1);
    cout<<"Thread2 trying to lock resource1"<<endl;
    pthread_mutex_lock(&resource1);
    cout<<"Thread2 locked resource1"<<endl;
    pthread_mutex_unlock(&resource1);
    pthread_mutex_unlock(&resource2);
    return NULL;
}

int main() 
{
    pthread_mutex_init(&resource1,NULL);
    pthread_mutex_init(&resource2,NULL);

    pthread_t t1,t2;
    pthread_create(&t1,NULL,Thread1,NULL);
    pthread_create(&t2,NULL,Thread2,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_mutex_destroy(&resource1);
    pthread_mutex_destroy(&resource2);

    cout<<"Program finished"<<endl;
    return 0;
}
