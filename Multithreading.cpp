#include <iostream>
#include <pthread.h>
using namespace std;

void* Thread1(void* arg) 
{
    int* ans=new int(10);
    *ans+=5;
    pthread_exit(ans);
}

void* Thread2(void* arg) 
{
    int* ans=new int(20);
    *ans*=2;
    pthread_exit(ans);
}

int main() 
{
    pthread_t t1,t2;
    void* ans1;
    void* ans2;

    pthread_create(&t1,NULL,Thread1,NULL);
    pthread_create(&t2, NULL,Thread2,NULL);

    pthread_join(t1,&ans1);
    pthread_join(t2,&ans2);

    int val1=*(int*)ans1;
    int val2=*(int*)ans2;

    cout<<"Value from Thread1: "<<val1<<endl;
    cout<<"Value from Thread2: "<<val2<<endl;
    cout<<"Sum: "<<(val1+val2)<<endl;

    delete (int*)ans1;
    delete (int*)ans2;

    return 0;
}
