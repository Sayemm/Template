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

int prime[sz];

void sieve(int n)
{
    int limit = sqrt(n)+1;

    prime[0] = 1;
    prime[1] = 1;

    for(int i = 4; i <= n; i+=2)  prime[i] = 1;

    for(int i = 3; i <= limit; i+=2)
    {
        if(prime[i] == 0)
        {
            for(int j = 3; i*j <= n; j+=2)
            {
                prime[i*j] = 1;
            }
        }
    }
}

int main()
{
    READ
    // WRITE
    optimize

    int n;

    cin >> n;

    sieve(n);

    for(int i = 3; i <= n; i+=2)
    {
        if(prime[i]==0)
        {
           cout << i << " ";
        }
    }


    return 0;
}