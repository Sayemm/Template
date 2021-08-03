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

int bigmod(ll a, ll p, ll m )
{
    if (p==0) return 1; // If power is 0 ( a ^ 0 ), return 1

    if (p&1ll) // If power is odd
    {
        return ( (a%m) * bigmod(a, p - 1, m)) % m;
    }
    else
    {
        ll tmp = bigmod(a, p/2, m);

        return (tmp*tmp) % m;
    }
}

int main()
{
    READ
    optimize

    ll a, p;

    cin >> a >> p;

    cout << bigmod(a, p, MOD) << endl;


    return 0;
}

// also possible using binary exponential
//     2^100
// 2^50     2^50
//      2^25    2^25
//             2    2^24      