#include <bits/stdc++.h>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <math.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int> > 
#define vl vector<long long>
#define vc vector<char> 
#define vvc vector<vector<char> > 
#define vpi vector<pair<int,int> >
#define ll long long 
#define sz(a) int(a.size())
#define forn(i,n) for(int i = 0 ; i < int(n) ; i++)
#define all(x) x.begin(),x.end()
#define vpl vector<pair<long long,long long> > 
#define F first
#define S second
#define mp make_pair
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pci pair<char,int>
#define vpii vector<pii> 
#define vpll vector<pll> 
#define len(s) s.length()
#define un unsigned
# define M_PI           3.14159265358979323846  /* pi */
#define modulo 998244353ll
#define mod 1000000007ll
#define MAXN  1000001 
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
ll gcd(ll a,ll b){if(a==0 || b == 0) return max(a,b);if(a == 1 || b == 1)return 1;return gcd(max(a,b)%min(a,b),min(a,b));}



void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    pii curr;
    curr.F = -1;
    curr.S = -1;
    vi coll1;
    vi coll2;
    // int sum = 0;
    forn(i,n)
    {
        if(s[i] == '0' && curr.F == -1)
        curr.F = i;
        else if(s[i] == '1' && curr.F != -1)
        {
            if(curr.F == 0)
            coll1.pb(i);
            else
            {
                coll2.pb(i - curr.F);
            }
            curr.F = -1;
            curr.S = -1;
        }
    }
    sort(coll1.rbegin(),coll1.rend());
    sort(coll2.rbegin(),coll2.rend());
    if(curr.F != -1)
    coll1.pb(n-curr.F);
    int ans = 0; 
    for(int i = k/2 ; i < coll2.size() ; i++)
    ans += coll2[i];
    if(k == 0)
    {
        for(auto u : coll1)
        ans += u;
        cout<<ans<<endl;
        return;
    }
    if(k == 1 && coll1.size() > 1)
    {
        ans += coll1.back();
        cout<<ans<<endl;
        return;    
    }
    if(k%2 == 1 && coll1.size() > 1 && (k/2 - 1) >= 0 && (k/2-1) < coll2.size())
    ans += min(coll2[k/2 - 1 ],coll1.back());
    if(k%2 == 0 && (k/2 - 1) >= 0 && (k/2-1) < coll2.size())
    {
        int ss = 0;
        for(auto u : coll1)
        ss += u;    
        ans += min(ss,coll2[k/2 - 1]);
    }
    cout<<ans<<endl;
}

int main()    
{
    fast();
    int t;
    t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}




