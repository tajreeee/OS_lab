#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;

int cnt=0;
pthread_mutex_t mutexLock;
pthread_mutex_t wrt;
const int readers=3;
const int writers=2;
const int rl=5;
const int wrl=3;

void* reader(void* arg) 
{
    int id=*((int*)arg);
    for(int i=0;i<rl;i++) 
    {
        pthread_mutex_lock(&mutexLock);
        cnt++;
        if(cnt==1)
            pthread_mutex_lock(&wrt);
        pthread_mutex_unlock(&mutexLock);

        cout<<"Reader "<<id<<" is reading"<<endl;
        sleep(1);

        pthread_mutex_lock(&mutexLock);
        cnt--;
        if(cnt==0)
            pthread_mutex_unlock(&wrt);
        pthread_mutex_unlock(&mutexLock);

        sleep(1);
    }
    return nullptr;
}

void* writer(void* arg) 
{
    int id=*((int*)arg);
    for(int i=0;i<wrl;i++) 
    {
        pthread_mutex_lock(&wrt);
        cout<<"Writer "<<id<<" is writing"<<endl;
        sleep(2);
        pthread_mutex_unlock(&wrt);
        sleep(2);
    }
    return nullptr;
}

int main() 
{
    pthread_t r[readers], w[writers];
    int r_id[readers], w_id[writers];

    pthread_mutex_init(&mutexLock,nullptr);
    pthread_mutex_init(&wrt,nullptr);

    for(int i=0;i<readers;i++) 
    {
        r_id[i]=i+1;
        pthread_create(&r[i],nullptr,reader,&r_id[i]);
    }

    for(int i=0;i<writers;i++) 
   {
        w_id[i]=i+1;
        pthread_create(&w[i],nullptr,writer,&w_id[i]);
    }

    for(int i=0;i<readers;i++)
        pthread_join(r[i],nullptr);
    for(int i=0;i<writers;i++)
        pthread_join(w[i],nullptr);

    pthread_mutex_destroy(&mutexLock);
    pthread_mutex_destroy(&wrt);
    return 0;
}
