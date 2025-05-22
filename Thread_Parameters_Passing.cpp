#include <iostream>
#include <pthread.h>
using namespace std;

struct Parameter
{
    int a;
    int b;
};

void* Thread(void* arg)
{
    Parameter* p=(Parameter*)arg;
    int sum=p->a + p->b;
    int* result=new int(sum);
    pthread_exit(result);
}

int main()
{
    pthread_t t;
    Parameter args={10,20};
    void* ret;

    pthread_create(&t,NULL,Thread,&args);
    pthread_join(t,&ret);

    int val= *(int*)ret;
    
    pthread_create(&t,NULL,Thread,&args);
    pthread_join(t,&ret);

   
    cout<<"Sum of parameters: "<<val<<endl;

    delete (int*)ret;
    return 0;
}
