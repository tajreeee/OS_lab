#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;

int main()
{
    pid_t pr;
    pr=fork();



    if (pr<0)
    {
        cout<<"Oops!Failed to create the process."<<endl;
    }
    else if(pr==0)
    {

        cout<<"Child: Hello! I'm the child process."<<endl;
        cout<<"Child: My PID is: "<<getpid()<<endl;
        cout<<"Child: My parent's PID is: "<<getppid()<<endl;
        cout<<"Child: Doing my assigned tasks..."<<endl;
        sleep(2);
        cout<<"Child: Done with my work. Exiting now."<<endl; 
          exit(0);
    }
    else
    {

        cout<<"Parent: I'm the parent process."<<endl;
        cout<<"Parent: My PID is: "<<getpid()<<endl;
        cout<<"Parent: My child's PID is: "<<pr<<endl;
        cout<<"Parent: Waiting for the child to complete..."<<endl;
        wait(NULL);
        cout<<"Parent: Child has finished. Now parent process ends."<<endl;
    }

    return 0;
}
