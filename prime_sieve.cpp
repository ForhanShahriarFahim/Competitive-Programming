#include <bits/stdc++.h>
using namespace std;

//**************************************************************************************************************************************************************************
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//**************************************************************************************************************************************************************************
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-9
#define inf 1e18
#define sz(x) (int)((x).size())
#define gcd(a, b) __gcd(a, b)
#define LCM(x, y) (((x) / __gcd((x), (y))) * (y))
#define mem(x, n) memset(x, n, sizeof(x))
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x, y) fixed << setprecision(y) << x
#define FastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
//**************************************************************************************************************************************************************************

void c_p_c()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int p[1000005]={0};

// Sieve Approach - Generate a array containing prime Numbers
void prime_sieve(int *p)
{
    //first mark all odd number's prime
    for (int i = 3; i <= 1000000; i+=2)
    {
        p[i] = 1;
    }
    for (ll i = 3; i <= 1000000; i += 2)
    {
        //if the current number is not marked(it is priem)
        if (p[i] == 1)
        {
            //mark all the multiples of i as not prime
            for (ll j = i * i; j <= 1000000; j += i)
            {
                p[j] = 0;
            }
        }
        //special case
        p[2] = 1;
        p[1] = p[0] = 0;
    }
}

int main(int argc, char const *argv[])
{
    c_p_c();
    FastIO;
    int n;
    cin >> n;
    ll sum = 0, number,mx=0,cnt;
    prime_sieve(p);
    //lets print primes upto range
/*     for (int i = 0; i <= n; i++)
    {
        if (p[i] == 1)
        {
            cout << i << " ";
            if(n%i==0)
            {
                cout<<"i : "<<i<<" ";
            }
        }
    } */
    for (int i = n; i >990000; i--)
    {
        cnt = 0;
        sum = 0;
        for(int j=0;j<i;j++)
        {
            if (p[j] == 1)
            {
                if(i%j==0)
                {
                    sum+=j;
                    //cout<<"J: "<<j<<" i: "<<i<<" ";
                    cnt++;
                }
            }
        }
        if(sum>mx)
        {
           // cout<<"cnt: "<<cnt<<endl;
            mx = sum;
            number = i;
        }
        
    }
    cout<<number<<endl;
}