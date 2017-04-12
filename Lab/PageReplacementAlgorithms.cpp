#include <bits/stdc++.h>

using namespace std;

int sequence_no, frame_no;
string sequence[20], frame[10];
int r[20];

void input()
{
    cout << "Enter sequence no and frame no: " << endl;
    cin >> sequence_no >> frame_no;
    cout << "Enter sequences :" << endl;

    for(int i = 0; i < sequence_no ; i++)
    {
        cin >> sequence[i];

    }
}

void frame_init(string value)
{
    for(int i = 0; i < frame_no ; i++)
        frame[i] = value;
}

void frame_print()
{
    for(int i = 0; i <= frame_no ; i++)
    {
        cout << "--";

    }
    cout << endl;
    for(int i = 0; i < frame_no ; i++)
    {
        cout << "| " << frame[i];

    }
    cout << "|" << endl;
    for(int i = 0; i <= frame_no ; i++)
    {

        cout << "--";
    }
    cout << endl;
}

int find_page_in_frame(string st)
{
    for(int i = 0; i < frame_no ; i++)
    {
        if(st == frame[i])
            return i;//found page in frame at i location
    }
    return -1;//page fault
}

void optimal()
{
    int optimal_page_fault = 0;
    int p, label[frame_no + 3];
    cout << "Optimal Page Replacement Algorithm " << endl;

    frame_init("B");
    for(int i = 0; i < frame_no ; i++)
        frame[i] = sequence[i];
    frame_print();
    for(int i = 0+frame_no; i < sequence_no ; i++)
    {
        p = find_page_in_frame(sequence[i]);
        if(p == -1)
        {
            optimal_page_fault++;
            int max_label = -1034323, max_label_index;
            for(int j = 0; j < frame_no ; j++)
            {
                cout << "Page " << frame[j] << "   Label :";
                cin >> label[j];
                if(max_label < label[j]){
                    max_label_index = j;
                    max_label = label[j];
                }

            }
            frame[max_label_index] = sequence[i];
            frame_print();
        }
    }

    cout << "Page fault for OPTIMAL is : " << optimal_page_fault;

}

void frame_left_shift()
{
    for(int i = 1; i < frame_no ; i++)
        frame[i-1] = frame[i];
}

void frame_left_shiftSC()
{
    string tmp = frame[0];
    int rt = 1-r[0];
    int i;
    for( i = 1; i < frame_no ; i++)
    {
        frame[i-1] = frame[i];
        r[i - 1] = r[i];
    }
    frame[i-1] = tmp;
    r[i-1] = rt;

}

void fifo()
{
    int fifo_page_fault = 0;
    int p, label[frame_no + 3];
    cout << "FIFO Page Replacement Algorithm " << endl;

    frame_init("B");
    for(int i = 0; i < frame_no ; i++)
        frame[i] = sequence[i];
    frame_print();
    for(int i = 0+frame_no; i < sequence_no ; i++)
    {
        p = find_page_in_frame(sequence[i]);
        if(p == -1)
        {
            fifo_page_fault++;
            frame_left_shift();
            frame[frame_no-1] = sequence[i];
            frame_print();
        }

    }

    cout << "PAGE fault for OPTIMAL is : " << fifo_page_fault ;

}

void not_recently_used()
{
    int nru_page_fault = 0;
    int p, label[frame_no + 3];
    cout << "Not Recently Used Page Replacement Algorithm " << endl;

    frame_init("B");
    for(int i = 0; i < frame_no ; i++)
        frame[i] = sequence[i];
    frame_print();
    for(int i = 0+frame_no; i < sequence_no ; i++)
    {
        p = find_page_in_frame(sequence[i]);
        if(p == -1)
        {
            nru_page_fault++;
            int min_label = 1034323, min_label_index;
            int r[frame_no], m[frame_no];
            for(int j = 0; j < frame_no ; j++)
            {
                cout << "Page " << frame[j] << "   Refference :";
                cin >> r[j] ;
                cout << "Modify :" ;
                cin >> m[j];
                label[j] = r[j] * 4 + m[j] * 2;
                if(min_label > label[j]){
                    min_label_index = j;
                    min_label = label[j];
                }

            }
            frame[min_label_index] = sequence[i];
            frame_print();
        }
    }

    cout << "Page fault FOR NRU is : " << nru_page_fault;

}

void second_chance()
{
    int sc_page_fault = 0;
    int p, label[frame_no + 3];
    cout << "Second Chance Page Replacement Algorithm " << endl;

    frame_init("B");
    for(int i = 0; i < frame_no ; i++)
        frame[i] = sequence[i];
    frame_print();
    for(int i = 0+frame_no; i < sequence_no ; i++)
    {
        p = find_page_in_frame(sequence[i]);
        if(p == -1)
        {
            sc_page_fault++;

            for(int j = 0; j < frame_no ; j++)
            {
                cout <<"Frame :"<< frame[j] << "Refference :";
                cin >> r[j];
            }
            while(1)
            {
                if(r[0] == 0)
                {
                    frame[0] = sequence[i];
                    break;
                }else
                {
                    frame_left_shiftSC();
                }
            }


            frame_print();
        }
    }

    cout << "Page fault FOR SC is : " << sc_page_fault;

}

void clock_r()
{
    int clock_page_fault = 0;
    int p, label[frame_no + 3];
    cout << "Clock Page Replacement Algorithm " << endl;

    frame_init("B");
    for(int i = 0; i < frame_no ; i++)
        frame[i] = sequence[i];
    frame_print();
    int circle = 0;
    for(int i = 0+frame_no; i < sequence_no ; i++)
    {
        p = find_page_in_frame(sequence[i]);
        if(p == -1)
        {
            clock_page_fault++;
            for(int j = 0; j < frame_no; j++)
            {
                cout <<"Page : " << frame[j] << ", Refference : ";
                cin >> r[j];
            }
            while(r[circle] != 0)
            {
                if(r[circle] == 1)
                {
                    r[circle] = 0;
                    circle++;
                }
                if(circle == frame_no - 1)
                    circle = 0;
            }
            frame[circle] = sequence[i];
            frame_print();
        }

    }

    cout << "Page fault FOR Clock is : " << clock_page_fault;

}


int main()
{

    input();
    optimal();
    cout << endl;
    //system("cls");
    not_recently_used();
    cout << endl;
    //system("cls");
    fifo();
    cout << endl;
    //system("cls");
    second_chance();
    //system("cls");
    cout << endl;
    clock_r();
    //system("cls");
    cout << "Thank you" << endl;

}
