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

vector <int> d[sz];

void divisor(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j+=i)
        {
            d[j].pb(i);
        }
    }
}

int main()
{
    // READ

    int n;

    cin >> n;

    divisor(n);

    for(auto x:  d[10]) cout << x << " ";

    return 0;
}

// complexity O(nlogn)
// n + n/2 + n/3 + ....
// n (1 + 1/2 + 1/3 + ....)
// n logn
