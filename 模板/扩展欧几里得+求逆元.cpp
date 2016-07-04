#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
//返回d = gcd(a,b),x和y对应于等式ax+by = d中的x,y
ll extend_gcd(ll a,ll b,ll &x,ll &y)
{
    if (a == 0&&b == 0) {
        return -1;
    }
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extend_gcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
//求逆元(a对n的逆元)
ll mod_reverse(ll a,ll n)
{
    ll x,y;
    ll d = extend_gcd(a, n, x, y);
    if (d == 1) {
        return (x%n+n)%n;
    }
    else return -1;
}
