// Works for a lot of component
// Complexity O(ElogE)

#include <bits/stdc++.h>

#define      mx           300009
#define      READ         freopen("in.txt", "r", stdin);

using namespace std;

struct nd
{
    int u, v, w;
} node[mx];

bool compare(nd a, nd b)
{
    return a.w < b.w;
}

int parent[mx];
int nrank[mx];

void make_set(int n)
{
	for(int i = 0; i < n; i++)
	{
		parent[i] = i;
		nrank[i] = 0;
	}
}

int find(int x)
{
	if(x!=parent[x]) return parent[x] = find(parent[x]);
	else return x;
}

void union_set(int x, int y)
{
	int px = find(x);
	int py = find(y);

	if(px==py) return;

	if(nrank[px] < nrank[py]) parent[px] = py;
	else if(nrank[px] > nrank[py]) parent[py] = px;
	else
	{
		parent[py] = px;
		nrank[px]++;
	}
}


int main()
{
    int n, m, ans = 0;

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> node[i].u >> node[i].v >> node[i].w;
    }

    sort(node, node+m, compare);

    make_set(n);

    for(int i = 0; i < m; i++)
    {
        if(find(node[i].u) != find(node[i].v))
        {
            union_set(node[i].u, node[i].v);

            ans += node[i].w;
        }
    }

    cout << ans << endl;

    return 0;
}
