#include <bits/stdc++.h>

#define        mx            1005
#define        inf           0x3f3f3f3f
#define        read          freopen("in.txt", "r", stdin);

using namespace std;

int w[mx][mx];
int u, v, node, edge;

void floyd()
{
	for(int k = 1; k <= node; k++)
	{
		for(int i = 1; i <= node; i++)
		{
			for(int j = 1; j <= node; j++)
			{
				w[i][j] = min(w[i][j], w[i][k]+w[k][j]);

				//w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
			}
		}
	}
}

int main()
{
	memset(w, inf, sizeof(w));

	cin >> node >> edge;

	for(int i = 0; i < edge; i++)
	{
		cin >> u >> v >> w[u][v];

		w[v][u] = w[u][v];
		w[u][u] = 0;
		w[v][v] = 0;
	}

	floyd();

	for(int i = 1; i <= node; i++)
	{
		for(int j = 1; j <= node; j++)
		{
			cout << w[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
