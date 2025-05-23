#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>
using namespace std;

int balance=1000;
sem_t sem;

void* deposit(void*) 
{
    for(int i=0;i<5;i++) 
    {
        sem_wait(&sem);
        int temp=balance;
        temp+=100;
        balance=temp;
        cout<<"Deposited 100, balance: " <<balance<<endl;
        sem_post(&sem);
        sleep(1);
    }
    return NULL;
}

void* withdraw(void*) 
{
    for(int i=0;i<5;i++) 
    {
        sem_wait(&sem);
        if(balance>=50) 
        {
            int temp=balance;
            temp-=50;
            balance=temp;
            cout<<"Withdrew 50, balance: "<<balance<<endl;
        } 
        else 
        {
            cout<<"Withdrawal failed: insufficient balance"<<endl;
        }
        sem_post(&sem);
        sleep(2); 
    }
    return NULL;
}

int main() 
{
    pthread_t t1,t2;

    sem_init(&sem,0,1);

    pthread_create(&t1,NULL,deposit,NULL);
    pthread_create(&t2,NULL,withdraw,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    cout<<"Final balance: "<<balance<<endl;

    sem_destroy(&sem);
    return 0;
}
