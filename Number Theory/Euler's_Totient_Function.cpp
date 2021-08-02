#include <bits/stdc++.h>

using namespace std;

typedef            long long int          ll;

ll func(ll n)
{
    ll limit = sqrt(n+1), ans = 1;

    for(int i = 2; i <= limit; i++)
    {
        if((n%i)==0)
        {
            ans *= (i-1);
            while((n%i)==0)
            {
                ans *= i;
                n /= i;
            }
            ans /= i;
        }
    }

    if(n!=1) ans *= (n-1ll);

    return ans;
}

int main()
{
    ll n;

    cin >> n;

    cout << func(n) << endl;

    return 0;
}

// calculates phi(n) Mul P^(pow-1) * P
