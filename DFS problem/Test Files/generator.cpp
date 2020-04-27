//Nihal Mittal - nihal_47
//Strike First , Strike Hard , No Mercy !!

/**⠀⠀⠀⠀⠀⠀⣀⣤⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣰⣿⣿⣿⣿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣧⢀⠀⠀⠀⠀
⠀⠀⠀⣿⣿⣿⠋⠀⠀⠀⠀⠀⠙⠀⠙⣿⣿⣿⣷⢳⢀⠀⠀⠀
⠀⠀⣠⣿⣿⣿⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⢀
⠀⠀⣸⣿⣿⣿⠸⠀⠀⠀⠒⠒⠒⠐⠀⠀⢿⣿⣿⣿⣿⣿⠀⠀
⠀⣴⣿⣿⣿⡿⠀⠒⣋⣙⡒⢰⠀⠤⣖⠒⢾⣿⣿⣿⣿⣧⠀⠀
⢺⣿⣿⣿⣿⢀⠀⠀⠉⠉⠉⠸⠀⡇⠉⠉⠀⢿⣿⣿⣿⣄⠀⠀
⠀⠙⣿⣿⣧⢻⠀⠀⠀⠀⠀⠠⠀⠰⠀⠀⠀⣸⠸⣿⣿⠿⠰⠀
⠀⠀⠀⠹⣿⣿⣿⣷⠀⡠⠙⣲⣔⣅⢡⣰⣷⣿⣿⣿⣧⠀⠀⠀
⠀⠀⠀⣼⣿⣿⣿⣿⠀⡿⠭⠭⠭⠭⢿⠀⣿⢻⣿⣿⠃⠀⠀⠀
⠀⠀⠀⠙⠛⣿⢻⠹⣿⠐⠙⠛⠟⠉⢀⣴⡟⢿⣿⡏⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡟⠀⠀⠻⣦⣤⣶⠾⠋⠀⠀⠁⡦⢄⢀⠀⠀⠀
⠀⠀⠀⠀⡠⠁⡇⠑⢄⠀⠀⠀⠀⠀⠀⠔⠀⠀⠁⠀⠀⠀⠉⠁
⠀⠔⠊⠁⠀⠀⣇⠀⠀⠀⠑⡤⠤⢎⠁⠀⠀⡘⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢢⠠⠀⡠⢆⠀⠀⡠⠙⢄⠀⡸⠀
**/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;
using namespace __gnu_pbds;
ll n;
vector<ll> v[100005];
vector<ll> a(100005) , sub, visited(100005) , si(100005);
ll randRange(ll lower,ll upper){
    ll num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
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
    ifstream fs,fa;
    ofstream fin,fout;
    fa.open("array.txt");
    fs.open("text2.txt");
    fin.open("Input_File_10_path.txt");
    fout.open("Output_File_10_path.txt");
    ll i,ans = LLONG_MAX;
    fs>>n;
    fin<<n<<endl;
    for(i=0;i<n-1;i++)
    {
    	ll x,y;
    	fs>>x>>y;
        fin<<x<<" "<<y<<endl;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    for(i=1;i<=n;i++)
    {
        fa>>a[i];
        fin<<a[i]<<" ";
    }
    dfs(1);
    for(i=1;i<=n;i++)
    {
    	sub.pb(si[i]);
    }
    sort(all(sub));
    for(i=1;i<n;i++) ans = min(ans , sub[i] - sub[i-1]);
    fout<<ans;
}
