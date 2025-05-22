#include<iostream>
#include<queue>
using namespace std;
#define MAX 1000

int main() 
{
    int n,quantum;
    int arrival[MAX],burst[MAX],remain[MAX],start[MAX],waiting[MAX],turnaround[MAX];
    bool visited[MAX]={false},started[MAX]={false};
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

    cout<<"Enter Time Quantum: ";
    cin>>quantum;

    queue<int>q;
    int time=0,done=0;

    while(done<n) 
    {
        for(int i=0;i<n;i++) 
        {
            if(arrival[i]<=time && !visited[i]) 
            {
                q.push(i);
                visited[i]=true;
            }
        }

        if(q.empty()) 
        {
            time++;
            continue;
        }

        int i=q.front();
        q.pop();

        if(!started[i]) 
        {
            start[i]=time;
            started[i]=true;
        }

        int run_time=min(quantum,remain[i]);
        remain[i]-=run_time;
        time+=run_time;

        for(int j=0;j<n;j++) 
        {
            if(arrival[j]<=time && !visited[j]) 
            {
                q.push(j);
                visited[j]=true;
            }
        }

        if(remain[i]>0) 
        {
            q.push(i);
        } 
        else 
        {
            int finish=time;
            turnaround[i]=finish-arrival[i];
            waiting[i]=turnaround[i]-burst[i];
            total_waiting+=waiting[i];
            total_turnaround+=turnaround[i];
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
             <<waiting[i]<<"\t"
             <<turnaround[i]<< endl;
    }

    float avg_waiting=(float)total_waiting/n;
    float avg_turnaround=(float)total_turnaround/n;

    cout<<endl<<"Average Waiting Time: "<<avg_waiting<<endl;
    cout<<"Average Turnaround Time: "<<avg_turnaround<<endl;

    return 0;
}
