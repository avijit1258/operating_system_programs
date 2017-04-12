#include <bits/stdc++.h>

using namespace std;

int no_of_resources, no_of_processes;
int E[20+1], A[20+1];
int C[10][20], R[10][20];
int mark[10];

int counter;

bool resource_available(int process){

    bool avail = true;

    for(int i = 0; i < no_of_resources ; i++)
    {
        if(A[i] < R[process][i])
            avail = false;
    }
    return avail;

}

bool any_process_unmarked()
{

    bool unmarked = false;
    for(int i = 0; i < no_of_processes ; i++)
    {
        counter++;
        if(!mark[i])
        {
            unmarked = true;
            return unmarked;
        }

    }
    return unmarked;
}

void available_print()
{
    for(int i = 0; i <= no_of_resources ; i++)
    {
        cout << "--";

    }
    cout << endl;
    for(int i = 0; i < no_of_resources ; i++)
    {
        cout << "| " << A[i];

    }
    cout << "|" << endl;
    for(int i = 0; i <= no_of_resources ; i++)
    {

        cout << "--";
    }
    cout << endl;

}

void increment_available(int p)
{
    for(int i = 0; i < no_of_resources ; i++)
        A[i] = A[i] + C[p][i];

    available_print();
}

void multiple_instance_output()
{
    cout << "Available Resources :\n";
    available_print();


    for(int i = 0 ; i < no_of_processes ; i++)
    {
        if(!mark[i])
            cout << "process : " << i << " is in deadlock"  << endl;
    }

    if(any_process_unmarked())
        cout << "Deadlock detected" << endl;
    else
        cout << "No DeadLock detected" << endl;

}

void multiple_instance()
{

    counter = 0;
    cout << "Enter number of resources and processes : \n" ;
    cin >> no_of_resources >> no_of_processes;

    //initialize unmarked
    for(int i = 0; i < no_of_processes ; i++)
        mark[i] = 0;

    cout << "Existing resource array :\n";
    for(int i = 0; i < no_of_resources ; i++)
        cin >> E[i];

    cout << "Available resource array :\n";
    for(int i = 0; i < no_of_resources ; i++)
        cin >> A[i];


    cout << "Currently allocated array :\n";
    for(int i = 0; i < no_of_processes ; i++)
        for(int j = 0; j < no_of_resources ; j++)
            cin >> C[i][j];
    cout << "Request array : \n";
    for(int i = 0; i < no_of_processes ; i++)
        for(int j = 0; j < no_of_resources ; j++)
            cin >> R[i][j];
    while( any_process_unmarked() && (counter <  no_of_processes*2) )
    {

        for(int i = 0; i < no_of_processes ; i++)
        {
            if(!mark[i])
            {
                if(resource_available(i))
                {
                    increment_available(i);
                    mark[i] = 1;
                }
            }
        }

    }

    multiple_instance_output();
}

int main()
{
    multiple_instance();

    return 0;
}
