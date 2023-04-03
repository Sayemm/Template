// Time Complexity O(N) + O(2E)

#include <bits/stdc++.h>

#define sz         100005

using namespace std;

bool vis[sz];
vector <int> v[sz];

void bfs(int nd) {
	queue <int> q;

	q.push(nd);
	vis[nd] = true;

	while(!q.empty()) {
		int n1 = q.front();
		q.pop();

		for(auto n2: v[n1]) {
			if(vis[n2] == false) {
				vis[n2] = true;
				q.push(n2);
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	bfs(0);

	return 0;
}
