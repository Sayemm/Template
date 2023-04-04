// Time Complexity O(N) + O(2E)

#include <bits/stdc++.h>

#define READ freopen("in.txt", "r", stdin);
#define WRITE freopen("out.txt", "w", stdout);
#define sz         100006

using namespace std;

bool vis[sz];
vector <int> v[sz];

void dfs(int n1) {
	vis[n1] = true;
	for(auto n2: v[n1]) {
		if(!vis[n2]) {
			dfs(n2);
		}
	}
}

int main()
{
	// READ
	// WRITE 
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
	  int n1, n2;
		cin >> n1 >> n2;

		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	dfs(0);

	return 0;
}