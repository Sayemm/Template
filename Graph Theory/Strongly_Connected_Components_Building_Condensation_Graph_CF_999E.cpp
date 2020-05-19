//Top sort then finding componenets in reverse graph.
//Kosaraju's Algorithm

#include <bits/stdc++.h>

#define       sf                 scanf
#define       pf                 printf
#define       pb                 push_back
#define       sz                 5003
#define       MOD                1000000007
#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);
#define 	  optimize           ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef       long long int      ll;

int dx[] = {0, 0, +1, -1};
int dy[] = {+1,-1, 0,  0};

vector <int> v[sz], vr[sz];
stack <int> s;
map <int, int> mp;

bool vis[sz];
int cnt[sz], n1[sz], n2[sz];

void dfs1(int n)
{
	vis[n] = true;

	for(int i = 0; i < v[n].size(); i++)
	{
		int x = v[n][i];

		if(vis[x]==false)
			dfs1(x);
	}

	s.push(n);
}

void dfs2(int n, int cn)
{
	vis[n] = true;
	cnt[n] = cn;

	for(int i = 0; i < vr[n].size(); i++)
	{
		int x = vr[n][i];

		if(vis[x]==false)
			dfs2(x, cn);
	}
}

int main()
{
	// READ
	optimize

	int n, m, st, ans = 0, cn = 1;

	cin >> n >> m >> st;

	for(int i = 0; i < m; i++)
	{
		cin >> n1[i] >> n2[i];

		v[n1[i]].pb(n2[i]);
		vr[n2[i]].pb(n1[i]);
	}

	for(int i = 1; i <= n; i++)
	{
		if(vis[i]==false) dfs1(i);
	}

	memset(vis, false, sizeof(vis));

	while(!s.empty())
	{
		int x = s.top();
		s.pop();

		if(vis[x]==false)
		{
			dfs2(x, cn);
			cn++;
		}
	}

	// cout << cn << endl;

	for(int i = 0; i < m; i++)
	{
		if(cnt[n1[i]]!=cnt[n2[i]])
		{
			mp[cnt[n2[i]]]++;
		}
	}

	for(int i = 1; i < cn; i++)
	{
		if(mp[i]==0 and i!=cnt[st])  ans++;
	}

	cout << ans << endl;

    return 0;
}


// SOURCES

// https://cp-algorithms.com/graph/strongly-connected-components.html
