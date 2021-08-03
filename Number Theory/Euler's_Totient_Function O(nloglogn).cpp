#include <bits/stdc++.h>

#define       pb                 push_back
#define       sf                 scanf
#define       pf                 printf
#define       sz                 100005
#define       MOD                1000000007
#define       optimize           ios::sync_with_stdio(0);cin.tie(0);
#define       inf                0x3f3f3f3f
#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);

using namespace std;

typedef       long long int      ll;
typedef       pair <int, int>    pii;

int phi[sz];

void phi_1_to_n(int n)
{
	phi[0] = 0;
	phi[1] = 1;

	for(int i = 2; i <= n; i++) phi[i] = i;

	for(int i = 2; i <= n; i++)
	{
		if(phi[i]==i)
		{
			for(int j = i; j <= n; j+=i)
			{
				phi[j] -= phi[j] / i; // prime dea divide hocce
			}
		}
	}
}

int main()
{
    // READ
    optimize

    int n; cin >> n;

    phi_1_to_n(n);

   	for(int i = 1; i <= n; i++) cout << phi[i] << " ";
   		
    return 0;
}

// complexity O(nloglogn)