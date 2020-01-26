#include <bits/stdc++.h>

#define            sf             scanf
#define            pf             printf

using namespace std;

typedef            long long int          ll;

ll func(ll n)
{
    if(n==0ll) return 0ll;
    else if(n==1ll) return 1ll;

    ll p = n-1;

    ll res[5][5], a[5][5];

    res[1][1] = res[2][2] = a[1][1] = a[1][2] = a[2][1] = 1;
    res[1][2] = res[2][1] = a[2][2] = 0;


    while(p>0) /// Binary Exponential Part
    {
        ll t[5][5];

        if(p&1ll)
        {
            t[1][1] = res[1][1]*a[1][1] + res[1][2]*a[2][1];
            t[1][2] = res[1][1]*a[1][2] + res[1][2]*a[2][2];
            t[2][1] = res[2][1]*a[1][1] + res[2][2]*a[2][1];
            t[2][2] = res[2][1]*a[1][2] + res[2][2]*a[2][2];

            res[1][1] = t[1][1]; res[1][2] = t[1][2]; res[2][1] = t[2][1]; res[2][2] = t[2][2];
        }

        t[1][1] = a[1][1]*a[1][1] + a[1][2]*a[2][1];
        t[1][2] = a[1][1]*a[1][2] + a[1][2]*a[2][2];
        t[2][1] = a[2][1]*a[1][1] + a[2][2]*a[2][1];
        t[2][2] = a[2][1]*a[1][2] + a[2][2]*a[2][2];

        a[1][1] = t[1][1]; a[1][2] = t[1][2]; a[2][1] = t[2][1]; a[2][2] = t[2][2];

        p >>= 1ll;
    }

    return res[1][1];
}

int main()
{
    ll n;

    while(sf("%lld", &n)!=EOF) cout << func(n) << endl; /// O(log(n))

    return 0;
}

///f(0) = 0 and f(1) = 1
