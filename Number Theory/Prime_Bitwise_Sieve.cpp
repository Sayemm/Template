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

bool check(int n, int pos) { return (bool) (n & (1<<pos)); }
int Set(int n, int pos) { return n = n | (1<<pos); }

int prime[sz/32]; //generate prime till sz

void sieve(int n)
{
    int limit = sqrt(n)+1;

    for(int i = 3; i <= limit; i+=2)
    {
        if(check(prime[i/32], i%32)==0)
        {
            for(int j = 3; i*j <= n; j+=2)
            {
                prime[(i*j)/32] = Set(prime[(i*j)/32], (i*j)%32);
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

    cout << 2 << " ";

    for(int i = 3; i <= n; i+=2)
    {
        if(check(prime[i/32], i%32)==0)
        {
            cout << i << " ";
        }
    }


    return 0;
}