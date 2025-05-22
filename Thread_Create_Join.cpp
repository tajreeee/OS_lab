#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;


void* thread_fun(void* arg) 
{
    cout<<"Inside thread"<<endl;
    for(int j=1;j<5;j++) 
    {
        cout<<j<<endl;
        sleep(1); 
    }
    return NULL;
}

int main() 
{
    pthread_t thread1;

    
    pthread_create(&thread1, NULL, thread_fun, NULL);

    pthread_join(thread1, NULL);

    cout<<"Back to main process"<<endl;

    for(int i=95;i<101;i++) 
    {
        cout<<i<<endl;
        sleep(1);
    }

    return 0;
}
