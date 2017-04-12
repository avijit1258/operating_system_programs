#include <bits/stdc++.h>

using namespace std;

typedef pair<char, char> ii;
typedef vector<ii> vii;

map<char, vii > AdjList;
map<char, bool > dfs_num;

vector<char> LIST;

bool is_cycle;
char start_node;

void read_graph()
{
    int edges;
    cout << "Enter number of edges " << endl;
    cin >> edges;

    char x, y;
    for(int i = 0; i < edges ; i++)
    {
        cin >> x >> y;
        AdjList[x].push_back(ii(y, 1));

    }
}

void dfs(char src)
{
    dfs_num[src] = true;
    if((int)AdjList[src].size() > 0)
        LIST.push_back(src);
    for(int j = 0 ; j < (int)AdjList[src].size() ; j++)
    {
        ii v = AdjList[src][j];

        if( v.first == start_node )
            is_cycle = true;
        if(dfs_num[v.first] == false)
            dfs(v.first);

    }
}

void deadlock()
{
    for(auto const &ent1 : AdjList) {
        is_cycle = false;
        LIST.clear();
        dfs_num.clear();
        //cout << ent1.first << endl;
        start_node = ent1.first;
        dfs(ent1.first);

        if(is_cycle)
        {
            cout << "Cycle is found for : " << ent1.first << endl;
            for(auto i : LIST)
            {
                cout << i << " ";
            }
            cout << "are in deadlock" <<endl;

        }



    }

}

int main()
{
    read_graph();
    deadlock();

    return 0;
}
