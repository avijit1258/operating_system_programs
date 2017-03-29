#include<iostream>

using namespace std;

int main()
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    int process[20];
    int arrival_time[20];
    int short_var;
    cout<<" Total number of processes:";
    cin>>n;

    cout<<"\nProcess Burst Time And Arrival Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];

        cin>>arrival_time[i];
        process[i] = i + 1;
    }

    //sorting with arrival time
    for(int i = 0; i < n ; i++)
    {
        short_var = i;
        for(int j = i+1; j < n ; j++)
        {
            if(arrival_time[j] < arrival_time[short_var])
                short_var = j;
        }

        swap(bt[i], bt[short_var]);
        swap(process[i], process[short_var]);

    }


    wt[0]=0;    //waiting time for first process is 0

    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=arrival_time[i];
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }

    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\tArrival Time";

    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]-arrival_time[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"\nP["<<process[i]<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<< arrival_time[i];
    }

    avwt/=i;
    avtat/=i;
    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat;
    cout << "\nAverage Throughput Time" << n/i;

    return 0;
}
