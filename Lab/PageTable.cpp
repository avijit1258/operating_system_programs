#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main()
{
    int process_size = 0, page_size = 0, main_memory_size = 0,  no_page, no_frame ;
    cout << "Process size , Page size  , Main Memory Size" << endl;
    cin >> process_size;
    cin >> page_size;
    cin >> main_memory_size;
    no_frame = main_memory_size/page_size;
    no_page = process_size/page_size;
   // map<int, int> page_table;
   int page_table[100];
    int a, b;//variable for taking page table's input page and frame
    cout << "Enter page table entries ( page no || frame no )" << endl;

    for(int i = 0; i < no_frame ; i++)
    {
        cin >> a >> b ;
        page_table[a] = b;
    }
    int logical_address, physical_address;
    cout << "Enter logical address" << endl;
    cin >> logical_address;
    cout << page_table[logical_address / page_size ] << endl;
    physical_address = page_table[logical_address / page_size ] * page_size + (logical_address % page_size);
    //cout << logical_address % page_size << endl;
    cout << "Physical address" << physical_address << endl;

    printf("\nPages\n");
    printf(" __________\n");

    for (int i=no_page; i>=0; i--)
    {
        if (i != (logical_address / page_size))
        {
                printf("%d|          | \n",i);
                printf(" _____________\n");
        }
        else
        {
                printf("%d|**-**-**-**| \n",i);
                printf(" ______________\n");
        }

    }


    printf("\nFrames\n");

     printf(" __________\n");

    for (int i= no_frame; i>=0; i--)
    {
        if (i != page_table[logical_address / page_size ])
        {
                printf("%d|          | \n",i);
                printf(" __________\n");
        }
        else
        {
                printf("%d|**-**-**| \n",i);
                printf(" ___________\n");
        }

    }

    return 0;
}
