//Problem Statement - Can Luffy become King Of Pirates ?
//Problem Code - NAKAPOWA

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mk make_pair
#define pb push_back
#define in insert
#define se second
#define fi first
#define mod 1000000007
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define all(v) (v).begin(),(v).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define pii pair<ll,ll>
#define vi(x) vector<x>
#define maxn 100005
using namespace std;
ll n;
vector<ll> v[100005];
vector<ll> a(100005) , sub, visited(100005) , si(100005);

void dfs(ll so)
{
	visited[so] = true;
    si[so] = a[so];
	for(auto u: v[so])
	{
		if(!visited[u])
		{
			dfs(u);
			si[so] += si[u];
		}
	}
}
signed main()
{
    fast;
    ll i,ans = LLONG_MAX;
    cin>>n;
    for(i=0;i<n-1;i++)
    {
    	ll x,y;
    	cin>>x>>y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    for(i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    for(i=1;i<=n;i++)
    {
    	sub.pb(si[i]);
    }
    sort(all(sub));
    for(i=1;i<n;i++) ans = min(ans , sub[i] - sub[i-1]);
    cout<<ans;
}
