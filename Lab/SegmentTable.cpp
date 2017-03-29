#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    string segment[10];
    string st;
    int temp;
    int limit[10], base[10];
    cout << "Enter segment no. " << endl;
    cin >> n ;
    cout << "Segment Name---Base----Limit" << endl;
    for(int i = 0; i < n; i++)
    {

        cin >> segment[i] >> base[i] >> limit[i];
    }

    cout << "Segment Name---Base----Limit" << endl;
    for(int i = 0; i < n; i++)
    {

        cout << "         "<< segment[i] << "        "<< base[i] <<"        " << limit[i]<< endl;
    }
    cout << "Enter no. of queries " << endl;
    cin >> m;
    cout << "segment Name-----Offset/Logical Address" << endl;
    for(int i = 0; i < m ; i++)
    {
        cin >> st >> temp;
        int forSumIndex;
        for(int j = 0; j < n; j++)
        {
            if(segment[j] == st)
            {
                forSumIndex = j;
                break;
            }

        }
        cout << "Physical Address for " << st << "Segment is : " <<temp+base[forSumIndex];
    }

    return 0;
}
