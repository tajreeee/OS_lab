#include <iostream>
using namespace std;
#define MAX 1000

int main() 
{
    int n;
    int arrival[MAX],burst[MAX],start[MAX],waiting[MAX],turnaround[MAX];
    int total_waiting=0,total_turnaround=0;

    cout<<"Enter the number of processes: ";
    cin>>n;

    cout<<"Enter the Arrival Time of each process:"<<endl;
    for (int i=0;i<n;i++) 
    {
        cout<<"Process "<<i+1<<" Arrival Time: ";
        cin>>arrival[i];
    }

    cout<<"Enter the Burst Time of each process:"<<endl;
    for (int i=0;i<n;i++) 
    {
        cout<<"Process "<<i+1<<" Burst Time: ";
        cin>>burst[i];
    }

    start[0]=arrival[0];
    waiting[0]=0;
    turnaround[0]=burst[0];
    total_turnaround+=turnaround[0];

    for (int i=1;i<n;i++) 
    {
        int finish=start[i-1]+burst[i-1];
        start[i]=max(finish,arrival[i]);
        waiting[i]=start[i]-arrival[i];
        turnaround[i]=waiting[i]+burst[i];
        total_waiting+=waiting[i];
        total_turnaround+=turnaround[i];
    }

    cout<<endl<<"Process\tBT\tAT\tST\tWT\tTAT"<<endl;
    for (int i = 0; i < n; i++) 
    {
        cout<<"P"<<i+1<<"\t"
             <<burst[i]<<"\t"
             << arrival[i]<<"\t"
             << start[i]<<"\t"
             << waiting[i]<<"\t"
             << turnaround[i]<<endl;
    }

    float avg_waiting=(float)total_waiting/n;
    float avg_turnaround=(float)total_turnaround/n;

    cout<<endl<<"Average Waiting Time: "<<avg_waiting<<endl;
    cout<<"Average Turnaround Time: "<<avg_turnaround<<endl;

    return 0;
}
