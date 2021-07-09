#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
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
#define All(x) (x).begin(), (x).end()
//**************************************************************************************************************************************************************************
char gap = 32;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << gap << p.second << ')';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')' << ':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef tree<int, null_type, less_equal<int>,
             rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
//**************************************************************************************************************************************************************************

void c_p_c()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/* #define N 101
int m,n;
int matrix[N][N], I[N][N]; */
typedef vector<vector<ll>> matrix;
int n;

matrix mul(matrix A, matrix B)
{
    matrix c(n + 1, vector<ll>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            for (int k = 1; k <= n; k++)
            {
                c[i][j] += A[i][k] * B[k][j];
                c[i][j] %= mod;
            }
        }
    }
        return c;
}

/* for(int i = 1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            matrix[i][j] = res[i][j];
        }
    } */

matrix power(matrix A, int p)
{
    if (p == 1)
        return A;
    matrix res = power(A, p / 2);
    res = mul(res, res);
    if (p & 1)
        res = mul(res, A);
    return res;
    /* while(n)
    {
        if(n&1)
        {
            mul(c,matrix);
        }
        mul(matrix,matrix);
        n>>=1;
    } */
}

/* void printMat(vector<vector<ll>>&matrix,int m)
{
    for(int i = 1;i<=m;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
} */

void solve()
{
    int p;
    cin >> n >> p;
    matrix m(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> m[i][j];
        }
    }

    matrix ans = power(m, p);
    //printMat(matrix, m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    // c_p_c();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
#endif
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}