#include <bits/stdc++.h>

#define        sf            scanf
#define        pf            printf
#define        MOD           1000000007

using namespace std;

typedef        long long int    ll;

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }

ll n, m, res[4][4], a[4][4], t[4][4];

ll func(ll n)
{
    if(n==1) return (m%MOD);
    else if(n==2) return modMul(m, m);
    else if(n==3) return modSub(modPow(m,3), m);

    ll p = n-3;

    ll f3 = modSub(modPow(m,3), m);
    ll f2 = modMul(m, m);
    ll f1 = m%MOD;

    /// Identity Matrix
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            if(i==j) res[i][j] = 1;
            else res[i][j] = 0;
        }
    }

    /// Initializing Matrix M
    a[1][1] = m%MOD; a[1][2] = 0; a[1][3] = modSub(1,m);
    a[2][1] = 1; a[2][2] = 0; a[2][3] = 0;
    a[3][1] = 0; a[3][2] = 1; a[3][3] = 0;

    /// Binary Exponential Part
    while(p>0)
    {
        if(p&1ll)
        {
            for(int i = 1; i <= 3; i++)
            {
                for(int j = 1; j <= 3; j++)
                {
                    t[i][j] = 0;

                    for(int k = 1; k <= 3; k++)
                    {
                        t[i][j] = modAdd(t[i][j], modMul(res[i][k],a[k][j]));
                    }
                }
            }

            for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++) res[i][j] = t[i][j];
        }

        for(int i = 1; i <= 3; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                t[i][j] = 0;

                for(int k = 1; k <= 3; k++)
                {
                    t[i][j] = modAdd(t[i][j], modMul(a[i][k],a[k][j]));
                }
            }
        }

        for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++) a[i][j] = t[i][j];

        p >>=1ll;
    }

    ll ans = modAdd(modAdd(modMul(res[1][1],f3), modMul(res[1][2], f2)), modMul(res[1][3], f1));

    return ans;
}

int main()
{
    int tc;

    sf("%d", &tc);

    while(tc--)
    {
        sf("%lld %lld", &n, &m);

        ll ans = func(n);

        cout << ans << endl;
    }

    return 0;
}

