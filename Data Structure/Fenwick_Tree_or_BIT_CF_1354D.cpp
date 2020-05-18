#include <bits/stdc++.h>

#define       sf                 scanf
#define       pf                 printf
#define       pb                 push_back
#define       sz                 1000006
#define       MOD                1000000007
#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);
#define 	  optimize           ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef       long long int      ll;

int dx[] = {0, 0, +1, -1};
int dy[] = {+1,-1, 0,  0};

int tree[sz];

void update(int in, int x, int n) // O(logn)
{
	while(in<=n)
	{
		tree[in] += x;
		in += (in & -in);
	}
}

int sum(int in) //O(logn)
{
	int sum = 0;

	while(in>0)
	{
		sum += tree[in];
		in -= (in & -in);
	}

	return sum;
}

int main()
{
	// optimize
	
	// READ

	int n, q, num, ans = 0;

	sf("%d %d", &n, &q);

	for(int i = 0; i < n; i++)
	{
		sf("%d", &num);

		update(num, 1, n);
	}

	for(int i = 0; i < q; i++)
	{
		sf("%d", &num);

		if(num>0) update(num, 1, n);
		else
		{
			num *= -1;

			int left = 1, right = n, in = 0;

			while(left<=right) //finding how many elements >= num
			{
				int mid = left + (right-left)/2;

				if(sum(mid)>=num)
				{
					in = mid;

					right = mid-1;
				}
				else left = mid+1;
			}

			update(in, -1, n);
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(tree[i]>0)
		{
			ans = i;
			break;
		}
	}

	cout << ans << endl;

    return 0;
}

// SOURCES

// https://cp-algorithms.com/data_structures/fenwick.html
// https://www.youtube.com/watch?v=aAALKHLeexw
// http://www.shafaetsplanet.com/?p=1961


