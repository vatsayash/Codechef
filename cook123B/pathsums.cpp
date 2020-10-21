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


int a[210];

vi adj[210];

int n;

void clear()
{
	forn(i,n+1)
	{
		adj[i].clear();
		a[i] = -1;
	}
}


void read_tree()
{
	forn(i,n-1)
	{
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
}

void dfs(int v,int p)
{
	if(a[v] == -1)
	{
		if(a[p] == 1)
		{
			a[v] = 2;
		}
		else
		{
			a[v] = 1;
		}
	}
	for(auto u : adj[v])
	{
		if(u != p)
		{
			dfs(u,v);
		}
	}
}

void solve() 
{
	cin>>n;
	if(n ==1)
	{
		cout<<2<<endl;
		return;
	}
	clear();
	read_tree();
	a[0] = 1;
	dfs(1,0);
	forn(i,n)
	{
		cout<<a[i+1]<<" ";
	}
	cout<<endl;
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


