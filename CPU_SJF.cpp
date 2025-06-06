#include <iostream>
using namespace std;
#define MAX 1000

int main() 
{
    int n;
    int arrival[MAX],burst[MAX],start[MAX],waiting[MAX],turnaround[MAX];
    int total_waiting=0,total_turnaround=0;
    bool complete[MAX]={false};
    int time=0;

    cout <<"Enter the number of processes: ";
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
    }

    for(int done=0;done<n;done++) 
    {
        int idx=-1;
        int mini=1e9;

        for(int i=0;i<n;i++) 
        {
            if(!complete[i] && arrival[i]<=time && burst[i]<mini) 
            {
                mini=burst[i];
                idx=i;
            }
        }

        if(idx==-1) 
        {
            time++;
            done--;
            continue;
        }

        start[idx]=time;
        waiting[idx]=start[idx]-arrival[idx];
        turnaround[idx]=waiting[idx]+burst[idx];
        time+=burst[idx];
        complete[idx]=true;

        total_waiting+=waiting[idx];
        total_turnaround+=turnaround[idx];
    }

    cout<<endl<<"Process\tBT\tAT\tST\tWT\tTAT"<<endl;
    for(int i=0;i<n;i++) 
    {
        cout<<"P"<<i+1<<"\t"
             <<burst[i]<<"\t"
             <<arrival[i]<<"\t"
             <<start[i]<<"\t"
             <<waiting[i]<<"\t"
             <<turnaround[i]<<endl;
    }

    float avg_waiting=(float)total_waiting/n;
    float avg_turnaround=(float)total_turnaround/n;

    cout<<endl<<"Average Waiting Time: "<<avg_waiting<<endl;
    cout<<"Average Turnaround Time: "<<avg_turnaround<<endl;

    return 0;
}
