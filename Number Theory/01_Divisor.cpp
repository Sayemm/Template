#include <bits/stdc++.h>

#define       optimize           ios::sync_with_stdio(0);cin.tie(0);
#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);

using namespace std;

typedef       long long int      ll;

const int SZ = 100005, MOD = 1e9 + 7;

int main()
{
	int n; cin >> n;

	for(int i = 1; i <= n; i++) {
		if(n % i == 0) {
			cout << i << endl;
		}
	}
	
	return 0;
}

// Complexity: O(n)