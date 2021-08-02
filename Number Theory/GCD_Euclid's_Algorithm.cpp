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

int gcd1(int a, int b)
{
	if(b==0) return a;
	else return gcd1(b, a%b);
}

int gcd2(int a, int b)
{
	while(b)
	{
		a = a%b;

		swap(a, b);
	}

	return a;
}

int main()
{
    // READ
    optimize

    int a, b;

    cin >> a >> b; if(b>a) swap(a, b);

    cout << gcd1(a, b) << endl;
    cout << gcd2(a, b) << endl;


    return 0;
}

// gcd(a, b) = gcd(a-b, b) [a>b]