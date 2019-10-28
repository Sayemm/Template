#include <bits/stdc++.h>

#define         mx          100005

using namespace std;

int parent[mx], nrank[mx];

void make_set(int n)
{
    for(int i = 0; i <= n; i++)
    {
        parent[i] = i;
        nrank[i] = 0;
    }
}

int find(int x)
{
    if(x != parent[x]) return parent[x] = find(parent[x]); // path compression
    else return x;

    //using path compression complexity of m times find function is O(mlogn)
}

void union_set(int x, int y)
{
    int px = find(x);
    int py = find(y);

    if(px==py) return; //cycle

    if(nrank[px]<nrank[py]) parent[px] = py;
    else if(nrank[py]<nrank[px]) parent[py] = px;
    else
    {
        parent[py] = px;
        nrank[px]++;
    }
}

int main()
{



    return 0;
}
