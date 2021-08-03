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

int phi(int n)
{
    int result = n;

    for(int i = 2; i*i<=n; i++)
    {
    	if(n%i==0)
    	{
    		while(n%i==0) n/=i;
    		result -= result/i;
    	}
    }

    if(n!=1) result -= result/n;

    return result;
}

int main()
{
    // READ
    optimize

    int n;

    cin >> n;

    cout << phi(n) << endl;


    return 0;
}