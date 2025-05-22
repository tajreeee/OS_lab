#include <iostream>
using namespace std;
#define MAX 1000

int main() 
{
    int n;
    int arrival[MAX],burst[MAX],start[MAX],waiting[MAX],turnaround[MAX],priority[MAX],remain[MAX];
    bool started[MAX]={false},complete[MAX]={false};
    int total_waiting=0,total_turnaround=0;

    cout<<"Enter the number of processes: ";
    cin>>n;

    cout<<"Enter the Arrival Time of each process:"<<endl;
    for(int i=0;i<n;i++) 
    {
        cout<<"Process "<<i+1<<" Arrival Time: ";
        cin>>arrival[i];
    }

    cout<<"Enter the Burst Time of each process:"<<endl;
    for(int i=0;i<n;i++) 
    {
        cout<<"Process "<<i+1<<" Burst Time: ";
        cin>>burst[i];
        remain[i]=burst[i];
    }

    cout<<"Enter the Priority of each process :"<<endl;
    for(int i=0;i<n;i++) 
    {
        cout<<"Process "<<i+1<<" Priority: ";
        cin>>priority[i];
    }

    int time=0;

    for(int done=0;done<n;) 
    {
        int idx=-1,high=1e9;
        for(int i=0;i<n;i++) 
        {
            if(!complete[i] && arrival[i]<=time && priority[i]<high && remain[i]>0) 
            {
                high=priority[i];
                idx=i;
            }
        }

        if(idx==-1) 
        {
            time++;
            continue;
        }

        if(!started[idx]) 
        {
            start[idx]=time;
            started[idx]=true;
        }

        remain[idx]--;
        time++;

        if(remain[idx]==0) 
        {
            complete[idx]=true;
            int finish=time;
            turnaround[idx]=finish-arrival[idx];
            waiting[idx]=turnaround[idx]-burst[idx];
            total_waiting+=waiting[idx];
            total_turnaround+=turnaround[idx];
            done++;
        }
    }

    cout<<endl<<"Process\tBT\tAT\tST\tWT\tTAT"<<endl;
    for(int i=0;i<n;i++) 
    {
        cout<<"P"<<i+1<<"\t"
             <<burst[i]<<"\t"
             <<arrival[i]<<"\t"
             <<start[i]<<"\t"
             <<waiting[i]<< "\t"
             <<turnaround[i]<< endl;
    }

    float avg_waiting=(float)total_waiting/n;
    float avg_turnaround=(float)total_turnaround/n;

    cout<<endl<<"Average Waiting Time: "<<avg_waiting<<endl;
    cout<<"Average Turnaround Time: "<<avg_turnaround<<endl;

    return 0;
}
