// Works for starting node containing component
// Complexity O(ElogE)

#include <bits/stdc++.h>

#define        mx              100005
#define        inf             0x3f3f3f3f

using namespace std;

typedef pair<int, int>      pii;

vector <pii> adj[mx];
priority_queue< pii, vector<pii>, greater<pii> > q;

int cost[mx];
bool vis[mx];
int n, m;

int prim(int source)
{
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		cost[i] = inf;
		vis[i] = false;
	}

	cost[source] = 0;

	q.push(pii(0, source));

	while(!q.empty())
    	{
        	int u = q.top().second;//node
		int c = q.top().first; //cost

		q.pop();

		if(vis[u]) continue;

		vis[u] = true;

		ans += c;

		for(int i = 0; i < adj[u].size(); i++)
		{
			 int v = adj[u][i].first; // node
			 int w = adj[u][i].second; // edge weight

			 if(vis[v]) continue;

			 if(cost[v]>w)
			 {
				cost[v] = w;

				q.push(pii(w, v));
			 }
		}
    	}

    return ans;
}

int main()
{
	int a, b, w;

	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> w;

		adj[a].push_back(pii(b, w));
		adj[b].push_back(pii(a, w));
	}

	cout << prim(0) << endl;


	return 0;
}
