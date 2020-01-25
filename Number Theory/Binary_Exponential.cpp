#include <bits/stdc++.h>

using namespace std;

typedef         long long int          ll;

ll b, p, MOD;

inline void normal(ll &a) { a%=MOD; (a<0) && (a+=MOD); }
inline ll modMul(ll a, ll b) { a%=MOD, b%=MOD; normal(a), normal(b); return(a*b)%MOD; }

ll binary_expo(ll a, ll p) // O(logp)
{
    ll res = 1;

    while(p>0)
    {
        if(p&1ll) res = modMul(res, a);

        a = modMul(a, a);

        p >>= 1ll;
    }

    return res;
}

int main()
{
    while(cin >> b >> p >> MOD) cout << binary_expo(b, p) << endl;

    return 0;
}

