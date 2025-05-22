#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
using namespace std;

int main() 
{
    pid_t pr=fork();

    if(pr==0) 
    {
        
        sleep(3); 
        cout<<"I am the child. My PID is: "<<getpid()<<endl;
        cout<<"My new parent's PID : "<<getppid()<<endl;
    }
    else if(pr>0) 
    {
        
        cout<<"I am the parent. My PID is: "<<getpid()<<endl;
        cout<<"Parent is terminating now...\n";
        exit(0);
    }

    return 0;
}

