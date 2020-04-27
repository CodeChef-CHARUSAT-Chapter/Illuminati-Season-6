/// DFS Problems

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define pb push_back

vector<ll> adj[(ll)1e5+5];
vector<bool> visited((ll)1e5+5,false);
vector<ll> a((ll)1e5+5);

void dfs(ll u,vector<ll> &subtree_sum){
    visited[u]=true;
    subtree_sum[u] = a[u];
    for(ll v:adj[u]){
        if(!visited[v]){
            dfs(v,subtree_sum);
            subtree_sum[u]+=subtree_sum[v];
        }
    }
}

int main(){

    ll n;

    cin>>n;
    vector<ll> subtree_sum(n+1,LLONG_MAX);
    ll u,v;

    for(ll i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    dfs(1,subtree_sum);

    for(ll i=1;i<=n;i++){
        cout<<subtree_sum[i]<<" ";
    }

    cout<<endl;
}
